// Day 26
// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int get_charge(int d1, int m1, int y1, int d2, int m2, int y2) {

    if ((y1 < y2) || ((y1 == y2) && (m1 < m2)) || ((y1 == y2) && (m1 == m2) && (d1 <= d2))) {
        return 0;
    } else {
        if ((y1 == y2) && (m1 == m2) && (d1 > d2)) {
            return 15 * (d1 - d2);
        } else if ((y1 == y2) && (m1 > m2)) {
            return 500 * (m1 - m2);
        } else {
            return 10000;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int d1, m1, y1, d2, y2, m2;
    cin >> d1 >> m1 >> y1;
    cin >> d2 >> m2 >> y2;

    cout << get_charge(d1, m1, y1, d2, m2, y2);

    return 0;
}
