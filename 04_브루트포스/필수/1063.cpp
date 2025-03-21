#include <iostream>
#include <vector>

using namespace std;


bool isOutOfRange(int col, int row){
    if(col <= 'A' || col >= 'H' || row <= '1'|| row >= '8')
        return false;
    else
        return true;
}

pair<string, string> getLocation(pair<string, string> king, string moving){

    // 끝에 있어서 못움직이는 경우 체크해야 함
    char col = king.first[0];
    char row = king.first[1];

    // king 의 움직임
    if (moving == "R") {
        if (col < 'H') 
            col++;
    } 
    else if (moving == "L") {
        if (col > 'A') 
            col--;
    } 
    else if (moving == "B") {
        if (row > '1') 
            row--;
    } 
    else if (moving == "T") {
        if (row < '8') 
            row++;
    } 
    else if (moving == "RT") {
        if (col < 'H' && row < '8') {
            col++;
            row++;
        }
    } 
    else if (moving == "LT") {
        if (col > 'A' && row < '8') {
            col--;
            row++;
        }
    } 
    else if (moving == "RB") {
        if (col < 'H' && row > '1') {
            col++;
            row--;
        }
    } 
    else if (moving == "LB") {
        if (col > 'A' && row > '1') {
            col--;
            row--;
        }
    }

    bool flag = true;
    // rock과 위치가 같으면.. (rock이 막고 있는 경우)
    if(king.second[0]== col && king.second[1]==row){
        if (moving == "R") {
            if (king.second[0] < 'H') 
                king.second[0]++;
            else
                flag = false; // 돌이 나가므로 king 움직일 수 없음.
        } 
        else if (moving == "L") {
            if (king.second[0] > 'A') 
                king.second[0]--;
            else
                flag = false;
        } 
        else if (moving == "B") {
            if (king.second[1] > '1') 
                king.second[1]--;
            else
                flag = false;
        } 
        else if (moving == "T") {
            if (king.second[1] < '8') 
                king.second[1]++;
            else
                flag = false;
        } 
        else if (moving == "RT") {
            if (king.second[0] < 'H' && king.second[1] < '8') {
                king.second[0]++;
                king.second[1]++;
            }
            else
                flag = false;
        } 
        else if (moving == "LT") {
            if (king.second[0] > 'A' && king.second[1] < '8') {
                king.second[0]--;
                king.second[1]++;
            }
            else
                flag = false;
        } 
        else if (moving == "RB") {
            if (king.second[0] < 'H' && king.second[1] > '1') {
                king.second[0]++;
                king.second[1]--;
            }
            else
                flag = false;
        } 
        else if (moving == "LB") {
            if (king.second[0] > 'A' && king.second[1] > '1') {
                king.second[0]--;
                king.second[1]--;
            }
            else
                flag = false;
        }

    }
    if (flag){
        // king 새로운 위치 업데이트
        king.first[0] = col;
        king.first[1] = row;
    }  
    
    return king;
}


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    pair<string, string> loc;
    int n;
    string moving;

    cin >> loc.first >> loc.second >> n;

    // 이동하는 위치 찾기
    for (int i =0 ; i<n ;i++){
        cin >> moving;
        loc = getLocation(loc, moving);
    }

    // 출력
    cout << loc.first << "\n" << loc.second << "\n";


    return 0;
}
