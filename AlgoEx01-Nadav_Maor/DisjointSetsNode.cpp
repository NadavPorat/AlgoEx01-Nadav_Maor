#include"DisjointSetsNode.h"

int DisjointSetsNode::getSize()
{
	return TreeSize;
}
int DisjointSetsNode::getParent()
{
	return parent;
}

void DisjointSetsNode::setSize(int size)
{
	TreeSize = size;
}

void DisjointSetsNode::setParent(int newParent)
{
	parent = parent;
}