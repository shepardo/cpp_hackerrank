// https://www.hackerrank.com/challenges/variable-sized-arrays/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;


vector<string> split(string &s) {
    istringstream is(s);
    const vector<string> result = vector<string>(istream_iterator<string>(is), istream_iterator<string>());
    return result;
}

void print_vector(const vector<string>& v) {
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << *i << ' ';
    }
    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, q;
    cin >> n >> q;
    vector<string> *a = new vector<string>[n];
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        a[i] = split(line);
        print_vector(a[i]);
    }

    for (int j = 0; j < q; j++) {
        int x, y;
        cin >> x >> y;
        cout << a[x][y] << endl;
    }
    delete[] a;
    return 0;
}
