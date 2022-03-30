// Day 10
// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int get_maximum_consecutive_1s(int n);


int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    cout << get_maximum_consecutive_1s(n) << endl;

    return 0;
}

int get_maximum_consecutive_1s(int n) {
    int max = 0;
    int tmp_max = 0;
    while (n) {
        if (n % 2 == 1) {
            tmp_max++;
        } else {
            max = tmp_max > max? tmp_max : max;
            tmp_max = 0;
        }
        n /= 2;
    }
    max = tmp_max > max? tmp_max : max;
    return max;
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
