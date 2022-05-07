#pragma once

#include "AdjacencyListGraph.h"

class Engine
{

	public:
		void run(string inFileName, string outFileName);
        AdjacencyListGraph* buildGraphFromFile(string inFileName, int* edgeToRemove);
};

