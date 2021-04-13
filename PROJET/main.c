#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include "index.h"
#include "second_ecran.h"
#include "first_ecran.h"
#include "partie_en_cours.h"
#include "third_ecran.h"

int main(void) {
	option A; /* permet de savoir le mode de jeu et la taille de la grille */
	int defaite; /* permet de savoir quel joueur a perdu */
	int futur = 0; /* permet de savoir si la partie doit recommencer ou pas */
	emplacement where_J1; /* Emplacement du joueur 1 */
 	emplacement where_J2; /* Emplacement du joueur 2 OU Bot */	


 	while(futur == 0) {
 		defaite = 0;
 		futur = 0;

 		/* Première Page du jeu */
		Init_FirstPage();
		A=InteractionFirstPage();
		/* Fermeture de la Première Page */

		/* Initialisation d'un tableau représentant ce que contient chaque case */
		int grille[A.taille][A.taille];
		Init_TabTab(A, grille);

		/* Deuxième Page et création du plateau de jeu selon la taille donné */
		Init_Plateau(A);

		/* Début de la partie avec le Premier Joueur */
		where_J1 = TourJoueur(A, grille, J1_PION);

		if((A.type) == J_VS_J) { /* Lancement d'une Partie Joueur VS Joueur */
			where_J2 = TourJoueur(A, grille, J2_PION); 

			while(defaite == 0){

				defaite = VerifyLoser(A, grille, J1_PION, where_J1);
				if(defaite == 0) {
					where_J1=Tour2Joueur(A, grille, J1_PION, where_J1);


					defaite = VerifyLoser(A, grille, J2_PION, where_J2);
					if(defaite == 0) {
						where_J2=Tour2Joueur(A, grille, J2_PION, where_J2);
					}
				}
			
			} 
	

		} else { /* Lancement d'une Partie Joueur VS Bot */
			where_J2 = TourBot(A, grille); 

			while(defaite==0){

				defaite = VerifyLoser(A, grille, J1_PION, where_J1);
				if(defaite == 0) {
					where_J1=Tour2Joueur(A, grille, J1_PION, where_J1);


					defaite = VerifyLoser(A, grille, J2_PION, where_J2);
					if(defaite == 0) {
						where_J2=Tour2Bot(A, grille, where_J2, where_J1);
					}
				}
			} 
		
		}

	FermerGraphique(); /* Fermeture du deuxième écran après avoir constaté un perdant */

	futur = EcranVictory(A, defaite); 

	}
  
 	 return EXIT_SUCCESS;
}