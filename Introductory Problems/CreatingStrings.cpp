#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    // Take input string
    string s;
    cin >> s;

    //int len = s.size();
    sort(s.begin(), s.end());
    // Finding all permutations of input string
    vector<string> perm;
    do{
        perm.push_back(s);
    }while(next_permutation(s.begin(), s.end()));
    // Print number of permutations
    cout << perm.size() << endl;
    // Print all permutations
    for (string p : perm){
        cout << p << endl;
    }
    return 0;
}