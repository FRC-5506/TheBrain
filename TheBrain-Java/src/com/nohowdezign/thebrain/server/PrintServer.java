package com.nohowdezign.thebrain.server;

public class PrintServer extends ServerFactory {
	
	public void onMessage(String message) {
		System.out.println(message);
	}
	
}
