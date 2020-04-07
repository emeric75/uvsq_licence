s1 = raw_input("Entrez une chaine de caracteres : ").lower()
s2 = raw_input("2eme chaine de caracteres : ").lower()

print "version count / 2 contenu dans 1 : ", (s1.count(s2) > 0)
print "version in    / 2 contenu dans 1 : ", (s2 in s1)
