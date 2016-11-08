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
}

char* MsgTask::getUsers(){
	char response[10];
	sprintf(response,"%d",Global->getUsers());

	return response;
}

char* MsgTask::getState(){
	if (Global->getPresence()){
		return "Occupato";
	} else if (Global->getAlarm()){
		return "Allarme";
	} else {
		return "Libero";
	}


}	

/*void MsgTask::flushBuffer(){
	
	char* output = Global->getWritingBuffer();
	MsgService.sendMsg(output);

	Global->setWritingBuffer("");
}*/

