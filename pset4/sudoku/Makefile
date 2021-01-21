#
# Makefile
#
# CC 50
# Pset 4
#

sudoku: Makefile sudoku.c sudoku.h
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -Wno-unused-but-set-variable -o sudoku sudoku.c -lncurses

clean:
	rm -f *.o a.out core log.txt sudoku

ncurses: Makefile ncurses.c
	gcc ncurses.c -o ncurses -lncurses

upload: Makefile sudoku.c
	git add . && git commit -m "Testing . . . " && git push

