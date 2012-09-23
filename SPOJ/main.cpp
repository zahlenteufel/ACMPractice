#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define forn(i, n) for(int i = 0; i < (n); i++)

using namespace std;

bool finDice[6] = {false,false,false,false,false,false};
bool tmp[5];
int fleas[4][4];

void moveDice(bool* fD, int move) {
    copy(tmp, tmp+5, fD);
    if (move==0) {        // N
        fD[0] = tmp[4];
        fD[4] = tmp[5];
        fD[5] = tmp[0];
    } else if (move==1) { // E
        fD[1] = tmp[0];
        fD[0] = tmp[2];
        fD[2] = tmp[3];
        fD[3] = tmp[1];
    }
    else if (move==2) {   // S
        fD[4] = tmp[0];
        fD[5] = tmp[4];
        fD[0] = tmp[5];
    }
    else {                // O
        fD[0] = tmp[1];
        fD[2] = tmp[0];
        fD[3] = tmp[2];
        fD[1] = tmp[3];
    }
}

int

int main(){
    #ifdef ACM
        freopen("test.in", "r", stdin);
    #endif

    int N;
    cin >> N;
    while (cin-->0) {
        int curx, cury;
        forn(y,4) {
            forn(x,4) {
                char c;
                cin >> c;
                if (c=='.')
                    fleas[y][x] = 0;
                else if (c=='X')
                    fleas[y][x] = 1;
                else {
                    fleas[y][x] = 0;
                    curx = x;
                    cury = y;
                }
            }
        }

    }

    return 0;
}
