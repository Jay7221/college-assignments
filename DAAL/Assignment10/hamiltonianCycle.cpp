#include <bits/stdc++.h>
using namespace std;

const int MAXV = 20;
int V;

void printSolution(int path[]);

bool isSafe(int v, bool graph[MAXV][MAXV],
            int path[], int pos)
{
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamCycleUtil(bool graph[MAXV][MAXV],
                  int path[], int pos)
{
    if (pos == V)
    {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            if (hamCycleUtil(graph, path, pos + 1) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

bool hamCycle(bool graph[MAXV][MAXV])
{
    int *path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;
    if (hamCycleUtil(graph, path, 1) == false)
    {
        cout << "\nSolution does not exist\n";
        return false;
    }

    printSolution(path);
    return true;
}

void printSolution(int path[])
{
    cout << "Solution Exists:"
            " Following is one Hamiltonian Cycle \n";
    for (int i = 0; i < V; i++)
        cout << path[i] + 1 << " ";
    cout << path[0] + 1 << " ";
    cout << endl;
}

int main()
{
    /* Let us create the following graph
        (0)--(1)--(2)
        |     / \   |
        |    /      \  |
        | /      \ |
        (3)-------(4) */
    cerr << "Enter the number of node in the graph : \n";
    cin >> V;
    int m;
    cerr << "Enter the number of edges in the graph : \n";
    cin >> m;
    bool graph[MAXV][MAXV];
    for(int i = 0; i < MAXV; ++i){
        for(int j = 0; j < MAXV; ++j){
            graph[i][j] = false;
        }
    }
    cerr << "Enter the edges :\n";
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u][v] = graph[v][u] = true;
    }
    hamCycle(graph);

    return 0;
}
