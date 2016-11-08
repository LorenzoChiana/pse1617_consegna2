
#include "CleaningTask.h"
#include "Arduino.h"

CleaningTask::CleaningTask(GlobalState *Global){
	this->Global = Global;
}

void CleaningTask::init(int period){
	Task::init(period);
	
	currentTime = initialTime = 0;
	//currentState = prevState = 0;
	executeCleaning = false;
	firstTime = true;
	userEntered = false;

}

void CleaningTask::tick(){
	if (Global->getUsers()%10==0 && executeCleaning){
		if (Global->getPresence()) {
			noInterrupts();
			
			Global->setWritingBuffer("Si prega di uscire, toilette in fase di auto-pulizia");
			interrupts();
		} 

		

		// se è il primo ciclo prendo il tempo iniziale e setto lo stato in "cleaning"
		if (firstTime){
			currentTime = initialTime = millis();
			noInterrupts();
			Global->setCleaning(true);
			interrupts();
		}
		
		currentTime = millis();
		//dopo 10 sec lo stato "cleaning" diventa falso
		if (currentTime - initialTime >= 10000){
			noInterrupts();
			Global->setCleaning(false);
			interrupts();
		}

		firstTime = false;
	} else if (Global->getUsers()%10!=0) {
		firstTime = true;
		executeCleaning = true;
	}

	//CONTROLLO NUMERI UTENTI ENTRATI NELLA TOILET

	//utente entra
	if(Global->getPresence()) {
		userEntered = true;
	}

	//utente esce
	if(!Global->getPresence() && userEntered) {
		noInterrupts();
		Global->incUsers();
		userEntered = false;
		interrupts();
	}
}