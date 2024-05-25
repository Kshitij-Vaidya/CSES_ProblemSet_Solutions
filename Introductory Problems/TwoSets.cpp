#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    // Check if the sum of the numbers from 1 to n is even
    // If it is, then it is possible to divide the numbers into two sets
    ll sum = n*(n+1)/2;

    if (sum%2 != 0){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        ll half = sum / 2;
        vector<ll> set1, set2;
        vector<int> used(n+1, 0);

        ll max = n;
        ll set1_sum = 0;

        while (set1_sum < half){
            ll  remain = half - set1_sum;

            if (remain > max){
                set1.push_back(max);
                set1_sum += max;
                used[max] = 1;
                max--;
            }
            else{
                set1.push_back(remain);
                set1_sum += remain;
                used[remain] = 1;
            }
        }

        for (ll i = 1; i <= n; i++){
            if (used[i] == 0){
                set2.push_back(i);
            }
        }

        cout << set1.size() << endl;
        for (auto x: set1){
            cout << x << " ";
        }

        cout << "\n";

        cout << set2.size() << endl;
        for (auto x: set2){
            cout << x << " ";
        }       
    }
    return 0;
}