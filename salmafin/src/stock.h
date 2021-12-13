#include<gtk/gtk.h>
typedef struct
{
int jour;
int mois;
int annee;
}DATE;


typedef struct
{
    
    char identifiant[20];
    char nom[15];
    int quantite;
    char type[20];
    char choix[20];
    char etat[20];
    DATE date;
}produit;

//Gestion du stock
void ajouterproduit(produit a);
void supprimerproduit(char identifiant []);
void affichageproduit(GtkWidget *liste);
void modifierproduit(produit a);
int remplirtab (produit tab[],int nb);
int rechercherproduit(char identifiant[]);
void affichageproduitrechercher(GtkWidget *liste);
//Rupture du stock
produit rupturer ();
void affichageproduitrupturer(GtkWidget *liste);
void message ( char ch[20]);
