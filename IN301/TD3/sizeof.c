#include <stdlib.h>
#include <stdio.h>

int main(){
	printf("%-10s %3d\n","char",sizeof(char));
	printf("%-10s %3d\n","int",sizeof(int));
	printf("%-10s %3d\n","double",sizeof(double));
	printf("%-10s %3d\n","char*",sizeof(char*));
	printf("%-10s %3d\n","void*",sizeof(void*));
	printf("%-10s %3d\n","int*",sizeof(int*));
	printf("%-10s %3d\n","double*",sizeof(double*));
	printf("%-10s %3d\n","int**",sizeof(int**));
	printf("%-10s %3d\n","int[10]",sizeof(int[10]));
	printf("%-10s %3d\n","char[7][3]",sizeof(char[7][3]));
	//printf("%-10s %d","int[]",sizeof(int[]));
	printf("\n");

	float tab[10] = {0};
	printf("%-10s %p %d\n", "tab", tab, sizeof(tab));
	printf("%-10s %f %d\n", "tab[0]", tab[0], sizeof(tab[0]));
	printf("%-10s %p %d\n", "&tab[0]", &tab[0], sizeof(&tab[0]));
	printf("%-10s %p %d\n", "*&tab", *&tab, sizeof(*&tab));
	printf("%-10s %f %d\n", "*&tab[0]", *&tab[0], sizeof(*&tab[0]));
	printf("\n");

	int T[7][3];
	printf("T %p &T[0][0] %p\n", T , &T[0][0]);
	printf("&T[0][1] %p\n",&T[0][1]);
	printf("&T[0][2] %p\n",&T[0][2]);
	printf("&T[1][0] %p\n",&T[1][0]);
	printf("&T[1][1] %p\n",&T[1][1]);
	printf("&T[6][2] %p ((long int)&T)+4*(6*3+2) %x\n", &T[6][2], ((long int) &T)+4*(6*3+2));
}

