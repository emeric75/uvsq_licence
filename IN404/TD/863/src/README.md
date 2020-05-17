## Exercice 8.6.3 : DessinCLI
####Compilation
Dans la racine
````
javac -cp src -d classes src/*.java
````
####Exécution
Toujours dans la racine
````
javac -cp classes App
````
####Organisation
+ package stock : stockage des données du dessin
    + Les formes (Shape) pouvant être créées par l'utilisateur sont stockées dans des figures (liste de formes), 
    + Le dessin complet (représenté par la classe Stock) est constitué d'une liste de figures.


+ package ui : interprétation des commandes utilisateur
et affichage des résultats.

+ App : classe responsable du dialogue UI-données / exécution du programme.
#####Types de forme disponibles
+ `circle` : demande 3 entiers (2 pour le centre du cercle + 1 pour le rayon)
+ `rectangle` : 4 entiers (2 * 2 entiers pour deux coins opposés du rectangle)

####Commandes disponibles
+ `create <type de forme> <paramètres spécifiques à la forme>`
    + La forme est directement insérée dans une figure à part.
    + Un nom est associé à chaque figure pour les manipulations (donné par défaut à la création, visible avec `list`)
+ `remove <nom fig>` : supprimer une figure
+ `list` : liste les figures créées et leurs formes associées
+ `rename <nom de la fig à renommer> <nouveau nom>`
+ `group <nom figure 1> <nom figure 2>` : regroupe les deux figures spécifiées en argument (elles doivent être différentes)
    + ajoute les figures de nom2 dans nom1.
    + la figure nom2 est supprimée à l'issue du groupement.
+ `split <nom figure>` : sépare toutes les formes de la figure donnée vers leur propre figure individuelle.
+ `move <nom figure> <deltaX> <deltaY>` : translate la figure donnée de (`deltaX`, `deltaY`)
+ `save <nom de fichier>` : enregistre l'état des figures dans un fichier
+ `load <nom de fichier>` : lit un état précédemment sauvegardé
+ `quit` : quitte l'application