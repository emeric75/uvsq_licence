#include "stdio.h"
#include "stdlib.h"
#include <math.h>
int main(){
	double to_sqrt, res_min=0, res_max,m,eps;
	int prec;
	printf("Entrez un nombre : ");
	scanf("%lf",&to_sqrt);
	printf("%lf\n", to_sqrt);
	printf("chiffres après la virgule :");
	scanf("%d",&prec);
	eps = 1.0f/pow(10,prec);
	res_max = to_sqrt;
	while(res_max-res_min > eps){
		m = (res_min+res_max)/2.0d;
		if((res_min*res_min-to_sqrt)*(m*m-to_sqrt)<0){
			res_max=m;
		}else{
			res_min=m;
		}
	}
	printf("Racine de %.*lf dans (%.*lf,%.*lf)\n",prec,to_sqrt,prec,res_min,prec,res_max);
}
