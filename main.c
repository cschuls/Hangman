/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#+
#+     Hangman
#+
#+     Copyright (C) 2022 by Craig Schulstad
#+
#+
#+ This program is free software; you can redistribute it and/or modify
#+ it under the terms of the GNU General Public License as published by
#+ the Free Software Foundation; either version 2 of the License, or
#+ (at your option) any later version.
#+
#+ This program is distributed in the hope that it will be useful,
#+ but WITHOUT ANY WARRANTY; without even the implied warranty of
#+ MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#+ GNU General Public License for more details.
#+
#+ You should have received a copy of the GNU General Public License
#+ along with this program; if not, write to the Free Software
#+ Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#+
#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

//	Sep 2, 2022

#include <gtk/gtk.h>
#include <ctype.h>

/* Structure to pass via address to the various signal handlers */

struct hang_data
{
    GtkWidget *img;
    GtkWidget *lbl;
    GtkWidget *usd;
    char  text[24];
    char  the_word[24];
    char  guess;
    gint  lives;
    gint  won_loss;
} hangman_data;

/* Prototypes */

static void activate (GtkApplication *, gpointer);
static void new_callback (GSimpleAction *, GVariant *, struct hang_data *);
static void quit_callback (GSimpleAction *, GVariant *, gpointer);
static void startup (GApplication *, gpointer);
static void make_guess(struct hang_data *);
static void display_dialog (gchar*);

void get_word(struct hang_data *);

void on_button_a_clicked(GtkButton *b, struct hang_data *);
void on_button_b_clicked(GtkButton *b, struct hang_data *);
void on_button_c_clicked(GtkButton *b, struct hang_data *);
void on_button_d_clicked(GtkButton *b, struct hang_data *);
void on_button_e_clicked(GtkButton *b, struct hang_data *);
void on_button_f_clicked(GtkButton *b, struct hang_data *);
void on_button_g_clicked(GtkButton *b, struct hang_data *);
void on_button_h_clicked(GtkButton *b, struct hang_data *);
void on_button_i_clicked(GtkButton *b, struct hang_data *);
void on_button_j_clicked(GtkButton *b, struct hang_data *);
void on_button_k_clicked(GtkButton *b, struct hang_data *);
void on_button_l_clicked(GtkButton *b, struct hang_data *);
void on_button_m_clicked(GtkButton *b, struct hang_data *);
void on_button_n_clicked(GtkButton *b, struct hang_data *);
void on_button_o_clicked(GtkButton *b, struct hang_data *);
void on_button_p_clicked(GtkButton *b, struct hang_data *);
void on_button_q_clicked(GtkButton *b, struct hang_data *);
void on_button_r_clicked(GtkButton *b, struct hang_data *);
void on_button_s_clicked(GtkButton *b, struct hang_data *);
void on_button_t_clicked(GtkButton *b, struct hang_data *);
void on_button_u_clicked(GtkButton *b, struct hang_data *);
void on_button_v_clicked(GtkButton *b, struct hang_data *);
void on_button_w_clicked(GtkButton *b, struct hang_data *);
void on_button_x_clicked(GtkButton *b, struct hang_data *);
void on_button_y_clicked(GtkButton *b, struct hang_data *);
void on_button_z_clicked(GtkButton *b, struct hang_data *);

int main (gint argc, char **argv)
{
    GtkApplication *app;
    gint status;

    app = gtk_application_new ("org.gtk.Hangman", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    g_signal_connect (app, "startup", G_CALLBACK (startup), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}

static void activate (GtkApplication *app, gpointer user_data)
{
    GtkCssProvider  *provider;

    GtkWidget       *clue;
    GtkWidget       *gallows_image;
    GtkWidget       *hangman_image;
    GtkWidget       *menubutton;
    GtkWidget       *menuimage;
    GMenu           *menumodel;
    GtkWidget       *used;
    GtkWidget       *window;

    GtkWidget       *gridx;
    GtkWidget       *grid0;
    GtkWidget       *grid1;
    GtkWidget       *grid2;
    GtkWidget       *grid3;
    GtkWidget       *grid4;
    GtkWidget       *grid5;
    GtkWidget       *grid6;
    GtkWidget       *grid7;
    GtkWidget       *grid8;

    GtkWidget       *spacer_1;
    GtkWidget       *spacer_2;
    GtkWidget       *spacer_3;
    GtkWidget       *spacer_4;
    GtkWidget       *spacer_5;

    GtkWidget       *button_a;
    GtkWidget       *button_b;
    GtkWidget       *button_c;
    GtkWidget       *button_d;
    GtkWidget       *button_e;
    GtkWidget       *button_f;
    GtkWidget       *button_g;
    GtkWidget       *button_h;
    GtkWidget       *button_i;
    GtkWidget       *button_j;
    GtkWidget       *button_k;
    GtkWidget       *button_l;
    GtkWidget       *button_m;
    GtkWidget       *button_n;
    GtkWidget       *button_o;
    GtkWidget       *button_p;
    GtkWidget       *button_q;
    GtkWidget       *button_r;
    GtkWidget       *button_s;
    GtkWidget       *button_t;
    GtkWidget       *button_u;
    GtkWidget       *button_v;
    GtkWidget       *button_w;
    GtkWidget       *button_x;
    GtkWidget       *button_y;
    GtkWidget       *button_z;

    window          = gtk_application_window_new (app);

    gridx           = gtk_grid_new ();
    grid0           = gtk_grid_new ();
    grid1           = gtk_grid_new ();
    grid2           = gtk_grid_new ();
    grid3           = gtk_grid_new ();
    grid4           = gtk_grid_new ();
    grid5           = gtk_grid_new ();
    grid6           = gtk_grid_new ();
    grid7           = gtk_grid_new ();
    grid8           = gtk_grid_new ();

    menubutton      = gtk_menu_button_new ();
    menuimage       = gtk_image_new();
    menumodel       = g_menu_new ();

    clue            = gtk_label_new("");
    spacer_1        = gtk_label_new("  ");
    spacer_2        = gtk_label_new("      ");
    spacer_3        = gtk_label_new("            ");
    spacer_4        = gtk_label_new("    ");
    spacer_5        = gtk_label_new("    ");
    used            = gtk_label_new("  ");

    provider        = gtk_css_provider_new();

    hangman_image   = gtk_image_new_from_resource("/Hangman/images/Hangman_Title.png");
    gallows_image   = gtk_image_new_from_resource("/Hangman/images/Hangman_0.png");

    gtk_window_set_title(GTK_WINDOW (window), "Hangman");
    gtk_window_set_default_size(GTK_WINDOW (window), 840, 460);

    gtk_widget_set_size_request(gallows_image, 240, 240);

    gtk_widget_set_name(clue, "Clue");
    gtk_css_provider_load_from_data(provider, "#Clue {font-family: \"Tahoma\"; font-size: 36px; }", -1, NULL);
    gtk_style_context_add_provider(gtk_widget_get_style_context(clue), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    gtk_image_set_from_icon_name(GTK_IMAGE(menuimage), "gtk-justify-fill", GTK_ICON_SIZE_BUTTON);

    button_q        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_q), "Q");
    gtk_widget_set_size_request(button_q, 24, 24);
    button_w        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_w), "W");
    gtk_widget_set_size_request(button_w, 24, 24);
    button_e        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_e), "E");
    gtk_widget_set_size_request(button_e, 24, 24);
    button_r        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_r), "R");
    gtk_widget_set_size_request(button_r, 24, 24);
    button_t       = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_t), "T");
    gtk_widget_set_size_request(button_t, 24, 24);
    button_y        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_y), "Y");
    gtk_widget_set_size_request(button_y, 24, 24);
    button_u        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_u), "U");
    gtk_widget_set_size_request(button_u, 24, 24);
    button_i        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_i), "I");
    gtk_widget_set_size_request(button_i, 24, 24);
    button_o        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_o), "O");
    gtk_widget_set_size_request(button_o, 24, 24);
    button_p        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_p), "P");
    gtk_widget_set_size_request(button_y, 24, 24);

    button_a        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_a), "A");
    gtk_widget_set_size_request(button_a, 24, 24);
    button_s        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_s), "S");
    gtk_widget_set_size_request(button_s, 24, 24);
    button_d        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_d), "D");
    gtk_widget_set_size_request(button_d, 24, 24);
    button_f        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_f), "F");
    gtk_widget_set_size_request(button_f, 24, 24);
    button_g        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_g), "G");
    gtk_widget_set_size_request(button_g, 24, 24);
    button_h        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_h), "H");
    gtk_widget_set_size_request(button_h, 24, 24);
    button_j        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_j), "J");
    gtk_widget_set_size_request(button_j, 24, 24);
    button_k        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_k), "K");
    gtk_widget_set_size_request(button_k, 24, 24);
    button_l        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_l), "L");
    gtk_widget_set_size_request(button_l, 24, 24);

    button_z        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_z), "Z");
    gtk_widget_set_size_request(button_z, 24, 24);
    button_x        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_x), "X");
    gtk_widget_set_size_request(button_x, 24, 24);
    button_c        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_c), "C");
    gtk_widget_set_size_request(button_c, 24, 24);
    button_v        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_v), "V");
    gtk_widget_set_size_request(button_v, 24, 24);
    button_b        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_b), "B");
    gtk_widget_set_size_request(button_b, 24, 24);
    button_n        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_n), "N");
    gtk_widget_set_size_request(button_n, 24, 24);
    button_m        = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button_m), "M");
    gtk_widget_set_size_request(button_m, 24, 24);

    gtk_widget_set_size_request(menubutton, 36, 36);

    gtk_container_add (GTK_CONTAINER (window), gridx);

    gtk_grid_attach(GTK_GRID (gridx), grid0, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid0), grid1, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid0), grid2, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID (grid0), grid3, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID (grid0), grid4, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID (grid0), grid5, 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID (grid0), grid7, 0, 5, 1, 1);
    gtk_grid_attach(GTK_GRID (grid0), grid8, 0, 6, 1, 1);
    gtk_grid_attach(GTK_GRID (gridx), grid6, 1, 0, 1, 1);

    gtk_grid_attach(GTK_GRID (grid1), spacer_4, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid1), menubutton, 1, 0, 1, 1);

    gtk_grid_attach(GTK_GRID (grid2), hangman_image, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid6), gallows_image, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid6), clue, 0, 1, 1, 1);

    gtk_grid_attach(GTK_GRID (grid3), spacer_1, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid3), button_q, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid3), button_w, 2, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid3), button_e, 3, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid3), button_r, 4, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid3), button_t, 5, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid3), button_y, 6, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid3), button_u, 7, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid3), button_i, 8, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid3), button_o, 9, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid3), button_p, 10, 0, 1, 1);

    gtk_grid_attach(GTK_GRID (grid4), spacer_2, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid4), button_a, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid4), button_s, 2, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid4), button_d, 3, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid4), button_f, 4, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid4), button_g, 5, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid4), button_h, 6, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid4), button_j, 7, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid4), button_k, 8, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid4), button_l, 9, 0, 1, 1);

    gtk_grid_attach(GTK_GRID (grid5), spacer_3, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid5), button_z, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid5), button_x, 2, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid5), button_c, 3, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid5), button_v, 4, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid5), button_b, 5, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid5), button_n, 6, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid5), button_m, 7, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid7), spacer_5, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID (grid8), used, 0, 0, 1, 1);

    gtk_button_set_image(GTK_BUTTON(menubutton), menuimage);
    gtk_button_set_label(GTK_BUTTON(menubutton), " ");
    gtk_button_set_always_show_image(GTK_BUTTON(menubutton), TRUE);
    gtk_button_set_image_position(GTK_BUTTON(menubutton), GTK_POS_RIGHT);

    g_menu_append(menumodel, "New", "app.new");
    g_menu_append(menumodel, "Quit", "app.quit");

    gtk_menu_button_set_menu_model (GTK_MENU_BUTTON (menubutton), G_MENU_MODEL (menumodel));

    /* Initialize the display widgets and starting game values */

    hangman_data.img        = gallows_image;
    hangman_data.lbl        = clue;
    hangman_data.usd        = used;
    hangman_data.lives      = 6;
    hangman_data.guess      = ' ';
    hangman_data.won_loss   = 0;
    get_word(&hangman_data);
    gtk_label_set_text(GTK_LABEL(hangman_data.lbl), hangman_data.text);
    gtk_label_set_text(GTK_LABEL(hangman_data.usd), "");

    /* Keyboard button signals*/

    g_signal_connect(G_OBJECT(button_a), "clicked", G_CALLBACK(on_button_a_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_b), "clicked", G_CALLBACK(on_button_b_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_c), "clicked", G_CALLBACK(on_button_c_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_d), "clicked", G_CALLBACK(on_button_d_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_e), "clicked", G_CALLBACK(on_button_e_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_f), "clicked", G_CALLBACK(on_button_f_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_g), "clicked", G_CALLBACK(on_button_g_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_h), "clicked", G_CALLBACK(on_button_h_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_i), "clicked", G_CALLBACK(on_button_i_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_j), "clicked", G_CALLBACK(on_button_j_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_k), "clicked", G_CALLBACK(on_button_k_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_l), "clicked", G_CALLBACK(on_button_l_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_m), "clicked", G_CALLBACK(on_button_m_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_n), "clicked", G_CALLBACK(on_button_n_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_o), "clicked", G_CALLBACK(on_button_o_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_p), "clicked", G_CALLBACK(on_button_p_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_q), "clicked", G_CALLBACK(on_button_q_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_r), "clicked", G_CALLBACK(on_button_r_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_s), "clicked", G_CALLBACK(on_button_s_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_t), "clicked", G_CALLBACK(on_button_t_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_u), "clicked", G_CALLBACK(on_button_u_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_v), "clicked", G_CALLBACK(on_button_v_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_w), "clicked", G_CALLBACK(on_button_w_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_x), "clicked", G_CALLBACK(on_button_x_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_y), "clicked", G_CALLBACK(on_button_y_clicked), &hangman_data);
    g_signal_connect(G_OBJECT(button_z), "clicked", G_CALLBACK(on_button_z_clicked), &hangman_data);

    gtk_widget_show_all (window);
}

static void new_callback (GSimpleAction *simple, GVariant *parameter, struct hang_data * user_data)
{
    gtk_image_set_from_resource(GTK_IMAGE(user_data->img), "/Hangman/images/Hangman_0.png");
    user_data->lives = 6;
    get_word(user_data);
    gtk_label_set_text(GTK_LABEL(user_data->lbl), user_data->text);
    user_data->guess = ' ';
    user_data->won_loss = 0;
    gtk_label_set_text(GTK_LABEL(user_data->usd), "");
}

static void quit_callback (GSimpleAction *simple, GVariant *parameter, gpointer user_data)
{
    GApplication *application = user_data;
    g_application_quit (application);
}

static void startup (GApplication *app, gpointer user_data)
{
    GSimpleAction *new_action;
    GSimpleAction *quit_action;

    new_action = g_simple_action_new ("new", NULL);
    g_signal_connect (new_action, "activate", G_CALLBACK (new_callback), &hangman_data);
    g_action_map_add_action (G_ACTION_MAP (app), G_ACTION (new_action));

    quit_action = g_simple_action_new ("quit", NULL);
    g_signal_connect (quit_action, "activate", G_CALLBACK (quit_callback), app);
    g_action_map_add_action (G_ACTION_MAP (app), G_ACTION (quit_action));
}

static void display_dialog (gchar* message)
{
    GtkWidget *dialog;

    dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "%s", message);
    //g_signal_connect_swapped (dialog, "response", G_CALLBACK (gtk_widget_destroy), dialog);   /* GTK4 */
    //gtk_widget_show_all (dialog);                                                             /* GTK4 */
    gtk_dialog_run(GTK_DIALOG (dialog));                                                        /* GTK3 */
    gtk_widget_destroy(dialog);                                                                 /* GTK3 */
}

void make_guess(struct hang_data * guess_data)
{
    if (guess_data->won_loss != 0)
    {
        return;
    }
    gint found = 0;

    char alphabet[60];
    gint k;

    if ((strcmp(gtk_label_get_text(GTK_LABEL(guess_data->usd)), "") == 0))
    {
        for (k = 0; k < 60; k ++)
        {
            alphabet[k] = 0;
        }
        alphabet[0] = ' ';
        alphabet[1] = 'U';
        alphabet[2] = 's';
        alphabet[3] = 'e';
        alphabet[4] = 'd';
    }
    else
    {
        for (k = 0; k < 60; k ++)
        {
            alphabet[k] = 0;
        }
        strcpy(alphabet, gtk_label_get_text(GTK_LABEL(guess_data->usd)));
    }

    k = strlen(alphabet);
    alphabet[k] = ' ';
    alphabet[k + 1] = guess_data->guess;

    gtk_label_set_text(GTK_LABEL(guess_data->usd), alphabet);

    for (gint k = 0; k < strlen(guess_data->the_word); k++)
    {
        if (k % 2 == 0)
        {
            if (guess_data->guess == guess_data->the_word[k])
            {
                found = 1;
                guess_data->text[k] = guess_data->guess;
                gtk_label_set_text(GTK_LABEL(guess_data->lbl), guess_data->text);
            }
        }
    }
    if (found == 0)
    {
        guess_data->lives -= 1;
    }

    if (guess_data->lives == 6)
    {
        gtk_image_set_from_resource(GTK_IMAGE(guess_data->img), "/Hangman/images/Hangman_0.png");
    }
    else if (guess_data->lives == 5)
    {
        gtk_image_set_from_resource(GTK_IMAGE(guess_data->img), "/Hangman/images/Hangman_1.png");
    }
    else if (guess_data->lives == 4)
    {
        gtk_image_set_from_resource(GTK_IMAGE(guess_data->img), "/Hangman/images/Hangman_2.png");
    }
    else if (guess_data->lives == 3)
    {
        gtk_image_set_from_resource(GTK_IMAGE(guess_data->img), "/Hangman/images/Hangman_3.png");
    }
    else if (guess_data->lives == 2)
    {
        gtk_image_set_from_resource(GTK_IMAGE(guess_data->img), "/Hangman/images/Hangman_4.png");
    }
    else if (guess_data->lives == 1)
    {
        gtk_image_set_from_resource(GTK_IMAGE(guess_data->img), "/Hangman/images/Hangman_5.png");
    }
    else
    {
        gtk_label_set_text(GTK_LABEL(guess_data->lbl), guess_data->the_word);
        gtk_image_set_from_file(GTK_IMAGE(guess_data->img), "/home/craig/C_Programs/GTK_Projects/Hangman/images/Hangman_6.png");
        guess_data->won_loss = -1;
        display_dialog("Sorry! - You lost\nSelect \"New Game\" to play again");
    }

    if ((strcmp(guess_data->text, guess_data->the_word)) == 0)
    {
        guess_data->won_loss = 1;
        display_dialog("Yea! - You won\nSelect \"New Game\" to play again");
    }

}

void get_word(struct hang_data * user_data)
{
    time_t t;
    gint r = 0;
    gint y = 0;
    FILE *fp;

    srand((unsigned) time(&t));

    char line[24];

    fp = fopen("Words.txt", "r");

    if (!fp)
    {
        g_print("Couldn't find file");
        strcpy(user_data->the_word, "H A N G M A N");
        strcpy(user_data->text, "_ _ _ _ _ _ _");
        return;
    }

    while (fgets(line, 20, fp))
    {
        y += 1;
    }

    fclose(fp);

    r = rand() % y;

    fp = fopen("Words.txt", "r");

    y = 0;

    while (fgets(line, 20, fp))
    {
        y += 1;

        if (r == y)
        {
            break;
        }
        for (gint j = 0; j < 24; j++)
        {
            user_data->text[j] = 0;
            user_data->the_word[j] = 0;
        }

        for (gint j = 0; j < strlen(line); j++)
        {
            user_data->the_word[2 * j] = toupper(line[j]);
            user_data->text[2 * j] = '_';
            if (j < strlen(line) - 2)
            {
                user_data->the_word[2 * j + 1] = ' ';
                user_data->text[2 * j + 1] = ' ';
            }
        }
    }

    fclose(fp);

    return;
}

void on_button_a_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'A';
    make_guess(user_data);
}

void on_button_b_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'B';
    make_guess(user_data);
}

void on_button_c_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'C';
    make_guess(user_data);
}

void on_button_d_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'D';
    make_guess(user_data);
}

void on_button_e_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'E';
    make_guess(user_data);
}

void on_button_f_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'F';
    make_guess(user_data);
}

void on_button_g_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'G';
    make_guess(user_data);
}

void on_button_h_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'H';
    make_guess(user_data);
}

void on_button_i_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'I';
    make_guess(user_data);
}

void on_button_j_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'J';
    make_guess(user_data);
}

void on_button_k_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'K';
    make_guess(user_data);
}

void on_button_l_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'L';
    make_guess(user_data);
}

void on_button_m_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'M';
    make_guess(user_data);
}

void on_button_n_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'N';
    make_guess(user_data);
}

void on_button_o_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'O';
    make_guess(user_data);
}

void on_button_p_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'P';
    make_guess(user_data);
}

void on_button_q_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'Q';
    make_guess(user_data);
}

void on_button_r_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'R';
    make_guess(user_data);
}

void on_button_s_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'S';
    make_guess(user_data);
}

void on_button_t_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'T';
    make_guess(user_data);
}

void on_button_u_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'U';
    make_guess(user_data);
}

void on_button_v_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'V';
    make_guess(user_data);
}

void on_button_w_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'W';
    make_guess(user_data);
}

void on_button_x_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'X';
    make_guess(user_data);
}

void on_button_y_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'Y';
    make_guess(user_data);
}

void on_button_z_clicked(GtkButton *b, struct hang_data * user_data)
{
    user_data->guess = 'Z';
    make_guess(user_data);
}
