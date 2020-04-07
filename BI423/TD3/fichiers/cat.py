filename = raw_input("Entrez un nom de fichier : ")
f = open(filename,"r")
ligne = f.readline()
res = ""
while ligne != "":
	res += ligne[:-1]
	ligne = f.readline()
print res
f.close()
