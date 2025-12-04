#include <ncurses.h>
#include <unistd.h>

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

int x = LINES/4, y = 0;
int tinggi = y+5, lebar = x+10;

WINDOW *kor_menu = newwin(tinggi, lebar, y, x);
keypad(kor_menu, TRUE);

const char *opsi_pilihan[] = {
"MULAI GAME",
"PILIH LEVEL",
"KELUAR GAME",
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
