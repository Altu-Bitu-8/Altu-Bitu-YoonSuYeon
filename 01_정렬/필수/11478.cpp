#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{

    string str, component;
    cin >> str;

    set<string> cnt;

    for(int i =0; i< str.size(); i++){
        for(int j=1; j<= str.size(); j++){
            component = str.substr(i,j); // 문자열 슬라이싱
            cnt.insert(component);
        }
    }

	// for (auto iter = cnt.rbegin(); iter !=cnt.rend(); iter++) {
	// 		cout << *iter << "\n";
	// }
    cout << cnt.size() << "\n";

    return 0;
}
