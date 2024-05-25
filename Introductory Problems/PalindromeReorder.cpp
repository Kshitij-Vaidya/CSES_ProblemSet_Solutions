#include<iostream>
#include<string>

using namespace std;
typedef long long ll;

// Use a Hash Map to keep track of the frequency of occurance of each letter in the input string
// Atmost one character can occur an odd number of times in a palindrome
int main(){
    string s;
    cin >> s;

    int count[26] = {};
    ll N = s.length();
    // Initialise an empty string to make the palindrome
    string palindrome(N, ' ');
    // Populate the hash map with the frequencies
    for (ll i = 0; i < N; i++){
        count[s[i] - 'A']++;
    }

    int odd_count = 0;
    for (int i = 0; i < 26; i++){
        if (count[i] % 2 == 1){
            odd_count++;
        }
    }
    if (odd_count > 1){
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    ll left = 0, right = N - 1;
    for (int i = 0; i < 26; i++){
        if (count[i] % 2 == 1){
            palindrome[N/2] = i + 'A';
            count[i]--;
        }

        while(count[i] > 0){
            palindrome[left++] = i + 'A';
            palindrome[right--] = i + 'A';
            count[i] -= 2;
        }
    }
    cout << palindrome << endl;
    return 0;
}