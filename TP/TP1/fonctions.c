#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 12
#define NB_LIGNE 50
#define LONGUEUR_LIGNE 150
#include "header.h"


int lire_restaurant (char *chemin, Restaurant restaurants[NB_LIGNE]) {
    int i = 0;

    // ouverture du fichier
    FILE *pf;
    pf = fopen(chemin, "r");
    if (pf == NULL) {
        printf("Erreur a l'ouverture\n");
        exit(-1);
    }

    // lecture de chaque ligne du fichier
    char ligne[LONGUEUR_LIGNE];
    fgets(ligne, LONGUEUR_LIGNE, pf);// sauter la premiere ligne

    int k = 0;

    while(fgets(ligne, LONGUEUR_LIGNE, pf)!=NULL) {
        // decoupage de la ligne en mots avec strtok
        char *mot = malloc(80 * sizeof (char));

        // obtenir le premier mot
        mot = strtok(ligne, ";");


        // obtenir les autres mots de la ligne
        while(mot!=NULL) {
            if (mot[0]==' ')mot++; //enlever les espaces inutiles
            if (k==0) {
                restaurants[i].nom_restaurant = strdup(mot) ;
                }
            else if (k==1) {
                restaurants[i].adresse_restaurant =strdup(mot);
                }
            else if (k==2) {
                restaurants[i].position_restaurant = strdup(mot);
                }
            else if (k==3) {
                restaurants[i].specialite = strdup(mot) ;
                i++;
                }
            mot = strtok(NULL, ";");
            k++;
        }
        //printf("\nOn a donc Restaurant[%d]\nNom : %s\nAdresse : %s\nPosition : %s\nSpecialite : %s \n\n\n", i, restaurants[i-1].nom_restaurant, restaurants[i-1].adresse_restaurant,restaurants[i-1].position_restaurant,  restaurants[i-1].specialite );
        k=0;

    }


    fclose(pf);
    return i;
}


void inserer_restaurant(char* chemin){
    FILE *pf;
    double x=0, y=0;
    pf = fopen(chemin, "a");
    if (pf == NULL) {
        printf("Erreur a l'ouverture\n");
        exit(-1);
    }
    char nom[50], adresse[50], specialite[50];
    printf("\nSaisir nouveau restaurant : \n");


    printf("Nom : ");
    fgets(nom, sizeof(nom), stdin);
    nom[strlen(nom)-1]='\0';
    fgets(nom, sizeof(nom), stdin);
    nom[strlen(nom)-1]='\0';


    printf("Adresse : ");
    fgets(adresse, sizeof(adresse), stdin);
    adresse[strlen(adresse)-1]='\0';



    printf("Position :\n ");
    printf("X=");
    scanf("%lf",&x);
    printf("Y=");
    scanf("%lf",&y);


    printf("Specialite : ");
    fgets(specialite, sizeof(specialite), stdin);
    specialite[strlen(specialite)-1]='\0';
    fgets(specialite, sizeof(specialite), stdin);
    specialite[strlen(specialite)-1]='\0';



    fprintf(pf, "%s; %s; (x=%lf, y=%lf); {%s};\n\n\0", nom, adresse, x, y, specialite);
    fclose(pf);
}

void afficher_restaux(Restaurant restaurants[NB_LIGNE], int taille){
    int i=0;
    printf("\n\n");
    for (i=0; i<taille; i++){
        printf("Restau[%d] : \n", i);
        printf("Nom : %s \n", restaurants[i].nom_restaurant);
        printf("Adresse : %s \n", restaurants[i].adresse_restaurant);
        printf("Position : %s \n", restaurants[i].position_restaurant);
        printf("Specialite : %s \n\n", restaurants[i].specialite);
    }
}

//fonction qui renvoie la position X d un restaurant
double X_position(char *chaine){
    int j=0, k=0;
    double x;
    char ch_x[30];
    while (chaine[j]!=',')
    {
        if (isdigit(chaine[j]) || chaine[j]=='.'){
                ch_x[k]=chaine[j];
                k++;
        }
        j++;
    }
    x = strtod(ch_x, &ch_x[j-1]);
    for(int l = 0; l < strlen(ch_x); l++) {ch_x[l] = '0';}
    //free(ch_x);
    return (x);
}

//fonction qui renvoie la position Y d un restaurant
double Y_position(char *chaine){
    int j=0, k=0;
    double y;
    char ch_y[30];
    while (chaine[j]!=',') j++;

    while (chaine[j]!=')')
    {
        if (isdigit(chaine[j]) || chaine[j]=='.'){
                ch_y[k]=chaine[j];
                k++;
        }
        j++;
    }
    y = strtod(ch_y, &ch_y[j-1]);
    for(int l = 0; l < strlen(ch_y); l++) {ch_y[l] = '0';}
    //free(ch_y);
    return (y);
}

//fonction qui recherche les restaurants selon un perimetre donnee
void cherche_restaurant(double x, double y, double rayon_recherche, Restaurant results[], Restaurant tab_restaurants[]){
    int nb_resto=lire_restaurant("restau.txt", tab_restaurants);
    int u=0;
    double x_resto, y_resto;
    char *chaine = malloc(sizeof(0));


    printf("\nLes restaurants suivants sont dans ce perimetre : \n");
    for (int i=0; i<nb_resto; i++){

        chaine = strdup(tab_restaurants[i].position_restaurant);
        x_resto = X_position(chaine);
        y_resto = Y_position(chaine);


        if ( (x_resto - x)*(x_resto - x) + (y_resto - y)*(y_resto - y) <= (rayon_recherche * rayon_recherche))  {
            results[u]=tab_restaurants[i];
            printf("%s - %s\n", tab_restaurants[i].nom_restaurant, tab_restaurants[i].position_restaurant);
            u++;
        }
    }
}

//fonction qui trie les restaurants selon la localisation donnee
void trier_results(Restaurant results[], double x, double y, int nb_restaurant){

    double x1,y1;
    int j;
    for (int i=1; i<=nb_restaurant; i++){
        Restaurant rest_ech = results[i];
        x1= X_position(results[i].position_restaurant);
        y1= Y_position(results[i].position_restaurant);
        j=i;
        while (j>0 && ((X_position(results[j-1].position_restaurant)-x)*(X_position(results[j-1].position_restaurant)-x) + (Y_position(results[j-1].position_restaurant)-y)*(Y_position(results[j-1].position_restaurant)-y)) > ((x1-x)*(x1-x)+(y1-y)*(y1-y)) ){
            results[j]=results[j-1];
            j=j-1;
        }
        results[j]=rest_ech;
    }
}

//fonction qui recherche les restaurants dont les specialites figurent parmi une liste donnee
void cherche_par_specialite(double x, double y, char *specialite[], Restaurant results[], Restaurant tab_restaurants[], int nb_spe){
    int nb_resto=lire_restaurant("restau.txt", tab_restaurants);
    int j=0, u=0, k=0;
    int l;
    int p=0;

    double x_resto, y_resto;
    char *chaine = malloc(sizeof(0));

    for (int i=0; i<nb_resto; i++){
        //printf("\n\nPour le restau %s specialite %s\n", tab_restaurants[i].nom_restaurant, tab_restaurants[i].specialite);

        chaine = strdup(tab_restaurants[i].position_restaurant);
        x_resto = X_position(chaine);
        y_resto = Y_position(chaine);

        for (p=0; p<nb_spe;p++){
                //printf("test specialite commune entre %s et %s\n", tab_restaurants[i].specialite, specialite[p]);
                if (strcmp(tab_restaurants[i].specialite, specialite[p])==0){ //PB tab_restaurants[i].specialite a un espace avant
                    //printf("%s et %s\n", tab_restaurants[i].nom_restaurant, tab_restaurants[i].specialite);
                    results[u]=tab_restaurants[i];
                    u++;
                }

        }
    }
    trier_results(results, x, y, u-1);
    printf("Voici les restaurants correspondants à ces specialites (ordonnes du plus proche au plus loin) : ");
    afficher_restaux(results, u);
}
