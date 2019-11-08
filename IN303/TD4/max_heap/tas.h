struct tas_b{
	int val;
	struct tas_b* fils_g;
	struct tas_b* fils_d;
	struct tas_b* pere;
};
typedef struct tas_b TAS;
