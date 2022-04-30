#pragma once
//#include "globalHeader.h"


class AdjacencyListNode;
class AdjacencyList;

class AdjacencyListGraph
{

    int numOfVertics;
    AdjacencyList* array;

public:
    AdjacencyListGraph(int _numberOfVerticsForMatrixInit);
    AdjacencyListGraph();
    void MakeEmptyGraph(int _numberOfVerticsForMatrixInit);
    void AddEdge(int src, int dest, float newEdgeWeight);
    bool IsAdjacent(int source, int dest);
    void RemoveEdge(int src, int dest);
    int getNumOfVertix();
    AdjacencyList GetAdjList(int requiredVertixAdjList);
    int getEdgeWeight(int source, int dest);


    static AdjacencyListNode* newAdjListNode(int newNodedest, float newEdgeWeight);




};


