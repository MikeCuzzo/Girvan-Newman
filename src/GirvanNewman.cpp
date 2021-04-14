//
// Created by mcuzzo on 4/13/21.
//

#include "GirvanNewman.h"

GirvanNewman::GirvanNewman(vector<boost::tuple<char, char>> edges) {
    for(int i = 0; i < edges.size(); i++) {
        add_edge(edges[i].get<0>() - 65, edges[i].get<1>() - 65, 1, g);
        //add_edge(2,3,1,g);
    }

    print_graph(g);

    findBetweenness();
}

void GirvanNewman::findBetweenness() {
    dijkstra();
}


 // BFS algorithm is used to calculate all the single source shortest paths in a non weighted graph and the source's closeness.
void GirvanNewman::dijkstra() {
     typedef graph_traits<Graph>::vertex_iterator vertex_iter;
     std::pair<vertex_iter, vertex_iter> vp;
     for (vp = vertices(g); vp.first != vp.second; ++vp.first) {
        // vector for storing distance property
        std::vector<int> d(num_vertices(g));
        std::vector<int> p(num_vertices(g));

        // get the first vertex
        Vertex s = *vp.first;
        // invoke variant 2 of Dijkstra's algorithm
        dijkstra_shortest_paths(g, s, distance_map(&d[0]).predecessor_map(&p[0]));

        std::cout << "distances from " << *vp.first << " vertex:" << std::endl;
        graph_traits<Graph>::vertex_iterator vi;
        for (vi = vertices(g).first; vi != vertices(g).second; ++vi)
            std::cout << "distance(" << *vi << ") = "
                      << d[*vi] << std::endl;
        std::cout << std::endl;

        cout << "parents in the tree of shortest paths:" << endl;
        for (vi = vertices(g).first; vi != vertices(g).second; ++vi) {
            cout << "parent(" << *vi;
            if (!p[*vi])
                cout << ") = no parent" << endl;
            else
                cout << ") = " << p[*vi] << endl;
        }
        cout << endl;
    }
 }