#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>

#define forn(i, n) for(int i = 0; i < (n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define forall(i, c) for(typeof(c)::iterator i = c.begin(); i != c.end(); i++)
#define isIn(x, c) c.find(x) != c.end()
#define mostrar(x) cout<< #x <<" "<<x<<endl;

using namespace std;

struct st {
    bool cte;
    char c;
    st *left;
    st *right;

    st() {
        cte = false;
        left = right = NULL;
    }

    ~st() {
        delete left;
        delete right;
    }
};

void printST(st* s) {
    if (s->cte) {
        cout << s->c;
    } else {
        if (s->c=='+') {
            printST(s->left);
            cout << '+';
            printST(s->right);
        } else { // '*'
            if (s->left->c=='+') {
                cout << '(';
                printST(s->left);
                cout << ')';
            } else
                printST(s->left);
            if (s->right->c=='+') {
                cout << '(';
                printST(s->right);
                cout << ')';
            } else
                printST(s->right);
        }
    }
}

st* cte(char c) {
    st* res = new st;
    res->cte = true;
    res->c = c;
    return res;
}

int matchParIndex(char* s, int n) {
    int cantParAb = 0;
    forsn (i,1,n) {
        if (s[i]=='(')
            cantParAb++;
        else if (s[i]==')') {
            if (cantParAb==0)
                return i;
            else
                cantParAb--;
        }

    }
    return -1;
}

int subexpEnd(char * s, int n) {
    if (s[0]=='(')
        return matchParIndex(s,n)+1;
    else
        return 1;
}

int termEnd(char* s, int n) {
    forn (i,n) {
        if (s[i]=='(')
            i+=matchParIndex(s+i,n-i);
        else if (s[i]=='+')
            return i;
    }
    return n;
}

void printc(char* s, int n) {
    forn (i,n)
        cout << s[i];
}

st* parse(char* s, int n) {
//    cout << "parse \"";
//    forn (i,n)
//        cout << s[i];
//    cout << '\"' << endl;
    char c = s[0];
    if (n==1)
        return cte(c);

    // ((expression))

    if (c=='(' && matchParIndex(s,n) == n-1) {
        return parse(s+1,n-2);
    }

    st* res = new st;
    int f = termEnd(s,n);
    if (f == n) {
        res->c = '*';
        int k = subexpEnd(s,n);
//        printc(s,k);
//        cout << endl;
//        printc(s+k,n-k);
//        cout << endl;
//        return NULL;
        res->left = parse(s,k);
        res->right = parse(s+k,n-k);
    }
    else {
        res->c = '+';
//        printc(s,f);
//        cout << endl;
//        printc(s+f+1,n-f-1);
//        cout << endl;
        res->left = parse(s,f);
        res->right = parse(s+f+1,n-f-1);
    }
    return res;
}

int main(){
//    #ifdef ACM
//        freopen("test.in", "r", stdin);
//    #endif

    string is;
    char s[1010];
    while (cin >> is) {
        memcpy(s,is.c_str(),1000);
        st* sintaxTree = parse(s,is.size());
        printST(sintaxTree);
        delete sintaxTree;
        cout << endl;
    }

    return 0;
}
