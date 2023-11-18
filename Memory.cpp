#include <iostream>
#include "Memory.h"

using namespace std;


Memory::Memory(int memSize) {
	this->memSize = memSize;
	mem = new Partition[memSize];
	queueSize = 0;
	queue = nullptr;

}

void Memory:: assemblePartitions(int sizes[]) {
	for (int i = 0; i < memSize; i++) {
		mem[i].partitionId = i + 1;
		mem[i].size = sizes[i];
		mem[i].remainingSize = sizes[i];
	}
}

void Memory:: enqueueProcesses(Process queue[], int size) {
	this->queue = new Process[size];
	queueSize = size;
	for (int i = 0; i < queueSize; i++) {
		this->queue[i].size = queue[i].size;
		this->queue[i].processId = i + 1;
	}


}

void Memory:: firstFit() {
	for (int i = 0; i < queueSize; i++) {
		for (int j = 0; j < memSize; j++) {

			if ((!mem[j].status) && mem[j].size >= queue[i].size) {
				mem[j].status = true;
				queue[i].status = true;
				mem[j].processId = queue[i].processId;
				queue[i].partitionId = mem[j].partitionId;
				mem[j].remainingSize = mem[j].remainingSize - queue[i].size;
				break;

			}
		}
	}

}



void Memory:: nextFit() {
	int index = 0;
	for (int i = 0; i < queueSize; i++) {
		for (int j = index; j < memSize; j++) {

			if ((!mem[j].status) && mem[j].size >= queue[i].size) {
				mem[j].status = true;
				queue[i].status = true;
				mem[j].processId = queue[i].processId;
				queue[i].partitionId = mem[j].partitionId;
				mem[j].remainingSize = mem[j].remainingSize - queue[i].size;
				index = j + 1;
				break;

			}
		}
	}

}


void Memory:: bestFit() {
	int bestIndex = 0;
	int bestWaste = 1000000;
	bool placed = false;
	for (int i = 0; i < queueSize; i++) {
		for (int j = 0; j < memSize; j++) {

			if ((!mem[j].status) && mem[j].size >= queue[i].size) {
				if (mem[j].remainingSize - queue[i].size <= bestWaste) {
					bestIndex = j;
					bestWaste = mem[j].remainingSize - queue[i].size;
					placed = true;
				}

			}
		}


		if ((placed)) {
			mem[bestIndex].status = true;
			queue[i].status = true;
			mem[bestIndex].processId = queue[i].processId;
			queue[i].partitionId = mem[bestIndex].partitionId;
			mem[bestIndex].remainingSize = mem[bestIndex].remainingSize - queue[i].size;
			bestIndex = 0;
			bestWaste = 1000000;
			placed = false;

		}


	}

}

void Memory:: worstFit() {
	int bestIndex = 0;
	int bestWaste = -1000000;
	bool placed = false;
	for (int i = 0; i < queueSize; i++) {
		for (int j = 0; j < memSize; j++) {

			if ((!mem[j].status) && mem[j].size >= queue[i].size) {
				if (mem[j].remainingSize - queue[i].size >= bestWaste) {
					bestIndex = j;
					bestWaste = mem[j].remainingSize - queue[i].size;
					placed = true;
				}

			}
		}


		if ((placed)) {
			mem[bestIndex].status = true;
			queue[i].status = true;
			mem[bestIndex].processId = queue[i].processId;
			queue[i].partitionId = mem[bestIndex].partitionId;
			mem[bestIndex].remainingSize = mem[bestIndex].remainingSize - queue[i].size;
			bestIndex = 0;
			bestWaste = -1000000;
			placed = false;

		}


	}

}


void Memory:: dynWorstFit() {
	int bestIndex = 0;
	int bestWaste = -1000000;
	bool placed = false;
	for (int i = 0; i < queueSize; i++) {
		for (int j = 0; j < memSize; j++) {

			if ((!mem[j].status) && mem[j].size >= queue[i].size) {
				if (mem[j].remainingSize - queue[i].size >= bestWaste) {
					bestIndex = j;
					bestWaste = mem[j].remainingSize - queue[i].size;
					placed = true;
				}

			}
		}


		if ((placed)) {
			mem[bestIndex].status = true;
			queue[i].status = true;
			mem[bestIndex].processId = queue[i].processId;
			queue[i].partitionId = mem[bestIndex].partitionId;
			mem[bestIndex].remainingSize = mem[bestIndex].remainingSize - queue[i].size;
			if (mem[bestIndex].remainingSize != 0) {

				Partition newPartition;
				newPartition.partitionId = memSize + 1;
				newPartition.size = mem[bestIndex].remainingSize;
				newPartition.remainingSize = newPartition.size;
				mem[bestIndex].remainingSize = 0;
				memSize++;



				Partition* newMemory = new Partition[memSize];

				for (int i = 0; i < memSize - 1; i++) {
					newMemory[i] = mem[i];
				}
				newMemory[memSize - 1] = newPartition;
				delete mem;
				mem = newMemory;




			}

			bestIndex = 0;
			bestWaste = -1000000;
			placed = false;

		}


	}

}






void Memory:: output() {

	cout << "Process ID\t " << "Partition ID\t" << "Wasted Space\t" << "Status\n";
	for (int i = 0; i < queueSize; i++) {
		cout << queue[i].processId << "\t\t";
		if (!queue[i].status) {
			cout << "N/A\t\t" << "N/A\t\t" << "Waiting";
		}
		else {
			cout << queue[i].partitionId << "\t\t" << mem[queue[i].partitionId - 1].remainingSize << "\t\t" << "Running";
		}
		cout << endl;

	}
	int sum = 0;
	for (int i = 0; i < memSize; i++) {
		if (mem[i].status)
			sum += (mem[i].remainingSize);
	}

	cout << "\nTotal Waste: " << sum << endl;



}


