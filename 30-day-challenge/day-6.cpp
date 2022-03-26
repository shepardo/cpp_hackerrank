// Day 6
// https://www.hackerrank.com/challenges/30-review-loop/problem?isFullScreen=true


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


string ltrim(const string &);
string rtrim(const string &);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string n_temp;
    getline(cin, n_temp);
    int n = stoi(ltrim(rtrim(n_temp)));

    while (n--) {
        string input;
        string odd;
        string even;

        cin >> input;

        for (int i = 0; i < input.length(); i++) {
            if (i % 2 == 0) {
                even += input[i];
            } else {
                odd += input[i];
            }
        }
        cout << even << " " << odd << endl;
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
