// day 25
// https://www.hackerrank.com/challenges/30-running-time-and-complexity?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool isPrime(int n) {

    if (n < 0) n = n * -1;
    for (int i = 2; i < n/2; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    while (n--) {
        int v;
        cin >> v;
        if (isPrime(v)) {
            cout << "Prime" << endl;
        } else {
            cout << "Not prime" << endl;
        }
    }
    return 0;
}
