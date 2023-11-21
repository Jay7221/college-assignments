#include <bits/stdc++.h>
using namespace std;

const int MAXV = 20;
int V;

void printSolution(int color[]);

bool isSafe(int v, bool graph[MAXV][MAXV], int color[], int c)
{
	for (int i = 0; i < MAXV; i++)
		if (graph[v][i] && c == color[i])
			return false;

	return true;
}

bool graphColoringUtil(bool graph[MAXV][MAXV], int m, int color[], int v)
{

	if (v == MAXV)
		return true;

	for (int c = 1; c <= m; c++) {

		if (isSafe(v, graph, color, c)) {
			color[v] = c;

			if (graphColoringUtil(graph, m, color, v + 1)
				== true)
				return true;

			color[v] = 0;
		}
	}

	return false;
}
bool graphColoring(bool graph[MAXV][MAXV], int m)
{
	int color[MAXV];
	for (int i = 0; i < MAXV; i++)
		color[i] = 0;

	// Call graphColoringUtil() for vertex 0
	if (graphColoringUtil(graph, m, color, 0) == false) {
		cout << "Solution does not exist\n";
		return false;
	}

	printSolution(color);
	return true;
}

void printSolution(int color[])
{
	cout << "Solution Exists:"
		<< " Following are the assigned colors"
		<< "\n";
	for (int i = 0; i < V; i++)
		cout << " " << color[i] << " ";

	cout << "\n";
}

int main()
{
    int n, m;
    cerr << "Enter the number of nodes : \n";
    cin >> n;
    cerr << "Enter the number of edges : \n";
    cin >> m;
    V = n;
    bool graph[MAXV][MAXV];
    for(int i = 0; i < MAXV; ++i){
        for(int j = 0; j < MAXV; ++j){
            graph[i][j] = false;
        }
    }
    cerr << "Enter the edges : \n";
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u][v] = graph[v][u] = true;
    }

    int noColor;
    cerr << "Enter the number of colors: \n";
    cin >> noColor;

	graphColoring(graph, noColor);
	return 0;
}

