#coding: utf-8
import matplotlib.pyplot as plt

def get_id(s):
    return s.split("|")[1]

def read_seq(f):
    id_seq = get_id(f.readline())
    seq = ""
    ligne = f.readline()
    while ligne != "":
        seq += ligne[:-1].upper()
        ligne = f.readline()
    return id_seq,seq
print "----- Dot Plot -----"

fname1 = raw_input("Fichier FASTA 1 : ")
fname2 = raw_input("Fichier FASTA 2 : ")
size = input("Taille fenêtre : ")
id_seuil = input("Pourcentage identité minimal : ")
out = raw_input("Sortie dot plot : ")

f1 = open(fname1,"r")
f2 = open(fname2,"r")

id1,seq1 = read_seq(f1)
id2,seq2 = read_seq(f2)

f1.close()
f2.close()

#création du plot
plt.title("Dot Plot (fenetre="+str(size)+ ", %id="+str(id_seuil)+")")
plt.xlabel(id1)
plt.ylabel(id2)
xs = list()
ys = list()
for i in range(len(seq1)/size):
    for j in range(len(seq2)/size):
        count = 0
        for k in range(size):
            if seq1[size*i+k] == seq2[size*j+k]:
                count += 1
        if count*100.0/size >= id_seuil:
            xs.append(i*size)
            ys.append(j*size)
            #plt.scatter(i*size,j*size,c='blue',s=size)
plt.plot(xs,ys,linestyle='none',marker='o',c='blue',markersize=10)
plt.savefig(out)
plt.show()
