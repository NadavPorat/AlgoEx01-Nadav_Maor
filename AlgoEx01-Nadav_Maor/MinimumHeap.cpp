#include "globalHeader.h"

//Constructors
//Check if need to implement build 
minimumHeap::minimumHeap(int _numOfVertex)
{
	array = new MinimumHeapNode * [_numOfVertex + 1];
}

void minimumHeap::Build(int _numOfVertex, int* weightArr)
{
	positionArr = (int*)malloc((_numOfVertex + 1) * sizeof(int));
	pysSize = _numOfVertex;
	logSize = _numOfVertex;

	for (int i = 0; i < _numOfVertex; i++)
	{
		array[i] = new MinimumHeapNode;
        array[i]->setVertexName(i + 1);
		array[i]->setValue(weightArr[i+1]);
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
	int smallest;
	int left = Left(idxToFix);
	int right = Right(idxToFix);


	if ((right <= logSize) && (array[right])->getValue() < (array[idxToFix])->getValue()) {
        smallest = right;
    }
    else
    {
        smallest = idxToFix;
    }

	if ((left <= logSize) && (array[left])->getValue() < (array[smallest])->getValue())
		smallest = left;

	if (smallest != idxToFix)
	{

		MinimumHeapNode* smallestNode = array[smallest];
		MinimumHeapNode* nodeToSwap = array[idxToFix];

		positionArr[smallestNode->getVertexName()] = idxToFix;
		positionArr[nodeToSwap->getVertexName()] = smallest;

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
        logSize--;
        array[0] = array[logSize];
		positionArr[array[0]->getVertexName()] = 0;
        positionArr[min->getVertexName()]= -1;
		fixHeap(0);

		return min;
	}

}

void  minimumHeap::decreaseKey(int keyToDecrease, float newValue)
{
	if (0 != keyToDecrease) //no vertex 0
	{
		int idx = positionArr[keyToDecrease];
		array[idx]->setValue(newValue);
        while (idx != 0 && array[idx]->getValue() < array[parent(idx)]->getValue())
        {
            swap(array[idx], array[parent(idx)]);
            idx = parent(idx);
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
		if (array[i]->getVertexName() == requiredNode)
			return true;
	}
	return false;
}