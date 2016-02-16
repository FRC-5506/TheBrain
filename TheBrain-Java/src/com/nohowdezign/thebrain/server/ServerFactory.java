package com.nohowdezign.thebrain.server;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetSocketAddress;
import java.net.SocketException;

public abstract class ServerFactory {
	private int port = 3000;
	private String bindAddress = "0.0.0.0";
	private DatagramSocket serverSocket = null;
	private byte[] receiveData = new byte[1024];
	
	protected void initialize() throws SocketException {
		System.out.println("Initializing...");
		DatagramSocket socket = new DatagramSocket(null);
		InetSocketAddress address = new InetSocketAddress(this.getBindAddress(), this.getPort());
		socket.bind(address);
		this.setServerSocket(socket);
	}
	
	protected void start() throws IOException {
		while(true) {
			DatagramPacket packet = new DatagramPacket(receiveData, receiveData.length);
			this.getServerSocket().receive(packet);
			String sentance = new String(packet.getData(), packet.getOffset(), packet.getLength());
			onMessage(sentance);
		}
	}
	
	public void run() throws IOException {
		this.initialize();
		this.start();
	}
	
	public void onMessage(String message) {
		
	}
	
	public void end() {
		
	}
	
	public int getPort() {
		return this.port;
	}
	
	public void setPort(int port) {
		this.port = port;
	}
	
	public void setBindAddress(String address) {
		this.bindAddress = address;
	}
	
	public String getBindAddress() {
		return this.bindAddress;
	}

	public DatagramSocket getServerSocket() {
		return serverSocket;
	}

	public void setServerSocket(DatagramSocket serverSocket) {
		this.serverSocket = serverSocket;
	}
}
