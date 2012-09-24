//~ 
//~ http://www.spoj.pl/problems/FILRTEST/
//~ 
#include <cstdio>
#include <cstring>
#include <iostream>

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

using namespace std;

char s[1000100];
int arr[1000100];

int main() {
	freopen("test.in", "r", stdin);
	int L;
	while (scanf("%d %s\n", &L, s)==2 && L!=-1) {
		arr[0] = 0;
		int n = strlen(s);
		int res = 0;
		
		if (n > L)
			res = 0;
		else if (n==L)
			res = 1;
		else if (n==1)
			res = L;
		else { // n < L
			int j = 0;
			int i = 1;
			while( i < n ){
				if(s[j] == s[i])
					arr[i++] = ++j;
				else if(j>0)
					j = arr[j-1];
				else
					arr[i++] = 0;
			}
			if (arr[n-1] > 0) {
				res ++;
				L -= n;
			}
			res += (L / (n - arr[n-1]));
		}
		printf("%d\n", res);
	}
	return 0;
}
