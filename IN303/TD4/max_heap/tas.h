struct elem{
	int val;
	int prio;
};
typedef struct elem ELEM;
struct tas_tab{
	int N;
	int MAX;
	ELEM* tab;
};
typedef struct tas_tab TAS_TAB;
struct tas_b{
	int val;
	struct tas_b* fils_g;
	struct tas_b* fils_d;
	struct tas_b* pere;
};
typedef struct tas_b TAS;

TAS_TAB creer_tas_tab();
TAS_TAB inserer_elem(TAS_TAB, int,int);
TAS_TAB tasser_elem(TAS_TAB,int);
void aff_tas_tab(TAS_TAB);
ELEM get_most_prio(TAS_TAB*);
