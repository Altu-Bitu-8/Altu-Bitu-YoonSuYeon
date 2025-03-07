#include <iostream>
#include <vector>

using namespace std;

int getGcd(int a, int b){
    // 유클리드 호제법.
    while(b != 0){
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, s;
    cin >> n >> s;
    vector<int> loc(n, 0);

    for (int i = 0; i < n; i++){
        cin >> loc[i];
        // s위치에서 절대적 거리로 변환.
        loc[i] = abs(loc[i]-s);

        //cout << loc[i] << " ";
    }
    // GCD
    int a = loc[0];
    for(int i = 1; i < n;i++) {
        a = getGcd(a, loc[i]);
       
    }
    cout << a << "\n";


    return 0;
}
