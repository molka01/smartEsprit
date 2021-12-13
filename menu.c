
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "menu.h"
#include <string.h>
#include <time.h>

#include <stdio.h>



void ajouter_nb(nutri A)
{
    FILE *F=NULL;

F=fopen("menu.txt","a");
if(F!=NULL)
{

    fprintf(F,"%0.4s %s %s %s %s %d %s %s \n",A.id,A.type,A.plat,A.ing,A. date,A.nb,A.groupetr,A.modetr);
    fclose(F);
    

}

}

void supp_nb(char id[])
{
  
   FILE *F, *FW;
  nutri D ;
  
F = fopen ("menu.txt", "r");
FW = fopen ("tr.txt", "w");

  if ((F!=NULL)&&(FW!=NULL))
 {


  while (fscanf (F, "%s %s %s %s %s %d %s %s",D.id,D.type,D.plat,D.ing,D. date,&D.nb,D.groupetr,D.modetr) == 8)
    if (strcmp (D.id, id) != 0) 
      fprintf (FW, "%s %s %s %s %s %d %s %s \n", D.id,D.type,D.plat,D.ing,D. date,D.nb,D.groupetr,D.modetr);
}
  fclose (F);
  fclose (FW);
remove("menu.txt");
rename("tr.txt", "menu.txt");




}

nutri rech_nb(char id[])
{

FILE *F;
  nutri Q;
  nutri A;
  
F = fopen ("menu.txt", "r");


  if (F!=NULL)
{
  while (fscanf (F, "%s %s %s %s %s %d %s %s", Q.id,Q.type,Q.plat,Q.ing,Q. date, &Q.nb,Q.groupetr,Q.modetr) != EOF)
    if (strcmp (Q.id, id) == 0) 
        {
        strcpy(A.type,Q.type); 
        strcpy(A.plat,Q.plat);
        strcpy(A.ing,Q.ing);
        strcpy(A.date,Q.date);
	strcpy(A.groupetr,Q.groupetr);
	strcpy(A.modetr,Q.modetr);
	
        }

  }
  return (A);
  fclose (F);  
}



void modi_nb(char id [] , nutri U) 
{
   FILE *F, *FW;
  nutri c; 
  
F = fopen ("menu.txt", "r");
FW = fopen ("tr.txt", "w");

  if ((F!=NULL)&&(FW!=NULL)) 
{
  while (fscanf (F, "%s %s  %s %s %s %d %s %s",c.id,c.type,c.plat,c.ing,c. date,&c.nb,c.groupetr,c.modetr) ==8) 
	
    if (strcmp (c.id, id) == 0)
     {

fprintf (FW, "%s %s %s %s %s %d %s %s\n",id,U.type,U.plat,U.ing,U.date,U.nb,U.groupetr,U.modetr);
     }
     else
     {

       fprintf (FW, "%s %s %s %s %s %d %s %s\n", c.id,c.type,c.plat,c.ing,c. date,c.nb,c.groupetr,c.modetr);
     }
}    

  fclose (F);
  fclose (FW);
remove("menu.txt");
rename("tr.txt", "menu.txt");

}


void afficher_nb (GtkWidget *treeviewMolka, char*l )

{
GtkListStore *adstore;      
GtkTreeViewColumn *adcolumn;      
GtkCellRenderer *cellad;  
FILE *f;


	char id[30];
	char type[30];
	char nb[30];
	char plat[30];
	char ing[30];
	char date[30];
	char groupetr[30];
	char modetr [30];

        adstore = gtk_list_store_new(8,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",id,type,plat,ing,date,nb,groupetr ,modetr)!= EOF)
        {
         GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,id,
                            1,type,
                            2,plat,
                            3,ing,
                            4,date,
			    5,nb,
                            6,groupetr,
                            7,modetr,
                            -1);}
        fclose(f);

if(o==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewMolka), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Chef",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewMolka), adcolumn);




        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Ingrédient",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewMolka), adcolumn);

        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Plat",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewMolka), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("SEMAINE",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewMolka), adcolumn);

        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Déchet",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewMolka), adcolumn);

        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Groupe",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewMolka), adcolumn);

        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Mode",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewMolka), adcolumn);


	o++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeviewMolka),
                                  GTK_TREE_MODEL(adstore)  );

}
