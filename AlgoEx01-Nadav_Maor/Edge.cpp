#pragma once

#include "Edge.h"

int Edge:: getX()
{
    return x;
}

int Edge::getY()
{
    return y;
}

int Edge::getWeight()
{
    return weight;
}

void Edge::setX(int v)
{
    x = v;
}

void Edge::setY(int u)
{
    y = u;
}

void Edge::setWeight(int size)
{
    weight = size;
}