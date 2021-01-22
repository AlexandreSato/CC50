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
#define TITLE "5ud0ku"

// banner's colors
#define FG_BANNER COLOR_CYAN
#define BG_BANNER COLOR_BLACK

// grid's colors
#define FG_GRID COLOR_YELLOW  //WHITE
#define BG_GRID COLOR_BLACK

// border's colors
#define FG_BORDER COLOR_WHITE
#define BG_BORDER COLOR_BLUE

// logo's colors
#define FG_LOGO COLOR_RED
#define BG_LOGO COLOR_BLACK

// number placed by the player
#define FG_NUMBER COLOR_YELLOW //203 //trying orange
#define BG_NUMBER COLOR_BLACK

// nicknames for pairs of colors
enum { PAIR_BANNER = 1, PAIR_GRID, PAIR_BORDER, PAIR_LOGO, PAIR_NUMBER };
