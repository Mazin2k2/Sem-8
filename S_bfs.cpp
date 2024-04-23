#include <iostream>
#include <vector>
#include <queue>
#include <omp.h>

using namespace std;

// Define the graph as an adjacency list
vector<vector<int> > graph;

// Function to perform breadth-first search (BFS)
vector<int> bfs(int start_node) {
    int num_nodes = graph.size();
    vector<bool> visited(num_nodes, false);
    vector<int> route;

    // Create a queue for BFS
    queue<int> q;

    // Mark the start node as visited and enqueue it
    visited[start_node] = true;
    q.push(start_node);

    while (!q.empty()) {
        // Dequeue a node from the queue
        int current_node = q.front();
        q.pop();

        // Add the current node to the route
        route.push_back(current_node);

        // Visit all the adjacent nodes of the current node
        for (int neighbor : graph[current_node]) {
            // If the neighbor is not visited, mark it as visited and enqueue it
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return route;
}

int main() {
    // Get the number of nodes in the graph from the user
    int num_nodes;
    cout << "Enter the number of nodes in the graph: ";
    cin >> num_nodes;

    // Resize the graph vector to accommodate the nodes
    graph.resize(num_nodes);

    // Get the adjacency list representation of the graph from the user
    for (int i = 0; i < num_nodes; ++i) {
        int num_neighbors;
        cout << "Enter the number of neighbors for node " << i << ": ";
        cin >> num_neighbors;

        cout << "Enter the neighbors of node " << i << ": ";
        for (int j = 0; j < num_neighbors; ++j) {
            int neighbor;
            cin >> neighbor;
            graph[i].push_back(neighbor);
        }
    }

    // Get the starting node for BFS from the user
    int start_node;
    cout << "Enter the starting node for BFS: ";
    cin >> start_node;

    // Perform BFS to find the route
    vector<int> route = bfs(start_node);

    // Print the route
    cout << "BFS Route: ";
    for (int node : route) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
