#include<iostream>
#include<set>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    set<ll> s;
    while(n--){
        ll x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
    return 0;
}