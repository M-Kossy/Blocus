#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include "index.h"
#include "second_ecran.h"

void RemplirCase(int i, int y) {

	RemplirRectangle(i*SEPARATION_PAR_CASE+EPAISSEUR, y*SEPARATION_PAR_CASE+EPAISSEUR,SEPARATION_PAR_CASE - (EPAISSEUR) - 1, SEPARATION_PAR_CASE - (EPAISSEUR) - 1);
}

void Init_TabTab(option A, int tab[A.taille][A.taille]){
	int i, y;

	for(i=0; i<A.taille; ++i) {
		for(y=0; y<A.taille; ++y) {

			tab[i][y] = 0;
		}
	}
}

void Init_Plateau(option A){
	couleur c;
	int i, y, a;
	InitialiserGraphique();
	CreerFenetre(500, 120, (A.taille)*SEPARATION_PAR_CASE, (A.taille)*SEPARATION_PAR_CASE); /* Crée la fenêtre selon la taille de la grille */
	ChoisirTitreFenetre("BLOCUS - GAME");
	c=CouleurParNom("black");
	ChoisirCouleurDessin(c);


/* Mise en forme des cases de la grille */
	for(i=0; i<(A.taille); ++i) {
		for(y=0; y<(A.taille); ++y) {
			for(a=0; a<EPAISSEUR; ++a){ /* rajoute des rectangles dans des rectangles selon le nombre de l'épaisseur */
		  		DessinerRectangle(SEPARATION_PAR_CASE*i+a, y*SEPARATION_PAR_CASE+a, SEPARATION_PAR_CASE-(2*a), SEPARATION_PAR_CASE-(2*a));
	    	}	
		}
	}
}


 void EmplacementSourisCase(option A, int grille[A.taille][A.taille] ) { /* vérifie où se trouve la souris */
 	int i, y;


	for(i=0; i<A.taille; i++) {
		for(y=0; y<A.taille; y++) {

			if( grille[i][y] != J1_PION  && grille[i][y] != J1_CROIX && grille[i][y] != J2_PION && grille[i][y] != J2_CROIX && 
			    _X>=i*SEPARATION_PAR_CASE+1 && _X<=SEPARATION_PAR_CASE*i+SEPARATION_PAR_CASE-1 && 
				_Y>=y*SEPARATION_PAR_CASE+1 && _Y<=SEPARATION_PAR_CASE*y+SEPARATION_PAR_CASE-1 ) { 
				/* Si la souris est au-dessus de la case et qu'elle ne contient ni pion, ni croix, elle est considéré comme ayant la souris dessus même si elle avait déjà ce titre*/

				grille[i][y] = SOURIS;

			} else if (grille[i][y] == SOURIS) { /* si la souris n'est pas au-dessus de la case et qu'elle avait la souris dessus, elle est considéré comme vide */

				grille[i][y] = VIDE;
			}
		}
	}
}

void ColoreEmplacementSouris(option A, int grille[A.taille][A.taille]) {

	int i, y;

	while(!SourisCliquee()) {
	
		SourisPosition();
		EmplacementSourisCase(A, grille); 

		for(i=0; i<A.taille; i++) {
			for(y=0; y<A.taille; y++) {

				if(grille[i][y] == SOURIS) { /* Si la souris est sur la case alors la case devient coloré */

					ChoisirCouleurDessin(CouleurParComposante(255, 213, 180));
					RemplirCase(i, y);

				} else if(grille[i][y] == VIDE) { /* Si la souris n'est pas sur la case alors la case devient blanche */ 

					ChoisirCouleurDessin(CouleurParNom("white"));
					RemplirCase(i, y);
				}

			}
		}
	}
}

void PlacementCroixJoueur(option A, int grille[A.taille][A.taille], int joueur){

	int i, y;
	int sortie = 0; /* permet de sortir de la boucle while */

	/* Valeur permettant de charger les sprites */
	int joueur_2_croix = ChargerSprite("croix_2.png"); 
 	int joueur_1_croix = ChargerSprite("croix_1.png");


	while(sortie == 0) {

		ColoreEmplacementSouris(A, grille);

		EmplacementSourisCase(A, grille);

		for(i=0; i<A.taille; i++) {
			for(y=0; y<A.taille; y++) {

				if(grille[i][y] == SOURIS) { /* S'il y a eu un clic sur la case alors la case affiche le sprite du joueur 1 */

					if(joueur == J1_PION) { /* Si c'est le joueur 1 */

						grille[i][y] = J1_CROIX;
						sortie = 1;
						AfficherSprite(joueur_1_croix, i*SEPARATION_PAR_CASE+EPAISSEUR, y*SEPARATION_PAR_CASE+EPAISSEUR);
					} else { /* Si c'est le joueur 2 */

						grille[i][y] = J2_CROIX;
						sortie = 1;
						AfficherSprite(joueur_2_croix, i*SEPARATION_PAR_CASE+EPAISSEUR, y*SEPARATION_PAR_CASE+EPAISSEUR);

					}
				}
			}
		}
	}
	LibererSprite(joueur_2_croix);
	LibererSprite(joueur_1_croix);
}

void PlacementCroixBot(option A, int grille[A.taille][A.taille], emplacement where_joueur) {

	int bot_croix = ChargerSprite("croix_bot.png");
	int i, y;
	int sortie = 0; /* Pour sortir d'un while */
	unsigned long int suivant; /* pour compter le temps entre chaque action du bot */

	suivant = Microsecondes() + CYCLE + CYCLE + CYCLE;

	while(sortie == 0){

		/* i et y peuvent prendre comme valeur : -1, 0 et 1 */
		i = where_joueur.x + (Microsecondes()%3)-1; 
		y = where_joueur.y + (Microsecondes()%3)-1;


		/* Si les emplacements obtenus ne correspondent pas à l'emplacement du joueur ou l'une des coordonnées ne fait pas parti de la grille alors il rentre dans le "if" */ 
		if(! (( i == where_joueur.x && y == where_joueur.y) || i == -1 || y == -1 || i == A.taille || y == A.taille )) { 

			if(grille[i][y] == VIDE){ /* si les emplacements obtenus correspondent à une case vide, alors le Bot attend un certain temps avant de poser une croix */

				suivant = Microsecondes() + CYCLE;
				while(suivant > Microsecondes()) {} /* Le Bot attend */

				AfficherSprite(bot_croix, i*SEPARATION_PAR_CASE+EPAISSEUR, y*SEPARATION_PAR_CASE+EPAISSEUR);


				grille[i][y] = J2_CROIX;
				sortie = 1;
			}
		}

		if(Microsecondes() > suivant) { /* Si le Bot prend un certain temps sans trouver d'emplacement autour du joueur pour poser une croix, il en pose une au hasard sur la grille */

			while(sortie == 0){
				i = Microsecondes()%(A.taille);
				y = Microsecondes()%(A.taille);

				if(grille[i][y] == VIDE) { /* si les emplacements obtenus correspondent à une case vide, alors le Bot attend un certain temps avant de poser une croix */

					sortie = 1;
					grille[i][y] = J2_CROIX;

					suivant = Microsecondes() + CYCLE;
					while(suivant > Microsecondes()) {} /* le Bot attend */

					AfficherSprite(bot_croix, i*SEPARATION_PAR_CASE+EPAISSEUR, y*SEPARATION_PAR_CASE+EPAISSEUR);

				}

			}
		}
	}
	LibererSprite(bot_croix);
}