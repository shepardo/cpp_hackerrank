// https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    static string numbers[] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };
    int lower, upper;
    cin >> lower >> upper;
    for (int i = lower; i <= upper; i++ ) {
        if (i >= 0 && i <= 9) {
            cout << numbers[i] << endl;
        } else if (i % 2 == 0) {
            cout << "even" << endl;
        } else {
            cout << "odd" << endl;
        }
    }
    return 0;
}
