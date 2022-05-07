#include "globalHeader.h"

#include <cstdlib>

int MinimumHeapNode::getVertexName()
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


void MinimumHeapNode::setVertexName(int newKey)
{
	vertexName = newKey;
}






