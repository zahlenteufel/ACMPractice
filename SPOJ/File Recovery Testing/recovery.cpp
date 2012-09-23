//~ 
//~ http://www.spoj.pl/problems/FILRTEST/
//~ 
#include <cstdio>
#include <cstring>

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

using namespace std;

char s[1000100];
int arr[1000100];

int main() {
	//freopen("test.in", "r", stdin);
	int L;
	while (scanf("%d %s\n", &L, s)==2 && L!=-1) {
		arr[0] = 0;
		int n = strlen(s);
		forsn(i,1,n) {
			if (s[i]==s[arr[i-1]])
				arr[i] = arr[i-1] + 1;
			else
				arr[i] = 0;
		}
		int res = 0;
		if (n > L) {
			res = 0;
		} else if (arr[n-1] > n/2) {
			res = L;
		} else {
			if (n > L) {
				res += 1;
				L -= n;
			}
			int k = n - arr[n-1];
			res += L / k;
		}
		printf("%d\n", res);
	}
	return 0;
}
