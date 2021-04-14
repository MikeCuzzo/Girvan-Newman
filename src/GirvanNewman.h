//
// Created by mcuzzo on 4/13/21.
//

#ifndef GIRVAN_NEWMAN_GIRVANNEWMAN_H
#define GIRVAN_NEWMAN_GIRVANNEWMAN_H

#include <boost/tuple/tuple.hpp>
#include <boost/graph/betweenness_centrality.hpp>
#include <iostream>
#include <utility>  //pair
#include <algorithm>  //for_each
#include <iterator>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/config.hpp>
#include <boost/utility.hpp> // for tie
#include <boost/graph/graphviz.hpp>
#include "vector"
#include "queue"
#include <boost/graph/graph_utility.hpp>
#include <boost/graph/named_function_params.hpp>
#include <boost/graph/visitors.hpp>
#include <boost/graph/bc_clustering.hpp>

using namespace std;
using namespace boost;

class GirvanNewman {
public:
    GirvanNewman(vector<boost::tuple<char, char>>);
    void findBetweenness();
    void findCommunities(vector<double>);
    vector<int> dijkstra(int);
    vector<vector<int>> getCommunities();
private:
    // typedefs
    typedef boost::property<boost::edge_weight_t, int> EdgeWeightProperty;
    typedef boost::adjacency_list<boost::listS, boost::vecS,boost::undirectedS,boost::no_property,EdgeWeightProperty> Graph;
    typedef Graph::edge_descriptor Edge;
    typedef graph_traits<Graph>::vertex_descriptor Vertex;
    //graph
    Graph g;
    vector<boost::tuple<char, char>> edges;
    vector<vector<int>> communities;
    int center = -1;
};


#endif //GIRVAN_NEWMAN_GIRVANNEWMAN_H
