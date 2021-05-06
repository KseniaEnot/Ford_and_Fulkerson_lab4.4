#pragma once
#include <iostream>
using namespace std;
class Ford_and_Fulkerson
{
private:
    int Vertices;
    int** graph_matrix;
    int from, to;
    int resultStream;
    char* VerticesName;
    int dfs(int, int, bool*);
public:
    void readList(string);
    int MaxFlow();
};

