//
// Created by mcuzzo on 4/13/21.
//

#ifndef GIRVAN_NEWMAN_GIRVANNEWMAN_H
#define GIRVAN_NEWMAN_GIRVANNEWMAN_H

#include <boost/tuple/tuple.hpp>
#include <boost/graph/betweenness_centrality.hpp>
#include <iostream>
#include <utility>  //std::pair
#include <algorithm>  //std::for_each
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/config.hpp>
#include <boost/utility.hpp> // for boost::tie
#include <boost/graph/graphviz.hpp>
#include "vector"
#include "queue"
#include <boost/graph/graph_utility.hpp>

using namespace std;

class GirvanNewman {
public:
    GirvanNewman(std::vector<boost::tuple<char, char>>);
    void findBetweenness();
    float bfs_SSSP();
private:
    // typedefs
    typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS> Graph;
    typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

    Graph g;

    map<string, float> edgeBetweenness;
    vector<float> nodeBetweenness;
    vector<float> closeness;
};


#endif //GIRVAN_NEWMAN_GIRVANNEWMAN_H
