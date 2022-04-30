#include "globalHeader.h"

void AdjacencyListNode::setWeight(float newWeight)
{
	weight = newWeight;
}

void AdjacencyListNode::setDest(int newDest)
{
	dest = newDest;
}

void AdjacencyListNode::setNext(AdjacencyListNode* newNext)
{
	next = newNext;
}

AdjacencyListNode* AdjacencyListNode::GetNext()
{
	return next;
}


float AdjacencyListNode::GetWeight()
{
	return weight;
}

int AdjacencyListNode::GetDest()
{
	return dest;
}

