#include <ncurses.h>

void print_menu(WINDOW *menu_win, int highlight, char *choices[], int n_choices) {
    int x, y, i;
    x = 2; 
    y = 2;

    box(menu_win, 0, 0); // membuat bingkai
    for (i = 0; i < n_choices; ++i) {
        if (highlight == i + 1) { // jika item dipilih
            wattron(menu_win, A_REVERSE); // menyoroti item
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE); // menghapus sorotan
        } else {
            mvwprintw(menu_win, y, x, "%s", choices[i]);
        }
        ++y;
    }
    wrefresh(menu_win); // memperbarui jendela
}

int main() {
    WINDOW *menu_win;
    int highlight = 1; // item yang disorot
    int choice = 0; // pilihan pengguna
    int c; // untuk menyimpan input dari pengguna
    char *choices[] = { "New Game", "Continue", "Options", "Exit" };
    int n_choices = sizeof(choices) / sizeof(char *);

    initscr(); // inisialisasi ncurses
    clear(); // membersihkan layar
    noecho(); // tidak menampilkan input
    cbreak(); // menyalakan mode karakter
    keypad(stdscr, TRUE); // mengaktifkan tombol panah
    menu_win = newwin(10, 40, 4, 4); // membuat jendela untuk menu
    refresh(); // memperbarui layar

    print_menu(menu_win, highlight, choices, n_choices); // mencetak menu

    while (1) {
        c = wgetch(menu_win); // mendapatkan input dari pengguna

        switch (c) {
            case KEY_UP: // jika tombol panah atas ditekan
                if (highlight == 1)
                    highlight = n_choices; // jika sudah di atas, kembali ke bawah
                else
                    --highlight;
                break;
            case KEY_DOWN: // jika tombol panah bawah ditekan
                if (highlight == n_choices)
                    highlight = 1; // jika sudah di bawah, kembali ke atas
                else
                    ++highlight;
                break;
            case 10: // jika tombol Enter ditekan
                choice = highlight; // simpan pilihan
                break;
            default:
                break;
        }
        print_menu(menu_win, highlight, choices, n_choices); // perbarui menu
        if (choice != 0) // jika ada pilihan
            break; // keluar dari loop
    }

    // Tindakan berdasarkan pilihan pengguna
    switch (choice) {
        case 1:
            mvprintw(0, 0, "You chose New Game");
            break;
        case 2:
            mvprintw(0, 0, "You chose Continue");
            break;
        case 3:
            mvprintw(0, 0, "You chose Options");
            break;
        case 4:
            mvprintw(0, 0, "You chose Exit");
            break;
    }
    refresh(); // memperbarui layar
    getch(); // menunggu input sebelum keluar

    endwin(); // mengakhiri ncurses
    return 0;
}