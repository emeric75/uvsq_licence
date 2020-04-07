filename = raw_input("Entrez un fichier de sequence : ")
motif = raw_input("Motif a rechercher (en majuscules) : ")
f = open(filename,"r")
seq = ""
ligne = f.readline()
while ligne != "":
	seq += ligne[:-1].upper()
	ligne = f.readline()
f.close()
if seq.find(motif) == -1:
	print "Le motif", motif, "n'est pas present"
else:
	print "Position de la 1ere occurrence de", motif , ":", seq.find(motif)+1
