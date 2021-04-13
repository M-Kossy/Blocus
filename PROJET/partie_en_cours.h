#include "index.h"

#ifndef PARTIE_EN_COURS_H
#define PARTIE_EN_COURS_H



emplacement Tour2Joueur(option, int grille[A.taille][A.taille], int, emplacement);
/* Gère les tours hormis le 1er selon quel joueur doit jouer avec "int" et renvoie 
	la nouvelle position en changeant les emplacements des sprites*/

emplacement TourJoueur(option, int grille[A.taille][A.taille], int);
/* Gère uniquement le 1er tour du Joueur "int", renvoie l'emplacement de celui-ci sur la "grille" et place les sprites*/

int VerifyLoser(option, int grille[A.taille][A.taille], int, emplacement);
/* Renvoie la valeur "0" si le joueur peut se déplacer, sinon il renvoie la valeur "J1_PION" ou "J2_PION"
	 selon qui est incapable de bouger */

emplacement TourBot(option, int grille[A.taille][A.taille]);
/* Gère uniquement le 1er Tour du Bot en renvoyant son emplacement et place les sprites*/

emplacement Tour2Bot(option, int grille[A.taille][A.taille], emplacement, emplacement); 
/* Gère les tours hormis le 1er du bot, renvoie sa nouvelle position et replace les sprites. 
	En sachant que les croix sont posés selon la position du joueur. */

#endif /* PARTIE_EN_COURS_H */