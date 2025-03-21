// 1476: 날짜 계산 (실버5/브루트포스)
#include <iostream>

using namespace std;

int solve(int earth, int sun, int moon)
{
    if (earth == 15) // 지구가 15면 0으로 바꾸어준다.
        earth = 0;
    if (sun == 28) // 해가 28면 0으로 바꾸어준다.
        sun = 0;
    if (moon == 19) // 달이 19면 0으로 바꾸어준다.
        moon = 0;
    // 행성의(지구, 태양, 달) 범위에 해당하면 0으로 바꾸어준다.
    // 아래 비교문에서 mod 연산을 사용했기 때문에 이를 고려한다.

    int year = 1; // year(실제 년도를 선언한다.)
    while (true)
    {
        if (year % 15 == earth && year % 28 == sun && year % 19 == moon)
        {
            // 실제 년도를 15로 나눈 나머지가 지구와 같고, 28로 나눈 나머지가 해와 같고, 달로 나눈 나머지가 19와 같을 때
            return year; // 년도를 반환한다.
        }
        year++; // 아니면 년도를 올려가며 계산하기.
    }
}

int main()
{
    // 입력
    int e, s, m;
    cin >> e >> s >> m; // 지구, 해, 달 입력받기.

    cout << solve(e, s, m); // 함수를 호출하여 연산 후 출력하기.

    return 0;
}