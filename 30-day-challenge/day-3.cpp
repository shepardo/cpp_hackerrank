// https://www.hackerrank.com/challenges/30-conditional-statements/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

const string solve(int N);

int main()
{
    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    cout << solve(N) << endl;

    return 0;
}

const string solve(int N) {
    string result;
    if (N % 2 == 1) {
        result = "Weird";
    } else {
        if (N >= 2 && N <= 5) result = "Not Weird";
        else if (N >= 6 && N <= 20) result = "Weird";
        else result = "Not Weird";
    }
    return result;
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
