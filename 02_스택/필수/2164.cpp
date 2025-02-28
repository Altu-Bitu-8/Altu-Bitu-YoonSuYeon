#include <iostream>
#include <vector>
#include <queue>

#define MAX_SIZE 500000

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    
    queue<int> q;
    int front = 0;

    // 멘 마지막이 n이 올것임.
    for(int i = 1; i <= n;i++){
        q.push(i);
    }

    while(q.size()>1){
        q.pop();
        
        if(q.empty()){
            cout << "-1\n";
        }
        else{
            front = q.front();
            q.pop();         
            q.push(front);

        }
    }
    // size = 1일 때
    cout << q.front() << "\n";

    return 0;
}
