#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned int n = 2868838400;
	int bit, i, octet;
	octet = sizeof(n);
	bit = octet * 8;
	printf("n est code sur %d octet \n", octet);
	printf("n est code sur %d bit \n", bit);

	for (i = 0; i < bit; i++) {
		if (n & (1 << i)) {
			printf("%d: ON \n", i);
		}
		else {
			printf("%d: OFF \n", i);
		}
	}
	printf("Bye ! ");
}