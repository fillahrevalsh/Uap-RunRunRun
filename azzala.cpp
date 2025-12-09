#include <ncurses/curses.h>
#include <unistd.h>
#include <string.h>
#include <windows.h>

void menu(WINDOW *kor_menu, const char *opsi_pilihan[], int opsi, int jumlah_menu) {
box(kor_menu, 0, 0);

for (int i = 0; i < jumlah_menu; i++) {

if (i == opsi) {
wattron(kor_menu, A_REVERSE);
mvwprintw(kor_menu, i+1, 1, "%s", opsi_pilihan[i]);
wattroff(kor_menu, A_REVERSE);
}else {
mvwprintw(kor_menu, i+1, 1, "%s", opsi_pilihan[i]);
}
}

wrefresh(kor_menu);
}

int main () {

initscr();
clear();
noecho();
cbreak();
curs_set(0);

start_color();
init_pair(1, COLOR_CYAN, COLOR_BLACK);
init_pair(2, COLOR_BLUE, COLOR_BLACK);
init_pair(3, COLOR_GREEN, COLOR_BLACK);
init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
init_pair(5, COLOR_RED, COLOR_BLACK);
init_pair(6, COLOR_YELLOW, COLOR_BLACK);
init_pair(7, COLOR_BLACK, COLOR_BLACK);

int tengahX = COLS / 2;

mvprintw(3, tengahX - 20, "========================================");
mvprintw(4, tengahX - (-10), "==========");

wattron(stdscr, COLOR_PAIR (3) | A_BOLD);
mvprintw(4, tengahX - 9, "<o RUN RUN RUN o>");
wattroff(stdscr, COLOR_PAIR (3) | A_BOLD);

mvprintw(4, tengahX - 20, "=========");
mvprintw(5, tengahX - 20, "========================================");

refresh();

char pesan[] = "SELAMAT DATANG DI RUN RUN RUN GAME! ";
int z = 0;

for(int i = 0; i < 100; i++){
    attron(COLOR_PAIR(7));
    mvprintw(0, tengahX - 20, "%s", pesan);
    attroff(COLOR_PAIR(7));
    refresh();
Sleep(500);
    attron(COLOR_PAIR(6));
    mvprintw(0, tengahX - 20, "%s", pesan);
    attroff(COLOR_PAIR(6));
    refresh();

    z++;
    if(z < tengahX) z = 0;

    Sleep(500);
}

int x = LINES/3, y = 3;
int tinggi = y+2, lebar = x+8;

WINDOW *kor_menu = newwin(tinggi, lebar, y, x);
keypad(kor_menu, TRUE);

const char *opsi_pilihan[] = {
" MULAI GAME",
" PILIH LEVEL",
" KELUAR GAME",
};

int jumlah_menu = sizeof(opsi_pilihan)/sizeof(opsi_pilihan[0]);
int milih = -1;
int opsi = 0;

while (1) {
menu(kor_menu, opsi_pilihan, opsi, jumlah_menu);
int tombol = wgetch(kor_menu);

switch(tombol) {

case KEY_UP :
if (opsi <= 0) {
opsi = jumlah_menu -1;
} else {
opsi--;
}
break;
case KEY_DOWN :
if (opsi >= jumlah_menu -1) {
opsi = 0;
}
else {
opsi++;
}
break;

case 10 :
milih = opsi;
break;
}

if (milih == 2) {
break;
}
}

refresh();
endwin();

return 0;
}
