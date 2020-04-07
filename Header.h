#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
typedef enum { False, True } Boolean;
#define N 2
#define M 26

Boolean createKeyMattrix(char* source, int** key);
int** allocateMatrix();
int** createX(int** key);
void cubeKey(int** key, int** res);
void copyMatrix(int** source, int** dest);
void freeMat(int** mat);
void resertMat(int** mat);
void printMat(int** mat);
void matMultiplyByScalar(int** mat, int scalar);
int** jointTwoMatrices(int** one, int** second);
Boolean invertibleMat(int** key, int** invertMat);
void moduloMat(int** mat);

char* door_encryption(char* ptext, int** key);
char* door_decryption(char* ctext, int** key);
