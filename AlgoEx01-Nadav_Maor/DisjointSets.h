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
#include "DisjointSetsNode.h"


class DisjointSets
{
private:

	DisjointSetsNode* arr;

public:
	DisjointSets(int size);
	void MakeSet(int idx);
	int Find(int idx);
	void Union(int repX, int repY);
	~DisjointSets();
};

