// Day 14
// https://www.hackerrank.com/challenges/30-scope/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;

  	public:
  	int maximumDifference;

	// Add your code here
    Difference(const vector<int>& celements): elements(celements) {}

    void computeDifference() {
        int max = -1;
        int min = 999999999;
        for (vector<int>::const_iterator it = elements.begin(); it != elements.end(); it++) {
            int v = *it;
            if (v < 0) v = v * -1;
            if (v < min) min = v;
            if (v > max) max = v;
        }
        this->maximumDifference = max - min;
    }

}; // End of Difference class

int main() {
    int N;
    cin >> N;

    vector<int> a;

    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;

        a.push_back(e);
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0;
}
