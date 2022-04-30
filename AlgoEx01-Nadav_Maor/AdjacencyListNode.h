#pragma once
//#include "globalHeader.h"

class AdjacencyListNode
{
private:
    float weight;
    int dest;
    AdjacencyListNode* next;

public:
    void setWeight(float newWeight);
    void setDest(int newDest);
    void setNext(AdjacencyListNode* newNext);
    AdjacencyListNode* GetNext();
    float GetWeight();
    int GetDest();
};

