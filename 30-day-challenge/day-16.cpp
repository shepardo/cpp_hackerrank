
// Day 16
// https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;



int main()
{
    string S;
    getline(cin, S);

    try {
        int n = stoi(S);
        cout << n << endl;
    } catch (invalid_argument) {
        cout << "Bad String" << endl;
    }

    return 0;
}

