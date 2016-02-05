/* Aufgabe 1
 *
 * Erweitern Sie den Cäsar-Chiffre um die Fähigkeit, auch Großbuchstaben zu
 * verschlüsseln.
 */

// 5 Punkte

#include <stdio.h>

#define MAX 100
#define N 26

char imsg[MAX]; // plaintext
char omsg[MAX]; // ciphertext

void cipher(int shift) {
	int i, c;

	for (i = 0; imsg[i]; i++) {
		c = imsg[i];
		if (c >= 'a' && c <= 'z')
			omsg[i] = ((c - 'a') + shift) % N + 'a';
		else if (c >= 'A' && c <= 'Z')
			omsg[i] = ((c - 'A') + shift) % N + 'A';
		else
			omsg[i] = c;
	}
	omsg[i] = '\0';
}

int main() {
	int shift;

	printf("shift: ");
	scanf("%d", &shift);
	fflush(stdin);
	printf("imsg: ");
	fgets(imsg, sizeof(imsg), stdin);
	cipher(shift);
	printf("omsg: %s", omsg);
	return 0;
}
