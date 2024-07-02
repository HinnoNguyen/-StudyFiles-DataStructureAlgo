/*
Path Exists in Graph
Problem
Given a bi-directional graph G with a set of vertices V = {0, 1, 2, ..., m} consisting of m vertices and n edges. Write a program to check if the path exists in the graph.

Input:

First line contains m, n are the number of vertices and edges respectively
Next n lines contains u and v indicating there is an edge between the two vertices u and v.
Last line contains a and b are the vertices you want to find the path between
Output: if there is a path between two vertices, print 1, else print 0.
*/

#include <iostream>
#include <vector>
#include <stack>
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

bool CheckPath (Graph& graph, int src, int dest) {
    vector<bool> visited(graph.GetV(), false);
    stack<int> st;
    st.push(src);
    visited[src] = true;

    while (!st.empty()) {
        int curr = st.top();
        st.pop();

        if (curr == dest) {
            return true; // Path found
        }

        for (int neighbor : graph.GetAdj(curr)) {
            if (!visited[neighbor]) {
                st.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return false;
}


int main () {
    int m, n;
    cin >> m >> n;

    Graph graph (m);

    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph.AddEdge(u, v);
    }

    
    
    return 0;
}