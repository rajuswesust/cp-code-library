//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define SZ(x) (int)(x.size())
#define printV(v) cout<<"#";for(int i = 0; i < v.size(); i++)cout<<v[i]<<" "<<" \n"[i == v.size()-1]
#define printA(a, N)cout<<"#";for(int i = 0; i < N; i++)cout<<a[i]<<" "<<" \n"[i==N-1]
#define ld long double

const int mod=1e9 + 7;
const int inf=2e9;
const ll INF = 1e18;
const int N = 1e5+5;

bool mark[N];//0->prime, 1->no
//bitset<N> mark;
vi primes;
void sieve() {
    for(int i=2; i*i<N; i++)
    {
        if(!mark[i])
        {
            for(int j=i*i; j<N; j+=i)
                mark[j]=true;
        }
    }
    for(int i=2; i<N; i++)
        if(!mark[i])primes.pb(i);
    cerr<<"#"<<SZ(primes)<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sieve();

}
/***


***/



