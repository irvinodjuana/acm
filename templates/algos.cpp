#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

// constants
ull MOD = 1e9 + 7;

/** Math and other useful algorithms here **/

// n choose k
int choose(int n, int k) {
    int res = 1;

    if (n - k < k) k = n - k;

    for (int i = 1; i <= k; i++) {
        res *= (n - k + i);
        res /= i;
    }

    return res;
}


// n choose k (large - big int and mod)
ull choose(ull n, ull k) {
    ull res = 1;

    if (n - k < k) k = n - k;

    for (ull i = 1; i <= k; i++) {
        res *= (n - k + i);
        res /= i;
        res %= MOD;
    }

    return res;
}

// n! - n factorial
int factorial(int n) {
    int res = 1;

    for (int i = 2; i <= n; i++) {
        res *= i;
    }

    return res;
}



// fibonacci - nth number (fib(0) = 1, fib(1) = 1)
int fibonacci(int n) {
    int prev = 1;
    int curr = 1;

    for (int i = 2; i <= n; i++) {
        prev += curr;
        swap(prev, curr);
    }

    return curr;
}


// gcd of a and b (a,b must be >= and cannot both be 0)
int gcd(int a, int b) {
    if (b > a) swap(a, b);

    while (b) {
      a %= b;
      swap(a, b);
    }

    return a;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    
    cout.flush();
    return 0;
}