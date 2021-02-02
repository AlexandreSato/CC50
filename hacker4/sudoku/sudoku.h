/****************************************************************************
 * sudoku.h
 *
 * CC 50
 * Pset 4
 *
 * Compile-time options for the game of Sudoku.
 ***************************************************************************/

// game's author
#define AUTHOR "Alexandre Nobuharu Sato"

// game's title
#define TITLE "S U D O K U"

// banner's colors
#define FG_BANNER COLOR_CYAN
#define BG_BANNER COLOR_BLACK

// grid's colors
#define FG_GRID COLOR_YELLOW  //WHITE
#define BG_GRID COLOR_BLACK

// border's colors
#define FG_BORDER COLOR_WHITE
#define BG_BORDER COLOR_RED

// logo's colors
#define FG_LOGO COLOR_CYAN
#define BG_LOGO COLOR_BLACK

// number placed by the player
#define FG_PLAYNUMBER COLOR_GREEN //203 orange work only graphical interface activated
#define BG_PLAYNUMBER COLOR_BLACK

// repeated numbers
#define FG_REPEATEDNUMBER COLOR_RED
#define BG_REPEATEDNUMBER COLOR_BLACK

#define FG_HINT COLOR_YELLOW
#define BG_HINT COLOR_BLACK

// nicknames for pairs of colors
enum { PAIR_BANNER = 1, PAIR_GRID, PAIR_BORDER, PAIR_LOGO, PAIR_PLAYNUMBER, PAIR_REPEATEDNUMBER, PAIR_HINT };

//Console suppor only eight basic colors:
//1- COLOR_BLACK
//2- COLOR_RED
//3- COLOR_GREEN
//4- COLOR_YELLOW
//5- COLOR_BLUE
//6- COLOR_MAGENTA
//7- COLOR_CYAN
//8- COLOR_WHITE
