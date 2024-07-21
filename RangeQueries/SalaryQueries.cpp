#include <bits/stdc++.h>
#include <climits>
using namespace std;

typedef long long ll
# define Loop(i, a, b) for (int i = a; i < b; i++)
# define Loopr(i, a, b) for (int i = a; i >= b; i--)
const ll MAX = 1e9 + 1;

// Building the sum segment tree -- For the frequency array
void buildSegmentTree(vector<ll> &segmentTree, vector<ll> &arr, ll low, ll high, ll index) {
    if (low == high) {
        segmentTree[index] = arr[low];
        return;
    }
    else {
        ll mid = (low + high) / 2;
        buildSegmentTree(segmentTree, arr, low, mid, 2 * index + 1);
        buildSegmentTree(segmentTree, arr, mid + 1, high, 2 * index + 2);
        segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
    }
}


void updateSegmentTree(vector<ll> &segmentTree, ll index, ll value, ll low, ll high) {
    if (low == high)  segmentTree[index] += value;
    else {
        ll mid = (low + high) >> 1;
        if (index <= mid) updateSegmentTree(segmentTree, 2 * index + 1, value, low, mid);
        else updateSegmentTree(segmentTree, 2 * index + 2, value, mid + 1, high);
        segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
    }
}


// Returns the sum of the array elements within the range [l, r]
ll rangeSumQuery(vector<ll> &segmentTree, ll l, ll r, ll low, ll high, ll index) {
    if (l <= low && r >= high) return segmentTree[index];
    if (l > high || r < low) return 0;
    ll mid = (low + high) >> 1;
    return rangeSumQuery(segmentTree, l, r, low, mid, 2 * index + 1) + rangeSumQuery(segmentTree, l, r, mid + 1, high, 2 * index + 2);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, q; cin >> n >> q;
    vector<ll> arr(MAX, 0);
    vector<ll> segmentTree(2 * MAX, 0);
    Loop(i, 0, n) {
        ll x; cin >> x;
        arr[x]++;
    }
    buildSegmentTree(segmentTree, arr, 0, MAX - 1, 0);

    while (q--) {
        char type; cin >> type;
        if (type == '!') {
            ll k, x; cin >> k >> x;
            
            
        }
    }
}