#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	srand(getpid());
	for(int i = 0; i<10000; i++){
		printf("%d\n", rand()%1000);
	}

}
