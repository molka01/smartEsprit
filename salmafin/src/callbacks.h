#include <gtk/gtk.h>

int o;
int m;
int s;



// stock salma///////////////////////////////////////////////////////////////////////////

void
on_SJtreeview1_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_affich_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_rechSJ_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton2_nv_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_anc_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_affichagesalma_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_rmod_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_nv_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_anc_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_salmasupprimer_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_rsup_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_SJtreeview3_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_checkbutton_sup_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_rruptu_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_rrrch_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_recherchesalma_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_SJtreeview4_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button3_rnon_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajoutsalma_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_yes_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttondur_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonper_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1per_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1dur_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonrupturee_clicked              (GtkButton       *button,
                                        gpointer         user_data);
