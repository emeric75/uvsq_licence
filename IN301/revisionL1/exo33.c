#include "stdio.h"
#include "stdlib.h"

int main(){
	for(int i = 0; i<10; i++){
		for(int j = i+1; j<10; j++){
			printf(" ");
		}
		printf("*\n");
	}
}
