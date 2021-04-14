//
// Created by mcuzzo on 4/13/21.
//

#include "GirvanNewman.h"

GirvanNewman::GirvanNewman(std::vector<boost::tuple<char, char>> edges) {
    for(int i = 0; i < edges.size(); i++)
        add_edge(edges[i].get<0>(), edges[i].get<1>(), g);

     print_graph(g);
     //findBetweenness();
}

//void GirvanNewman::findBetweenness() {
//    // boost::brandes_betweenness_centrality(g);
//    bfs_SSSP();
//}

 // BFS algorithm is used to calculate all the single source shortest paths in a non weighted graph and the source's closeness.
//float GirvanNewman::bfs_SSSP() {
//    // Closeness counter.
//    float closeness = 0;
//
//    // Vector that holds the distances from the source.
//    vector<int> dist;
//    dist.resize(n, -1);
//    dist[src] = 0;
//
//    // Queue used for the Bfs algorithm.
//    queue<int> visitQueue;
//    visitQueue.push(src);
//
//    // While there are still elements in the queue.
//    while (!visitQueue.empty()) {
//        // Pop the first.
//        int v = visitQueue.front();
//        visitQueue.pop();
//        visitStack.push(v);
//
//        // Closeness part aggregation.
//        closeness += dist[v];
//
//        // Check the neighbors w of v.
//        for (vector<neighbor>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++) {
//            int w = it->target;
//            // Node w found for the first time?
//            if (dist[w] < 0) {
//                visitQueue.push(w);
//                dist[w] = dist[v] + 1;
//            }
//            // Is the shortest path to w via u?
//            if (dist[w] == dist[v] + 1) {
//                pred[w].push_back(v);
//                sigma[w] += sigma[v];
//            }
//        }
//
//    }
//    // Closeness part inversion.
//    if (closeness!=0) {
//        return 1.0 / closeness;
//    } else {
//        return 0;
//    }
//}