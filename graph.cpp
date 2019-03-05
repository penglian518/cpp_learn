//
// Created by Lian, Peng on 2019-03-04.
//

#include "graph.h"

using namespace std;
using namespace G;

// constructor
Graph::Graph(int V) {
    printf("\nWelcome to use the Graph module!\n");

    this->V = V;
    adj = new list<int> [V];                //init the dynamic memory to be an V-sized array of lists
}

void Graph::showGraph() {
    printf("The nodes number are: %d\n", this->V);
    printf("Node, adjacent list\n");
    // list nodes and their adjacent list
    for (int i=0; i<V; i++) {
        cout << i << ", ";
        for (auto j: adj[i]){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);                    //Add w to v's list.
}

void Graph::BFS(int s) {
    bool *visited = new bool [V];           // delcare a dynamic memory of bools, and init it to be an array of V bools
    for (int i=0; i<V; i++)
        visited[i] = false;

    list<int> queue;                        // a queue for Graph

    visited[s] = true;                      // mark the current node as visited
    queue.push_back(s);                     // enqueue the current node

    list<int>::iterator i;                  // create an iterator pointer

    printf("The results for Breadth First Traversal:\n");

    while (!queue.empty()){
        // pop out the current element from the queue
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // check the adjacent elements of the current element, if not been visited, put into the queue
        for (i = adj[s].begin(); i != adj[s].end(); i++){
            if (!visited[*i]){
                queue.push_back(*i);
                visited[*i] = true;
            }
        }
    }
    cout << endl;
}


void Graph::DFSUtil(int v, bool *visited) {
    // mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // recursively visit all the vertical adjacent
    list<int>::iterator i;
    for (i=adj[v].begin(); i!=adj[v].end(); i++){
        if (!visited[*i]){
            this->DFSUtil(*i, visited);
        }
    }

}


void Graph::DFS(int s) {
    // init the visited array
    bool *visited = new bool [V];
    for (int i=0; i<V; i++) visited[i] = false;         // mark all as false

    printf("The results for Depth First Traversal:\n");

    for (int i=0; i<V; i++){
        if (! visited[i]){
            this->DFSUtil(s, visited);
        }
    }
    cout << endl;
}
