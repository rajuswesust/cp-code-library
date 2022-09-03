#include <iostream>
#include <cmath>
using namespace std;

#define ll long long
#define SZ 1005

const ll mod = 1000000007;

ll ft[SZ], ncr[SZ][SZ];
ll power(ll a, ll n, ll mod)
{
    ll res=1;
    a%=mod;
    while(n>0)
    {
        if(n&1)
            res=(res*a) % mod;
        n>>=1;
        a = (a*a) % mod;
    }
    return res;
}
void fact()
{
    ft[0]=1;
    for(int i=1; i<SZ; i++)
        ft[i] = (ft[i-1]*1LL*i) % mod;
}
void nCr()
{
    ncr[0][0]=1;
    for(int i=1; i<SZ; i++)
    {
        ncr[i][0]=1;
        for(int j=1; j<=i; j++)
        {
            ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % mod;
        }
    }
}

//modular inverse a^-1 = a^m-2 under modulo m
ll inv(ll a)
{
    ll res=power(a, mod-2, mod);
    return res;
}

ll NCR(ll n, ll r)
{
    if(r>n)
        return 0;
    if(n==r)
        return 1;
    if (r==0)
        return 1;

    ll res = (ft[n]*inv(ft[r])) % mod;
    res = (res*inv(ft[n-r])) % mod;
    return res;
}
int main()
{
    fact();
    nCr();

    for(int i=0; i<=20; i++)
        cout<<i<<" : "<<ft[i]<<endl;
    cout<<endl;
    for(int i=1; i<=20; i++)
    {
        cout<<i<<" : "<<endl;
        for(int j=1; j<=i; j++)
            cout<<"#"<<j<<": "<<ncr[i][j]<<", "<<NCR(i, j)<<endl;
        cout<<endl;
    }

    return 0;
}
