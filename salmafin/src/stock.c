#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "stock.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>

enum
{ 
	EID,
	ENOM,
	EQUANTITE,
	ETYPE,
	EJOUR,
	EMOIS,
	EANNEE,
	ECHOIX,
        EETAT,
	COLUMNS,
};


void ajouterproduit(produit a)
{

FILE *f;
f=fopen("Produits.txt","a+");

fprintf(f,"%s %s %d %s %d %d %d %s %s \n",a.identifiant,a.nom,a.quantite,a.type,a.date.jour,a.date.mois,a.date.annee,a.choix,a.etat);
fclose(f);
}

void supprimerproduit(char identifiant [])
{
produit a;
FILE *f1;
FILE *f2;

f1=fopen("Produits.txt","r");
f2=fopen("prod.txt","w");
while(fscanf(f1,"%s %s %d %s %d %d %d %s %s \n",a.identifiant,a.nom,&a.quantite,a.type,&a.date.jour,&a.date.mois,&a.date.annee,a.choix,a.etat)!=EOF)
{if (strcmp(identifiant,a.identifiant)!=0)
fprintf(f2,"%s %s %d %s %d %d %d %s %s \n",a.identifiant,a.nom,a.quantite,a.type,a.date.jour,a.date.mois,a.date.annee,a.choix,a.etat);
}
fclose(f1);
fclose(f2);
remove("Produits.txt");
rename("prod.txt","Produits.txt");

}

void affichageproduit(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char id[30];
	char nom[30];
	char quantite[30];
	char type[30];
	char jour[10];
	char mois[10];
	char annee[10];
	char choix[30];
	char etat[30];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("quantite", renderer, "text",EQUANTITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);   

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("choix", renderer, "text",ECHOIX,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etat", renderer, "text",EETAT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING);
	f=fopen("Produits.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("Produits.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",id,nom,quantite,type,jour,mois,annee,choix,etat)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EID, id, ENOM, nom, EQUANTITE , quantite, ETYPE, type, EJOUR,jour, EMOIS,mois, EANNEE,annee, ECHOIX,choix, EETAT,etat, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}
                       
void modifierproduit(produit a1)
{
produit a;
FILE *f1;
FILE *f2;
f1=fopen("Produits.txt","r");
f2=fopen("prod.txt","a");

if((f1!=NULL)&&(f2!=NULL))
{
while(fscanf(f1,"%s %s %d %s %d %d %d %s %s \n",a.identifiant,a.nom,&a.quantite,a.type,&a.date.jour,&a.date.mois,&a.date.annee,a.choix,a.etat)!=EOF)
	{
	if(strcmp(a.identifiant,a1.identifiant)==0)
		{
		fprintf(f2,"%s %s %d %s %d %d %d %s %s \n",a1.identifiant,a1.nom,a1.quantite,a1.type,a1.date.jour,a1.date.mois,a1.date.annee,a1.choix,a1.etat);
		}
	else
		{
		fprintf(f2,"%s %s %d %s %d %d %d %s %s \n",a.identifiant,a.nom,a.quantite,a.type,a.date.jour,a.date.mois,a.date.annee,a.choix,a.etat);
		}
	}

}
fclose(f1);
fclose(f2);
remove("Produits.txt");
rename("prod.txt","Produits.txt");
}


int remplirtab (produit tab[],int nb)
{
    char id[20],nom[20];
    char type[20];
    int quantite;		
    char choix[20],etat[20];
    int jour,mois,annee;
    FILE* fichier ;
    int i;

    fichier = fopen("Produits.txt", "a+");


        while (fscanf(fichier,"%s %s %d %s %d %d %d %s %s \n",id,nom,&quantite,type,&jour,&mois,&annee,choix,etat)!=EOF)
        {
            
            strcpy(tab[i].identifiant,id);
	    strcpy(tab[i].nom,nom);
	    tab[i].quantite=quantite;
            strcpy(tab[i].type,type);
	    tab[i].date.jour=jour;
            tab[i].date.mois=mois;
	    tab[i].date.annee=annee;
            strcpy(tab[i].choix,choix);
	    strcpy(tab[i].etat,etat);
            nb++;
	    
        }
        

        fclose(fichier);
	return(nb);
}


int rechercherproduit(char identifiant[])
{
produit tabl[100];
int nb;
int ce,i;
FILE*f;
ce=0;
nb=remplirtab (tabl,nb);
for (i=0;i<nb;i++)
	{if (strcmp(identifiant,tabl[i].identifiant)==0)
		{
		ce=1;
		f=fopen("Produitrechercher.txt", "w+");
		if("f!=NULL")
			{fprintf(f,"%s %s %d %s %d %d %d %s %s \n",tabl[i].identifiant,tabl[i].nom,tabl[i].quantite,tabl[i].type,tabl[i].date.jour,tabl[i].date.mois,tabl[i].date.annee,tabl[i].choix,tabl[i].etat);}
		fclose(f);		
		}
	}

return(ce);
}
//////////////////////////Fonction Affichage rechercher//////////////////////////
void affichageproduitrechercher(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char id[30];
	char nom[30];
	char quantite[30];
	char type[30];
	char jour[10];
	char mois[10];
	char annee[10];
	char choix[30];
	char etat[30];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("quantite", renderer, "text",EQUANTITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);   

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("choix", renderer, "text",ECHOIX,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etat", renderer, "text",EETAT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING);
	f=fopen("Produits.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("Produitrechercher.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",id,nom,quantite,type,jour,mois,annee,choix,etat)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EID, id, ENOM, nom, EQUANTITE , quantite, ETYPE, type, EJOUR,jour, EMOIS,mois, EANNEE,annee, ECHOIX,choix, EETAT,etat, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}


void message ( char ch[20])
{

GtkWidget *output1 ,*output2, *output3 ,*inputquantite;
GtkWidget *o1 ,*o2, *o3, *i11;

produit a;

strcpy(a.quantite,ch);
if (strcmp(i11,a.identifiant)==0)
if ( strcmp(ch,"0")==0)
{
gtk_widget_hide (o2);
gtk_widget_hide (o3);
gtk_label_set_text(GTK_LABEL(o1),"Rupture de stock veuillez ajouter");
gtk_widget_show (o1);}
else
{gtk_widget_hide (o1);
gtk_label_set_text(GTK_LABEL(o2),"la quantite est egale à");
gtk_label_set_text(GTK_LABEL(o3),ch);
gtk_widget_show (o2);
gtk_widget_show (o3);
}
}

