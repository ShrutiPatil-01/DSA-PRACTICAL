#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS
void BFS(int startNode, const vector<vector<int>>& adjacencyList, vector<bool>& visited) {
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        // Visit all adjacent nodes
        for (int neighbor : adjacencyList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    // Sample graph as an adjacency list
    int numNodes = 6;
    vector<vector<int>> adjacencyList = {
        {1, 2},      // Neighbors of node 0
        {0, 3, 4},   // Neighbors of node 1
        {0, 4},      // Neighbors of node 2
        {1, 5},      // Neighbors of node 3
        {1, 2, 5},   // Neighbors of node 4
        {3, 4}       // Neighbors of node 5
    };

    // Visited vector to keep track of visited nodes
    vector<bool> visited(numNodes, false);

    // Perform BFS starting from node 0
    BFS(0, adjacencyList, visited);

    return 0;
}

