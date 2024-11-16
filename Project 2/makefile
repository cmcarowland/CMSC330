.PHONY : all clean test project2
CXXFLAGS += -I./test/include
LDFLAGS += -L./test/lib

all: clean test project2

test:
	clang++ -std=c++17 -pthread test/project2Tests.cpp `ls src/*.cpp | grep -v project2.cpp` $(CXXFLAGS) $(LDFLAGS) /usr/local/lib/libgtest.a /usr/local/lib/libgtest_main.a  -o bin/tests
	
project2:
	clang++ src/*.cpp -g -o bin/project2.exe

clean:
	rm -f bin/*.exe