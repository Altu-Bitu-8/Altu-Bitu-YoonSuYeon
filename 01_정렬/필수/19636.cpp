#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int before_W, before_I, T;
    cin >> before_W >> before_I >> T;
    // 체중, 일일에너지 섭취량&기초 대사량, 역치
    int D, I, A;
    cin >> D >> I >> A;
    // 기간, 기간 일일 에너지 섭취량, 일일 활동 대사량

    int W1, W2, basic;
    W1 = before_W;
    W2 = before_W;
    // 체중 = 일일 에너지 섭취량 - (일일 기초 대사량 + 일일 활동 대사량)
    basic = before_I;

    for (int i =0 ; i<D ; i++){
        W1 += I - (before_I + A);
        W2 += I - (basic + A);
        // basic += (abs(I - ( basic + A)) > T) ? abs(I - ( basic + A))/2 : I - ( basic + A);
        if (abs(I - ( basic + A)) > T) {
            basic += (I - (basic + A))/2;
        }
        
        //cout << W2 << " " << basic << "\n";
    }
    // before Diet
    if (W1 <= 0 || before_I <= 0 ){
        cout << "Danger Diet\n";
    }
    else{
        cout << W1 << " " << before_I << "\n";
    }

    // during Diet
    if (W2 <= 0 || basic <= 0 ){
        cout << "Danger Diet\n";
    }
    else{
        cout << W2 << " " << basic << " ";
        if (before_I - basic > 0){
            cout << "YOYO\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
