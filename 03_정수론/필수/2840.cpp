#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n, k; // 바퀴 칸 수, 돌리는 횟수
    cin >> n >> k;

    vector<char> wheel(n, '?');
    

    int change_num;
    char alpha;
    int target=0;
    bool flag = true;

    for(int i = 0; i<k; i++){
        cin >> change_num >> alpha;
        
        target = (target + change_num) % n;

        for(int j = 0; j < n;j++){
            if(j == target)
                continue;
            if (wheel[j]==alpha) {
                cout << "!\n";
                flag = false;
                break;
            }
        }

        if(wheel[target]!='?'){
            
            if (wheel[target]==alpha){
                continue;
            }
            cout << "!\n";
            flag = false;
            break;
        }
        wheel[target] = alpha;
        
    }
    // 시계방향으로 출력
    if (flag == true){
        for(int i = target; i >=0; i--){
            cout << wheel[i];
        }
        for(int i = n-1; i>target;i--){
            cout << wheel[i];
        }
        cout << "\n";
    }

    return 0;
}