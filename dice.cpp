#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int H = 0, M = 1, S = 0, F = 1;
int pairs[6][2] = {
{9,  00},
{10, 40},
{12, 40},
{14, 20},
{16, 20},
{18, 00}};

int minutes (int hour, int minute) {
    for (int i = 5; i >= 0; --i){
        if (hour > pairs[i][H] or (hour == pairs[i][H] and minute >= pairs[i][M])) {
            int res = (hour-pairs[i][H])*60 + (minute - pairs[i][M]);
            if (res <= 90) return res;
        }
    }
    return -1;
}

string fortune_from(int dice, int hour, int minute) {
    int min = minutes(hour, minute);
    if (min == -1) return "BREAKTIME";
    if (min <= 15) return "YES DEFINITELY";
    return (dice > min) ? "YES" : "NO";
}

int main(void) {
    int h, m;
    if (h>20) {
        cout << "Hello world";
    }
    srand(time(NULL));
    std::cout << "a";
    cout << "Hours? "; cin >> h;
    cout << "Minutes? "; cin >> m;
    cout << fortune_from(rand()%91, h, m);
    return 0;
}

template <typename T>
T minimum(const T& lhs, const T& rhs)
{
    return lhs < rhs ? lhs : rhs;
}
