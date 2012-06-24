#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define forn(i, n) for(int i = 0; i < (n); i++)
#define forall(i, c) for(typeof(c)::iterator i = c.begin(); i != c.end(); i++)
#define isIn(x, c) c.find(x) != c.end()
#define mostrar(x) cout<< #x <<" "<<x<<endl;

#define INF 10000
#define tam 26

using namespace std;

vector<vector<int> > distsY;
vector<vector<int> > distsM;

int let2ind(char l) {
    return l - 'A';
}

char ind2let(int n) {
    return n + 'A';
}

int main(){
    #ifdef ACM
        freopen("test.in", "r", stdin);
    #endif

    int N;
    while (cin >> N && N>0) {
        distsM = vector<vector<int> >(tam,vector<int>(tam,INF));
        distsY = vector<vector<int> >(tam,vector<int>(tam,INF));
        forn (i,N) {
            char tipoGrafo, direccion, nodo1, nodo2;
            int energy;
            cin >> tipoGrafo >> direccion >> nodo1 >> nodo2 >> energy;
            if (tipoGrafo=='Y') {
                distsY[let2ind(nodo1)][let2ind(nodo2)] = energy;
                if (direccion=='B')
                    distsY[let2ind(nodo2)][let2ind(nodo1)] = energy;
            } else {
                distsM[let2ind(nodo1)][let2ind(nodo2)] = energy;
                if (direccion=='B')
                    distsM[let2ind(nodo2)][let2ind(nodo1)] = energy;
            }
        }

        forn (i, tam) {
            distsY[i][i] = 0;
            distsM[i][i] = 0;
        }

        forn (k,tam)
            forn (i,tam)
                forn (j,tam) {
                    distsY[i][j] = min(distsY[i][j], distsY[i][k] + distsY[k][j]);
                    distsM[i][j] = min(distsM[i][j], distsM[i][k] + distsM[k][j]);
                }

        char nodoMio, nodoMiguel;
        cin >> nodoMio >> nodoMiguel;

        vector<int> distTot(tam,INF);
        forn (i,tam)
            if (distsY[let2ind(nodoMio)][i]!=INF && distsM[let2ind(nodoMiguel)][i] != INF)
                distTot[i] = distsY[let2ind(nodoMio)][i] + distsM[let2ind(nodoMiguel)][i];

        int minDist = INF;
        forn (i,tam)
            minDist = min(minDist, distTot[i]);

        if (minDist==INF)
            cout << "You will never meet." << endl;
        else {
            cout << minDist;
            forn (i,tam) {
                if (distTot[i]==minDist)
                    cout << " " << ind2let(i);
            }
            cout << endl;
        }

    }

    return 0;
}
