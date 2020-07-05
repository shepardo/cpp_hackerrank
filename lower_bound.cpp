// https://www.hackerrank.com/challeanges/cpp-lower-bound/problem
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
    sort(a.begin(), a.end());
    cin >> n;
    while (n--) {
        cin >> x;
        vector<int>::iterator it = lower_bound(a.begin(), a.end(), x);
        if (*it == x ) {
            cout << "Yes " << (it - a.begin() + 1) << endl;
        } else {
            cout << "No " << (it - a.begin() + 1) << endl;
        }
    }
    return 0;
}
