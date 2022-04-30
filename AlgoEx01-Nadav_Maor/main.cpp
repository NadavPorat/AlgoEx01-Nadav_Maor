#include "globalHeader.h"

/*NAME :
 *ID:
 *
 * This project solves in several ways the problem of the minimum distances
 * from a single origin to a single destination in directed graphs,
 * according to several algorithms and also calculates the runtimes of the various solutions.*/

static void run(string inFileName, string outFileName);
int* Prim(AdjacencyListGraph* adjacencyListGraph);


using namespace std;

int main(int argc, char* argv[])
{
	if (argv[1] != nullptr && argv[2] != nullptr)
	{
		run(argv[1], argv[2]);
	}

	else
	{
		cout << "Invalid argument\n";
	}

	return 0;
}

static void run(string inFileName, string outFileName)
{
	ifstream inputFile;
	inputFile.open(inFileName);
	string inputLine;

	if (!inputFile)
	{
		cout << "Error while reading from file\n";
		exit(1);
	}

	int numOfVertix;
	int numOfEdges;
	int edgeToremoveSrc;
	int edgeToRemoveDest;

	float weightInFloat;

	inputFile >> numOfVertix;
	inputFile >> numOfEdges;

	AdjacencyListGraph* adjacencyListGraph = new AdjacencyListGraph(numOfVertix);

	bool flag = true;
	string source;
	string dest;
	string weight;

	getline(inputFile, inputLine);

	for (int i = 0; i < numOfEdges; i++)
	{
		(getline(inputFile, inputLine, '\n') && flag);
		string comma_string;
		istringstream text_stream(inputLine);
		text_stream >> source;
		getline(text_stream, comma_string, ' ');
		text_stream >> dest;
		getline(text_stream, comma_string, ' ');
		text_stream >> weight;

		if (source == "" && dest == "" && weight == "")
		{
			flag = false;
		}

		if (flag)
		{
			//Check if shalem number
			if ((stoi(source) > numOfVertix || stoi(dest) > numOfVertix || source == "" || dest == "" || weight == ""))
			{
				cout << "Invalid input\n";
				exit(1);
			}
			else
			{
				weightInFloat = stof(weight);
				adjacencyListGraph->AddEdge(stoi(source), stoi(dest), stof(weight));
				if (!(floor(weightInFloat) == weightInFloat)) // Check if the new weight is a whole number or not.
				{
					cout << "Invalid input\n";
				}
			}

		}
		source = dest = weight = "";
	}

	inputFile >> edgeToremoveSrc;
	inputFile >> edgeToRemoveDest;


	// AdjacencyListGraph* kruskalTree = Kruskal(adjacencyListGraph);
	int* primTree = Prim(adjacencyListGraph);
	cout << "yuvL";
	//int primWeigth = GetWeigth(primTree);
	//int kruskalWeigth = GetWeigth(kruskalTree);

	ofstream myfile(outFileName);
}

int* Prim(AdjacencyListGraph* adjacencyListGraph) {


	int numOfVertix = adjacencyListGraph->getNumOfVertix();
	minimumHeap* Q = new minimumHeap(numOfVertix);
	bool* inT = new bool[numOfVertix];
	for (int i = 0; i < numOfVertix; i++) {
		inT[i] = false;
	}

	int* minArr = new int[numOfVertix];
	int* parent = new int[numOfVertix];

	int startVertix = 1; //Change to random vertix 1<i<n
	minArr[startVertix] = 0;
	parent[startVertix] = NULL;

	for (int j = 2; j < numOfVertix; j++)
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
				minArr[adj->GetDest()] = adj->GetWeight();
				parent[adj->GetDest()] = u->getVertixName();
				Q->decreaseKey(adj->GetDest(), minArr[adj->GetDest()]);
			}
			adj->setNext(adj->GetNext());
		}
	}

	return parent;
}


//AdjacencyListGraph* Kruskal(AdjacencyListGraph* adjacencyListGraph) {

//}

//int  GetWeigth(AdjacencyListGraph* tree) {

//}