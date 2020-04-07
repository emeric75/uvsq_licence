seq = raw_input("Entrez une sequence : ").upper()
n = input("Entrez un nombre de caracteres (n) : ")
choix = raw_input("Premiers (P) / Derniers (D) ? ")
if type(n) == int and n < len(seq):
	if choix == 'P':
		print n,"premiers caracteres :",seq[:n]
	elif choix == 'D':
		print n,"derniers caracteres :",seq[len(seq)-n:]
	else:
		print "pb"
else:
	print "pb"
