#include <stdio.h>
#include <stdlib.h>

/*
1. Dados dois inteiros n e k, elabore um algoritmo de backtracking que gere todas as sequências
binárias de comprimento n que possuam exatamente k posições contendo 1 e não possuam dois 1’s
consecutivos. Por exemplo, para n = 5 e k = 2, a sequência 10100 é uma solução, mas 11000 não
é. Seu algoritmo deve ser ótimo, isto é, sua complexidade de tempo assintótica deve ser Θ(f(n, k)),
onde f(n, k) é a quantidade de sequências binárias válidas a serem geradas.
*/


void BinK(int n, int k, int b[], int d){
	if (d > n-1 && k == 0){
		printf("(");
		for(int i = 0; i < d; i++){
			if(i == d-1){
				printf("%d", b[i]);
			} else {
				printf("%d,", b[i]);
			}
		}
		printf(")");
		return;
	}
	int ant;
	d == 0? ant = 0: ant = b[d-1];
	if ((ant && 2*k > (n-d)) || (!ant && (2*k)-1 > (n-d))) return;
	
	for(int i = 0; i < 2; i++){
		if(!ant && i == 1 && k > 0){
			b[d] = i;
			BinK(n, k-1, b, d+1);
		}else if(i == 0){
			b[d] = i;
			BinK(n, k, b, d+1);
		}
	}
}

int main() {
	int n = 15; 
	int k = 8;
	int b[n];
	BinK(n,k,b,0);
}
