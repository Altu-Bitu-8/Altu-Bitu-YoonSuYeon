#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct isGreater {
    bool operator()(const int &child, const int &parent) {
        // 두 수 중 큰 수가 부모노드로
        return parent < child;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;

    cin >> n;

    vector<int> table = {n, 0};
    priority_queue<int, vector<int>, isGreater> pq; 

    for(int i = 0;i<n*n;i++){
        cin >> x;
        pq.push(x);

        if(pq.size() > n){
            pq.pop(); // 가장 작은 값 제거
        }
        
    }
    // n번째로 큰 수를 구하는 것이므로
    cout << pq.top() << "\n";

    return 0;

}