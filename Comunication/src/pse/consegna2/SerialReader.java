package pse.consegna2;

public class SerialReader implements Runnable{

	private SerialCommChannel channel;

	SerialReader(SerialCommChannel channel){
		this.channel = channel;
	}		
	@Override
	public void run(){

		String msg = new String();
		
		while (true){
			try {
				msg = channel.receiveMsg();
			} catch (InterruptedException e) {
				System.out.println("Reader error");
			}
			System.out.println("Message recived: "+ msg);
			
		}		
	}		
}	