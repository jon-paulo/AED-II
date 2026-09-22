#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
1. Você possui uma fita de comprimento m e deseja cortá-la em vários (0 ou mais) pedaços de tamanho
a, b ou c (onde a, b, c, m ∈ N∗ e a < b < c < m). Elabore um algoritmo de complexidade de tempo
e espaço O(m) que determine uma tripla ótima (na, nb, nc) que indique quantidades de pedaços
de cada tamanho que, caso obtidas, maximizem o total de pedaços obtidos. Em outras palavras,
(na, nb, nc) é uma configuração que maximiza a expressão na + nb + nc respeitando a restrição
de que a · na + b · nb + c · nc = m. Caso mais de uma configuração (na, nb, nc) seja uma tripla
ótima, seu algoritmo pode retornar qualquer uma delas. Seu algoritmo deve indicar ainda caso não
seja possível realizar um corte conforme desejado. Para exemplificar, quando m = 6, a = 1, b = 3 e
c = 4, uma tripla ótima seria (na, nb, nc) = (0, 2, 0). Já quando m = 12, a = 2, b = 3 e c = 5, uma
tripla ótima seria (na, nb, nc) = (1, 0, 2). Por fim, no caso de m = 6, a = 3, b = 4 e c = 5, não é
possível obter um configuração de corte com as medidas desejadas.

Ficou bem confuso se o exercicio pedia o maximo de pedaços ou minimo, eu fiz o minimo mas é facil converter pra maximo
*/


int MinPed(int m, int a, int b, int c, vector<int>& E, vector<int>& M) {
    if (m < 0) return 1000000; 
    if (m == 0) return 0;      
    
    if (M[m] != -1) return M[m];

    int opcaoA = MinPed(m - a, a, b, c, E, M);
    int opcaoB = MinPed(m - b, a, b, c, E, M);
    int opcaoC = MinPed(m - c, a, b, c, E, M);

    int menor = min({opcaoA, opcaoB, opcaoC});

    if (menor == opcaoA) {
        E[m] = a;
    } else if (menor == opcaoB) {
        E[m] = b;
    } else if (menor == opcaoC) {
        E[m] = c;
    }

    M[m] = menor + 1;
    return M[m];
}

int main() {
    int m = 7, a = 4, b = 5, c = 6;
    vector<int> M(m + 1, -1);
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
