#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 12
#define NB_LIGNE 50
#define LONGUEUR_LIGNE 150

typedef struct Restaurant {
    char* nom_restaurant ;
    char* adresse_restaurant ;
    char* position_restaurant ; //coordonnees position_restaurant;
    char* specialite ;
}Restaurant;


int lire_restaurant (char *chemin, Restaurant restaurants[NB_LIGNE]);
void inserer_restaurant(char* chemin);
void afficher_restaux(Restaurant restaurants[NB_LIGNE], int taille);
double X_position(char *chaine);
double Y_position(char *chaine);
void cherche_restaurant(double x, double y, double rayon_recherche, Restaurant results[], Restaurant tab_restaurants[]);
void trier_results(Restaurant results[], double x, double y, int nb_restaurant);
void cherche_par_specialite(double x, double y, char *specialite[], Restaurant results[], Restaurant tab_restaurants[], int nb_spe);




#endif // HEADER_H_INCLUDED
