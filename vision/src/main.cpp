#include "vision.h"
#include "target.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>
#include <thread>
#include "rapidjson/document.h"
#include "client.h"
#include <sstream>

Vision vt;
Target target;
Client client;

double targetFeet = 20;
double pixelWidth = 640;
double fovAngle = 59.7 / 2;

stringstream ss;
rapidjson::Document jsonData;
int sock;
int port = 5000;
int bytes_read;
socklen_t addr_len;
char recv_data[1024];
struct sockaddr_in server_addr , client_addr;

void processImage(string imageFile) {
    Mat src = imread(imageFile, 1);
    Mat hsv_image = vt.applyHsvThreshold(src);
    vector<RotatedRect> getRectangles = vt.getContours(hsv_image);
    vector<map<int, double> > results = vt.getResults(getRectangles);
    for(int i = 0; i < results.size(); i++) {
        map<int, double> resultMap = results[i];
        double distanceOne = target.directDistanceToTarget(targetFeet, resultMap[0], pixelWidth, fovAngle);
//        double distanceTwo = target.directDistanceToTarget(targetFeet, resultMap[4], pixelWidth, fovAngle);
//        cout << distanceOne << endl;
        ss << distanceOne;
        client.send(ss.str());
        ss.str(string());
    }
}

int server() {
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_addr.sin_zero),8);

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("Bind");
        exit(1);
    }

    addr_len = sizeof(struct sockaddr);
    cout << "UDPServer Waiting for client on port 5000" << endl;

    while (1) {
        bytes_read = recvfrom(sock, recv_data, 1024, 0, (struct sockaddr *)&client_addr, &addr_len);
        recv_data[bytes_read] = '\0'; // recv_data is the data to parse
        jsonData.Parse(recv_data);
        string image = jsonData["image"].GetString();
        if(strcmp(jsonData["command"].GetString(), "Autonomous") == 0) {
            thread t1(processImage, image);
            t1.join();
        }
    }
    return 0;
}

int main() {
    server();
}
