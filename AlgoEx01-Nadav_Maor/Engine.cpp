#include "globalHeader.h"
#include "Engine.h"


void Engine::run(string inFileName, string outFileName) {
    int edgeToRemove[2];
    AdjacencyListGraph* adjacencyListGraph = buildGraphFromFile(inFileName, edgeToRemove);
    if(!adjacencyListGraph->IfConnectedGraph())
    {
        cout<< "invalid input (Graph is not connected) ";
        exit(1);
    }
    ////start of Prim ////
    int primWeight = Prim(adjacencyListGraph);
    ////end of Prim ////


    ////start of kruskal ////

    int kruskalWeight = Kruskal(adjacencyListGraph);
    string KruskalAfterRemove;
    if(  adjacencyListGraph->RemoveEdge(edgeToRemove[0], edgeToRemove[1]) )
    {
        if(!adjacencyListGraph->IfConnectedGraph())
        {
            KruskalAfterRemove = "invalid input (Graph is not connected after remove edge) ";
        }
        else {
            int KruskalTreeAfterRemoveEdge = Kruskal(adjacencyListGraph);
            KruskalAfterRemove = "Kruskal ";
            KruskalAfterRemove += to_string(KruskalTreeAfterRemoveEdge);
        }
    }
    else
    {
        KruskalAfterRemove = "invalid input (No Edge To Remove) ";

    }


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




    cout << KruskalAfterRemove;
    outFile << KruskalAfterRemove;
    outFile.close();
}

AdjacencyListGraph *Engine::buildGraphFromFile(string inFileName, int *edgeToRemove) {
    string inputLine;
    ifstream inputFile;
    //TODO RETURN IF NOT IN MAC
    //inputFile.open(inFileName);
    string str = "/Users/nporat/CLionProjects/AlgoEx01-Nadav_Maor/AlgoEx01-Nadav_Maor/tests/";
    str.append(inFileName);
    inputFile.open(str);

    if (!inputFile)
    {
        cout << "Error while reading from file\n";
        exit(1);
    }

    int numOfVertex;
    int numOfEdges;
    int edgeToRemoveSrc;
    int edgeToRemoveDest;

    float weightInFloat;

    inputFile >> numOfVertex;
    inputFile >> numOfEdges;

    AdjacencyListGraph* adjacencyListGraph = new AdjacencyListGraph(numOfVertex);

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
            if ((stoi(source) > numOfVertex || stoi(dest) > numOfVertex || source == "" || dest == "" || weight == ""))
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
    inputFile >> edgeToRemoveSrc;
    inputFile >> edgeToRemoveDest;
    int edgeToRemoveFromFile[2];
    edgeToRemove[0] = edgeToRemoveSrc;
    edgeToRemove[1] = edgeToRemoveDest;
    inputFile.close();
    return adjacencyListGraph;
}
