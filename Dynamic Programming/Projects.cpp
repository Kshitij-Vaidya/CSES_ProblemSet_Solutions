#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
# define Loop(i, a, b) for (ll i = a; i < b; i++)

struct Project
{
    ll start = 0;
    ll end = 0;
    ll reward = 0;
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<Project> projects(n + 1);
    vector<ll> end_dates(n + 1);
    Loop(i, 1, n + 1){
        ll start, end, reward;
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }
    sort(projects.begin() + 1, projects.end(), [](Project &a, Project &b){
        if (a.end == b.end) return a.reward < b.reward;
        return a.end < b.end;
    });
    Loop(i, 1, n + 1) end_dates[i] = projects[i].end;
    vector<ll> max_reward(n + 1 , 0);
    Loop(i, 1, n + 1){
        auto it = lower_bound(end_dates.begin(), end_dates.end(), projects[i].start);
        ll index = distance(end_dates.begin(), it) - 1;
        max_reward[i] = max(max_reward[i - 1], max_reward[index] + projects[i].reward);
    }
    cout << max_reward[n] << '\n';
    return 0;
}