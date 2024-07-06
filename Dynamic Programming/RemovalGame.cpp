#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
# define Loop(i, a, b) for(int i = a; i < b; i++)  
# define RevLoop(i, a, b) for(int i = a; i >= b; i--) 
# define MIN -1000000001

int main(){
    ll n; cin >> n;
    vector<ll> nums(n);
    ll sum = 0;
    Loop(i, 0, n){
        cin >> nums[i];
        sum += nums[i];
    }

    // score[i][j] = maximum score that can be obtained by player 1 from the subarray nums[i..j]
    vector<vector<ll>> score(n, vector<ll>(n, MIN));
    
    RevLoop(i, n - 1, 0){
        Loop(j, i, n){
            if (i == j) score[i][j] = nums[i];
            // For a subarray, player 1 can either choose the first element or the last element
            // If he chooses the first, then then difference between their scores will be nums[i] - score[i + 1][j] because player 2 will play optimally
            // If he chooses the last, then then difference between their scores will be nums[j] - score[i][j - 1]
            // The negative sign is because player 2 will play optimally (like Player 1)
            else score[i][j] = max(nums[i] - score[i + 1][j], nums[j] - score[i][j - 1]);
        }
    }
    // We found the maximum difference between the scores of player 1 and player 2
    // The sum of the scores of player 1 and player 2 will be the sum of the array
    // Therefore, the score of player 1 will be (sum + score[0][n - 1]) / 2
    cout << ((sum + score[0][n - 1]) / 2) << endl;
    return 0;
}