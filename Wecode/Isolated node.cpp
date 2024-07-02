/*
Isolated node
Problem
Given an undirected graph G with a set of vertices V = {0, 1, 2, ..., m} consisting of m vertices and n edges. Write a program to print the number of vertices that do not have a direct edge to any other vertex in G (the number of isolated vertices).

Input:

The first line contains two numbers m and n separated by a space. It is known that 1 ≤ m ≤ 1000, 0 ≤ n ≤ 3000.
The next n lines, each line contains two integers u and v indicating there is an edge between the two vertices u and v.
Output An integer representing the number of isolated vertices.
*/

#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int v;
    vector<int> *adj;
public:
    Graph(int v) {
        this->v = v;
        adj = new vector<int>[v];
    }
    void AddEdge (int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    int GetV() {
        return v;
    }
    vector<int> GetAdj (int v) {
        return adj[v];
    }
};



int main () {
    int m, n;
    cin >> m >> n;

    Graph graph (m);

    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph.AddEdge(u, v);
    }

    int IsolatedCount = 0;
    for (int i = 0; i < m; ++i) {
        if (graph.GetAdj(i).empty())
            IsolatedCount++;
    }
    cout << IsolatedCount;
    return 0;
}