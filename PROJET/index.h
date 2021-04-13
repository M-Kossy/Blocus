#ifndef INDEX_H
#define INDEX_H

#define CYCLE 300000L /* Correspond aux nombres de microseconde avant chaque action du BOT */
#define EPAISSEUR 2 /* correspond à l'épaisseur des cases */
#define SEPARATION_PAR_CASE (70+EPAISSEUR) /* Corresponds aux nombres de pixel séparant le coin supérieur gauche d'une case à une autre*/

#define VIDE 0 /* La case est vide */
#define J1_PION 1 /* La case est habité par le pion du joueur 1  */
#define SOURIS 2 /* La souris se situe sur la case */
#define J1_CROIX 3 /* La case est habité par une croix posé par le joueur 1 */
#define J2_PION 4 /* La case est habité par le pion du joueur 2 ou bot */
#define J2_CROIX 5 /* La case est habité par une croix posé par le joueur 2 ou bot */

#define J_VS_J 6 /* Mode de jeu Joueur Contre Joueur */
#define J_VS_BOT 7 /* Mode de jeu Joueur Contre BOT */

struct emplacement_s {
	int x;
	int y;
}; /* Défini l'emplacement d'un objet selon sa longeur et largeur sur un plan */

typedef struct emplacement_s emplacement;

struct option_s
{
	int taille;
	int type;
}; /* Permet d'identifier la taille de la grille et quel mode de jeu mettre */

typedef struct option_s option;

option A;

#endif /* INDEX_H */