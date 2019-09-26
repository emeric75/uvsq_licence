#include <stdio.h>
#include <stdlib.h>

int mystrlen_iter(char *s){
	int i = 0;
	//while(s[i++]);
	while(s[i] != '\0') i++;
	return i;
}

int mystrlen_rec(char *s){
	if(*s == '\0') return 0;
	return 1+mystrlen_rec(s+1);
}

int mystrcmp_iter(char *s1, char *s2){
	int i = 0;
	while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') i++;
	return s1[i]-s2[i];
}

int mystrcmp_rec(char *s1, char *s2){
	if(*s1 != *s2 || *s1 == '\0' || *s2 == '\0') return *s1 - *s2;
	return mystrcmp_rec(s1 + 1, s2 + 1);
}

int miroir(char *s1, char *s2){
	int len = mystrlen_iter(s1);
	if(mystrlen_iter(s2) != len) return 0;
	for(int i = 0; i < len; i++){
		if(s1[i] != s2[len-1-i]) return 0;
	}
	return 1;
}
int sous_chaine(char *s1, char *s2){
	int len1 = mystrlen_iter(s1);
	int len2 = mystrlen_iter(s2);
	int ok;
	//if(len2>len1) return 0;
	for(int i = 0; i<=len1-len2; i++){
		ok = 1;
		for(int j = 0; j< len2; j++){
			if(s1[i+j] != s2[j]) ok = 0;
		}
		if(ok) return 1;
	}
	return 0;
}
int main(int argc, char **argv){
	if(argc != 3){
		printf("You must provide 2 strings\n");
		exit(1);
	}
	printf("len s1 = %d\nlen s2 = %d\n", mystrlen_iter(argv[1]), mystrlen_rec(argv[2]));
	printf("strcmp_iter(s1, s2) = %d\n", mystrcmp_iter(argv[1], argv[2]));
	printf("strcmp_rec(s1, s2)  = %d\n", mystrcmp_rec(argv[1], argv[2]));
	printf("miroir(s1,s2) = %d\n", miroir(argv[1], argv[2]));
	printf("sous_chaine(s1,s2) = %d\n", sous_chaine(argv[1], argv[2]));
}
