#include <ncurses/curses.h>
#include <unistd.h>
#include <string.h>
#include <cstdlib>

void game(int target, int level){
 //void pertama untuk game

int x = COLS/2, y = LINES/2;
int korX = 0, korY = 0;

initscr();
curs_set(0);
raw();
keypad(stdscr, TRUE);
nodelay(stdscr, TRUE);
noecho();

bool program = true;

int musuhX[target];
int musuhY[target];
int dapat = 0;

for (int i = 0; i<target; i++) {
musuhX[i] = rand() % COLS;
musuhY[i] = rand() % LINES;
}

while(1) {
int analog = getch();
if (analog == KEY_UP) {
korY= -1;
korX = 0;
} else if (analog == KEY_DOWN) {
korY+=1;
korX = 0;
} else if (analog == KEY_LEFT) {
korX-=1;
korY=0;
} else if (analog == KEY_RIGHT) {
korX+=1;
korY=0;
} else if (analog == 'q') {
break;
}

x += korX;
y += korY;

if (y < 0) {
y = LINES-1;
} else if (y > LINES-1) {
y = 1;
}

if (x < 0) {
x = COLS-1;
} else if (x > COLS-1) {
x = 1;
}

clear();

for (int i =0; i < target; i++) {
mvprintw(musuhY[i], musuhX[i], "X");

if (musuhY[i] == y && musuhX[i] == x) {
dapat += 1;
musuhX[i] = -1;
musuhY[i] = -1;
}

if (dapat == target) {
break;
}

}

mvprintw(0, COLS/2, "%d", dapat);


mvprintw(y, x, "♪");
refresh();
usleep(level);
}

}





//void kedua untuk window menu
void menu(WINDOW *kotak,WINDOW *kor_menu, const char *opsi_pilihan[], int opsi, int jumlah_menu) {

box(kor_menu, 0, 0);

for (int i = 0; i < jumlah_menu; i++) {

if (i == opsi) {
wattron(kotak, A_REVERSE);
mvwprintw(kotak, i+1, 1, "%s", opsi_pilihan[i]);
wattroff(kotak, A_REVERSE);
}else {
mvwprintw(kotak, i+1, 1, "%s", opsi_pilihan[i]);
}
}

wrefresh(kor_menu);
}





int opening(){ //void ketiga untuk ala-ala opening

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

mvprintw(12, tengahX - 20,   "     ==============================     ");
mvprintw(13, tengahX - (-10), "==========");

wattron(stdscr, COLOR_PAIR (3) | A_BOLD);
mvprintw(13, tengahX - 10, "<o SELAMAT DATANG o>");
wattroff(stdscr, COLOR_PAIR (3) | A_BOLD);

mvprintw(13, tengahX - 20,                                  "=========");
mvprintw(14, tengahX - 20,   "     ==============================     ");

refresh();

char pesan[] = "  SELAMAT DATANG DI RUN RUN RUN GAME! ";

for(int i = 0; i<= 5; i++){
    attron(COLOR_PAIR(3));
mvprintw(1, tengahX - 17, "####  #  # #   #  ####  #  # #   #");
mvprintw(2, tengahX - 17, "#   # #  # ##  #  #   # #  # ##  #");
mvprintw(3, tengahX - 17, "####  #  # # # #  ####  #  # # # #");
mvprintw(4, tengahX - 17, "#   # #  # #  ##  #   # #  # #  ##");
mvprintw(5, tengahX - 17, "#   #  ##  #   #  #   #  ##  #   #");

 mvprintw(7, tengahX - 17, "        ####  #  # #   #           ");
 mvprintw(8, tengahX - 17, "        #   # #  # ##  #           ");
 mvprintw(9, tengahX - 17, "        ####  #  # # # #           ");
mvprintw(10, tengahX - 17, "        #   # #  # #  ##           ");
mvprintw(11, tengahX - 17, "        #   #  ##  #   #           ");
    attroff(COLOR_PAIR(3));
    refresh();
usleep(500000);
    attron(COLOR_PAIR(6));
mvprintw(1, tengahX - 17, "####  #  # #   #  ####  #  # #   #");
mvprintw(2, tengahX - 17, "#   # #  # ##  #  #   # #  # ##  #");
mvprintw(3, tengahX - 17, "####  #  # # # #  ####  #  # # # #");
mvprintw(4, tengahX - 17, "#   # #  # #  ##  #   # #  # #  ##");
mvprintw(5, tengahX - 17, "#   #  ##  #   #  #   #  ##  #   #");

 mvprintw(7, tengahX - 17, "        ####  #  # #   #           ");
 mvprintw(8, tengahX - 17, "        #   # #  # ##  #           ");
 mvprintw(9, tengahX - 17, "        ####  #  # # # #           ");
mvprintw(10, tengahX - 17, "        #   # #  # #  ##           ");
mvprintw(11, tengahX - 17, "        #   #  ##  #   #           ");
refresh();

    attroff(COLOR_PAIR(6));
    refresh();

    usleep(500000);
}

while (1) {
mvprintw(15, tengahX - 7, "tekan ENTER");
refresh();
int tekan = getch();
switch (tekan) {
case 10:
mvprintw(8, tengahX - 7, "");
}
break;
}

int x = tengahX-20, y = 17;
int tinggi = y, lebar = x+20;
WINDOW *kor_menu = newwin(tinggi, lebar, y, x);
keypad(kor_menu, TRUE);


int tengahX1 = COLS/2;
int x1 = tengahX1-20, y1 = 17;
int kory1 = y1, korx1 = x1+20;
WINDOW *kotak = newwin (kory1,korx1, y1, x1);
keypad(kotak, TRUE);
wgetch(kor_menu);

wrefresh(kotak);
wrefresh(kor_menu);


const char *opsi_pilihan[] = {
" MULAI GAME",
" PILIH LEVEL",
" KELUAR GAME",
};

int jumlah_menu = sizeof(opsi_pilihan)/sizeof(opsi_pilihan[0]);
int milih = -1;
int opsi = 0;

//fungsi while
while (1) {

menu(kotak, kor_menu, opsi_pilihan, opsi, jumlah_menu);
int tombol = wgetch(kotak);
wrefresh(kor_menu);


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
return milih;
}

}

refresh();
return milih;
}





//Pilih level
int level(){

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

mvprintw(1, tengahX - 20,   "     ==============================     ");
mvprintw(2, tengahX - (-10), "==========");

wattron(stdscr, COLOR_PAIR (3) | A_BOLD);
mvprintw(2, tengahX - 9, "<o PILIH LEVEL o>");
wattroff(stdscr, COLOR_PAIR (3) | A_BOLD);

mvprintw(2, tengahX - 20,                                  "=========");
mvprintw(3, tengahX - 20,   "========================================");

refresh();


for(int i = 0; i<= 1; i++){
    attron(COLOR_PAIR(3));
mvprintw(4, tengahX - 17, "####  #  # #   #  ####  #  # #   #");
mvprintw(5, tengahX - 17, "#   # #  # ##  #  #   # #  # ##  #");
mvprintw(6, tengahX - 17, "####  #  # # # #  ####  #  # # # #");
mvprintw(7, tengahX - 17, "#   # #  # #  ##  #   # #  # #  ##");
mvprintw(8, tengahX - 17, "#   #  ##  #   #  #   #  ##  #   #");

mvprintw(10, tengahX - 17, "        ####  #  # #   #           ");
mvprintw(11, tengahX - 17, "        #   # #  # ##  #           ");
mvprintw(12, tengahX - 17, "        ####  #  # # # #           ");
mvprintw(13, tengahX - 17, "        #   # #  # #  ##           ");
mvprintw(14, tengahX - 17, "        #   #  ##  #   #           ");
    attroff(COLOR_PAIR(3));
    refresh();
usleep(500000);
    attron(COLOR_PAIR(6));
mvprintw(4, tengahX - 17, "####  #  # #   #  ####  #  # #   #");
mvprintw(5, tengahX - 17, "#   # #  # ##  #  #   # #  # ##  #");
mvprintw(6, tengahX - 17, "####  #  # # # #  ####  #  # # # #");
mvprintw(7, tengahX - 17, "#   # #  # #  ##  #   # #  # #  ##");
mvprintw(8, tengahX - 17, "#   #  ##  #   #  #   #  ##  #   #");

mvprintw(10, tengahX - 17, "        ####  #  # #   #           ");
mvprintw(11, tengahX - 17, "        #   # #  # ##  #           ");
mvprintw(12, tengahX - 17, "        ####  #  # # # #           ");
mvprintw(13, tengahX - 17, "        #   # #  # #  ##           ");
mvprintw(14, tengahX - 17, "        #   #  ##  #   #           ");
refresh();

    attroff(COLOR_PAIR(6));
    refresh();

    usleep(500000);
}

int x = tengahX-20, y = 17;
int tinggi = y, lebar = x+20;
WINDOW *kor_menu = newwin(tinggi, lebar, y, x);
keypad(kor_menu, TRUE);


int tengahX1 = COLS/2;
int x1 = tengahX1-20, y1 = 17;
int kory1 = y1, korx1 = x1+20;
WINDOW *kotak = newwin (kory1,korx1, y1, x1);
keypad(kotak, TRUE);

wrefresh(kotak);
wrefresh(kor_menu);


const char *opsi_pilihan[] = {
" MUDAH ",
" SEDANG ",
" SULIT ",
" KEMBALI ",
};

int jumlah_menu = sizeof(opsi_pilihan)/sizeof(opsi_pilihan[0]);
int milih = -1;
int opsi = 0;

//fungsi while
while (1) {

menu(kotak, kor_menu, opsi_pilihan, opsi, jumlah_menu);
int tombol = wgetch(kotak);
wrefresh(kor_menu);


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
return milih;
}

}

refresh();
return milih;
}



//fungsi utama
int main() {

start_color();
init_pair(3, COLOR_WHITE, COLOR_BLACK);
bool program = true;
int tengahX = COLS/2;
while(program){
int pilih = opening();

if (pilih == 0) {
game(5,150000);
wattron(stdscr, COLOR_PAIR (3) | A_BOLD);
mvprintw(LINES/2,COLS/2-7, "Level 1 done...");
wattroff(stdscr, COLOR_PAIR (3) | A_BOLD);
refresh();
usleep(5000000);


game(10,100000);
wattron(stdscr, COLOR_PAIR (3) | A_BOLD);
mvprintw(LINES/2,COLS/2-7, "Level 2 done...");
wattroff(stdscr, COLOR_PAIR (3) | A_BOLD);
refresh();
usleep(5000000);

game(20,80000);
wattron(stdscr, COLOR_PAIR (3) | A_BOLD);
mvprintw(LINES/2,(COLS/2) - 16, "Level 3 done... KAMU JAGO BANGET");
wattroff(stdscr, COLOR_PAIR (3) | A_BOLD);
refresh();
usleep(5000000);

} else if(pilih == 1) {

while (1) {
int kesulitan = level();
if (kesulitan == 0) {
game(5,150000);
wattron(stdscr, COLOR_PAIR (3) | A_BOLD);
mvprintw(LINES/2,(COLS/2)-7, "Level 1 done...");
wattroff(stdscr, COLOR_PAIR (3) | A_BOLD);
refresh();
usleep(5000000);
} else if (kesulitan == 1) {
game(10,100000);
wattron(stdscr, COLOR_PAIR (3) | A_BOLD);
mvprintw(LINES/2,(COLS/2)-7, "Level 2 done...");
wattroff(stdscr, COLOR_PAIR (3) | A_BOLD);
refresh();
usleep(5000000);
} else if (kesulitan == 2) {
game(20,80000);
wattron(stdscr, COLOR_PAIR (3) | A_BOLD);
mvprintw(LINES/2,(COLS/2) - 7, "Level 3 done...");
wattroff(stdscr, COLOR_PAIR (3) | A_BOLD);
refresh();
usleep(5000000);
} else if (kesulitan == 3) {
break;
}
}

} else if (pilih == 2) {
break;
}
}

endwin();
return 0;
}
