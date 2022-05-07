#pragma once

#include "globalHeader.h"

class Edge
{

private:
    int x;
    int y;
    int weight;

public:
    int getX();
    int getY();
    int getWeight();

    void setX(int v);
    void setY(int u);
    void setWeight(int size);


};

