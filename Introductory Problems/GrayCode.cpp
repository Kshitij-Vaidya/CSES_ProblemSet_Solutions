#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> grayCode(int n){
    if(n == 1){
        vector<string> v;
        v.push_back("0");
        v.push_back("1");
        return v;
    }
    else{
        vector<string> s = grayCode(n-1);
        // Make a copy of the string 
        vector<string> s1 = s;
        // Add 0 to the front of one string, 1 to the front of the other
        // The second string is reversed and appended to the first string
        for(int i = 0; i < s1.size(); i++){
            s1[i] = '1' + s1[i];
            s[i] = '0' + s[i];
        }
        for(int i = s1.size()-1; i >= 0; i--){
            s.push_back(s1[i]);
        }
        return s;
    }
}



int main(){
    int n;
    cin >> n;
    vector<string> s = grayCode(n);
    for (auto &s : s){
        cout << s << endl;
    }
    return 0;
}