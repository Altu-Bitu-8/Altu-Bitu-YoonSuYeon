#include <iostream>
#include <vector>
#include <cmath>

#define MAX_SIZE 1000001

using namespace std;

void isPrime(int n, vector<bool> &is_prime){
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<=sqrt(n);i++){
        if(is_prime[i] == false){ // i가 소수가 아니면 넘기기
            continue;
        }
        for(int j = i*i; j <=n;j+=i){
            is_prime[j] = false; // i 의 배수 제거
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n, test = 0;
    vector<bool> is_prime(MAX_SIZE, true);
    isPrime(MAX_SIZE, is_prime);
    bool flag = false;
    while(true){
        
        cin >> n;
        if(n == 0 || test++ == 100000){
            break;
        }
        
        for(int i = 2; i <=n/2; i++){
            if(is_prime[i]==true&&is_prime[n-i]==true){
                flag = true;
                cout << n << " = " << i << " + " << n-i << "\n";           
                break;
            }
        }
        if(!flag){
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    return 0;
}