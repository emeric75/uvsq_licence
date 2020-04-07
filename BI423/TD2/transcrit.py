seq = raw_input("Sequence d'ADN a transcrire : ").upper()
i = 0
transcrit = ""
while i<len(seq):
	if seq[i] == 'T':
		transcrit += 'U'
	else:
		transcrit += seq[i]
	i += 1
print transcrit
