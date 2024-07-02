CC = gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 -I brick_game/tetris -I gui/cli
OS = $(shell uname)
ifeq ($(OS), Linux)
 LIBS = -lcheck -lpthread -lrt -lsubunit -lm
 LCOV = -o
else
 LIBS = -lcheck -lpthread -lm
 LCOV = --ignore-errors unmapped -o
endif



TESTS=$(wildcard ./unit_tests/*.c)
OBJ_FSM := tetris_fsm.o tetris_backend.o
OBJ_CLI := brick_game_frontend.o

INSTALL_DIR = ./bin

VERSION = 1.0
TARGET = tetris
DIST_DIR = $(TARGET)-$(VERSION)
DIST_SOURCES = ./Makefile ./unit_tests ./gui ./brick_game

all: clean tetris
	./tetris

install: clean tetris
	mkdir $(INSTALL_DIR)
	cp tetris $(INSTALL_DIR)

uninstall:
	rm -rf $(INSTALL_DIR)

dist: clean 
	mkdir -p $(DIST_DIR)
	cp -r $(DIST_SOURCES) $(DIST_DIR)
	tar -czf $(DIST_DIR).tar.gz $(DIST_DIR)
	rm -rf $(DIST_DIR)

dvi: clean doxy
	(cd ./doxygen/latex; sudo pdflatex refman.tex)
	
doxy: clean
	doxygen

clean:
	rm -rf *.a *.o *.gcno *.gcda unit_test *.css *.html *.gcov tetris *.txt ./doxygen

rebuild: clean all

tetris: tetris.a $(OBJ_CLI) main.o
	$(CC) $(CFLAGS) $^ -o $@ tetris.a -lncurses

%.o: brick_game/tetris/%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: gui/cli/%.c
	$(CC) $(CFLAGS) -c $< -o $@

tetris.a: $(OBJ_FSM)
	ar rc tetris.a $(OBJ_FSM)
	ranlib tetris.a

test: clean
	$(CC) $(CFLAGS) $(TESTS) -c 
	$(CC) $(CFLAGS) -o unit_test *.o ./brick_game/tetris/*.c --coverage $(LIBS)
	chmod +x unit_test
	./unit_test

gcov_report: clean test
	gcov *.gcda
	gcovr --html-details -o report.html -g

style:
	cp ../materials/linters/.clang-format .
	 clang-format -n ./brick_game/tetris/*.c ./brick_game/tetris/*h ./gui/cli/*.c ./gui/cli/*.h ./unit_tests/*.c
	rm -rf .clang-format

style_fix:
	cp ../materials/linters/.clang-format .
	clang-format -i ./brick_game/tetris/*.c ./brick_game/tetris/*h ./gui/cli/*.c ./gui/cli/*.h ./unit_tests/*.c
	rm -rf .clang-format

valgrind:
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s  ./unit_test
