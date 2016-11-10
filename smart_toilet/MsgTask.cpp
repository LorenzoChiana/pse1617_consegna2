#include "MsgTask.h"
#include "Arduino.h"
#include "config.h"

MsgTask::MsgTask(/*float differenceThreshold,*/ GlobalState* Global){
this->Global = Global;
}

void MsgTask::init(int period){
	Task::init(period);
	emptyString = "\0";	
	MsgService.init();
}

void MsgTask::tick(){	
	if (MsgService.isMsgAvailable()) {
		Serial.print("RICEVUTO: ");
		Msg* msg = MsgService.receiveMsg();  
		Serial.println(msg->getContent()) ; 
		if (msg->getContent() == COMMAND_USERS){
			Serial.println("Mandato");
			MsgService.sendMsg(getUsers());
		}
		if (msg->getContent() == COMMAND_STATE){
			MsgService.sendMsg(getState());
		}
		delete msg;
	}

	flushBuffer();
}

char* MsgTask::getUsers(){
	char response[10];
	sprintf(response,"%d",Global->getUsers());
	return response;
}

char* MsgTask::getState(){
	char state[10];
	if (Global->getPresence()){
		strcpy(state,"Occupato");	
	} else if (Global->getAlarm()){
		strcpy(state,"Allarme");  
	} else {
		strcpy(state,"Libero"); 
	}
	return state;


}	

void MsgTask::flushBuffer(){

	char* output = Global->getWritingBuffer();
	if (strlen(output)>0){
		MsgService.sendMsg(output);		
		Global->setWritingBuffer("\0");
	}
}

