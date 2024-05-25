#include<iostream>
#include<vector>

using namespace std;

void towerOfHanoi(int n, int a, int b, int c){
    if (n == 1){
        cout << a << " " << c << endl;
    }
    else{
        towerOfHanoi(n-1, a, c, b);
        cout << a << " " << c << endl;
        towerOfHanoi(n-1, b, a, c);
    }
}

int main(){
    int n;
    cin >> n;
    // Print minimum number of moves required
    cout << (1<<n) - 1 << endl;
    towerOfHanoi(n, 1, 2, 3);
    return 0;
}