#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V): V(V) {
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i])
                DFSUtil(*i, visited);
        }
    }

    void DFS(int startVertex) {
        vector<bool> visited(V, false);

        DFSUtil(startVertex, visited);
    }
};

int main() {
    Graph g(4); // Create a graph given in the above diagram
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Traversal (starting from vertex 2): ";
    g.DFS(2);

    return 0;
}
