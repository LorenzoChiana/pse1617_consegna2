#include "MsgTask.h"
#include "Arduino.h"
#include "config.h"

MsgTask::MsgTask(/*float differenceThreshold,*/ GlobalState* Global){
  this->Global = Global;
}

void MsgTask::init(int period){
	Task::init(period);	
	MsgService.init();
}

void MsgTask::tick(){	
  	if (MsgService.isMsgAvailable()) {
		Msg* msg = MsgService.receiveMsg();    
		if (msg->getContent() == COMMAND_USERS){
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
	char* emptyString = "";
	char* output = Global->getWritingBuffer();
	if (strcmp(Global->getWritingBuffer(),emptyString)!=0){
		MsgService.sendMsg(output);		
		Global->setWritingBuffer(" ");
	}
}

