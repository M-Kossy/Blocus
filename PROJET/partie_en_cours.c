#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include "index.h"
#include "second_ecran.h"
#include "partie_en_cours.h"

emplacement TourJoueur(option A, int grille[A.taille][A.taille], int joueur) { 

	int joueur_1_logo = ChargerSprite("joueur_1.png");
 	int joueur_2_logo = ChargerSprite("joueur_2.png");

	int i, y;
	int sortie = 0;

	emplacement where_joueur; /* Donnée renvoyer par la fonction correspondant à l'emplacement du joueur */

 	while(sortie == 0){

		ColoreEmplacementSouris(A, grille);


		EmplacementSourisCase(A, grille);

		for(i=0; i<A.taille; i++) {
			for(y=0; y<A.taille; y++) {

				if(grille[i][y] == SOURIS) { /* S'il y a eu un clic sur la case alors la case affiche le sprite du joueur */

					if (joueur == J1_PION) { /* Si c'est le joueur 1 */

						grille[i][y] = J1_PION;
						AfficherSprite(joueur_1_logo, i*SEPARATION_PAR_CASE+EPAISSEUR, y*SEPARATION_PAR_CASE+EPAISSEUR);
						where_joueur.x = i;
						where_joueur.y = y; 
						sortie = 1;

					} else { /* Si c'est le joueur 2 */

						grille[i][y] = J2_PION;
						AfficherSprite(joueur_2_logo, i*SEPARATION_PAR_CASE+EPAISSEUR, y*SEPARATION_PAR_CASE+EPAISSEUR);
						where_joueur.x = i;
						where_joueur.y = y; 
						sortie = 1;

					}
				}
			}
		}
	}

	LibererSprite(joueur_1_logo);
	LibererSprite(joueur_2_logo);

	return where_joueur;
}

emplacement Tour2Joueur(option A, int grille[A.taille][A.taille], int joueur, emplacement where_joueur) {
	int sortie=0; /* Permet de sortir du while */
	int i, y;

	int joueur_1_logo = ChargerSprite("joueur_1.png");
	int joueur_2_logo = ChargerSprite("joueur_2.png");

	while(sortie == 0){

		ColoreEmplacementSouris(A, grille);


		EmplacementSourisCase(A, grille);

		for(i=0; i<A.taille; i++) {
			for(y=0; y<A.taille; y++) {

				if(grille[i][y] == SOURIS) { /* S'il y a eu un clic sur la case alors la case affiche le sprite du joueur */


					/* Si la case sélectionner se trouve autour de l'emplacement du pion du joueur, on rentre dans le "if" */
					if(i >= (where_joueur.x)-1 && i<= (where_joueur.x)+1 && y >= (where_joueur.y)-1 && y<= (where_joueur.y)+1 ) {
						if (joueur == J1_PION) { /* Si c'est le joueur 1 */


							/* Il colore l'ancien emplacement du joueur en blanc puis le considère comme vide */

							ChoisirCouleurDessin(CouleurParNom("white"));
							RemplirCase(where_joueur.x, where_joueur.y);
							grille[where_joueur.x][where_joueur.y] = 0;


							/* Il place le sprite au nouvelle emplacement et le considère comme habité par le pion */ 

							grille[i][y] = J1_PION;
							AfficherSprite(joueur_1_logo, i*SEPARATION_PAR_CASE+EPAISSEUR, y*SEPARATION_PAR_CASE+EPAISSEUR);
							where_joueur.x = i;
							where_joueur.y = y;  
							sortie = 1;

						} else { /* Si c'est le joueur 2 */


							/* Il colore l'ancien emplacement du joueur en blanc puis le considère comme vide */

							ChoisirCouleurDessin(CouleurParNom("white"));
							RemplirCase(where_joueur.x, where_joueur.y);
							grille[where_joueur.x][where_joueur.y] = 0;


							/* Il place le sprite au nouvelle emplacement et le considère comme habité par le pion */

							grille[i][y] = J2_PION;
							AfficherSprite(joueur_2_logo, i*SEPARATION_PAR_CASE+EPAISSEUR, y*SEPARATION_PAR_CASE+EPAISSEUR);
							where_joueur.x = i;
							where_joueur.y = y; 
							sortie = 1;
						}

					}
				}
			}
		}
	}
	LibererSprite(joueur_1_logo);
	LibererSprite(joueur_2_logo);

	PlacementCroixJoueur(A, grille, joueur);

	return where_joueur;
}


int VerifyLoser(option A, int grille[A.taille][A.taille], int joueur, emplacement where_joueur) {
	int i, y;

	/* on regarde autour du pion du joueur */
	for(i=(where_joueur.x)-1; i<=(where_joueur.x)+1; i++){
		for(y=(where_joueur.y)-1; y<=(where_joueur.y)+1; ++y) {

			/* si les coordonnées font parti de la grille, on rentre dans le "if" */
			/* ps : pour éviter les bugs si le pion se trouve aux limites de la grille */
			if(! (i == -1 || y == -1  || i == A.taille || y == A.taille) ) { 

				if(grille[i][y] == VIDE){ /* Si une case est considéré comme VIDE alors le joueur n'a pas perdu et on renvoie 0 */
					return 0;
				}
			}

		}
	}

	/* Si aucune case autour du joueur n'est considéré VIDE, alors on renvoie la valeur du Joueur */
	return joueur;	


}


emplacement TourBot(option A, int grille[A.taille][A.taille]) {

	unsigned long int suivant; /* pour faire des pauses entre chaque action du Bot */
	int i, y;
	int bot_logo = ChargerSprite("joueur_bot.png");
	int sortie = 0; /* pour sortir du while */

	emplacement where_bot;

	while(sortie == 0){
		i = Microsecondes()%(A.taille);
		y = Microsecondes()%(A.taille);

		if(grille[i][y] == VIDE) { /* Si la case est VIDE, alors on place le pion du Bot au hasard */

			sortie = 1;
			grille[i][y] = J2_PION;

			suivant = Microsecondes()+ CYCLE;
			while(suivant > Microsecondes()) {}

			AfficherSprite(bot_logo, i*SEPARATION_PAR_CASE+EPAISSEUR, y*SEPARATION_PAR_CASE+EPAISSEUR);

			where_bot.x = i;
			where_bot.y = y;

		}
	}

	return where_bot;


}

emplacement Tour2Bot(option A, int grille[A.taille][A.taille], emplacement where_bot, emplacement where_joueur) {

	unsigned long int suivant;
	int bot_logo = ChargerSprite("joueur_bot.png");
	int i, y;
	int sortie = 0;

	while(sortie == 0){

		/* i et y prennent l'actuelle coordonnée du Bot et rajoute soit -1, 0 ou 1 pour considérer les coordonnées autour du pion du bot */
		i = where_bot.x + (Microsecondes()%3)-1;
		y = where_bot.y + (Microsecondes()%3)-1;


		/* si les coordonnées font parti de la grille et qu'il ne correspond pas à l'actuelle position du joueur alors on rentre dans le "if" */
		if(! (( i == where_joueur.x && y == where_joueur.y) || ( i == -1 || y == -1 ) || ( i == A.taille || y == A.taille)) ) {

			if(grille[i][y] == VIDE){ /* Si la case est VIDE, alors il se replace à la coordonné obtenu */

				suivant = Microsecondes() + CYCLE;
				while(suivant > Microsecondes()) {} /* le Bot attend */


				/* Remplie la case de l'ancien emplacement du joueur par du blanc et le considère comme VIDE */
				ChoisirCouleurDessin(CouleurParNom("white"));
				RemplirCase(where_bot.x, where_bot.y);
				grille[where_bot.x][where_bot.y] = VIDE;


				/* Place le sprite sur le nouvel emplacement et le considère comme tel. Conserve les nouvelles coordonnés */
				AfficherSprite(bot_logo, i*SEPARATION_PAR_CASE+EPAISSEUR, y*SEPARATION_PAR_CASE+EPAISSEUR);
				grille[i][y] = J2_PION;
				sortie = 1;
				where_bot.x = i;
				where_bot.y = y;

			}
		}
	}
	LibererSprite(bot_logo);




/* Placement de la croix */
	PlacementCroixBot( A, grille, where_joueur);

	return where_bot;
}