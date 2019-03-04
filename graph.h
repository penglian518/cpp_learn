//
// Created by Lian, Peng on 2019-03-04.
//

#ifndef CPP_LEARN_GRAPH_H
#define CPP_LEARN_GRAPH_H

#include <iostream>
#include <list>

namespace G{
    class Graph {
    private:
        int V;                  // No. of vertices
        std::list<int> *adj;         // declare a dynamic memory to hold lists containing the adjacency lists

        void DFSUtil(int v, bool *visited);   // a recursive function used by DFS

    public:
        Graph(int V);           // constructor
        void showV();
        void addEdge(int v, int w);
        void BFS(int s);        // prints Graph traversal from a given source s
        void DFS(int s);        // DFS traversal
    };
}



#endif //CPP_LEARN_GRAPH_H
