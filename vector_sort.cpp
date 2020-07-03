// https://www.hackerrank.com/challenges/vector-sort/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> a;
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for(vector<int>::const_iterator it = a.cbegin(); it != a.cend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
