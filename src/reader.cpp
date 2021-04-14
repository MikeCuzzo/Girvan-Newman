#include "reader.hpp"

Reader::Reader(){
    //reads file
    data.push_back(boost::make_tuple('a', 'f'));
    print();
}

Reader::Reader(string path){
    ifstream infile;
    infile.open(path+"put_data_here.txt");
    string buffer;
    getline(infile, buffer);
    int size = stoi(buffer);
    for (int i = 0; i < size; i++){
        buffer = "";
        getline(infile, buffer);
        data.push_back(boost::make_tuple(buffer[0], buffer[4]));
    }
    infile.close();
    //print();

    //runs girvan newman
    GirvanNewman girvan = GirvanNewman(data);
    vector<vector<int>> communities = girvan.getCommunities();

    ofstream outfile;
    outfile.open(path+"output.txt");
    //outputs communities
    for (int i =0; i<communities.size();i++){
        if(!communities[i].empty()) {
            outfile << "Community " << i << endl << i << " -> ";
            for (int j = 0; j < communities[i].size(); j++) {
                outfile << communities[i][j] << " ";
            }
            outfile << endl << endl;
        }
    }

    outfile.close();
}

vector<boost::tuple<char,char>> Reader::getData(){
    return data;
}

void Reader::print(){
    for (int i = 0; i < data.size(); i++){
        cout << "(" << data[i].get<0>() << ", " << data[i].get<1>() << ")" << endl;
    }
}

