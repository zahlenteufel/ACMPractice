#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>
#include <cstring>

#define forn(i,n) for(int i=0;i<int(n);++i)

using namespace std;

const int M = 100100;
char  s[M];
int arr[M];

int main() {
    #ifdef ACM
//        freopen("entrada.in","r",stdin);
    #endif

    init_criba();

    while (scanf("%s\n",s)==1 && s[0] != '*') {
        //kmp
        int i, j, n;
        n = strlen(s);
        i = 0;
        j = arr[0] = -1;
        while (i < n) {
            while (j>-1 && s[i] != s[j])
                j = arr[j];
            arr[++i] = ++j;
        }
        if (n % (n - arr[n]) != 0)
            cout << "1" << endl;
        else
            cout << n / (n - arr[n]) << endl;
    }

    return 0;
}
