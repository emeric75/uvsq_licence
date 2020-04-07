s1 = raw_input("Entrez une chaine de caracteres : ").lower()
s2 = raw_input("2eme chaine de caracteres : ").lower()
print s1, " longueur ", len(s1)
print s2, " longueur ", len(s2)
if len(s2) != 0:
	print "Nombre d'occurences de la 2nde dans la 1ere : ", s1.count(s2)
