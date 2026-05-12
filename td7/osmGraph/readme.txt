exercice 2 
(1) 

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

(2)
Extraction OSM
Ce module sert à récupérer les données depuis la base de données OpenStreetMap. Il filtre les informations pour ne conserver que les éléments pertinents selon une zone géographique précise ou des balises spécifiques.

Simplification
Son rôle est de réduire la complexité géométrique des objets extraits. En supprimant les points superflus des tracés tout en préservant leur forme globale, il permet d'alléger le poids des fichiers, d'accélérer les calculs et d'améliorer la fluidité de l'affichage.

Visualisation
C'est l'étape finale qui transforme les données numériques en rendu graphique. Ce module applique des styles (couleurs, épaisseurs de traits, icônes) pour rendre l'information lisible et interactive pour l'utilisateur, sur une modélisation 3D.

(3)
L'objectif de simplify.cpp est de transformer une carte brouillon, remplie de détails inutiles, en un graphe propre pour faciliter les calculs pour la recherche d'itinéraire (dijkstra).

Le nettoyage : On commence par supprimer tous les morceaux isolés pour ne garder que le réseau principal où tout est connecté. On coupe les minuscules impasses de quelques mètres qui ne mènent nulle part. Le code vérifie le degré du nœud c'est a dire le nombre de voisins du noeud. 

L'allègement des lignes : Pour économiser de la mémoire, on retire les points intermédiaires sur les routes bien droites. Si un point ne sert qu'à relier deux segments presque alignés, on le supprime sans changer la forme de la route.
lm::pi représente un angle plat(180 degrés). Le code calcule la différence entre l'angle réel des deux routes et un angle plat. Si cette différence est inférieure au seuil (30 degrés), ça signifie que la route est assez droite pour retirer le point.
Et la fonction replace_node_by_arc retire le nœud central et connecte directement ses deux voisins entre eux.

La simplification des carrefours : Au lieu d'avoir dix points différents pour représenter un seul grand carrefour complexe, on fusionne les points très proches les uns des autres pour créer un seul nœud central (clusters).
Pour chaque nœud, on regarde ses voisins (neighbor_depth). Si un de ces voisins est à moins de 10 mètres physiquement, ils sont ajoutés à un même groupe. À la fin, la fonction graph.merge_nodes fusionne tous les nœuds d'un groupe en un seul point situé au centre.