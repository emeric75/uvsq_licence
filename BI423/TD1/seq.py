seq = raw_input("Entrez une seq nucleotidique : ").upper()
pA = (seq.count('A')*1.0)/len(seq)*100
pT = (seq.count('T')*1.0)/len(seq)*100
pG = (seq.count('G')*1.0)/len(seq)*100
pC = (seq.count('C')*1.0)/len(seq)*100
pOther = round(100.0-pA-pT-pC-pG,2)

pA = round(pA,2)
pT = round(pT,2)
pG = round(pG,2)
pC = round(pC,2)

print "%A : ", pA
print "%T : ", pT
print "%G : ", pG
print "%C : ", pC
print "%autres : ", pOther
