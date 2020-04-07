seq = raw_input("Entrez une sequence ADN : ").upper()
i = 0
ok = 1
while i < len(seq)/2:
	if seq[i]+seq[len(seq)-1-i] not in "AT/TA/GC/CG":
		ok = 0
	i += 1
if ok == 1:
	print "c'est un palindrome biologique"
else:
	print "c'est pas joli joli"
	
