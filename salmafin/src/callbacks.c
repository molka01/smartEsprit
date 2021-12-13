#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h> 

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include <time.h>
#include "stock.h"

int z,y;
int l,t2;

//stock salma



void
on_SJtreeview1_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}
void
on_ajoutsalma_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
produit a;
GtkWidget *windowstock,*type,*id,*nom,*quantite,*jour,*mois,*annee,*choix,*etat;

windowstock=create_window_stock();
id = lookup_widget(button,"entry1_iden");
nom = lookup_widget(button,"entry2_nom");
quantite = lookup_widget(button,"spinbutton1_quantite");
type=lookup_widget(button,"comboboxentry1_type");
jour = lookup_widget(button,"spinbutton1_date");
mois = lookup_widget(button,"spinbutton1_mois");
annee = lookup_widget(button,"spinbutton1_annee");
strcpy(a.identifiant,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
a.quantite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (quantite));
strcpy(a.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
a.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour));
a.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois));
a.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee));
if(z==1 )
{strcpy(a.choix,"produit durable");} 
else
{strcpy(a.choix,"produit périssable");}
if(l==1)
{strcpy(a.etat,"existe déjà");} 
else
{strcpy(a.etat,"inexistant");}
ajouterproduit(a);
z=0;
l=0;
windowstock=create_window_stock();
gtk_widget_show(windowstock);
}

void
on_button2_yes_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
produit a1;
GtkWidget *windowmodif, *windowstock, *id1, *nom1, *quant1,*type1,*jour1,*mois1,*annee1,*choix1,*etat1;
id1 = lookup_widget(button,"entry2_iden");
nom1 = lookup_widget(button,"entry2_nom");
quant1 = lookup_widget(button,"spinbutton2_quantite");
type1=lookup_widget(button,"comboboxentry2_type");
jour1 = lookup_widget(button,"spinbutton2_jour");
mois1 = lookup_widget(button,"spinbutton2_mois");
annee1 = lookup_widget(button,"spinbutton2_annee");
strcpy(a1.identifiant,gtk_entry_get_text(GTK_ENTRY(id1)));
strcpy(a1.nom,gtk_entry_get_text(GTK_ENTRY(nom1)));
a1.quantite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (quant1));
strcpy(a1.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type1)));
a1.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour1));
a1.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois1));
a1.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee1));
if(y==1 )
{strcpy(a1.choix,"produit durable");} 
else
{strcpy(a1.choix,"produit périssable");}
if(t2==1)
{strcpy(a1.etat,"existe déjà");} 
else
{strcpy(a1.etat,"inexistant");}
modifierproduit(a1);
y=0;
t2=0;

windowstock=create_window_stock();
gtk_widget_show (windowstock);
}

void
on_radiobuttondur_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=1;}
}


void
on_radiobuttonper_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=0;}
}


void
on_radiobutton1per_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=0;}
}


void
on_radiobutton1dur_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=1;}
}


void
on_checkbutton2_nv_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{t2=0;}
}


void
on_checkbutton2_anc_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{t2=1;}
}

void
on_checkbutton_nv_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{l=0;}
}


void
on_checkbutton_anc_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active((togglebutton)))
{l=1;}

}
void
on_salmasupprimer_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowstock, *iden, *identi;
GtkWidget *tree;
//windowstock=create_window_stock();
/*windowstock=lookup_widget(button,"window_stock");
tree=lookup_widget(windowstock,"SJtreeview1");
iden = lookup_widget(button,"entry3");
strcpy(identi,gtk_entry_get_text(GTK_ENTRY(iden)));
supprimerproduit(identi);
affichageproduit(tree);

gtk_widget_show(windowstock);*/

windowstock=lookup_widget(button,"window_stock");
gtk_widget_destroy(windowstock);
gtk_widget_show (windowstock);

}



void
on_button_rechSJ_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowrechercher, *windowstock;
windowstock=lookup_widget(button,"window_stock");
gtk_widget_destroy(windowstock);

}

/*
void
on_affichagesalma_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree,*windowstock;
windowstock=create_window_stock();
tree=lookup_widget(windowstock,"SJtreeview5");

affichageproduit(tree);

gtk_widget_hide(windowstock);
gtk_widget_show(windowstock);
}
*/
////Bouton retour modification ////
void
on_button2_rmod_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodif, *windowstock;
windowstock=lookup_widget(button,"window_stock");
gtk_widget_destroy(windowstock);
//windowinscrit=create_window_inscrit();
//gtk_widget_show (windowinscrit);
}




void
on_button1_rsup_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_SJtreeview3_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


////Boutton Retour aff rechercher
void
on_button4_rrrch_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *o, *windowstock;
o=lookup_widget(button,"create_oui");
gtk_widget_destroy(o);
windowstock=create_window_stock();
gtk_widget_show (windowstock);
}

void
on_button_affich_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree,*windowstock;
windowstock=create_window_stock();
tree=lookup_widget(windowstock,"SJtreeview1");

affichageproduit(tree);

gtk_widget_hide(windowstock);
gtk_widget_show(windowstock);
}
//recherche stock//
void
on_recherchesalma_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
char identir[20];
GtkWidget *idenr, *rech,*o, *n;
GtkWidget *tree;
GtkWidget *windowrechercher;

int ce;
windowrechercher=lookup_widget(button,"window_stock");
o=create_oui();
n=create_non();
idenr = lookup_widget(button,"entry_rech");
strcpy(identir,gtk_entry_get_text(GTK_ENTRY(idenr)));
ce=rechercherproduit(identir);
if (ce==0)
	{
		gtk_widget_show(n);
	}
if (ce==1)	
	{	

gtk_widget_destroy(windowrechercher);
tree=lookup_widget(o,"treeview4");

affichageproduitrechercher(tree);
gtk_widget_show(o);
}
}


void
on_SJtreeview4_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button3_rnon_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *n, *windowstock;
n=lookup_widget(button,"create_non");
gtk_widget_destroy(n);
windowstock=create_window_stock();
gtk_widget_show (windowstock);
}






void
on_button1_rruptu_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}





void
on_buttonrupturee_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowstock;
GtkWidget *output1 ,*output2, *output3 ,*inputquantite;
GtkWidget *o1 ,*o2, *o3, *i11;
char ch[100];

windowstock=create_window_stock();

i11=lookup_widget(button,inputquantite);
o1= lookup_widget(button,output1);
o2= lookup_widget(button,output2);
o3= lookup_widget(button,output3);
gtk_widget_hide (o1);
gtk_widget_hide (o2);
gtk_widget_hide (o3);
message(ch);


windowstock=create_window_stock();
gtk_widget_show (windowstock);
}

