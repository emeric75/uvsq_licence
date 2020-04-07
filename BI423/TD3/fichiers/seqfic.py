filename = raw_input("Entrez un fichier de sequence : ")
f = open(filename,"r")
seq = ""
ligne = f.readline()
while ligne != "":
	seq += ligne[:-1].upper()
	ligne = f.readline()
f.close()

nbPur = seq.count("A") + seq.count("G")
pourPur = round(nbPur*100.0/len(seq),2)

out = raw_input("Entrez un nom de fichier de sortie : ")
g = open(out,"w")
g.write("Resultats " + filename + "\n")
g.write(seq + "\n")
g.write("Longueur : " + str(len(seq)) + "\n")
g.write("Pourcentage purines : " + str(pourPur) + "\n")
g.close()
