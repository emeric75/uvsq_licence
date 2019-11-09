#include "tas.h"
int main(){
	TAS_TAB t = creer_tas_tab();
	aff_tas_tab(t);
	t=inserer_elem(t,10,10);
	t=inserer_elem(t,1,20);
	t=inserer_elem(t,7,30);
	t=inserer_elem(t,2,1);
	aff_tas_tab(t);
	get_most_prio(&t);
	aff_tas_tab(t);
	get_most_prio(&t);
	aff_tas_tab(t);
	get_most_prio(&t);
	aff_tas_tab(t);
	get_most_prio(&t);
	aff_tas_tab(t);
	free(t.tab);
}
