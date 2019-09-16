#include "stdio.h"
#include "stdlib.h"

int main(){
	int total,sec,min,hour;
	char pl_sec, pl_min, pl_hour;
	printf("Temps en secondes : ");
	scanf("%d", &total);
	hour = (total-total%3600)/3600;
	min = ((total - hour*3600) - (total - hour*3600)%60)/60;
	sec = (total - hour*3600 - min*60);
	pl_sec = sec > 1 ? 's': ' ';
	pl_min = min > 1 ? 's': ' ';
	pl_hour= hour > 1 ? 's': ' ';
 	printf("%d seconde correspond à %d heure%c %d minute%c %d seconde%c\n",total,hour,pl_hour,min,pl_min,sec,pl_sec);

}
