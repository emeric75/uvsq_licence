seq = raw_input("Entrez une sequence d'ADN : ").upper()
nA = 0
nT = 0
nC = 0
nG = 0
i = 0
while i<len(seq):
	if seq[i] == 'A':
		nA+=1
	if seq[i] == 'T':
		nT+=1
	if seq[i] == 'C':
		nC+=1
	if seq[i] == 'G':
		nG+=1
	i+=1
print "%A : ", round(nA*100.0/len(seq),2)
print "%T : ", round(nT*100.0/len(seq),2)
print "%C : ", round(nC*100.0/len(seq),2)
print "%G : ", round(nG*100.0/len(seq),2)
