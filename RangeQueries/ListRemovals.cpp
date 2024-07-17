#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
# define Loop(i, a, b) for (int i = a; i < b; i++)
# define LoopReverse(i, a, b) for (int i = a; i >= b; i--)
# define LoopAuto(i, a) for (auto i: a)

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


ll prefixSum(ll index, ll l, ll r, ll low, ll high, vector<ll> &segmentTree) {
    if (low == l && high == r) {
        return segmentTree[index];
    }
    if (l > r) return 0;

    ll mid = (low + high) / 2;
    // Return the sum of the left and right child
    return prefixSum(2 * index + 1, l, min(r, mid), low, mid, segmentTree) + prefixSum(2 * index + 2, max(l, mid + 1), r, mid + 1, high, segmentTree);
}


ll processQuery(ll query, vector<ll> &segmentTree, ll n) {
    ll left = 0, right = n - 1;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll index = prefixSum(1, 0, mid, 0, n - 1, segmentTree);
        if (index >= query) right = mid - 1;
        else left = mid + 1;
    }
    return left;
}


void updateSegmentTree(vector<ll> &segmentTree, ll index, ll low, ll high, ll pos) {
    if (low == high) {
        segmentTree[index] = 0;
        return;
    }
    ll mid = (low + high) / 2;
    // If the position is in the left child then update the left child
    if (pos <= mid) updateSegmentTree(segmentTree, 2 * index + 1, low, mid, pos);
    else updateSegmentTree(segmentTree, 2 * index + 2, mid + 1, high, pos);
    segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> arr(n, 0), present(n, 1);
    Loop(i, 0, n) cin >> arr[i];
    vector<ll> segmentTree(4 * n, 0);
    buildSegmentTree(segmentTree, present, 0, n - 1, 1); // Build the Segment Tree of Present Array
    Loop(i, 0, n) {
        ll query; cin >> query;
        ll index = processQuery(query, segmentTree, n);
        cout << arr[index] << ' ';
        updateSegmentTree(segmentTree, 1, 0, n - 1, index);
    }
    return 0;
}
