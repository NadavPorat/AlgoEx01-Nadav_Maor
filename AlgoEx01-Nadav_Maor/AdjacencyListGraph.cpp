#include "globalHeader.h"
#include "AdjacencyListGraph.h"


#define INF INT_MAX;

using namespace std;


AdjacencyListGraph::AdjacencyListGraph(int _numberOfVerticesForMatrixInit)
{
    MakeEmptyGraph(_numberOfVerticesForMatrixInit);
}

AdjacencyListGraph::AdjacencyListGraph()
{
    MakeEmptyGraph(1);

}

void AdjacencyListGraph::MakeEmptyGraph(int _numberOfVerticesForMatrixInit)
{
    this->numOfVertices = _numberOfVerticesForMatrixInit;
    this->numOfEdge = 0;
    array = new AdjacencyList[_numberOfVerticesForMatrixInit + 1];

    for (int forIdx = 0; forIdx <= _numberOfVerticesForMatrixInit; forIdx++)
    {
        array[forIdx].setHead(nullptr);
    }
}


bool AdjacencyListGraph::IsAdjacent(int source, int dest)
{
    AdjacencyListNode* nodeToCheck = array[source].getHead();

    while (nodeToCheck != nullptr)
    {
        if (nodeToCheck->GetDest() == dest)
        {
            return true;
        }
        else
            nodeToCheck = (nodeToCheck->GetNext());
    }
    return false;
}

AdjacencyList AdjacencyListGraph::GetAdjList(int requiredVertexAdjList)
{
    return array[requiredVertexAdjList];
}

int AdjacencyListGraph::getNumOfVertex()
{
    return numOfVertices;
}


//Creating New Adjacency List Node    
AdjacencyListNode* AdjacencyListGraph::newAdjListNode(int newNodedest, float newEdgeWeight)
{
    AdjacencyListNode* newNode = new AdjacencyListNode;
    newNode->setDest(newNodedest);
    newNode->setWeight(newEdgeWeight);
    newNode->setNext(nullptr);
    return newNode;
}



/*
 * Adding Edge to Graph
 */
void AdjacencyListGraph::AddEdge(int src, int dest, float newEdgeWeight)
{
    AdjacencyListNode* newEdge = newAdjListNode(dest, newEdgeWeight);
    newEdge->setNext(array[src].getHead());
    array[src].setHead(newEdge);

    AdjacencyListNode* cloneEdge = newAdjListNode(src, newEdgeWeight);
    cloneEdge->setNext(array[dest].getHead());
    array[dest].setHead(cloneEdge);
    this->numOfEdge += 1;
}

bool AdjacencyListGraph::IfConnectedGraph()
{
    bool isConnected =true;
    AdjacencyListNode* nodeToCheck ;
    for(int i=1; i <= numOfVertices; i++)
    {
        nodeToCheck =  array[i].getHead();
        if(nodeToCheck== nullptr)
        {
            isConnected= false;
        }
    }
    if(numOfEdge < numOfVertices - 1)
    {
        isConnected = false;
    }
    else
    {
        if(!DFS())
        {
            isConnected = false;
        }
    }
    return isConnected;
}
bool AdjacencyListGraph::DFS()
{
    //0 -white
    //1 - grey
    //2 - black
    int color[numOfVertices];
    for(int i=1; i <= numOfVertices; i++)
    {
        color[i]=0;
    }

    VISIT(1,color);

    for(int i=1; i <= numOfVertices; i++)
    {
        if(color[i]!= 2)
        {
            return false;
        }
    }
    return true;
}

void AdjacencyListGraph::VISIT(int u, int * color) {
    color[u]=1;
    AdjacencyListNode* v = array[u].getHead();
    while (v != nullptr)
    {
        if(color[v->GetDest()]==0)
        {
            color[v->GetDest()]=1;
            VISIT(v->GetDest(),color);
        }
        v= v->GetNext();
    }
    color[u]=2;

}


bool AdjacencyListGraph::RemoveEdge(int source, int dest)
{
    if(source>0 && source<= numOfVertices && dest > 0 && dest<= numOfVertices) {
        if (IsAdjacent(source, dest)) {
            AdjacencyListNode *sourceNode = array[source].getHead();
            AdjacencyListNode *destNode = array[dest].getHead();

            while (sourceNode != nullptr) {

                if (sourceNode->GetDest() == dest) {
                    array[source].setHead(sourceNode->GetNext());
                    break;
                }
                if (sourceNode->GetNext()->GetDest() == dest) {

                    sourceNode->setNext(sourceNode->GetNext()->GetNext());
                    break;
                } else
                    sourceNode = (sourceNode->GetNext());
            }

            while (destNode != nullptr) {

                if (destNode->GetDest() == source) {
                    array[dest].setHead(destNode->GetNext());
                    break;
                }
                if (destNode->GetNext()->GetDest() == source) {
                    destNode->setNext(destNode->GetNext()->GetNext());
                    break;
                } else
                    destNode = (destNode->GetNext());
            }

            this->numOfEdge--;
            return true;
        } else {
            return false;
        }
    }
    else
    {
        return false;
    }
}


int AdjacencyListGraph::getEdgeWeight(int source, int dest)
{

    AdjacencyListNode* adj = array[source].getHead();

    while (adj->GetDest() != dest)
    {
        adj = adj->GetNext();
    }
    return adj->GetWeight();
}

int AdjacencyListGraph::getNumOfEdges() {
    return numOfEdge;
}





