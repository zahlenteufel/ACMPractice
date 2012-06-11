#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)

int abs(int n) {
	return (n < 0) ? -n : n;
}

#define N 1000000

vector<bool> esPrimo(N,true);

void calcPrimos() { // eratostenes
	for (int i=2;i<N;i++)
		if (esPrimo[i])
			for (int k=2*i;k<N;k+=i)
				esPrimo[k] = false;
}

vector<int> factorizar(int n) {
	vector<int> res;
	int sqrn = sqrt(n);
	while (n%2==0) {
        res.push_back(2);
        n >>= 1;
	}
	for (int i=3;i<=sqrn;i+=2) {
		if (esPrimo[i]) {
			while (n%i==0) {
				res.push_back(i);
				n /= i;
			}
		}
	}
	if (n>1)
        res.push_back(n);
	return res;
}

int fzaBruta(int n) {
    int m = 1000000000;
		for (int k=1;k<=n;k++)
			if (n%k==0) {
//			    if (abs(n/k - k) < m) {
//                    cout << "k nuevo " << k << endl;
//			    }
				m = min(m, abs(n/k - k));
			}
    return m;
}

void printvec(vector<int>& v) {
	forn (i,v.size())
		cout << v[i] << " ";
	cout << endl;
}

int main() {
	int t, n;
	calcPrimos();
	cin >> t;
	forn (i,t) {
		cin >> n;
		if (n==1)
            cout << "0" << endl;
        else {
            vector<int> facts = factorizar(n);
            //printvec(facts);
            if (facts.size()==1) // si es primo..
                cout << facts[0] - 1 << endl;
            else {
                int c = (1 << int(facts.size())) - 1;
                int res = 100000000;
                for (int m = 1; m <= c; m++) {
                    int k = m;
                    //cout << "m" << m << endl;
                    // a partir de la mascara computar la 'cuadratura'
                    int f1, f2;
                    f1 = f2 = 1;
                    forn (j, facts.size()) {
                        if (m & (1<<j))
                            f1 *= facts[j];
                        else
                            f2 *= facts[j];
                    }
                    //cout << f1 << " x " << f2 << " diff " << abs(f1-f2) << endl;
                    res = min(res, abs(f1-f2));
                }
//                int fza = fzaBruta(n);
//                if (res != fzaBruta(n)) {
//                    cout << "error en " << n << " fza bruta = " << fza << " != " << res << endl;
//                    return 1;
//                }
                cout << res << endl;
            }
        }
    }
	return 0;
}
