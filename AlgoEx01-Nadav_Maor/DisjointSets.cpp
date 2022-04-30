#include "DisjointSets.h"

DisjointSets::DisjointSets(int size)
{
	arr = new DisjointSetsNode[size];

	for (int i = 0; i < size; i++)
	{
		arr[i].setParent(-1);
		arr[i].setSize(0);
	}
}

DisjointSets::~DisjointSets()
{
	delete[] arr;
}

void DisjointSets::MakeSet(int idx)
{
	arr[idx].setParent(idx);
	arr[idx].setSize(1);
}

int DisjointSets::Find(int idx)
{
	if (arr[idx].getParent() == idx)
		return idx;

	else
	{
		int index = Find(arr[idx].getParent());
		arr[idx].setParent(index);
		return index;
	}
}

void DisjointSets::Union(int repX, int repY)
{
	if (arr[repX].getSize() > arr[repY].getSize())
	{
		arr[repY].setParent(repX);
		arr[repX].setSize(arr[repX].getSize() + arr[repY].getSize());
	}
	else
	{
		arr[repX].setParent(repY);
		arr[repY].setSize(arr[repY].getSize() + arr[repX].getSize());
	}
}
