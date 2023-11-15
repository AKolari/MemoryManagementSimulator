#pragma once
#ifndef PROCESS_H
#define PROCESS_H


struct Process {
	int processId;
	bool status;//Waiting=0, running=1
	int partitionId;
	int size;
	Process();


};

#endif 
