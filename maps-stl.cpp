
// https://www.hackerrank.com/challenges/cpp-maps/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    map<string, int> m;
    string first_multiple_input_temp;
    int n;
    cin >> n;
    getline(cin, first_multiple_input_temp); // prune garbage
    while (n--) {
        getline(cin, first_multiple_input_temp);
        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));
        if (first_multiple_input[0] == "1") {
            map<string, int>::iterator it = m.find(first_multiple_input[1]);
            int score = stoi(rtrim(ltrim(first_multiple_input[2])));
            if (it != m.end()) {
                score += it->second;
                m[first_multiple_input[1]] = score;
            } else {
                m.insert(make_pair(first_multiple_input[1], score));
            }
            m[first_multiple_input[1]] = score;
        } else if (first_multiple_input[0] == "2") {
            m.erase(first_multiple_input[1]);
        } else if (first_multiple_input[0] == "3") {
            map<string, int>::iterator it = m.find(first_multiple_input[1]);
            if (it != m.end()) {
                cout << it->second << endl;
            } else {
                cout << "0" << endl;
            }
        }
    }

    return 0;
}




string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

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


