#include <iostream>
#include <vector>
#include <stack>
#include <omp.h>

using namespace std;

// Define the graph as an adjacency list
vector<vector<int>> graph;

// Function to perform depth-first search (DFS)
vector<int> dfs(int start_node) {
    int num_nodes = graph.size();
    vector<bool> visited(num_nodes, false);
    vector<int> route;

    // Create a stack for DFS
    stack<int> s;

    // Push the start node onto the stack
    s.push(start_node);

    // Perform DFS
    while (!s.empty()) {
        // Pop a node from the stack
        int current_node = s.top();
        s.pop();

        // If the node has not been visited yet
        if (!visited[current_node]) {
            // Mark the node as visited
            visited[current_node] = true;

            // Add the current node to the route
            route.push_back(current_node);

            // Visit all the adjacent nodes of the current node in reverse order
            for (int i = graph[current_node].size() - 1; i >= 0; --i) {
                int neighbor = graph[current_node][i];
                // If the neighbor has not been visited, push it onto the stack
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
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

    // Get the starting node for DFS from the user
    int start_node;
    cout << "Enter the starting node for DFS: ";
    cin >> start_node;

    // Perform DFS to find the route
    vector<int> route = dfs(start_node);

    // Print the route
    cout << "DFS Route: ";
    for (int node : route) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
