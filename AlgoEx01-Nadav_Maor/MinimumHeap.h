#pragma once
//#include "globalHeader.h"


class MinimumHeapNode;
class minimumHeap
{
public:

	MinimumHeapNode** array;
	int pysSize;    //   Pys size
	int logSize;   //   Log size	
	int* positionArr;


	static int Left(int Idx);
	static int Right(int Idx);
	static int parent(int Idx);
	void fixHeap(int node);
	MinimumHeapNode* deleteMin();
	minimumHeap(int _numOfVertix);
	minimumHeap();

	void insert(MinimumHeapNode* item);
	void decreaseKey(int keyToDecrease, float newDistance);
	bool isEmptyHeap();
	MinimumHeapNode* getExactHeapNode(int requiredNode);
	bool isInHEap(int requiredNode);
	int getLogSize() const;
	void Build(int _numOfVertix, int* weigthArr);
};

