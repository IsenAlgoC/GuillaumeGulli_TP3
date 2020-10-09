#include <stdio.h>
#include <stdlib.h>
#include <Math.h>
#define NBMAXNOTES 30

int main() {
	float note[NBMAXNOTES] = { -2 };
	int i = 0;
	float n = 0;
	int absent = 0;
	char r;
	float moyenne = 0;
	float total = 0;
	int compteur = 0;
	float max = 0;
	float min = 20;
	int j = 0;
	int valide = 0;
	int k = 0;

	for (i = 0; i < 30; i++) {
		printf("\n Entrer la note no [%d] : ", i + 1);
		scanf_s("%f", &n);
		if (n < 0 || n>20) {
			printf("Eleve absent ? ou voulez-vous arreter la saisie des notes?A/O/N : ");
			r = _getch();
			switch (r)
			{
			case 'A':
				absent++;
				note[i] = -1;
				break;
			case 'N':
				printf("\n Ressaisir la valeur: ");
				scanf_s("%f", &n);
				compteur = compteur + 1;
				note[i] = n;
				valide = valide + 1;
				break;
			case 'O':
				i = NBMAXNOTES;
				break;
			default:
				printf("Error");
				break;
			}
		}
		else{
			valide = valide + 1;
			note[i] = n;
			compteur = compteur + 1;
		}
	}
	
	for (j = 0; j < NBMAXNOTES; j++) { 
		if (note[j] == -2) { 
			break; 
		} 
		if (note[j] != -1 && note[j] != -2) {
			total = total + note[j];
		}
	}

	for (k = 0; k < NBMAXNOTES; k++) {
		if (note[k] > 0) {
			if (max < note[k]) {
				max = note[k];
			}
			if (min > note[k]) {
				min = note[k];
			}
		}
	}
	
	moyenne = total / compteur;
	printf("\nLe nombre de note valide : %d \nLe nombre d'absent : %d \n", valide, absent);
	printf("La moyenne des notes : %0.2f \nLa note min : %f \nLa note max : %f", moyenne, min, max);

	float somme = 0;
	float puissance = 0;
	for (int k = 0; k < NBMAXNOTES; k++) {
		if (note[k] == -2) {
			break;
		}
		if (note[k] != -1 && note[k] != -2) {
			puissance = powf((note[k] - moyenne), 2);
			somme = somme + puissance;
		}
	}
	float ecarttype = 0;
	ecarttype = somme / (valide - 1);
	ecarttype = sqrtf(ecarttype);
	printf("\nEcart-type : %f\n", ecarttype);
}