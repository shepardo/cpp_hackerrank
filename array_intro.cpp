// https://www.hackerrank.com/challenges/arrays-introduction/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    int *arr = new int[n];
    int i;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (i = n - 1; i >= 0; i--) {
        cout << arr[i] << ' ';
    }
    delete[] arr;
    return 0;
}
