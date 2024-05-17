#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& graph, int start_node) {
    int num_nodes = graph.size();
    vector<bool> visited(num_nodes, false);
    queue<int> queue;

    queue.push(start_node);
    visited[start_node] = true;

    while (!queue.empty()) {
        int current_node = queue.front();
        queue.pop();

        cout << current_node << " "; // Displaying the data of the current node

        for (int neighbor : graph[current_node]) {
            if (!visited[neighbor]) {
                queue.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}


void bfs1(vector<vector<int>>& graph, int start_node){
	int num_nodes = graph.size();
	vector<bool>visited(num_nodes,false);
	queue<int> queue;
	
	queue.push(start_node);
	visited[start_node] = true;
	
	while(!queue.empty()){
		int curr_node = queue.front();
		queue.pop();
		
		cout<<curr_node<<" ";
		
		for(int i : graph[curr_node]){
			if(!visited[i]){
				queue.push(i);
				visited[i]= true;
			}
		}
		
	}
	
	
	
}
int main() {
    // Example graph
    int num_nodes = 6;
    vector<vector<int>> graph(num_nodes);

    // Adding edges to the graph
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    // Starting node for BFS
    int start_node = 0;

    cout << "Breadth-First Search traversal starting from node " << start_node << ":" << endl;
    bfs1(graph, start_node);

    return 0;
}
