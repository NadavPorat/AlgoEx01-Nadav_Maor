#include "globalHeader.h"

//Constructors
//Check if need to implement build 
minimumHeap::minimumHeap(int _numOfVertex)
{
	array = new MinimumHeapNode * [_numOfVertex + 1];
}

void minimumHeap::Build(int _numOfVertex, int* weigthArr)
{
	positionArr = (int*)malloc((_numOfVertex + 1) * sizeof(int));
	pysSize = _numOfVertex;
	logSize = _numOfVertex;

	for (int i = 0; i < _numOfVertex; i++)
	{
		array[i] = new MinimumHeapNode;
		array[i]->setKey(i + 1);
		array[i]->setValue(weigthArr[2]);

		positionArr[i+1] = i;
	}

	for (int i = logSize / 2 - 1; i >= 0; i--)
	{
		fixHeap(i);
	}
}


minimumHeap::minimumHeap()
{
	array = new MinimumHeapNode * [1];
	positionArr = (int*)malloc((1) * sizeof(int));
	pysSize = 0;
	logSize = 0;
}


int minimumHeap::Left(int Idx)
{
	return ((2 * Idx));
}

int minimumHeap::Right(int Idx)
{
	return  ((2 * Idx) + 1);
}

int minimumHeap::parent(int Idx)
{
	return  ((Idx - 1) / 2);
}

int minimumHeap::getLogSize() const
{
	return logSize;
}




//The fixHeap algorithm runs on a minimum heap whose only (maybe) root
//violates its rules
void minimumHeap::fixHeap(int idxToFix)
{
	int smallest = idxToFix;
	int left = Left(idxToFix);
	int right = Right(idxToFix);


	if ((right <= logSize) && (((((array[right])->getValue() < (array[smallest])->getValue()) && ((array[right])->getValue() != INF)) || ((array[right]->getValue() != INF) && array[smallest]->getValue() == INF))))
		smallest = right;

	if ((left <= logSize) && ((((array[left])->getValue() < (array[smallest])->getValue()) && ((array[left])->getValue() != INF)) || ((array[left]->getValue() != INF) && array[smallest]->getValue() == INF)))
		smallest = left;


	if (smallest != idxToFix)
	{

		MinimumHeapNode* smallestNode = array[smallest];
		MinimumHeapNode* nodeToswap = array[idxToFix];

		positionArr[smallestNode->getVertixName()] = idxToFix;
		positionArr[nodeToswap->getVertixName()] = smallest;

		swap(array[smallest], array[idxToFix]);
		fixHeap(smallest);
	}

}

//The algorithm deletes the node with minimum frequancy (root) and fixes the heap by fixHeap algorithem
MinimumHeapNode* minimumHeap::deleteMin()
{
	if (logSize < 1)
	{
		cout << "Error" << endl;
		return nullptr;
	}

	else
	{
		MinimumHeapNode* min = array[0];
		positionArr[min->getVertixName()] = logSize;
		array[0] = array[logSize - 1];
		logSize--;
		fixHeap(0);

		return min;
	}

}

void  minimumHeap::decreaseKey(int keyToDecrease, float newValue)
{
	if (0 != keyToDecrease) //no vetrex 0
	{
		int idx = positionArr[keyToDecrease];
		array[idx]->setValue(newValue);

		while (parent(idx) >= 0)
		{
			fixHeap(parent(idx));
			idx = parent(idx);

			if (idx == 0)
				idx = -1;
		}
	}
}


bool  minimumHeap::isEmptyHeap()
{
	return logSize == 1;
}


MinimumHeapNode* minimumHeap::getExactHeapNode(int requiredNode)
{
	int exactPositionnInHeapArray = positionArr[requiredNode];
	if (isInHEap(requiredNode))
	{
		return array[exactPositionnInHeapArray];

	}
	return nullptr;
}



bool minimumHeap::isInHEap(int requiredNode)
{
	for (int i = 0; i <= logSize; i++)
	{
		if (array[i]->getVertixName() == requiredNode)
			return true;
	}
	return false;
}