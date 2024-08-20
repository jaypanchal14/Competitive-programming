#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>

using namespace std;

/*
Given number of total nodes and directed edges between source and destination nodes of the graph.
Write a traversal method such that, it will return the node values in order such that it is lexicographically largest number possible.
*/


vector<int> lexicographicallyLargestTopologicalSort(int n, const vector<pair<int, int>>& edges) {
    // Graph representation
    vector<vector<int>> adjList(n);
    vector<int> inDegree(n, 0);
    
    // Build the graph and calculate in-degrees
    for (const auto& edge : edges) {
        int src = edge.first;
        int dst = edge.second;
        adjList[src].push_back(dst);
        inDegree[dst]++;
    }

    // Max-heap (priority_queue) to get the lexicographically largest node first
    priority_queue<int, vector<int>, less<int>> maxHeap;
    
    // Add nodes with in-degree 0 to the heap
    for (int node = 0; node < n; ++node) {
        if (inDegree[node] == 0) {
            maxHeap.push(node);
        }
    }
    
    vector<int> result;
    
    while (!maxHeap.empty()) {
        int node = maxHeap.top();
        maxHeap.pop();
        result.push_back(node);
        
        // Process all adjacent nodes
        for (int neighbor : adjList[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                maxHeap.push(neighbor);
            }
        }
    }
    
    return result;
}

int main() {
    int n = 6;  // Number of nodes
    vector<pair<int, int>> edges = {
        {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}  // Directed edges
    };
    
    vector<int> result = lexicographicallyLargestTopologicalSort(n, edges);
    
    cout << "Topologically sorted order (lexicographically largest): ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}
