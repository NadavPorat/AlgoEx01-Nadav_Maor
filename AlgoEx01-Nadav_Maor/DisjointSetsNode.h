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

class DisjointSetsNode
{
private:
	int parent;
	int TreeSize;
public:
	int getSize();
	int getParent();
	void setSize(int size);
	void setParent(int newParent);
};




