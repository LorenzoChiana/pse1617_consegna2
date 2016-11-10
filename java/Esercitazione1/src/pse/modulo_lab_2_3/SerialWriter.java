package pse.modulo_lab_2_3;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class SerialWriter implements Runnable{

	private SerialCommChannel channel;

	BufferedReader br;

	SerialWriter(SerialCommChannel channel){
		this.channel = channel;
		br = new BufferedReader(new InputStreamReader(System.in));
	}		
	@Override
	public void run(){
		String msg = new String();
		while(true){			
			try {
				msg = br.readLine();
				channel.sendMsg(msg);			
			} catch (Exception e) {
				System.out.println("Writer error");
			}
		}

	}		
}