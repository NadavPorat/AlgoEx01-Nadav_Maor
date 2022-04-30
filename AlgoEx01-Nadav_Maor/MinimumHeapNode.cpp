#include "globalHeader.h"

#include <cstdlib>

int MinimumHeapNode::getVertixName()
{
	return vertexName;
}

float MinimumHeapNode::getValue()
{
	return value;
}

void MinimumHeapNode::setValue(int newValue)
{
	value = newValue;
}


void MinimumHeapNode::setKey(int newKey)
{
	vertexName = newKey;
}






