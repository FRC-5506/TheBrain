package com.nohowdezign.thebrain;

import java.io.IOException;

import com.nohowdezign.thebrain.server.PrintServer;

public class Main {
	
	public static void main(String[] args) {
		PrintServer server = new PrintServer();
		try {
			server.setPort(5001);
			server.run();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
}
