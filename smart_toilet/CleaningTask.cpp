
#include "CleaningTask.h"
#include "Arduino.h"
#include "config.h"

CleaningTask::CleaningTask(GlobalState *Global){
	this->Global = Global;
}

void CleaningTask::init(int period){
	Task::init(period);
	
	currentTime = initialTime = 0;
	this->message = "Si prega di uscire, toilette in fase di auto-pulizia";
	this->executeCleaning = false;
	this->firstTime = true;
	this->firstWarning = true;
	this->userEntered = false;

}

void CleaningTask::tick(){
	/*
		non pulisce finché vi è un allarme attivo
		appena l'allarme viene stoppato si esegue -> guardare stopAlarm
	*/
	
	if (Global->getUsers()%10==0 && executeCleaning && !Global->getAlarm()){
		if (Global->getPresence() && this->firstWarning) {
			Global->setWritingBuffer(this->message);
			this->firstWarning = false;
		}
		if (!Global->getPresence()){
			this->firstWarning=true;
		}
		// se è il primo ciclo prendo il tempo iniziale e setto lo stato in "cleaning"
		if (firstTime){
			currentTime = initialTime = millis();
			Global->setCleaning(true);
		}
		currentTime = millis();
		//dopo 10 sec lo stato "cleaning" diventa falso
		if (currentTime - initialTime >= TMAX_CLEANING){
			Global->setCleaning(false);
			this->firstWarning = true;
			executeCleaning=false;
		}
		firstTime = false;
	} else if (Global->getUsers()%10!=0) {
		firstTime = true;
		executeCleaning = true;
	}
	//CONTROLLO NUMERI UTENTI ENTRATI NELLA TOILET
	if (!Global->isCleaning()){
		//utente entra
		if(Global->getPresence()) {
			userEntered = true;
		}
		//utente esce
		if(!Global->getPresence() && userEntered) {
			Global->incUsers();
			userEntered = false;
		}
	}
}
