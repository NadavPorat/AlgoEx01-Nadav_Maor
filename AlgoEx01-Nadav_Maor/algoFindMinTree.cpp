#include "globalHeader.h"

static int calcGraphWightPrim(int* parentList, AdjacencyListGraph* graph)
{
	int sum = 0;
	for (int i = 1; i <= graph->getNumOfVertex(); i++)
	{
		if (parentList[i] != -1)
		{
			sum += graph->getEdgeWeight(parentList[i], i);
		}
	}
	return sum;
}
int Prim(AdjacencyListGraph* adjacencyListGraph) {


	int numOfVertex = adjacencyListGraph->getNumOfVertex();
	minimumHeap* Q = new minimumHeap(numOfVertex);
	bool* inT = new bool[numOfVertex];
	for (int i = 0; i <= numOfVertex; i++) {
		inT[i] = false;
	}

	int* minArr = new int[numOfVertex];
	int* parent = new int[numOfVertex];

	int startVertex = 1; //Change to random vertex 1<i<n
	minArr[0] = INF;
	minArr[startVertex] = 0;
	parent[startVertex] = -1;


	for (int j = 2; j <= numOfVertex; j++)
	{
		minArr[j] = INF;
		parent[j] = -1;
	}
    parent[0]= -1;
	Q->Build(numOfVertex, minArr);
	MinimumHeapNode* u;
	while (!Q->isEmptyHeap())
	{
		u = Q->deleteMin();
		inT[u->getVertexName()] = true;
		AdjacencyList uAdjList = adjacencyListGraph->GetAdjList(u->getVertexName());
		AdjacencyListNode* adj = uAdjList.getHead();

		while (adj != nullptr)
		{
			if (!inT[adj->GetDest()] && adj->GetWeight() < minArr[adj->GetDest()])
			{
				int vertexDest = adj->GetDest();
				minArr[vertexDest] = adj->GetWeight();
				parent[vertexDest] = u->getVertexName();
				Q->decreaseKey(adj->GetDest(), minArr[vertexDest]);
			}
			adj = adj->GetNext();
		}
	}
	int sum = calcGraphWightPrim(parent, adjacencyListGraph);
	return sum;
}

Edge* MakeEdgesArr(AdjacencyListGraph* graph)
{
    int size = graph->getNumOfEdges();
    Edge* edgesArr = new Edge[size];
    int logSize = 0;
    AdjacencyListNode* node ;
    for (int i = 1; i <= graph->getNumOfVertex(); i++)
    {
        node = graph->GetAdjList(i).getHead();
        while (node!=nullptr)
        {
            int destVertex =node->GetDest();
            if (i < destVertex) // If i<dest , we will put him in edgesArr  , else it means we already put him there.
            {
                edgesArr[logSize].setX(i);
                edgesArr[logSize].setY(destVertex);
                edgesArr[logSize].setWeight(node->GetWeight());
                logSize++;
                node = node->GetNext();
            }
            else {
                node = node->GetNext();
            }
        }
    }

    if (logSize > size)
    {
        cout << "The amount of edges that were copy are wrong" << endl;
        exit(1);
    }

    return edgesArr;
}

int partition(Edge arr[], int start, int end)
{

    int pivot = arr[start].getWeight();

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i].getWeight() <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i].getWeight() <= pivot) {
            i++;
        }

        while (arr[j].getWeight() > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

static void quickSort(Edge arr[], int start, int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}

int Kruskal(AdjacencyListGraph* adjacencyListGraph)
{

    int sumWight =0;
    int pv = 0, pu = 0;
    int size = adjacencyListGraph->getNumOfEdges();
    Edge* edges = MakeEdgesArr(adjacencyListGraph);
    Edge* minSpan = new Edge[size];
    int logSize = 0;
    DisjointSets T(adjacencyListGraph->getNumOfVertex());
    for (int i = 1; i <= adjacencyListGraph->getNumOfVertex(); i++)
    {
        T.MakeSet(i);
    }

    quickSort(edges, 0, size-1);

    for (int i = 0; i < size; i++)
    {
        pv = T.Find(edges[i].getX());
        pu = T.Find(edges[i].getY());

        if (pv  != pu)
        {

            minSpan[logSize].setWeight(edges[i].getWeight());
            sumWight +=  minSpan[logSize].getWeight();
            minSpan[logSize].setX(pv);
            minSpan[logSize].setY(pu);
            T.Union(pv, pu);
            logSize++;
        }
    }

    return sumWight;
}