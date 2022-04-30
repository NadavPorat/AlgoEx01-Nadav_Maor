#include "globalHeader.h"





static int calcGraphWight(int* parentList, AdjacencyListGraph* graph)
{
	int sum = 0;
	for (int i = 1; i <= graph->getNumOfVertix(); i++)
	{
		if (parentList[i] != INF && parentList[i] != 0)
		{
			sum += graph->getEdgeWeight(parentList[i], i);
		}
	}
	return sum;
}
static void quickSort(int arr[], int start, int end);

int Prim(AdjacencyListGraph* adjacencyListGraph) {


	int numOfVertix = adjacencyListGraph->getNumOfVertix();
	minimumHeap* Q = new minimumHeap(numOfVertix);
	bool* inT = new bool[numOfVertix];
	for (int i = 0; i <= numOfVertix; i++) {
		inT[i] = false;
	}

	int* minArr = new int[numOfVertix];
	int* parent = new int[numOfVertix];

	int startVertix = 1; //Change to random vertix 1<i<n
	minArr[0] = INF;
	minArr[startVertix] = 0;
	parent[startVertix] = NULL;

	for (int j = 2; j <= numOfVertix; j++)
	{
		minArr[j] = INF;
		parent[j] = NULL;
	}

	Q->Build(numOfVertix, minArr);
	MinimumHeapNode* u;
	while (!Q->isEmptyHeap())
	{
		u = Q->deleteMin();
		inT[u->getVertixName()] = true;
		AdjacencyList uAdjList = adjacencyListGraph->GetAdjList(u->getVertixName());
		AdjacencyListNode* adj = uAdjList.getHead();

		while (adj != nullptr)
		{
			if (!inT[adj->GetDest()] && adj->GetWeight() < minArr[adj->GetDest()])
			{
				int vertexDest = adj->GetDest();
				minArr[vertexDest] = adj->GetWeight();
				parent[vertexDest] = u->getVertixName();
				Q->decreaseKey(adj->GetDest(), minArr[vertexDest]);
			}
			adj = adj->GetNext();
		}
	}
	int sum = calcGraphWight(parent, adjacencyListGraph);
	return sum;
}
int Kruskal(AdjacencyListGraph* adjacencyListGraph)
{
	int* parent = new int[3];
	return 1;
	//int pv = 0, pu = 0;
	//vector <edge> minSpan;
	//vector <edge> edges;

	//extractEdgeNum(gr, edges);
	//quickSort(edges, 0, edges.size() - 1);

	//T = UnionFind(gr.getVerSize());

	//for (int i = 0; i < edges.size(); i++)
	//{
	//	if ((pv = T.Find(edges.at(i).from - 1)) != (pu = T.Find(edges.at(i).to - 1)))
	//	{
	//		minSpan.push_back(edges.at(i));
	//		T.Union(pv, pu);
	//	}
	//}

	//return calcGraphWight(parent, adjacencyListGraph);
}





int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

static void quickSort(int arr[], int start, int end)
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