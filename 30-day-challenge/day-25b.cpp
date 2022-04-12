
/*
https://en.wikipedia.org/wiki/Primality_test
https://cp-algorithms.com/algebra/primality_tests.html
https://www.geeksforgeeks.org/primality-test-set-2-fermet-method/

*/

// day 25 variant 2, uses Fermat method
// https://www.geeksforgeeks.org/primality-test-set-2-fermet-method/
// https://www.hackerrank.com/challenges/30-running-time-and-complexity?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/* Iterative Function to calculate (a^n)%p in O(logy) */
int power(int a, unsigned int n, int p)
{
    int res = 1;      // Initialize result
    a = a % p;  // Update 'a' if 'a' >= p

    while (n > 0)
    {
        // If n is odd, multiply 'a' with result
        if (n & 1)
            res = (res*a) % p;

        // n must be even now
        n = n>>1; // n = n/2
        a = (a*a) % p;
    }
    return res;
}

/*Recursive function to calculate gcd of 2 numbers*/
int gcd(int a, int b)
{
    if(a < b)
        return gcd(b, a);
    else if(a%b == 0)
        return b;
    else return gcd(b, a%b);
}

// If n is prime, then always returns true, If n is
// composite than returns false with high probability
// Higher value of k increases probability of correct
// result.
bool doIsPrime(unsigned int n, int k)
{
   // Corner cases
   if (n <= 1 || n == 4)  return false;
   if (n <= 3) return true;

   // Try k times
   while (k>0)
   {
       // Pick a random number in [2..n-2]
       // Above corner cases make sure that n > 4
       int a = 2 + rand()%(n-4);

       // Checking if a and n are co-prime
       if (gcd(n, a) != 1)
          return false;

       // Fermat's little theorem
       if (power(a, n-1, n) != 1)
          return false;

       k--;
    }

    return true;
}


bool isPrime(int n) {

    return doIsPrime(n, 3);
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
