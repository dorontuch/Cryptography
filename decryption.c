#include "Header.h"

// D3(y) = ( y * ( key^3 + 2*key )^-1 ) % M
char* door_decryption(char* ctext, int** key) {
	char* pText, * pTextTemp;
	char ch;
	int temp[N];
	int i, j, k, len, val;

	len = strlen(ctext);
	assert(pTextTemp = (char*)malloc(sizeof(char) * len + 1));
	pText = pTextTemp;
	while (*ctext) {
		for (i = 0; i < N && *ctext; i++) {
			temp[i] = *ctext - 'a';
			ctext++;
		}
		k = i;
		for (i = 0; i < k; i++, pTextTemp++) {
			for (j = 0, val = 0; j < k; j++) {
				val += (key[j][i] * temp[i]);
			}
			val %= M;
			*pTextTemp = (val + 'a');
		}
	}
	*pTextTemp = '\0';

	return pText;
}