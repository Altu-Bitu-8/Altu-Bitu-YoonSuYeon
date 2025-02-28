#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string arr1, string arr2) {
    // 1. 글자 수 비교
    if (arr1.size() != arr2.size()){
        return arr1.size() < arr2.size();
    }
    
    // 2. 숫자 합 비교
    int num1=0, num2 = 0;
    for(int i = 0; i <arr1.size();i++){
        if (arr1[i] >= '0' && arr1[i] <= '9' ){
            num1 += int(arr1[i]) - '0';
        }

        if (arr2[i] >= '0' && arr2[i] <= '9' ){
            num2 += int(arr2[i]) - '0';
        }

    }
    if (num1 != num2) {
        return num1 < num2;
    }

    // 3. 알파벳 비교
    return arr1 < arr2;
}

int main()
{
    int n;

    cin >> n;

    vector<string> arr(n);
    vector<int> arr_len(n);

    for (int i =0; i < n; i++){
        cin >> arr[i];
        arr_len[i] = arr[i].size();
    }
   
    sort(arr.begin(), arr.end(), comp);

   
    for (int i = 0; i < n ; i++) {
        cout << arr[i] << "\n";
    }




    return 0;
}
