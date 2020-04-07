seq = raw_input("Entrez une chaine de caracteres : ").upper()
i = 0
nberr = 0
while i < len(seq):
	if seq[i] not in "ATCG":
		print "erreur ", seq[i], "position ", i+1
		nberr += 1
	i += 1
if(nberr == 0):
	print "C'est une sequence ADN"
else:
	print "Ce n'est pas une sequence ADN :", nberr, "erreurs"
"""
ok = 1
while i < len(seq) and ok:
	if seq[i] not in "ATCG":
		print "erreur", seq[i], "position", i+1
		ok = 0
	i += 1
"""
