#include <iostream>

using namespace std;

int getYear(int e, int s, int m){
    int year=e;
    // 15*a+e = 28*b+s = 19*c +m = year 을 찾아야 한다.
    // year%15 = e, year %28 = s, year %19 = m
    int flag = true;
    while(true){
        int mod_earth = year%15;
        int mod_sun = year %28;
        int mod_moon = year %19;


        if((mod_earth == e) && (mod_sun == s) && (mod_moon == m ))
            break;
        year++;

    }
    return year;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int earth, sun, moon;
    // 입력
    cin >> earth >> sun >> moon;

    int year;
    year = getYear(earth, sun, moon);

    cout << year << "\n";

    return 0;
}