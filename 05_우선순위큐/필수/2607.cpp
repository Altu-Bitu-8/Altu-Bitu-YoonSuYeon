#include <iostream>
#include <vector>

using namespace std;


bool cmpSimilarity(string std, string word){
    vector<int> array(26, 0);

    int size = std.size();
    int cmpsize = word.size();
    int del=0, add=0;
    
    // 2글자 이상 차이나면 아님.
    if((abs(size-cmpsize))>1) return false;

    // 기준 단어는 +, 비교 단어는 -
    for(char ch : std) array[ch-'A']++;
    for(char ch : word) array[ch-'A']--;

    // DEL = 단어가 삭제된 것,ADD = 단어가 추가된 것
    for(int i =0;i < 26;i++){
        if(array[i] ==1) {
            del++;
        }
        else if(array[i]==-1) {
            add++;
        }
        else if (!(array[i]==1 || array[i] == -1 || array[i]==0))
            return false;
    }
    // 대체, 삭제, 추가, 똑같을 경우 true
    if((del == 1 && add ==1) || (del == 1 && add == 0)|| (del == 0 && add == 1)|| (del == 0 && add == 0))
        return true;
    
    // 그 외 0
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);


    int n,cnt = 0;
    string x;
    
    cin >> n;
    
    vector<string> words(n);
    
    for(int i =0;i<n;i++){
        cin >> words[i];
    }


    for(int i =1;i<n;i++){
        if(cmpSimilarity(words[0], words[i]))
                cnt++;
    }

    cout << cnt;

    return 0;
}