print "Calculer l'aire d'une figure"
choix = raw_input("Rectangle(R)/Triangle(T) ? ")
if choix == 'R':
	lo = input("Quelle est sa longueur ? ")
	la = input("Quelle est sa largeur ? ")
	print "Aire du rectangle : ", lo*la
elif choix == 'T':
	b = input("Quelle est sa base ? ")
	h = input("Quelle est sa hauteur ? ")
	print "Aire du triangle : ", b*h/2.0
else:
	print "pas de choix de figure"
