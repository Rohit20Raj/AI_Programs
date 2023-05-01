#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to perform Greedy Best First Search
void greedyBestFirstSearch(vector<vector<int>>& graph, int start, int goal) {
    int numNodes = graph.size();

    // Priority queue to store nodes based on their heuristic value
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Boolean array to keep track of visited nodes
    vector<bool> visited(numNodes, false);

    // Vector to store the path from start to goal
    vector<int> path(numNodes, -1);

    // Enqueue the start node with a heuristic value of 0
    pq.push(make_pair(0, start));
    visited[start] = true;

    while (!pq.empty()) {
        int current = pq.top().second;
        pq.pop();

        // Check if the goal node is reached
        if (current == goal) {
            // Print the path from start to goal
            vector<int> finalPath;
            int node = current;
            while (node != -1) {
                finalPath.push_back(node);
                node = path[node];
            }
            cout << "Path from start to goal: ";
            for (int i = finalPath.size() - 1; i >= 0; i--) {
                cout << finalPath[i] << " ";
            }
            cout << endl;
            return;
        }

        // Explore the neighboring nodes
        for (int i = 0; i < numNodes; i++) {
            if (graph[current][i] != 0 && !visited[i]) {
                // Enqueue the neighboring nodes with their heuristic values
                pq.push(make_pair(graph[current][i], i));
                visited[i] = true;
                path[i] = current;
            }
        }
    }

    // If the goal node is not reachable
    cout << "Goal node is not reachable from the start node." << endl;
}

int main() {
    int numNodes;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    vector<vector<int>> graph(numNodes, vector<int>(numNodes, 0));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            cin >> graph[i][j];
        }
    }

    int start, goal;
    cout << "Enter the start node: ";
    cin >> start;
    cout << "Enter the goal node: ";
    cin >> goal;

    greedyBestFirstSearch(graph, start, goal);

    return 0;
}
