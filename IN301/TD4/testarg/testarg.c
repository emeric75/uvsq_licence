#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int isfloat(char *s){
	int i = 0;
	int point_seen = 0;
	if(!(s[i] == '-' || isdigit(s[i])))
		return 0;
	i++;
	while(s[i] != '\0'){
		if (s[i] == '.'){
			if(point_seen) return 0;
			point_seen = 1;
		}
		else if (isdigit(s[i])){
			
		}else{
			return 0;
		}
		i++;
	}
	return 1;
}


int main(int argc, char **argv){
	int i;
	float sum = 0.0;
	printf("argc = %d\n", argc);
	if(argc == 1){printf("Provide at least one number\n"); exit(1);}
	for(i = 1; i < argc; i++){
		if(!isfloat(argv[i])){
			 printf("At least one of the args is not a number\n");
			 exit(1);
		}
		sum += atof(argv[i]);
	}
	printf("somme args = %f\n", sum);
	return 0;
}
