# C++ compiler, compiler flags, and include statement
CXX      := g++-9
CXXFLAGS := -Wall -std=c++17
CXXINCLD := -I /Users/cmbrandt/projects/stl-algorithms/include

all: test.exe

test.exe: test_main.o test_algorithm.o test_functional.o test_iterator.o
	$(CXX) $(CXXFLAGS) $(CXXINCLD) -o test.exe test_main.o test_algorithm.o test_functional.o test_iterator.o

test_main.o: test_main.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) -c test_main.cxx

test_algorithm.o: test_algorithm.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) -c test_algorithm.cxx

test_functional.o: test_functional.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) -c test_functional.cxx

test_iterator.o: test_iterator.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) -c test_iterator.cxx

run: test.exe
	./test.exe

clean:
	rm *.exe *.o