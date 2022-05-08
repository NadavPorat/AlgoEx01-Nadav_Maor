#pragma once
//#include "globalHeader.h"


class AdjacencyListNode;
class AdjacencyList;

class AdjacencyListGraph
{

    int numOfVertices;
    int numOfEdge;
    AdjacencyList* array;

public:
    AdjacencyListGraph(int _numberOfVerticesForMatrixInit);
    AdjacencyListGraph();
    void MakeEmptyGraph(int _numberOfVerticesForMatrixInit);
    void AddEdge(int src, int dest, float newEdgeWeight);
    bool IsAdjacent(int source, int dest);
    bool RemoveEdge(int src, int dest);
    int getNumOfVertex();
    int getNumOfEdges();
    AdjacencyList GetAdjList(int requiredVertexAdjList);
    int getEdgeWeight(int source, int dest);

    static AdjacencyListNode* newAdjListNode(int newNodeDest, float newEdgeWeight);

    bool IfConnectedGraph();

    bool DFS();

    void VISIT(int i);

    void VISIT(int u, int *color);
};


