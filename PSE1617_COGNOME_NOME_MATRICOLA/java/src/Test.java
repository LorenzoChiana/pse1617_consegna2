package pse.consegna2;

/**
 * Testing simple message passing.
 * 
 * To be used with an Arduino connected via Serial Port
 * running modulo-2.3/pingpong.ino
 * 
 * @author aricci
 *
 */
public class Test {

	public static void main(String[] args) throws Exception {
		SerialCommChannel channel = new SerialCommChannel(args[0],9600);		
		
		System.out.println("Waiting Arduino for rebooting...");		
		Thread.sleep(4000);
		System.out.println("Ready.");		

		//Launched the thread that reads the messages for the Arduino connected	
		new Thread(new SerialReader(channel)).start();
		//Launched the thread that writes the messages to the Arduino connected	
		new Thread(new SerialWriter(channel)).start();
			
		
	}

}
