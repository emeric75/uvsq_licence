Exercice 8.6.3 : DessinCLI
---
Formes disponibles
+ `circle` : demande 3 entiers (2 pour le centre du cercle + 1 pour le rayon)
+ `rectangle` : 4 entiers (2 * 2 entiers pour deux coins opposés du rectangle)

Commandes disponibles
+ `create <type de forme> <paramètres spécifiques à la forme>`
    + Un id est associé à chaque figure pour les manipulations (visible avec `list`)
+ `list` : liste les figures créées et leurs formes associées
+ `group <id figure 1> <id figure 2>` : regroupe les deux figures spécifiées en argument (elles doivent être différentes)
+ `move <id figure> <deltaX> <deltaY>` : translate la figure donnée de (`deltaX`, `deltaY`)
+ `save <nom de fichier>` : enregistre l'état des figures dans un fichier
+ `load <nom de fichier>` : lit un état précédemment sauvegardé
+ `quit` : quitte l'application