#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define forn(i, n) for(int i = 0; i < int(n); i++)

using namespace std;

struct trie {

    pair<int,trie*> letters[26];

    trie() {
        forn (i,26) {
            letters[i].first = 0;
            letters[i].second = NULL;
        }
    }

    ~trie() {
        forn (i,26)
            delete letters[i].second;
    }

    void insert(char s[], int k) {
        if (k>0) {
            int i = s[0] - 'a';
            if (letters[i].second == NULL)
                letters[i].second = new trie;
                
            if (k==1)
				letters[i].first++;
			else
                letters[i].second->insert(s+1,k-1);
        }
    }
    
    int lengthNonDecreasingBranch(int i) {
		int val = letters[i].first;
		trie* cursor = letters[i].second;
		int count = 1;
		while (1) {
			int nxt = cursor->next();
			if (nxt == -1 || cursor->letters[nxt].first < val)
				break;
			count++;
			cursor = cursor->letters[nxt].second;
		}
		return count;
	}
	
	int maxInd(int maxRootValue) {
		int res, maxLength = 0;
		forn (i,26) {
			if (letters[i].second != NULL && letters[i].first == maxRootValue) {
				int l = lengthNonDecreasingBranch(i);
				if (l > maxLength) {
					maxLength = l;
					res = i;
				}
			}
		}
		return res;
	}
	
	int next() {
		forn (i,26)
			if (letters[i].second != NULL)
				return i;
		return -1;
	}

    void printTrie() {
        bool isLeaf = true;
        forn (i,26) {
            if (letters[i].second != NULL) {
                isLeaf = false;
                cout << "  " << letters[i].first << " " << char('a' + i);
                letters[i].second->printTrie();
            }
        }
        if (isLeaf)
            cout << endl;
    }
    
    void printMaxBranch() {
		int m = 0, nxt;
		forn (i, 26)
			m = max(letters[i].first, m);
			
		nxt = maxInd(m);
    
		int val = letters[nxt].first;
		trie* cursor = letters[nxt].second;
		while (1) {
			cout << char(nxt + 'a');
			nxt = cursor->next();
			if (nxt == -1 || cursor->letters[nxt].first < val)
				break;
			cursor = cursor->letters[nxt].second;
		}
	}
};

int main(int agrc, char* argv[]){
	int n = strlen(argv[1]);
    trie t;
    for (int sz=1;sz<=n;sz++)
        forn (i,n-sz+1)
            t.insert(argv[1]+i,sz);
    
    //t.printTrie();
    //t.printMaxBranch();
    cout << endl;

    return 0;
}
