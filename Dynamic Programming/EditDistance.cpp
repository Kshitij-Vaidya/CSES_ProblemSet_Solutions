#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <string>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
# define Loop(i, a, b) for (ll i = a; i < b; i++)
# define MOD 1000000007

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    ll n = s1.size(), m = s2.size();
    vector<vector<ll>> transform(n + 1, vector<ll>(m + 1, 0));
    Loop(i, 0, n + 1) transform[i][0] = i;
    Loop(i, 0, m + 1) transform[0][i] = i;

    Loop(i, 1, n + 1){
        Loop(j, 1, m + 1){
            // The substrings are already identical, no changes required
            if (s1[i - 1] == s2[j - 1]) transform[i][j] = transform[i - 1][j - 1];
            // Now, we must either insert, remove or subtitute a character
            else transform[i][j] = min({transform[i - 1][j - 1], transform[i][j - 1], transform[i - 1][j]}) + 1; 
        }
    }
    cout << transform[n][m] << endl;
    return 0;
}