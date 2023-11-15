#pragma once
#ifndef MEMORY_H
#define MEMORY_H
#include "Process.h"
#include "Partition.h"


class Memory {
private:
	Partition* mem;
	Process* queue;
	int memSize;
	int queueSize;
public:
	Memory(int memSize);

	void assemblePartitions(int sizes[]);

	void enqueueProcesses(Process queue[], int size);

	void firstFit();



	void nextFit();


	void bestFit();

	void worstFit();


	void dynWorstFit();





	void output();







};

#endif 
