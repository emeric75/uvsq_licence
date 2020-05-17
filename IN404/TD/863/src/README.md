## Exercice 8.6.3 : DessinCLI
####Compilation
####Exécution
####Formes disponibles
+ `circle` : demande 3 entiers (2 pour le centre du cercle + 1 pour le rayon)
+ `rectangle` : 4 entiers (2 * 2 entiers pour deux coins opposés du rectangle)

####Commandes disponibles
+ `create <type de forme> <paramètres spécifiques à la forme>`
    + La forme est directement insérée dans une figure.
    + Un nom est associé à chaque figure pour les manipulations (donné par défaut à la création, visible avec `list`)
+ `remove <nom fig>` : supprimer une figure
+ `list` : liste les figures créées et leurs formes associées
+ `rename <nom de la fig à renommer> <nouveau nom>`
+ `group <nom figure 1> <nom figure 2>` : regroupe les deux figures spécifiées en argument (elles doivent être différentes)
+ `split <nom figure>` : sépare toutes les formes de la figure donnée
+ `move <nom figure> <deltaX> <deltaY>` : translate la figure donnée de (`deltaX`, `deltaY`)
+ `save <nom de fichier>` : enregistre l'état des figures dans un fichier
+ `load <nom de fichier>` : lit un état précédemment sauvegardé
+ `quit` : quitte l'application