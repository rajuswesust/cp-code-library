/**************

to see another implementation of prime factorization for multiple queries search:
Prime Factorization using Sieve O(log n) for multiple queries

***************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define MX 50000
bool isPrime[MX+5];
vector <int> primes;

void simpleSieve()
{
    int i, j;
    int limit = sqrt(MX) + 1;

    isPrime[2] = true;
    for(i = 3; i <= MX; i += 2)
        isPrime[i] = true;
    primes.push_back(2);
    for(i = 3; i <= MX; i += 2)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            if(i <= limit)
            {
                for(j = i; j <= MX; j += 2*i)
                    isPrime[j] = false;
            }
        }
    }
    //cout << primes.size() << endl;
}
vector<int> getFactorization(int x)
{
    vector<int> ret;
    for(int i=0; i<primes.size(); i++)
    {
        while(x%primes[i]==0)
        {
            x/=primes[i];
            ret.push_back(primes[i]);
        }
    }
    if(x>1)
        ret.push_back(x);
    return ret;
}
void printV(vector<int> v)
{
    cout<<"printing: ";
    for(auto it: v)
        cout<<it<<" ";
    cout<<endl;
}
int main()
{
    simpleSieve();

    int n = 292440407;
    vector<int> fact = getFactorization(n);
    printV(fact);
    return 0;
}

