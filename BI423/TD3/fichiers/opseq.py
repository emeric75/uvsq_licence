print "Transcrit/Inv Comp"
continuer = 1
comp = {"A":"T","T":"A","C":"G","G":"C"}
while continuer:
	infile = raw_input("Entrez un fichier de sequence : ")
	choice = raw_input("Transcrit (T) / Inv Comp (I)? ")

	while choice != "T" and choice != "I":
		print "Choisissez T ou I"
		choice = raw_input("Transcrit (T) / Inv Comp (I)? ")
	f = open(infile,"r")

	seq = ""
	ligne = f.readline()
	while ligne != "":
		seq += ligne[:-1]
		ligne = f.readline()
	f.close()

	if choice == "T":
		res = seq.replace("T","U")
	else: #choice == "I"
		res = ""
		i = 0
		while i < len(seq):
			res = comp[seq[i]] + res
			i+=1

	outfile = raw_input("Entrez un fichier de sortie : ")
	g = open(outfile, "w")
	g.write(res)
	g.close()
	continuer = input("Voulez-vous continuer avec un autre fichier ? (1 oui / 0 non) ")
