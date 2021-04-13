#include "reader.hpp"
#include <vector>
#include <boost/tuple/tuple.hpp>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Reader::Reader(){
    data.push_back(boost::make_tuple('a', 'f'));
    print();
}

Reader::Reader(string path){
    ifstream infile;
    infile.open(path);
    string buffer;
    getline(infile, buffer);
    int size = stoi(buffer);
    for (int i = 0; i < size; i++){
        buffer = "";
        getline(infile, buffer);
        data.push_back(boost::make_tuple(buffer[0], buffer[4]));
    }
    infile.close();
    print();
}

vector<boost::tuple<char,char>> Reader::getData(){
    return data;
}

void Reader::print(){
    for (int i = 0; i < data.size(); i++){
        cout << "(" << data[i].get<0>() << ", " << data[i].get<1>() << ")" << endl;
    }
}