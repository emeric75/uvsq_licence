filename = raw_input("Entrez un fichier de sequence : ")
motif = raw_input("Motif a rechercher (en majuscules) : ")
f = open(filename,"r")
seq = ""
ligne = f.readline()
while ligne != "":
	seq += ligne[:-1].upper()
	ligne = f.readline()
f.close()

nbOcc = 0
i = 0
ok = seq.find(motif,i)
print "Occurrences de", motif, ":"
while i<len(seq) and ok != -1:
	nbOcc += 1
	print ok+1,
	i = ok+1
	ok = seq.find(motif,i)
if nbOcc == 0:
	print "Pas d'occurrences"
