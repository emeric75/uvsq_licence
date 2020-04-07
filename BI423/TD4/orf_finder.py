from biomol import *
from os import mkdir,path
from math import ceil,log10
def write_cds_info(f,seq,idcds,deb,fin,sens):
	if deb == None:
		phase = sens*((fin-2)%3 + 1)
		deb = "<1" if sens == 1 else ">"+str(len(seq))
		fin = len(seq)-fin if sens == -1 else fin+1
		fin = str(fin)
		f.write("CDS"+str(idcds)+"\t"+str(phase)+"\t"+deb+"\t"+fin+"\n")
	elif fin == None:
		phase = sens*(deb%3 + 1)
		fin = ">"+str(len(seq)) if sens == 1 else "<1"
		deb = len(seq)-deb if sens == -1 else deb+1
		deb = str(deb)
		f.write("CDS"+str(idcds)+"\t"+str(phase)+"\t"+deb+"\t"+fin+"\n")
	else:
		nt = fin-deb+1
		cod = nt/3
		aa = cod-1
		phase = sens*(deb%3+1)
		if sens == -1:
			deb = len(seq)-deb-1
			fin = len(seq)-fin-1
		deb = str(deb+1)
		fin = str(fin+1)
		f.write("CDS"+str(idcds)+"\t"+str(phase)+"\t"+deb+"\t"+fin+"\t"+str(nt)+"/"+str(aa)+"\n")
def write_cds(f,cds_seq):
	lines = [cds_seq[k:k+50] for k in range(0,len(cds_seq),50)]
	protein = translate(transcribe(cds_seq))
	lines_prot = [protein[k:k+50] for k in range(0,len(protein),50)]
	for line in lines:
		f.write("\t"+line+"\n")
	f.write("\n")
	for line in lines_prot:
		f.write("\t"+line+"\n")
def list_all_cds(seq,sens):
	global idcds
	i=0
	out = list()
	used_stops = list()
	ok = seq.find("ATG",i)
	i_taa = 0
	i_taa = seq.find("TAA",i_taa)
	#orf qui commencent avant le debut
	while i_taa<ok and i_taa != -1:
		idcds+=1
		out.append( (seq[0:i_taa], (idcds,None,i_taa+2,sens)) )
		i_taa = seq.find("TAA",i_taa+1)
		
	#orf entierement dans la seq
	while i<len(seq) and ok != -1:
		deb = ok
		fin = ok
		while fin+3 < len(seq) and seq[fin:fin+3] not in "TAA/TAG/TGA":
			fin+=3
		#orf se terminant en dehors
		if fin+3 > len(seq) and fin-deb+1>=min_len :
			idcds += 1
			out.append( (seq[deb:],(idcds,deb,None,sens)) )
		#orf completement dans la sequence
		if fin+3 <= len(seq) and fin-deb+1>=min_len and fin not in used_stops:
			idcds += 1
			out.append( (seq[deb:fin+3],(idcds,deb,fin+2,sens)) )
			used_stops.append(fin)
		i=ok+1
		ok = seq.find("ATG",i)
	
	return out

def list_cds_codons(seq,sens):
	global idcds
	out = list()
	for phase in [0,1,2]:
		codons = [seq[k:k+3] for k in range(phase,len(seq),3)]
		if len(codons[-1]) < 3:
			del codons[-1]
		used_stops = []
		for start in range(len(codons)):
			if codons[start] == "ATG":
				for end in range(start+1,len(codons)):
					if codons[end] in "TAA/TAG/TGA":
						if end in used_stops or end-start+1<min_len/3:
							break
						idcds += 1
						out.append( (seq[phase+3*start:phase+3*(end+1)],(idcds,phase+3*start,phase+3*end+2,sens)) )
						used_stops.append(end)
						break
	return out
filename = raw_input("Nom de fichier FASTA  : ")
outname = raw_input("Nom de dossier de sortie : ")
min_len = input("Longueur minimale d'un ORF (nt) : ")

######### lecture fasta 
f = open(filename,"r")
infos = f.readline()
ligne = f.readline()
seq = ""
while ligne != "":
	seq += ligne.strip()
	ligne = f.readline()
f.close()

######### traitement sequence
idcds = 0
if not path.exists(outname):
	mkdir(outname)
	
recap = open(outname+"/recap.txt","w")
recap.write(seq + "\n")
recap.write(infos + "\n")
recap.write("CDS\tcadre\tdebut\tfin\tTaille(nt/aa)\n")

##### cadres pos
forward = list_all_cds(seq,1)

##### cadres neg
# inverse complementaire
inv = inv_comp(seq)
backward = list_all_cds(inv,-1)

########## regroupement pos/neg, tri par longueur decroissante et affichage
cdss = forward + backward
cdss.sort(key=lambda e: -(e[1][2]-e[1][1]) if e[1][2] != None and e[1][1] != None else 0)
for cds in cdss:
	cds_file = open(outname+"/CDS"+'%0*d'%(int(ceil(log10(idcds))) if idcds > 1 else 1,cds[1][0])+".txt","w")
	write_cds_info(cds_file,seq,*(cds[1]))
	write_cds(cds_file,cds[0])
	write_cds_info(recap,seq,*(cds[1]))
	cds_file.close()
recap.close()
