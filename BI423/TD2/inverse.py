seq = raw_input("Entrez une sequence ADN : ").upper()
i = len(seq)-1
inverse = ""
while i >= 0:
	if seq[i] == 'A':
		inverse += 'T'
	if seq[i] == 'T':
		inverse += 'A'
	if seq[i] == 'C':
		inverse += 'G'
	if seq[i] == 'G':
		inverse += 'C'
	i -= 1
print "inverse comp", inverse
