#include <ncurses/curses.h>
#include <unistd.h>

int main() {

int x = 10, y = 10;
int korX = 0, korY = 0;

initscr();
raw();
keypad(stdscr, TRUE);
nodelay(stdscr, TRUE);
noecho();
mvprintw(20,20, "GUNAKAN WASD");

bool program = true;

while(program) {
int analog = getch();
mvprintw(0,0, "Gunakan WASD");

if (analog == KEY_UP) {
korY= -1;
korX = 0;
} else if (analog == KEY_DOWN) {
korX = 0;
korY+=1;
} else if (analog == KEY_LEFT) {
korX-=1;
korY=0;
} else if (analog == KEY_RIGHT) {
korX+=1;
korY=0;
} else if (analog == 'q') {
program = false;
}

x += korX;
y += korY;

if (y < 0) {
y += LINES-1;
} else if (y > LINES-1) {
y -= LINES-1;
}

clear();
mvprintw(y, x, "♪");
refresh();
usleep(100000);
}

endwin();
return 0;
}
