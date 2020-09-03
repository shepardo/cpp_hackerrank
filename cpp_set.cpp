// https://www.hackerrank.com/challenges/cpp-sets/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    set<int> s;
    int q, n, x;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> n >> x;
        switch (n) {
            case 1:
                s.insert(x);
                break;
            case 2:
                s.erase(x);
                break;
            case 3:
                set<int>::iterator it = s.find(x);
                if (it != s.end()) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
                break;
        }
    }  
    return 0;
}



