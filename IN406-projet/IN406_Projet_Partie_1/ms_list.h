typedef struct multi_state{
	int id_state_det;
	int *multi_state;
	int nb_states;
} MULTI_STATE;

typedef struct multi_states{
	MULTI_STATE ms;
	struct multi_states *suiv;
} MS_LIST;

MS_LIST* ms_list_init();
void ms_list_lib(MS_LIST *ms_list);

//ajoute un multi_state dans ms_list, et lui attribue un 
//id_state_det (>= 0) dans l'automate déterministe
MS_LIST* ms_list_append(MS_LIST* ms_list, int *multi_state, int nb_states);

MULTI_STATE ms_list_pop(MS_LIST** ms_list);

//renvoie id_state_det de multi_state s'il existe dans ms_list, -1 sinon
int ms_list_find(MS_LIST *ms_list, int *multi_state, int nb_states);
int check_equal(int *l1, int *l2, int length);
int not_zero(int *tab, int l);

