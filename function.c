#include "Header.h"


// key ^ -1
Boolean invertibleMat(int** key, int** invertMat) {
	int det, i, j, inverse, temp;
	det = key[0][0] * key[1][1];
	det = det - (key[0][1] * key[1][0]);

	det %= M;
	det = det < 0 ? det + M : det;
	for (i = 0; i < M; i++)
		if ((det * i) % M == 1)
			break;
	if (i == M)
		return False;
	inverse = i;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			temp = key[i][j] * inverse;
			temp %= M;
			invertMat[i][j] = temp;
		}
	temp = invertMat[0][0];
	invertMat[0][0] = invertMat[1][1];
	invertMat[1][1] = temp;

	temp = -1 * invertMat[1][0];
	invertMat[1][0] = -1 * invertMat[0][1];
	invertMat[0][1] = temp;

	return True;
}

void moduloMat(int** mat) {
	for (int i = 00; i < N; i++)
		for (int j = 0; j < N; j++)
			mat[i][j] %= M;
}

// x3 =  ( key^3 + 2*key )
int** createX(int** key) {
	int** res;
	int** cubKey;
	int** keyWithScalar;
	int** result;

	// key^3
	cubKey = allocateMatrix();
	resertMat(cubKey);
	cubeKey(key, cubKey);

	// 2 * key
	keyWithScalar = allocateMatrix();
	copyMatrix(key, keyWithScalar);
	matMultiplyByScalar(keyWithScalar, 2);

	//(key ^ 3 + 2 * key)
	result = allocateMatrix();
	result = jointTwoMatrices(cubKey, keyWithScalar);

	//(key ^ 3 + 2 * key) % M
	moduloMat(result);

	freeMat(cubKey);
	freeMat(keyWithScalar);

	return result;

}

Boolean createKeyMattrix(char* source, int** key) {
	int i = 0, j = 0, val;
	char ch;
	while (*source) {
		ch = *source;
		ch = tolower(ch);
		if (ch >= 'a' && ch <= 'z')
			val = ch - 'a';
		else
			if (ch >= 'A' && ch <= 'Z')
				val = ch - 'A';
			else
				return False;
		key[i][j++] = val;
		if (j == N) {
			j = 0;
			i++;
		}
		source++;
	}
	return True;
}

int** allocateMatrix() {
	int** newMat;
	int i, j;
	assert(newMat = (int**)malloc(sizeof(int*) * N));
	for (i = 0; i < N; i++) {
		assert(newMat[i] = (int*)malloc(sizeof(int) * N));
	}
	return newMat;
}
void copyMatrix(int** source, int** dest) {
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			dest[i][j] = source[i][j];
}

void freeMat(int** mat) {
	for (int i = 0; i < N; i++)
		free(mat[i]);
	free(mat);

}

void resertMat(int** mat) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			mat[i][j] = 0;
}

void cubeKey(int** key, int** res) {
	int i, j, k, cube;
	int** tempMat;
	tempMat = allocateMatrix();
	copyMatrix(key, tempMat);
	for (cube = 0; cube < 2; cube++) {
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				for (k = 0; k < N; k++)
					res[i][j] += tempMat[i][k] * key[k][j];
		if (cube == 0) {
			copyMatrix(res, tempMat);
			resertMat(res);
		}
	}
	freeMat(tempMat);
}

void matMultiplyByScalar(int** mat, int scalar) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			mat[i][j] *= scalar;
}

int** jointTwoMatrices(int** one, int** second) {
	int** sum = allocateMatrix();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			sum[i][j] = one[i][j] + second[i][j];
	return sum;
}