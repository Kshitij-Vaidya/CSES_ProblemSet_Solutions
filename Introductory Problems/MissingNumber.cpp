#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin >> n;
    ll sum = 0;
    for (ll i = 0; i < n-1 ; i++)
    {
        cin >> m;
        sum += m;
    }
    ll missing = (n * (n + 1)) / 2 - sum;
    cout << missing << endl;
    return 05;
}