#pragma once
//#include "globalHeader.h"
class AdjacencyListNode;

class AdjacencyList
{

private:

	AdjacencyListNode* head;


public:
	void setHead(AdjacencyListNode* newHead);
	AdjacencyListNode* getHead();

};

