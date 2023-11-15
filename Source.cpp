#include<iostream>
#include "Memory.h"
using namespace std;








int main() {
	
	Process queue[5];
	for (int i = 0; i < 5; i++) {
		cout << "Enter size of process\n";
		int size;
		cin >> size;
		queue[i].size=size;

	}

	int partitionSizes[5];

	for (int i = 0; i < 4; i++) {
		cout << "Enter size of partition\n";
		int size;
		cin >> size;
		partitionSizes[i] = size;
	}


	
	Memory firstFit(4);
	firstFit.assemblePartitions(partitionSizes);
	firstFit.enqueueProcesses(queue, 5);
	firstFit.firstFit();
	cout << "\n================FIRST FIT========================\n";
	firstFit.output();


	Memory nextFit(4);
	nextFit.assemblePartitions(partitionSizes);
	nextFit.enqueueProcesses(queue, 5);
	nextFit.nextFit();
	cout << "\n================NEXT FIT========================\n";
	nextFit.output();





	Memory bestFit(4);
	bestFit.assemblePartitions(partitionSizes);
	bestFit.enqueueProcesses(queue, 5);
	bestFit.bestFit();
	cout << "\n================BEST FIT========================\n";
	bestFit.output();

	Memory worstFit(4);
	worstFit.assemblePartitions(partitionSizes);
	worstFit.enqueueProcesses(queue, 5);
	worstFit.worstFit();
	cout << "\n================WORST FIT========================\n";
	worstFit.output();


	Memory dynWorstFit(4);
	dynWorstFit.assemblePartitions(partitionSizes);
	dynWorstFit.enqueueProcesses(queue, 5);
	dynWorstFit.dynWorstFit();
	cout << "\n================DYNAMIC WORST FIT========================\n";
	dynWorstFit.output();



	















	return 0;
}