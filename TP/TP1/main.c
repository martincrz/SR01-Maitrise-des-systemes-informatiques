#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 12
#define NB_LIGNE 50
#define LONGUEUR_LIGNE 150
#include "fonctions.c"
#include "header.h"



int main() {
    int choix;
    Restaurant tab_restaurants[NB_LIGNE];
    for (int i=0;i<NB_LIGNE; i++)
    {
        tab_restaurants[i].nom_restaurant=malloc(sizeof(0));
        tab_restaurants[i].adresse_restaurant=malloc(sizeof(0));
        tab_restaurants[i].position_restaurant=malloc(sizeof(0));
        tab_restaurants[i].specialite=malloc(sizeof(0));
    }

    do {
        printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * MENU * * * * * * * * * * * * * * * * * * * * * * * * * * * \n\n");
        printf("1 - Afficher le nombre de restaurants \n2 - Inserer restaurant dans le fichier \n3 - Rechercher les restaurants dans un rayon de recherche \n4 - Rechercher les restaurants de specialites choisies \n\nSaisir la fonctionnalite desiree : ");
        scanf("%d", &choix);
        switch (choix){
            case 1:{
                printf("Il y a %d restaurants dans le fichier \n\n", lire_restaurant("restau.txt", tab_restaurants));
                break;
                }
            case 2 :
                inserer_restaurant("restau.txt");
                break;
            case 3 :{
                lire_restaurant("restau.txt", tab_restaurants);

                double x, y, rayon;
                printf("Saisir l abscisse : ");
                scanf("%lf", &x);
                printf("Saisir l ordonnee : ");
                scanf("%lf", &y);
                printf("Saisir le rayon : ");
                scanf("%lf", &rayon);
                Restaurant results[NB_LIGNE];
                cherche_restaurant(x,y, rayon, results, tab_restaurants);
                break;}

            case 4 : {
                lire_restaurant("restau.txt", &tab_restaurants);
                double x, y, rayon;
                printf("Saisir l abscisse : ");
                scanf("%lf", &x);
                printf("Saisir l ordonnee : ");
                scanf("%lf", &y);

                int nb_spe;
                printf("\nCombien de specialite voulez vous afficher : ");
                scanf("%d", &nb_spe);
                char *tab_specialite[nb_spe];
                char specialite[50];
                printf("#Ecrire sous la forme {specialite}\n");
                fgets(specialite, sizeof(specialite), stdin);
                specialite[strlen(specialite)-1]='\0';
                for (int k=0;k<nb_spe; k++){
                        printf("Specialite %d : ", k+1);
                        fgets(specialite, sizeof(specialite), stdin);
                        specialite[strlen(specialite)-1]='\0';
                        tab_specialite[k] = strdup(specialite);
                        specialite[0]='\0';
                }


                Restaurant results[NB_LIGNE];
                cherche_par_specialite(x,y,tab_specialite, results, tab_restaurants, nb_spe);
                break;}

            default :
                printf("Choix non valide\n\n");
        }
    }while (choix>=1 && choix<=4);

    return 0;
}

