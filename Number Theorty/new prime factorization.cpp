#include <bits/stdc++.h>
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
const int N = 1e6 + 5;

int spf[N];
void sieve()
{
    for(int i=2; i<N; i++)
        spf[i]=i;
    for(int i=2; i<N; i++)
    {
        for(int j=i; j<N; j+=i)
            spf[j]=min(spf[j], i);
    }
    //for(int i=1; i<=100; i++)
    //    cout<<i<<": "<<spf[i]<<endl;
}

void solve(int n)
{
    vi fact;
    while(n>1)
    {
        fact.pb(spf[n]);
        n/=spf[n];
    }
    printV(fact);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sieve();
    solve(12);
    solve(636916);
}
/***


***/



