#pragma once
#include "globalHeader.h"
using namespace std;
class MinimumHeapNode
{

private:
	int value;
	float vertexName;

public:

	int getVertexName();
	float getValue();
	void setValue(int val);

	/*****************************************************************************/
	MinimumHeapNode* createNewMinimumHeapNode(int newSource, int newDest, int newWeight);
	void setVertexName(int i);
};

