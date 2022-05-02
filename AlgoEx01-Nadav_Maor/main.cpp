#include "globalHeader.h"

/*NAME :
 *ID:
 *
 * This project solves in several ways the problem of the minimum distances
 * from a single origin to a single destination in directed graphs,
 * according to several algorithms and also calculates the runtimes of the various solutions.*/

using namespace std;

static AdjacencyListGraph* buildGraphFromFile(string inFileName, int* edgeToRemove)
{


	ifstream inputFile;
    //TODO RETURN IF NOT IN MAC
	//inputFile.open(inFileName);
	inputFile.open("/Users/nporat/CLionProjects/AlgoEx01-Nadav_Maor/AlgoEx01-Nadav_Maor/inputGraph.txt");
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
	int edgeToRemoveFromFile[2];
	edgeToRemove[0] = edgeToremoveSrc;
	edgeToRemove[1] = edgeToRemoveDest;
	inputFile.close();
	return adjacencyListGraph;

}
static void run(string inFileName, string outFileName)
{
	int edgeToRemove[2];
	AdjacencyListGraph* adjacencyListGraph = buildGraphFromFile(inFileName, edgeToRemove);

	////start of Prim ////
	int primWeight = Prim(adjacencyListGraph);
	////end of Prim ////


	////start of kruskal ////

	int kruskalWeight = Kruskal(adjacencyListGraph);
	adjacencyListGraph->RemoveEdge(edgeToRemove[0], edgeToRemove[1]);
	int KruskalTreeAfterRemoveEdge = Kruskal(adjacencyListGraph);



	ofstream outFile;
	outFile.open(outFileName);
	string Kruskal = "Kruskal ";
	Kruskal += to_string(kruskalWeight);
	cout << Kruskal;
	cout << "\n";
	outFile << Kruskal;
	outFile << "\n";

	string prim = "Prim ";
	prim += to_string(primWeight
            );
	cout << prim;
	cout << "\n";
	outFile << prim;
	outFile << "\n";

	string KruskalAfterRemove = "Kruskal ";
	KruskalAfterRemove += to_string(KruskalTreeAfterRemoveEdge);


	cout << KruskalAfterRemove;
	outFile << KruskalAfterRemove;
	outFile.close();
}


int main(int argc, char* argv[])
{
	/*engine e;*/

	if (argv[1] != nullptr && argv[2] != nullptr)
	{
		//e.run(argv[1], argv[2]);
		run(argv[1], argv[2]);
	}

	else
	{
		cout << "Invalid argument\n";
	}

	return 0;
}