#include "globalHeader.h"
#include "AdjacencyListGraph.h"


#define INF INT_MAX;

using namespace std;


AdjacencyListGraph::AdjacencyListGraph(int _numberOfVerticsForMatrixInit)
{
    MakeEmptyGraph(_numberOfVerticsForMatrixInit);
}

AdjacencyListGraph::AdjacencyListGraph()
{
    MakeEmptyGraph(1);

}

void AdjacencyListGraph::MakeEmptyGraph(int _numberOfVertecsForMatrixInit)
{
    this->numOfVertecs = _numberOfVertecsForMatrixInit;
    this->numOfEdge = 0;
    array = new AdjacencyList[_numberOfVertecsForMatrixInit + 1];

    for (int forIdx = 0; forIdx <= _numberOfVertecsForMatrixInit; forIdx++)
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
    return numOfVertecs;
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


void AdjacencyListGraph::RemoveEdge(int source, int dest)
{
    ///TODO ADD REMOVE FROM BOTH SIDE
    if (IsAdjacent(source, dest))
    {
        AdjacencyListNode* nodeToCheck = array[source].getHead();

        while (nodeToCheck != nullptr)
        {
            if (nodeToCheck->GetDest() == dest)
            {
                break;
            }
            else
                nodeToCheck = (nodeToCheck->GetNext());
        }
        ///TODO fix logic

        if (nodeToCheck == array[source].getHead())
        {
            array[source].setHead(nodeToCheck->GetNext());
        }
        else
        {
            //TODO if node to chack->getnext()->get dest === dest.
            //TODO modeTocaheck->set next(chack->getnext()->getnext)
            nodeToCheck->setNext(nodeToCheck->GetNext());
        }

    }
    else
    {
        cout<< "invalid input";
        exit(1);
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




