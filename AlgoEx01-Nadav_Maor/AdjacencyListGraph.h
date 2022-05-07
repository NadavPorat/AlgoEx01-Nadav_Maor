#pragma once
//#include "globalHeader.h"


class AdjacencyListNode;
class AdjacencyList;

class AdjacencyListGraph
{

    int numOfVertecs;
    int numOfEdge;
    AdjacencyList* array;

public:
    AdjacencyListGraph(int _numberOfVerticsForMatrixInit);
    AdjacencyListGraph();
    void MakeEmptyGraph(int _numberOfVertecsForMatrixInit);
    void AddEdge(int src, int dest, float newEdgeWeight);
    bool IsAdjacent(int source, int dest);
    bool RemoveEdge(int src, int dest);
    int getNumOfVertex();
    int getNumOfEdges();
    AdjacencyList GetAdjList(int requiredVertexAdjList);
    int getEdgeWeight(int source, int dest);


    static AdjacencyListNode* newAdjListNode(int newNodedest, float newEdgeWeight);




};


