config=`pkg-config --libs opencv`

all:
	g++ $(config) -std=c++0x -pthread -Iinclude/ -Isrc src/main.cpp src/client.cpp src/target.cpp src/vision.cpp $(config) -o bin/VisionTracking

calibration:
	g++ $(config) src/calibration.cpp $(config) -o bin/calibrate

targettest:
	cxxtestgen --error-printer -o test/target/TargetTest.cpp test/target/TargetTest.h
	g++ $(config) -Isrc src/target.cpp src/vision.cpp test/target/TargetTest.cpp $(config) -o bin/TargetTest
