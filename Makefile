all:
	mingw32-make -C PDCurses-3.8\wincon
	ren PDCurses-3.8\wincon\pdcurses.a libpdcurses.a
	g++ main.cpp player.cpp enemy.cpp Game.cpp Map.cpp Generator.cpp -o main -IPDCurses-3.8 -LPDCurses-3.8\wincon -lpdcurses
clean:
	del PDCurses-3.8\wincon\*.o PDCurses-3.8\wincon\*.a
	