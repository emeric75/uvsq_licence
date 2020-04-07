chaine = raw_input("Entrez une chaine de caracteres : ").upper()
i = 0
ok = 1
size = len(chaine)
while i<size/2:
	if chaine[i] != chaine[size-i-1]:
		ok = 0
	i += 1
if ok == 1:
	print "c'est une palindrome"
else:
	print "ce n'est pas un palindrome"
