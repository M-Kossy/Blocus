#ifndef FIRST_ECRAN_H
#define FIRST_ECRAN_H

void EcritCompteur(int);
/* Créé le compteur en y mettant la valeur de "int" en rouge */

void EcritModeJeu();
/* affiche les modes de jeux possible ( player vs player  OR  player vs bot) */

void Titre();
/* Affiche le titre du jeu */

void ButtonPlay();
/* affiche le bouton pour jouer */

void Init_FirstPage();
/* Créé la première page avec les différents éléments visuels*/

option InteractionFirstPage();
/* Permet d'identifié si le joueur à appuyer sur la 1er page et connaitre les options voulus de l'utilisateur */

#endif /* FIRST_ECRAN_H */