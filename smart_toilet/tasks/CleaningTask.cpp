#include "ClaeaningTask.h"
#include "Arduino.h"

ClaeaningTask::ClaeaningTask(){
}

void ClaeaningTask::init(int period){
	Task::init(period);
	
	currentTime = initialTime = 0;
	//currentState = prevState = 0;
	executeCleaning = false;
	firstTime = true;

}

void ClaeaningTask::tick(){
	if (Global.getUsers()%10==0 && executeCleaning){
		if (Global.getPresence()) {
			noInterrupts();
			/*
				MANDARE MESSAGGIO!!!
			*/
			interrupts();
		} 

		

		// se è il primo ciclo prendo il tempo iniziale e setto lo stato in "cleaning"
		if (firstTime){
			currentTime = initialTime = millis();
			noInterrupts();
			Global.setCleaning(true);
  			interrupts();
		}
		
		currentTime = millis();
		//dopo 10 sec lo stato "cleaning" diventa falso
		if (currentTime - initialTime >= 10000){
			noInterrupts();
			Global.setCleaning(false);
  			interrupts();
		}

		firstTime = false;
	} else if (Global.getUsers()%10!=0) {
		firstTime = true;
		executeCleaning = true;
	}

	//CONTROLLO NUMERI UTENTI ENTRATI NEL WC

	//utente entra
	if(Global.getPresence) {
		userEntered = true;
	}

	//utente esce
	if(!Global.getPresence && userEntered) {
		noInterrupts();
		Global.setUsers(Global.getUsers() + 1);
		userEntered = false;
  		interrupts();
	}
}