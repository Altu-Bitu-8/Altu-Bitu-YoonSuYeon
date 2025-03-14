#include <iostream>

using namespace std;

int set = 0; // 전역변수로

void calculateSet(string cal){
    int num ;

    // 비트 마스킹 이용하기
    if(cal == "add"){
        cin >> num;
        set =set | (1<<(num-1));
    }
    else if (cal ==  "remove"){
        cin >> num;
        set =(set & ~(1<<(num-1)));
    }
    else if (cal == "check"){
        cin >> num;
        if(set & (1<<(num-1))) // num 번째 비트가 1인지 확인
            cout << "1\n";
        else
            cout << "0\n";
    }
    else if (cal == "toggle"){
        cin >> num;
        // XOR
        set = set ^ (1<<(num-1)); // 있으면 삭제하고, 없으면 추가
        
    }
    else if (cal == "all"){ // 1~20으로 바꾼다
        set = (1<< 20) -1;
        
    }
    else if (cal == "empty"){ // 공집합으로
        set = 0;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int m;
    cin >> m;
    string cal;

    for(int i = 0 ; i<m;i++){
        cin >> cal;
        calculateSet(cal);
        
    }

    return 0;
}