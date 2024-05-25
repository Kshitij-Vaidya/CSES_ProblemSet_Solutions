#include<iostream>
#include<string>

using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin >> t;
    // Processing t queries
    while (t--){
        ll n;
        cin >> n;
        ll temp = 9;
        // Finding number of digits in the number
        ll digits = 1;
        while (n > temp * digits){
            n -= temp * digits;
            temp *= 10;
            digits++;
        }
        // Finding the number where the digit is present
        ll num = (n-1) / digits + temp / 9;
        // Finding the digit in the number
        int digit = n % digits;
        string s = to_string(num);
        /*
        if (digit == 0){
            cout << num % 10 << endl;
        }
        else{
            num++;
            for (int i = 0; i < digits - digit; i++){
                num /= 10;
            }
            cout << num % 10 << endl;
        }
        */
        if (digit == 0){
            cout << s.back() << endl;
        }
        else{
            cout << s[digit-1] << endl;
        }
    }
}