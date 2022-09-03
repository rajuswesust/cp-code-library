#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define vi vector<int>
#define pb push_back
#define ll long long
#define maxn 1000005

int phi[maxn];
int main()
{
    for(int i = 1; i <= maxn; i++)
        phi[i] = i;
    for(int i = 2; i <= maxn; i++)
    {
        if(phi[i] == i)
        {
            for(int j = i; j <= maxn; j += i)
            {
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }
    int tc, n;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        cout << "phi(" << n << ") = " << phi[n] << "\n";
        cout << "\n";
    }
    return 0;
}
