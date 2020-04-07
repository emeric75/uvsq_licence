seq = raw_input("Entrez une sequence proteique : ").upper()
i = 0
nbS = 0
while i<len(seq):
	if(seq[i] == 'M' or seq[i] == 'C'): #seq[i] in 'MC':
		nbS += 1
	i+=1
print "Nombre d'AA soufres : ", nbS
