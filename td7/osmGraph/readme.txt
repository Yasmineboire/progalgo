exercice 2 
1) 

WeightedGraph
Cette fonction sert a représenter un Graphe Pondéré. 
Elle est constitué de 2 structures: 
-la WeightedArc : elle représente une connexion sortante d'un sommet.
IDType to - c'est l'identifiant du sommet vers laquelle l'arrete pointe.
weight - c'est la valeur de l'arrete (la pondération)
serialize - Permet de sauvegarder et charger l'arrete sur un disque dur via la bibliothèque Cereal. 

-la WeightedGraph : représente le graphe complet et toutes les liaisons
adjacency_list - la liste d'adjacence utilise une table de hachage (hash map) ou chaque clé qui correspond à l'identifiant unique d'un nœud source, est associée à un vecteur de WeightedArc.
Méthodes add / remove - fonctions pour ajouter des sommets, créer des liaisons orienté ou non, ou supprimer des éléments.
get_neighbors - Elle permet de consulter rapidement quelle chemin est connecté a quoi.


PositionedGraph
Le rôle de PositionedGraph est de créer une carte géographique qui comprend comment les sommets sont reliés entre eux.
Elle fusionne deux informations :
graph - il sait quel point est relié à quel point
nodes - Il stocke la position réelle (coordonnées X, Y) de chaque point.
ca permet : D'ajouter des sommets avec leur position précise, relier deux points entre eux.
Fusionner deux points s'ils sont au même endroit (merge_nodes)

2)