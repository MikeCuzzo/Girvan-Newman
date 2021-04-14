//
// Created by mcuzzo on 4/13/21.
//

#include "GirvanNewman.h"

GirvanNewman::GirvanNewman(vector<boost::tuple<char, char>> params) {
    edges = params;
    for(int i = 0; i < edges.size(); i++) {
            add_edge(edges[i].get<0>() - 65, edges[i].get<1>() - 65, 1, g);
    }

    communities.resize(num_vertices(g));
    findBetweenness();
}

void GirvanNewman::findBetweenness() {
    for (int i = 0; i <= num_vertices(g); i++) {
    boost::shared_array_property_map<double, boost::property_map<Graph, vertex_index_t>::const_type>
            centrality_map(num_vertices(g), get(boost::vertex_index, g));
    brandes_betweenness_centrality(g, centrality_map);

    vector<double> betweenness;
    for (int j = 0; j < num_vertices(g); j++)
        betweenness.push_back(centrality_map[j]);

    findCommunities(betweenness);
    }
}

void GirvanNewman::findCommunities(vector<double> betweenness) {
    // finds highest betweenness
    int highest = 0;
    int highestIdx = 0;
    for(int i=0;i<betweenness.size();i++){
        if(betweenness[i]>highest) {
            highest = betweenness[i];
            highestIdx = i;
            if(center > 0)
                center = highestIdx;
        }
    }
    Vertex toCheck = highestIdx;
    vector<int> pathCount = dijkstra(highestIdx);
    clear_vertex(highestIdx,g);
    if(communities[highestIdx].empty()) {
        for (int i = 0; i < pathCount.size(); i++)
            if (pathCount[i] >= num_vertices(g) && i!=center)
                communities[highestIdx].push_back(i);
    }
}

 // BFS algorithm is used to calculate all the single source shortest paths in a weighted graph and the source's closeness.
vector<int> GirvanNewman::dijkstra(int toCheck) {
        // vector for storing distance property
        std::vector<int> d(num_vertices(g));

        // get the first vertex
        Vertex s = *(vertices(g).first)+toCheck;
        // invoke variant 2 of Dijkstra's algorithm
        dijkstra_shortest_paths(g, s, distance_map(&d[0]));

     return d;
 }

vector<vector<int>> GirvanNewman::getCommunities() {
    //cleans up communities
    for(int i=0;i<communities.size();i++){
        for(int j=0;j<communities[i].size();j++){
            //removes center
            if(communities[i][j] == center)
                communities[i].erase(communities[i].begin(),communities[i].begin()+j);
        }
    }
    return communities;
}