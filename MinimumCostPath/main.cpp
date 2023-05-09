//
//  main.cpp
//  MinimumCostPath
//
//  Created by Sart Way on 1/5/23.
//

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <fstream>
#include <vector>
#include <list>
#include "Solution.hpp"
using namespace std;
string ltrim(const string &str);
string rtrim(const string &str);
vector<string> split(const string &str);

int main(int argc, const char * argv[]) {
    fstream input("File.txt", ios::in | ios::out);
    //fstream output("output.txt", ios::in);
    string q_temp;
    getline(input, q_temp);
    
    int q = stoi(ltrim(rtrim(q_temp)));
    vector<vector<int>>a(q);
    for(int q_itr=0;q_itr<q;++q_itr)
    {
        string first_multiple_input_temp;
        string rtemp;
        getline(input, first_multiple_input_temp);
        
        vector<string> a_temp = split(rtrim(first_multiple_input_temp));

        

        for (int i = 0; i < q; i++) {
            int a_item = stoi(a_temp[i]);

            a[q_itr].push_back(a_item);
        }
        
    }
//    for(int i=0;i<q;++i)
//    {
//        for(int j=0;j<q;++j)
//        {
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }
    Solution soln;
    int ans = soln.minimumCostPath(a);
    
    return 0;
}


string ltrim(const string &str) {
    string s(str);

    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);}));
    return s;

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);}));
    return s;

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
