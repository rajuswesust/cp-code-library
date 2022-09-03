#include <iostream>
#include <cmath>
using namespace std;

#define ll long long

//Binary Exponential
ll power(ll a, ll n) {
    ll res = 1;
    while(n) {
        if(n%2) {
            res = res*a;
            n--;
        }
        else {
            a *= a;
            n /= 2;
        }
    }
    return res;
}

//Modular Exponential
ll power(ll a, ll n, ll p) {
    ll res = 1;
    while(n) {
        if(n%2) {
            res = (res*a) % p;
            n--;
        }
        else {
            a = (a*a) % p;
            n /= 2;
        }
    }
    return res;
}

int main() {
    ll a = 2, n = 50, p = 1000000007;

    cout << power(2, 30) << endl;
    cout << power(a, n, p) << "\n";

    return 0;
}
