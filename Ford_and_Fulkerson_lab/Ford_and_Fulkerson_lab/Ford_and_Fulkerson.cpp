#include "Ford_and_Fulkerson.h"
#include <fstream>
void Ford_and_Fulkerson::readList(string fileName) {
	fstream file;
	char firstName, secondName;
	int weight;
	int edge;
	int CountVerticesName = 0;
	file.open(fileName, ios::in);
	/*read count vertices and edge*/
	file >> Vertices >> edge;
	if (file.eof() || Vertices == 0) throw out_of_range("Graph is empty");

	/*memory allocation*/
	VerticesName = new char[Vertices];
	int** arr_check;
	arr_check = (int**)malloc(sizeof(int*) * Vertices);  
	if (!arr_check) {
		throw std::out_of_range("Allocation error");
		return;
	}
	else {
		graph_matrix = arr_check;
	}
	for (size_t i = 0; i < Vertices; i++)
	{
		arr_check[i] = (int*)malloc(Vertices * sizeof(int));
		if (!arr_check[i]) { throw std::out_of_range("Allocation error"); return; }
		else graph_matrix[i] = arr_check[i];
		for (size_t j = 0; j < Vertices; j++) {
			graph_matrix[i][j] = 0;
		}

	}
	/*read file*/
	int found1, found2;
	for (size_t i = 0; i < edge; i++)
	{
		file >> firstName >> secondName >> weight;

		found1 = -1;
		for (size_t j = 0; j < CountVerticesName; j++)
			if (VerticesName[j] == firstName)
				found1 = j;
		if (found1 == -1)
		{
			VerticesName[CountVerticesName] = firstName;
			found1 = CountVerticesName;
			CountVerticesName++;
		}

		found2 = -1;
		for (size_t j = 0; j < CountVerticesName; j++)
			if (VerticesName[j] == secondName)
				found2 = j;
		if (found2 == -1)
		{
			VerticesName[CountVerticesName] = secondName;
			found2 = CountVerticesName;
			CountVerticesName++;
		}
		graph_matrix[found1][found2] = weight; //save in matrix
	}
	for (size_t i = 0; i < Vertices; i++)  //search for source and sink
	{
		if (VerticesName[i] == 'S')
			from = i;
		else if (VerticesName[i] = 'T')
			to = i;
	}
}

int Ford_and_Fulkerson::MaxFlow() {
	resultStream = 0;
	int toAdd = 0;
	int bufVe, bufPrice;
	bool* visited = new bool[Vertices];
	do
	{
		for (size_t i = 0; i < Vertices; i++)
			visited[i] = false;
		toAdd = dfs(from, INT_MAX, visited);
		resultStream += toAdd;
	} while (toAdd>0);  //while there is something to add
	return resultStream;
}
int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}
int Ford_and_Fulkerson::dfs(int u, int Cmin,bool* visited) {
	if (u == to)
		return Cmin;
	visited[u] = true;
	int delta;
	for (size_t v = 0; v < Vertices; v++)
	{
		if (!visited[v] && (graph_matrix[u][v] > 0))
		{
			delta = dfs(v, min(Cmin, graph_matrix[u][v]), visited);
			if (delta > 0) //change the network
			{
				graph_matrix[u][v] -= delta;
				graph_matrix[v][u] += delta;
				return delta;
			}
		}
	}
	return 0;
}