#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include "index.h"
#include "first_ecran.h"

void EcritCompteur(int x) {
	couleur c;

    c=CouleurParNom("grey");
	ChoisirCouleurDessin(c);
	RemplirRectangle(130, 160, 180, 50);

	c=CouleurParNom("red");
	ChoisirCouleurDessin(c);
	EcrireTexte(215, 200, (char*) &x, 1);

	ChoisirCouleurDessin(CouleurParNom("black"));
	RemplirTriangle(80, 190, 110, 190, 95, 170);
	DessinerRectangle(130, 160, 180, 50);
	RemplirTriangle(330, 170, 360, 170, 345, 190);
	EcrireTexte(140, 180, "Taille de la grille :", 1);


}

void EcritModeJeu(void) {

	  couleur c;

	  c=CouleurParNom("blue");
      ChoisirCouleurDessin(c);
      EcrireTexte(97, 300, "BOT", 1);

	  c=CouleurParComposante(253, 167, 81);
	  ChoisirCouleurDessin(c);
      EcrireTexte(80, 250, "Joueur 1", 1);
      EcrireTexte(310, 250, "Joueur 1", 1);

	  c=CouleurParNom("purple");
	  ChoisirCouleurDessin(c);
	  EcrireTexte(310, 300, "Joueur 2", 1);

	  c=CouleurParNom("black");
	  ChoisirCouleurDessin(c);
	  EcrireTexte(100, 275, "VS", 1);
	  EcrireTexte(330, 275, "VS", 1);

	  DessinerArc(60, 220, 100, 100, 0, 360);
	  DessinerArc(290, 220, 100, 100, 0, 360);
}

void Titre(void){
    couleur c;

	  c=CouleurParNom("brown");
	  ChoisirCouleurDessin(c);
	  EcrireTexte(180, 50, "Blocus", 2);
}

void ButtonPlay(void) {

	ChoisirCouleurDessin(CouleurParNom("black"));
	DessinerRectangle(175, 300, 100, 50);
	ChoisirCouleurDessin(CouleurParNom("green"));
	EcrireTexte(200, 335, "PLAY", 2);
}

void Init_FirstPage(void) {

    InitialiserGraphique();
    CreerFenetre(450, 80, 450, 400);
    ChoisirTitreFenetre("BLOCUS - MENU");

    EcritModeJeu();
    EcritCompteur('3');
    Titre();
}

option InteractionFirstPage(void) {
	char x = '3';
	int value = 0; /* permet de déterminer quel mode de jeu est choisi et faire apparaître le button pour commencer la partie*/
	int taille; /* permet de savoir la taille de la grille */
	int sortie = 0; /* permet de sortir d'un while (pour éviter les utilisations de "while(1)" et "break") */

	while(sortie == 0) {

	  while(!SourisCliquee()) {}

	  if(_X >= 60 && _X<=160 && _Y>=220 && _Y<=320) { /* Si le joueur appuie sur "joueur vs bot" alors cela colore le fond du bloc ciblé est donne un fond blanc à "joueur vs joueur" */
		  ChoisirCouleurDessin(CouleurParNom("green"));
		  RemplirArc(60, 220, 100, 100, 0, 360);

		  ChoisirCouleurDessin(CouleurParNom("white"));
		  RemplirArc(290, 220, 100, 100, 0, 360);
		  value= J_VS_BOT;

		  EcritModeJeu();
		  ButtonPlay();
		}

	  if(_X >= 290 && _X<=390 && _Y>=220 && _Y<=320) { /* Si le joueur appuie sur "joueur vs joueur" alors cela colore le fond du bloc ciblé est donne un fond blanc à "joueur vs bot" */
		  ChoisirCouleurDessin(CouleurParNom("green"));
		  RemplirArc(290, 220, 100, 100, 0, 360);

		  ChoisirCouleurDessin(CouleurParNom("white"));
		  RemplirArc(60, 220, 100, 100, 0, 360);
		  value = J_VS_J;
		  

		  EcritModeJeu();
		  ButtonPlay();
		}

	  if(_X >= 80 && _X<=110 && _Y>=170 && _Y<=190) { /* Si le joueur appuie sur le triangle vers le haut, cela augmente la taille de la grille si elle n'est pas égale à 9 */
	  	if(x != '9') {
	  		x=x+1;
	  		EcritCompteur((int) x);
	  	}
	  }
	  if(_X >= 330 && _X<=360 && _Y>=170 && _Y<=190) { /* Si le joueur appuie sur le triangle vers le bas, cela diminue la taille de la grille si elle n'est pas égale à 3 */
	  	if(x != '3') {
	  		x=x-1;
	  		EcritCompteur((int) x);
	  	}
	  }

	  if(value!=0 &&_X >= 175 && _X<=275 && _Y>=300 && _Y<=350) { /* Si le joueur appuie sur le button qui n'est disponible uniquement lorsqu'un mode de jeu a été choisi, cela termine ce programme */
	  	sortie = 1;
	  }

	}
	taille = (int) x - (int) '0'; /* reconversion des valeurs pour transformer le nombre en "char" en "int" */
	option A = {taille, value};
	FermerGraphique();

    
	return A;
}

