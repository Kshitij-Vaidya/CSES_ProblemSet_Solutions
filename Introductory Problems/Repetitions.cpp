#include<iostream>
#include<string>

using namespace std; 

int main() {
    string s;
    cin >> s;
    int max = 1, count = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            count++;
            if (count > max)
            {
                max = count;
            }
        }
        else
        {
            count = 1;
        }
    }
    cout << max;
    return 0;
}