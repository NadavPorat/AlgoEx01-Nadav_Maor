#include "globalHeader.h"
#include "Engine.h"


void Engine::run(string inFileName, string outFileName) {
    int edgeToRemove[2];
    AdjacencyListGraph* adjacencyListGraph = buildGraphFromFile(inFileName, edgeToRemove);
    if(!adjacencyListGraph->IfConnectedGraph())
    {
        cout<< "invalid input ";
        exit(1);
    }
    ////start of Prim ////
    int primWeight = Prim(adjacencyListGraph);
    ////end of Prim ////


    ////start of kruskal ////

    int kruskalWeight = Kruskal(adjacencyListGraph);
    string KruskalAfterRemove;
    if(adjacencyListGraph->RemoveEdge(edgeToRemove[0], edgeToRemove[1]) )
    {
        if(!adjacencyListGraph->IfConnectedGraph())
        {
            KruskalAfterRemove = "No MST ";
        }
        else {
            int KruskalTreeAfterRemoveEdge = Kruskal(adjacencyListGraph);
            KruskalAfterRemove = "Kruskal ";
            KruskalAfterRemove += to_string(KruskalTreeAfterRemoveEdge);
        }
    }
    else
    {
        KruskalAfterRemove = "invalid input (Edge To Remove not exist) ";

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
        cout << "invalid input";
        exit(1);
    }

    int numOfVertex;
    int numOfEdges;
    int edgeToRemoveSrc =0;
    int edgeToRemoveDest =0;

    float weightInFloat;

    inputFile >> numOfVertex;
    inputFile >> numOfEdges;

    if(numOfVertex <= 0)
    {
        cout<< "invalid input";
        exit(1);
    }
        AdjacencyListGraph *adjacencyListGraph = new AdjacencyListGraph(numOfVertex);

        bool flag = true;
        string source;
        string dest;
        string weight;

        getline(inputFile, inputLine);

        for (int i = 0; i < numOfEdges; i++) {
            (getline(inputFile, inputLine, '\n') && flag);
            string comma_string;
            istringstream text_stream(inputLine);
            text_stream >> source;
            getline(text_stream, comma_string, ' ');
            text_stream >> dest;
            getline(text_stream, comma_string, ' ');
            text_stream >> weight;

            if (source == "" && dest == "" && weight == "") {
                flag = false;
            }

            if (flag) {

                if(!isNumber(source) || isNumber(dest) || isNumber(weight))
                {
                    cout << "Invalid input\n";
                    exit(1);
                }
                //Check if number
                if (stoi(source) < 1 ||(stoi(source) > numOfVertex ||stoi(dest) <1 || stoi(dest) > numOfVertex ))
                {
                    cout << "Invalid input\n";
                    exit(1);
                } else {
                    weightInFloat = stof(weight);
                    if(weightInFloat<0)
                    {
                        cout << "Invalid input\n";
                        exit(1);
                    }
                    adjacencyListGraph->AddEdge(stoi(source), stoi(dest), stof(weight));
                    if (!(floor(weightInFloat) == weightInFloat)) // Check if the new weight is a whole number or not.
                    {
                        cout << "Invalid input\n";
                        exit(1);
                    }
                }

            }
            source = dest = weight = "";
        }
        inputFile >> edgeToRemoveSrc;
        inputFile >> edgeToRemoveDest;

        if((edgeToRemoveSrc<1 || edgeToRemoveSrc> numOfVertex || edgeToRemoveDest<1 ||edgeToRemoveDest> numOfVertex)&&edgeToRemoveSrc!=0 && edgeToRemoveDest!=0)
        {
            cout << "Invalid input\n";
            exit(1);
        }
        if(edgeToRemoveSrc!=0 && edgeToRemoveDest!=0) {
            edgeToRemove[0] = edgeToRemoveSrc;
            edgeToRemove[1] = edgeToRemoveDest;
        }
        inputFile.close();
        return adjacencyListGraph;

}
bool Engine::isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0)
            return false;
    }
    return true;
}