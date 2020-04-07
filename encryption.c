#include "Header.h"

// x3 = ( ( key^3 + 2*key ) * x0 ) % M
char* door_encryption(char* ptext, int** key) {
	char* cText, * cTextTemp;
	char ch;
	int temp[1][N];
	int i, j, len, val, k;
	Boolean even = False;

	len = strlen(ptext);
	assert(cTextTemp = (char*)malloc(sizeof(char) * len + 1));
	cText = cTextTemp;
	while (*ptext) {
		for (i = 0; i < N && *ptext; i++) {
			temp[0][i] = *ptext - 'a';
			ptext++;
		}
		even = i % N ? True : False;
		k = i;
		for (i = 0; i < k; i++, cTextTemp++) {
			for (j = 0, val = 0; j < k; j++) {
				val += (key[i][j] * temp[0][j]);
			}
			val %= M;
			*cTextTemp = (val + 'a');
		}
	}
	*cTextTemp = '\0';

	return cText;
}