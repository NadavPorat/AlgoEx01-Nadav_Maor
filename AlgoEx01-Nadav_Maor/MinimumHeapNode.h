#pragma once
#include "globalHeader.h"
using namespace std;
class MinimumHeapNode
{

private:
	int value;
	float vertexName;

public:

	int getVertixName();
	float getValue();
	void setValue(int val);

	/*****************************************************************************/
	MinimumHeapNode* createNewMinimumHeapNode(int newSource, int newDest, int newWeight);
	void setKey(int i);
};

