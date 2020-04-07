#include "Header.h"

// X = ( ( key^3 + 2*key ) * x0 ) % M

// D(y) = ( y * ( key^3 + 2*key )^-1 ) % M

void main() {
	char temp[256];
	char* palinText;
	char* cText;
	int** key;
	int** X, **Y;
	
	temp[0] = '\0';
	printf("please enter the key (4 letters): ");
	while (1) {
		scanf_s("%s", temp, (unsigned)_countof(temp));
		if (strlen(temp) != 4)
			printf("the key must be in length of 4 letters\nPlease enter again the key: ");
		else
			break;
	}
	key = allocateMatrix();
	if (createKeyMattrix(temp, key) == False ) {
		printf("The key is invalid\nExit program");
		exit(1);
	}
	X = createX(key);
	Y = allocateMatrix();
	if (invertibleMat(X, Y) == False) {
		printf("The Matrix is NOT invertible");
		exit(1);
	}
	
	temp[0] = '\0';
	printf("Enter the plain text: ");
	scanf_s("%s", temp, (unsigned)_countof(temp));

	//encrypt the text
	cText = door_encryption(temp, X);
	printf("\n----\nencrypt: %s\n----\n", cText);

	//decrypt the text
	palinText = door_decryption(cText, Y);
	printf("\n----\ndecrypt: %s\n----\n", palinText);
}