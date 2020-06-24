// https://www.hackerrank.com/challenges/c-tutorial-strings/problem
#include <iostream>
#include <string>
using namespace std;

void exchange(string &s, int i, int j) {
    char t = s[i];
    s[i] = s[j];
    s[j] = t;
}

void exchange(char &a, char &b) {
    char t = char(a);
    a = b;
    b = a;
}

void exchange(string& a, string &b, int i, int j) {
    char t= a[i];
    a[i] = b[j];
    b[j] = t;
}

int main() {
	// Complete the program
    string a, b;
    cin >> a >> b;
    cout << a.size() << " " << b.size() << endl;
    cout << a + b << endl;
    //exchange(a, 0, 1);
    //exchange(b, 0, 1);
    //exchange(a[0], b[0]);
    exchange(a, b, 0, 0);
    cout << a << " " << b << endl;

    return 0;
}
