#include "index.h"

#ifndef SECOND_ECRAN_H
#define SECOND_ECRAN_H

 void EmplacementSourisCase(option, int grille[A.taille][A.taille]); 
/* Donne une valeur à chaque case de la grille en sachant soit la souris est dessus soit elle ne l'est pas. Elle ne compte pas les grilles occupés par les pions ou croix*/

void ColoreEmplacementSouris(option, int grille[A.taille][A.taille]);
/* Colore la case où se situe la souris (sans compter les croix et pion) en y impregnant ses coordonnés dans la grille tant qu'il n'y a eu aucun clic de souris */

void Init_Plateau(option);
/* Créé le plateau de jeu selon les options définissant la taille du plateau*/

void Init_TabTab(option, int grille[A.taille][A.taille]);
/* donne la valeur 0 à chaque case du tableau */

void PlacementCroixJoueur(option, int grille[A.taille][A.taille], int);
/* Place une croix selon le joueur "int" grâce aux repères de la "grille" */

void PlacementCroixBot(option, int grille[A.taille][A.taille], emplacement);
/* Si possible, place une croix autour du Joueur selon son "emplacment" sinon une au hasard sur la grille */ 

void RemplirCase(int, int);
/* permet de remplir une case du tableau de coordonnées x et y en ayant au préalable déterminer la couleur souhaité */ 

#endif /* SECOND_ECRAN_H*/