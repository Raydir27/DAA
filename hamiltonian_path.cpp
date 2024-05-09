#include <iostream>

using namespace std;

#define V 5

bool isSafe(int v, int graph[V][V], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; ++i)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianPathUtil(int graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; ++v) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianPathUtil(graph, path, pos + 1))
                return true;
            path[pos] = -1;
        }
    }

    return false;
}

bool hamiltonianPath(int graph[V][V]) {
    int path[V] = {-1};
    path[0] = 0;

    if (!hamiltonianPathUtil(graph, path, 1)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    cout << "Solution exists. The path is: ";
    for (int i = 0; i < V; ++i)
        cout << path[i] << " ";
    cout << path[0] << endl;
    return true;
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianPath(graph);
    return 0;
}
