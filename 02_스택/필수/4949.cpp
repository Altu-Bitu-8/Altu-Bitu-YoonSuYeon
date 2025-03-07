#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
int isBalance(string s){

    stack<char> sStack;
    bool result = true;

    for(int i = 0; i< s.length(); i++){
        if(s[i]=='(' || s[i] == '['){
            sStack.push(s[i]);
        }
        else if(s[i]==')'){
            if (sStack.empty() || sStack.top()=='['){
                result = false;
            }
            else {
                sStack.pop();
            }
        }
        else if(s[i] == ']'){
            if (sStack.empty() || sStack.top()=='('){
                result = false;
            }
            else {
                sStack.pop();
            }
        }
        else {
            continue;
        }
    }

    if (sStack.empty() && result == 1){
            cout << "yes\n";
    }
    else {
        cout << "no\n";
    }
    
    return 0;

}

int main(int argc, char const *argv[])
{
    while(true) {
        ios::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);

        string s;
        getline(cin, s);

        if(s.length()== 1 || s[0]=='.'){
            break;
        }
        isBalance(s);


    }
    
    return 0;
}
