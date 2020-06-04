// https://www.hackerrank.com/challenges/variable-sized-arrays/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;


const vector<string> split(string &s) {
    vector<string> result;
    istringsgtream is(s);
    vector<string> result = vector<string>(istream_iterator<string>(is), istream_iterator<string>());
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, q;
    vector<string> *a = new vector<string>();
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        *a[i] = split(line);
    }
    
    return 0;
}
