// Day 8
// https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    std::map<string,int> map;
    cin >> n;
    while (n--) {
        int val;
        string name;
        cin >> name >> val;
        map[name] = val;
    }
    string line;
    getline(cin, line);
    while (getline(cin, line)) {
        std::map<string,int>::const_iterator it = map.find(line);
        if (it != map.end()) {
            cout << it->first << "=" << it->second << endl;
        } else {
            cout << "Not found" << endl;
        }
    }
    /*
    for (std::map<string,int>::const_iterator it = map.begin(); it != map.end(); it++) {
        cout << it->first << "=" << it->second << endl;
    }*/
    return 0;
}
