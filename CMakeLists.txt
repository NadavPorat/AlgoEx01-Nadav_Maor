cmake_minimum_required(VERSION 3.22)
project(AlgoEx01_Nadav_Maor)

set(CMAKE_CXX_STANDARD 14)

include_directories(AlgoEx01-Nadav_Maor)

add_executable(AlgoEx01_Nadav_Maor
        AlgoEx01-Nadav_Maor/AdjacencyList.cpp
        AlgoEx01-Nadav_Maor/AdjacencyList.h
        AlgoEx01-Nadav_Maor/AdjacencyListGraph.cpp
        AlgoEx01-Nadav_Maor/AdjacencyListGraph.h
        AlgoEx01-Nadav_Maor/AdjacencyListNode.cpp
        AlgoEx01-Nadav_Maor/AdjacencyListNode.h
        AlgoEx01-Nadav_Maor/algoFindMinTree.cpp
        AlgoEx01-Nadav_Maor/DisjointSets.cpp
        AlgoEx01-Nadav_Maor/DisjointSets.h
        AlgoEx01-Nadav_Maor/DisjointSetsNode.cpp
        AlgoEx01-Nadav_Maor/DisjointSetsNode.h
        AlgoEx01-Nadav_Maor/Engine.cpp
        AlgoEx01-Nadav_Maor/Engine.h
        AlgoEx01-Nadav_Maor/globalHeader.h
        AlgoEx01-Nadav_Maor/main.cpp
        AlgoEx01-Nadav_Maor/MinimumHeap.cpp
        AlgoEx01-Nadav_Maor/MinimumHeap.h
        AlgoEx01-Nadav_Maor/MinimumHeapNode.cpp
        AlgoEx01-Nadav_Maor/MinimumHeapNode.h
        AlgoEx01-Nadav_Maor/UnionFind.cpp AlgoEx01-Nadav_Maor/Edge.cpp AlgoEx01-Nadav_Maor/Edge.h)
