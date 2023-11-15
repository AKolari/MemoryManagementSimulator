#pragma once
#ifndef PARTITION_H
#define PARTITION_H


struct Partition {
	int partitionId;
	bool status;
	int processId;
	int size;
	int remainingSize = 0;
	Partition();

};
#endif 
