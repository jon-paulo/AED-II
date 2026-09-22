#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void MinPedBottomUp(int m, int a, int b, int c, vector<int>& E, vector<int>& M) {
    M[0] = 0; 

    for (int i = 1; i <= m; i++) {
        if (i - a >= 0 && M[i - a] + 1 < M[i]) {
            M[i] = M[i - a] + 1;
            E[i] = a;
        }
        if (i - b >= 0 && M[i - b] + 1 < M[i]) {
            M[i] = M[i - b] + 1;
            E[i] = b;
        }
        if (i - c >= 0 && M[i - c] + 1 < M[i]) {
            M[i] = M[i - c] + 1;
            E[i] = c;
        }
    }
}

int main() {
    int m = 7, a = 4, b = 5, c = 6;
    
    vector<int> M(m + 1, 1000000);
    vector<int> E(m + 1, -1);

    MinPed(m, a, b, c, E, M);

    if (M[m] < 1000000) {
        int na = 0, nb = 0, nc = 0;
        int atual = m;
        
        while (atual > 0) {
            if (E[atual] == a) na++;
            else if (E[atual] == b) nb++;
            else if (E[atual] == c) nc++;
            
            atual = atual - E[atual]; 
        }
        
        cout << "(" << na << ", " << nb << ", " << nc << ")" << endl;
    } else {
        cout << "Não é possível obter uma configuração de corte." << endl;
    }

    return 0;
}
