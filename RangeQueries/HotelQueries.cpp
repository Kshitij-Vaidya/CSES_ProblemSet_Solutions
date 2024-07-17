#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
# define Loop(i, a, b) for (int i = a; i < b; i++)
# define LoopReverse(i, a, b) for (int i = a; i >= b; i--)
# define LoopAuto(i, a) for (auto i : a)

ll processQuery(vector<pair<ll, ll>> &hotel,ll start, ll end, ll query, ll index) {
    if (hotel[index].first < query) return 0;
    if (start == end) return hotel[index].first >= query ? hotel[index].second : 0;
    ll mid = (start + end) / 2;
    ll left = processQuery(hotel, start, mid, query, 2 * index);
    if (left != 0) return left;
    return processQuery(hotel, mid + 1, end, query, 2 * index + 1);
}

void updateQuery(vector<pair<ll, ll>> &hotel, ll index, ll maxN, ll query) {
    index += maxN - 1;
    hotel[index].first -= query;
    while (index > 1) {
        index /= 2;
        if (hotel[2 * index].first >= hotel[2 * index + 1].first) {
            hotel[index].first = hotel[2 * index].first;
            hotel[index].second = hotel[2 * index].second;
        }
        else {
            hotel[index].first = hotel[2 * index + 1].first;
            hotel[index].second = hotel[2 * index + 1].second;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    ll maxN = pow(2, ceil(log2(n)));
    vector<pair<ll, ll>> hotel(2 * maxN, {0, 0});
    Loop(i, 0, n) {
        cin >> hotel[maxN + i].first;
        hotel[maxN + i].second = i + 1;
    }
    // Build Segment Tree to store the maximum value of the hotel rooms
    LoopReverse(i, maxN - 1, 1) {
        if (hotel[2 * i].first >= hotel[2 * i + 1].first) {
            hotel[i].first = hotel[2 * i].first;
            hotel[i].second = hotel[2 * i].second;
        }
        else {
            hotel[i].first = hotel[2 * i + 1].first;
            hotel[i].second = hotel[2 * i + 1].second;
        }
    }

    // Input the groups(queries)
    vector<ll> groups(m, 0);
    Loop(i, 0, m) cin >> groups[i];

    LoopAuto(group, groups) {
        ll res = processQuery(hotel, 0, maxN - 1, group, 1);
        if (res == 0) cout << 0 << ' ';
        else {
            cout << res << ' ';
            updateQuery(hotel, res, maxN, group);
        }
    }
    return 0;
}