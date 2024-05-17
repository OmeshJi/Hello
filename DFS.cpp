#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS traversal recursively
void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
    // Mark the current node as visited
    visited[node] = true;
    cout << node << " ";

    // Recur for all adjacent vertices of the current node
    for (int adjNode : graph[node]) {
        if (!visited[adjNode]) {
            dfs(graph, visited, adjNode);
        }
    }
}


void dfs1(vector<vector<int>>& graph, vector<bool>&visited, int node){
	visited[node]= true;
	cout<<node<<" ";
	
	for(int i : graph[node]){
		if(!visited[i]){
			dfs1(graph,visited,i);
		}
	}
	
}
int main() {
    // Example graph representation using adjacency list
    int V = 6; // Number of vertices
    vector<vector<int>> graph(V);

    // Add edges
    graph[0]= {1,2};
    graph[1]= {0,3,4};
    graph[2]={0,4};
    graph[3]={1,5};
    graph[4]={1,5};
    graph[5]={3,4};
    

    // Mark all vertices as not visited
    vector<bool> visited(V, false);

    cout << "Depth-First Traversal (starting from vertex 0): ";
    dfs1(graph, visited, 0); // Start DFS from vertex 0

    return 0;
}

