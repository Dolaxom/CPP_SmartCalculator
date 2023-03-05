CXX=g++
CXXFLAGS=-std=c++17 -Wall -Werror -Wextra -pedantic -UQT_MACRO
GCOV=--coverage
OUTNAME=tests

.PHONY: install
install: tests cmake build

.PHONY: cmake
cmake:
	mkdir -p build && cd build && cmake ..

.PHONY: build
build: cmake
	cd build && make

.PHONY: tests
tests: clean
	$(CXX) $(CXXFLAGS) $(GCOV) -c model.cc 
	$(CXX) $(CXXFLAGS) -c gtests.cc -lgtest
	$(CXX) $(CXXFLAGS) $(GCOV) -o $(OUTNAME) model.o gtests.o -lgtest
	./$(OUTNAME)

.PHONY: clean
clean:
	rm -rf build ./*.o ./*.a ./a.out ./*.gcno ./*.gcda ./gcov_report *.info ./*.info tests

.PHONY: uninstall
uninstall:
	@rm -rf build*

.PHONY: dist
dist:
	@tar -cf calc.tar *.cc *.h Makefile build

.PHONY: dvi
dvi:
	open ../materials/doc.tex
	# pdflatex ../materials/doc.tex