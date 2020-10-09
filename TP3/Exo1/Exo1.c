#include <stdio.h>
#include <stdlib.h>
#define carre(x) x * x

int main() {
	int nb = 5;
	int nbplus1 = nb + 1;
	int resultat = carre(nb);
	int resulta = carre(nbplus1);
	printf("le carre de nb est %d \n", resultat);
	printf("le carre de nbplus1 est %d \n", resulta);
}