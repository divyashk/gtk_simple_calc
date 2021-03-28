#include <gtk/gtk.h>

GtkWidget *operand1;
GtkWidget *operand2;
GtkWidget *operator;
GtkWidget *result;
GtkWidget *equal;
GtkWidget *calculate;

static void calc(GtkApplication *app, gpointer user_data)
{

    int op1 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(operand1)));
    int op2 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(operand2)));
    char *oper = (char *)gtk_entry_get_text(GTK_ENTRY(operator));
    g_print("%d %d\n", op1, op2);
    g_print("%d\n", *oper);
    char buffer[32];

    if (strcmp(oper, "+") == 0)
    {
        snprintf(buffer, sizeof(buffer), "%d", op1 + op2);
    }
    else if (strcmp(oper, "-") == 0)
    {
        snprintf(buffer, sizeof(buffer), "%d", op1 - op2);
    }
    else if (strcmp(oper, "/") == 0)
    {
        snprintf(buffer, sizeof(buffer), "%d", op1 / op2);
    }
    else if (strcmp(oper, "*") == 0)
    {
        snprintf(buffer, sizeof(buffer), "%d", op1 * op2);
    }
    else
    {
        snprintf(buffer, sizeof(buffer), "%s", "invalid operator");
    }

    gtk_label_set_text(GTK_LABEL(result), buffer);
}

int main(int argc, char **argv)
{

    gtk_init(&argc, &argv);
    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 1000);
    gtk_widget_show_all(window);

    GtkWidget *grid;
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    operand1 = gtk_entry_new();
    operand2 = gtk_entry_new();
    operator= gtk_entry_new();
    equal = gtk_label_new(" = ");
    result = gtk_label_new("      ");
    calculate = gtk_button_new_with_label("Calculate");

    g_signal_connect(calculate, "clicked", G_CALLBACK(calc), NULL);

    gtk_grid_attach(GTK_GRID(grid), operand1, 1, 1, 2, 2);
    gtk_grid_attach(GTK_GRID(grid), operand2, 8, 1, 2, 2);
    gtk_grid_attach(GTK_GRID(grid), operator, 5, 1, 2, 2);
    gtk_grid_attach(GTK_GRID(grid), equal, 13, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), result, 15, 2, 2, 2);
    gtk_grid_attach(GTK_GRID(grid), calculate, 3, 10, 2, 2);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}