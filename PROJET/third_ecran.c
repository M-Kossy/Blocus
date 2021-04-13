#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include "index.h"

int EcranVictory(option A, int loser) {
  couleur c;
  int futur; /* valeur qui sera renvoyer pour savoir si on recommance ou pas la partie */
  int sortie = 0; /* pour sortir du while */

  InitialiserGraphique();
  CreerFenetre(450, 80, 450, 400);
  ChoisirTitreFenetre("BLOCUS - FIN");
  
  c=CouleurParNom("brown");
	  ChoisirCouleurDessin(c);
	  EcrireTexte(145, 50, "Partie Finie!", 2);
  

  if (loser == J2_PION) { /* Si le joueur 2 ou le bot est perdant, le joueur 1 a gagné */
  c=CouleurParNom("orange");
	  ChoisirCouleurDessin(c);
   EcrireTexte(90, 170, "Joueur 1 est le gagnant!", 2);
  }
  
  if (loser == J1_PION && (A.type) == J_VS_J) { /* Si le joueur 1 a perdu et qu'on est en mode Joueur contre Joueur, le Joueur 2 a gagné */
  c=CouleurParNom("purple");
	  ChoisirCouleurDessin(c);
   EcrireTexte(90, 170, "Joueur 2 est le gagnant!", 2);
  }
  
   if (loser == J1_PION && (A.type) == J_VS_BOT) { /* Si le joueur 1 a perdu et qu'on est en mode Joueur contre BOT, le Bot a gagné */
  c=CouleurParNom("blue");
	  ChoisirCouleurDessin(c);
   EcrireTexte(90, 170, "le BOT est le gagnant!", 2);
  }
  
   c=CouleurParNom("black");
	  ChoisirCouleurDessin(c);
	  EcrireTexte(163, 232, "Voulez-vous...", 1);

    DessinerRectangle(135, 240, 160, 40);
    
    c=CouleurParNom("brown");
	  ChoisirCouleurDessin(c);
    EcrireTexte(150, 270, "Recommencer", 2);
    
     c=CouleurParNom("black");
	  ChoisirCouleurDessin(c);
    EcrireTexte(205, 300, "ou", 1);
    
    DessinerRectangle(165, 310, 100, 40),

     c=CouleurParNom("brown");
	  ChoisirCouleurDessin(c);
    EcrireTexte(175, 340, "Quitter", 2);

    while(sortie == 0) {

      while(!SourisCliquee()) {}

      if( _X >= 135 && _X <= 295 && _Y >= 240 && _Y <= 280 ) { /* si le joueur appuie sur "recommencez" */

        sortie = 1;
        futur = 0;
      
      } else if( _X >= 165 && _X <= 265 && _Y >= 310 && _Y <= 350 ) { /* si le joueur appuie sur "quittez" */

        sortie = 1;
        futur = 1;
      }

    }

    FermerGraphique();

    return futur;

}
    
    
  