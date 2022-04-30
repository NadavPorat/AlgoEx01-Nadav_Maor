#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include<iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <stdlib.h> 
#include<cmath>

using namespace std;

#include "engine.h"
#include "DisjointSets.h"
#include "DisjointSetsNode.h"
#include "MinimumHeapNode.h"
#include "MinimumHeap.h"
#include "AdjacencyListNode.h"
#include "AdjacencyList.h"
#include "AdjacencyListGraph.h"

int* Prim(AdjacencyListGraph* adjacencyListGraph);
int* Kruskal(AdjacencyListGraph* adjacencyListGraph);

#define INF INT_MAX

