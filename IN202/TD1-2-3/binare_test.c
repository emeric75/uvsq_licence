#include <stdio.h>

void print_base_2(int x, int size){//size est le nombre de bits sur lequel x est affiché
								   //pour size = 0, on affiche juste le bon nombre de bits
	int res[64];
	int i = 0;
	while(x != 0){
		res[i] = x%2;
		x = x/2;
		i++;
	}
	if(size != 0){
		for(int j=0; j< size - i; j++){
			printf("0");
		}
	}
	for(int j = i-1; j>=0; j--){
		printf("%d",res[j]);
	}
	printf("\n");
}

int parcount (unsigned char x){
	int res = 0;
	for(int i = 0; i <8; i++){
		res += (x>>i)%2;
	}
	return res;
}

int main(){
	char prenom = 'E';
	char nom = 'G';
	print_base_2(prenom, 8);
	print_base_2(nom,8);
	print_base_2(0b00001111^prenom,8);
	print_base_2(0b10101010^nom,8);
	print_base_2(0b00100100^prenom,8);
	print_base_2(0b11001101^nom,8);
	
	printf("%d",(parcount(0b00001111^prenom) + parcount(0b10101010^nom) + parcount(0b00100100^prenom) + parcount(0b11001101^nom))%2);
}
