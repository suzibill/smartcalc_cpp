CC= g++ 
CFLAGS= -Wall -Wextra -Werror
STANDART= -std=c++17
TESTFLAGS=-lgtest
OS= $(shell uname)
TESTFILES= tests/test.cc
SRC = model/*.cc view/*.cc controller/*.cc
PROJECT_NAME= smart_calc



all: install

install: build
	cd calc; make
	open calc/view.app

build:
	@rm -rf calc
	mkdir calc
	cd calc && cmake ../../src/view


uninstall:
	rm -rf calc
	
execution:
	open calc/view.app

test: $(TESTFILES)
	$(CC) $(TESTFILES) $(TESTFLAGS) $(STANDART) $(CFLAGS) model/*.cc  -o test 
	./test

gcov_report: clean 
	$(CC) --coverage $(TEST_FLAGS) $(CFLAGS) $(SOURCES) $(TEST_FILES) -o test
		
	./test
	lcov -t "test" -o test.info -c -d . 
	genhtml -o report test.info
	
ifeq ($(OS), Darwin)
	open report/index.html
else
	xdg-open ./report/index.html
endif


check: test
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config $(SRC)
ifeq ($(OS), Darwin)
	leaks --atExit -- ./test
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./test
endif


dvi:
	cd Doxygen; doxygen
	open doxygen/html/index.html

dist: build
	tar  -zcf$(PROJECT_NAME).tar calc


clean:
	rm -rf *.a *.so *.out *.o report *.gc* *.info *.txt *.cmake test *.gch *.pdf *.tar  
	rm -rf  *.html *.css test.info test.dSYM report
	rm -rf calc
	rm -rf view/build
