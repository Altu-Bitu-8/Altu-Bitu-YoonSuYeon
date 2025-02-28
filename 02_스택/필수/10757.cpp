#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int addNum(string A, string B) {
    string ans;

    int ALen, BLen, maxLen;
    ALen = A.length();
    BLen = B.length();
    maxLen = (ALen > BLen) ? ALen : BLen;
    
    if(ALen >= BLen){
        B = string(maxLen - BLen, '0') + B;
    }
    else {
        A = string(maxLen - ALen, '0') + A;
    }
    stack<int> calRes;
    int add, round = 0; // 올린 다음 자리 수

    for (int i = maxLen-1; i >= 0; i--) {
        add = (A[i] - '0') + (B[i]- '0') + round;
        calRes.push(add % 10);
        
        if (add / 10 != 0 ){ // 올린 다음 자리수가 있으면 저장
            round = add /10;
        }
        else {
            round = 0;
        }
        if(i== 0 && round !=0){ // 가장 높은 자리에서 올림 수가 있을 때
            calRes.push(round);
        }
    }
    while(!calRes.empty()){ // 가장 높은 자리부터 출력.
        cout << calRes.top();
        calRes.pop();
    }
    cout << "\n";
    
    return 0;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string A, B;

    cin >> A >> B;

    addNum(A, B);
    
    return 0;
}
