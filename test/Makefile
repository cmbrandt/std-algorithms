# C++ compiler, compiler flags, and include statements

CXX      := g++-10
CXXFLAGS := -Wall -Wpedantic -Wextra -std=c++20
CXXINCLD := -I $(HOME)/projects/std-algorithms/test
STDINCLD := -I $(HOME)/projects/std-algorithms/include
TESTOBJS := test_main.o test_algorithm.o test_functional.o test_iterator.o test_numeric.o test_utility.o


all: test.exe


test.exe: $(TESTOBJS)
	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -o test.exe $(TESTOBJS)


test_main.o: test_main.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -c test_main.cxx

test_algorithm.o: test_algorithm.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -c test_algorithm.cxx

test_functional.o: test_functional.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -c test_functional.cxx

test_iterator.o: test_iterator.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -c test_iterator.cxx

test_numeric.o: test_numeric.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -c test_numeric.cxx

test_utility.o: test_utility.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -c test_utility.cxx


run: test.exe
	./test.exe


clean:
	rm *.exe *.o
	clear
