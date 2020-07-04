// https://www.hackerrank.com/challenges/vector-erase/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, x;
    cin >> n;
    vector<int> a;
    while (n--) {
        cin >> x;
        a.push_back(x);
    } 
    int q1, q2;
    cin >> q1;
    a.erase(a.begin() + q1 - 1);
    cin >> q1 >> q2;
    a.erase(a.begin() + q1 - 1, a.begin() + q2 - 1);
    cout << a.size() << endl;
    for (vector<int>::const_iterator it = a.cbegin(); it != a.cend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
