#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct person {
    int d;
    int h;
    int row; 
    int col;
};

struct cmp {
    bool operator()(person a, person b) {
        if(a.d !=b.d){
            return a.d < b.d; // 높으면 먼저
        }
        if(a.h !=b.h){
            return a.h < b.h; // 높으면 먼저
        }
        return a.row > b.row;
    }
};

int main(){
    int n, m, k;
    int cnt =0;

    cin >> n >> m >> k;

    vector<queue<person>> lines(m);
    int d, h;
    

    for(int i = 0;i<n;i++){
        cin >> d >> h;
        lines[i%m].push({d,h,i%m,i});

    }

    priority_queue<person, vector<person>, cmp> pq;
    
    for (int i = 0; i < m; ++i) {
        if (!lines[i].empty()) { // 비어있지 않으면
            pq.push(lines[i].front()); // 맨 앞줄에 있는 사람만 가져간다.
            lines[i].pop();
        }
    }
    // 순서 찾기.
    int order = 0;
    while (!pq.empty()) { //pq가 빌 때까지 반복복
        person curr = pq.top(); 
        pq.pop();
        // k이면 데카이므로 출력.
        if (curr.col == k) {
            cout << order <<"\n";
            break;
        }

        if (!lines[curr.row].empty()) {
            pq.push(lines[curr.row].front());
            lines[curr.row].pop();
        }
        order++;
    }


    return 0;
}