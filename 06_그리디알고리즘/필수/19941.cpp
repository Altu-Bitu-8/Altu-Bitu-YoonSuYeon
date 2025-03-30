#include <iostream>
#include <vector>

using namespace std;

int canEatHamburger(vector<char> &arr,int length){
    vector<int> cnt(arr.size(),0);
    int answer=0;

    // 사람은 -1, 햄버거는 0
    for(int i=0;i<arr.size();i++){
        if(arr[i]=='P'){
            cnt[i]= -1;
        }
        else if(arr[i]=='H'){
            cnt[i]= 1;
        }
        else{
            cnt[i] =0;
        }

    }

    for(int i=0;i<cnt.size();i++){
            for(int k = length;k>0;k--){
                if(cnt[i-k]== 1 && cnt[i] ==-1){
                    cnt[i-k] =0;
                    cnt[i] = 0;
                    answer++;
                    //cout << "debug:" << answer <<"\n";
                    continue;
                }
            }
            for(int k = 1;k<=length;k++){
                if(cnt[i+k]== 1 && cnt[i] ==-1){
                    cnt[i+k] =0;
                    cnt[i] = 0;
                    answer++;
                    //cout << "debug:" << answer <<"\n";
                    continue;
                }
            }
        }
    return answer;
    
}

int main(){
    int desk_length, ham_length;
    // 입력
    cin >> desk_length >> ham_length;

    vector <char> arr(desk_length, 0);

    for (int i =0;i<desk_length;i++){
        cin >> arr[i];
    }
    // 계산및출력
    cout << canEatHamburger(arr, ham_length);

    return 0;
}