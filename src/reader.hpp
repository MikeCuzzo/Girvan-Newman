#include <vector>
#include <boost/tuple/tuple.hpp>
#include <string>
#include <fstream>
#include "GirvanNewman.h"
#include "iostream"

using namespace std;

class Reader{
    private:
        std::vector<boost::tuple<char, char>> data;
        void print();
    public:
        Reader();
        Reader(std::string);
        std::vector<boost::tuple<char,char>> getData();
};