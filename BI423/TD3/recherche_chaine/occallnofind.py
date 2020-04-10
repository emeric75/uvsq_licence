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
print "Occurrences de", motif, ":"
while i<len(seq):
	k=0
	while k<len(motif) and i+k<len(seq) and seq[i+k] == motif[k]:
		k+=1
	if k == len(motif):
		nbOcc += 1
		print i+1,
	"""if seq[i:i+len(motif)] == motif:
		nbOcc += 1
		print i+1,"""
	i+=1
if nbOcc == 0:
	print "Pas d'occurrences"
