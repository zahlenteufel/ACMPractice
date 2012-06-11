#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define forn(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long tint;

vector<int> pol; // [c_d, c_d-1, ..., c_0] = c_d X^d + .... + c_0
int f[2][900];
tint evalcache[900];

tint evalpol(int x) { // Horner's Rule... evaluate P(n*x) modulo 1000000007, pre: |pol| > 0
    tint res = pol[0];
    for (int i=1;i<int(pol.size());++i)
        res = (res * x + pol[i]);
    return res % 1000000007;
}

int calcf(int m, int n, int x) {
    for (int j=0;j<=n;j++)
        f[1][j] = evalcache[j] = evalpol(j * x);

    for (int i=2;i<=m;i++) {
        f[i%2][0] = (f[(i-1)%2][0] * evalcache[0]) % 1000000007;
        for (int j=1;j<=n;j++) {
            tint sum = 0;
            for (int k=0;k<=j;k++)
                sum = (sum + evalcache[k] * f[(i-1)%2][j-k]) % 1000000007;
            f[i%2][j] = sum;
        }
    }

    return f[m%2][n];
}

int main(){
    #ifdef ACM
        freopen("test.in", "r", stdin);
    #endif

    int t, m, n, d, x;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d %d", &m, &n, &x, &d);

        pol = vector<int>(d+1);
        forn (i,d+1)
            scanf("%d", &pol[d-i]);

        printf("%d\n", calcf(m, n, x));
    }

    return 0;
}
