# Project 2

This project will take a file named input.txt and for each line convert a statement into a series or expressions and evaluate the expressions.  The parser will throw exceptions for invalid operators, accessing variables that are undefined, and variables that have previously been defined.  

The project comes with a make file to build the project and tests.  
### Make options
```
make
- Will make all by default

all 
    - Calls Clean which deletes all previous build files
    - Compiles the tests
    - Compiles the executable

test
    - Will rebuild the test executable

project2
    - Will rebuild the project2 main executable


EX:
@cmcarowland ➜ /workspaces/CMSC330/Project 2 (p2) $ make 
rm -f bin/*.exe
clang++ -std=c++17 -pthread test/project2Tests.cpp `ls src/*.cpp | grep -v project2.cpp` -I/usr/local/include -L/usr/local/lib /usr/local/lib/libgtest.a /usr/local/lib/libgtest_main.a  -o bin/tests
clang++ src/*.cpp -g -o bin/project2.exe
```

### Tests
```
@cmcarowland ➜ /workspaces/CMSC330/Project 2 (p2) $ ./bin/tests
Running main() from /workspaces/CMSC330/googletest-1.15.2/googletest/src/gtest_main.cc
[==========] Running 28 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 23 tests from EquationTest
[ RUN      ] EquationTest.AddVars
[       OK ] EquationTest.AddVars (0 ms)
[ RUN      ] EquationTest.AddLiteral
[       OK ] EquationTest.AddLiteral (0 ms)
......
```

### Project2
```
@cmcarowland ➜ /workspaces/CMSC330/Project 2 (p2) $ ./bin/project2.exe 
( a + z ) , a = 3, z = 4.9; Value = 7.9

( c - 4 ) , c = 7; Value = 3

( b * 4 ) , b = 4; Value = 16

( d / 4 ) , d = 32; Value = 8

......
```

---

## Project Requirements
#### Example Parse Tree
```
statement → expression ',' assignments ';'
expression → '(' expressions ')'
expressions → unary_expression | binary_expression | ternary_expression |
quaternary_expression | operand
unary_expression → expression '~'
binary_expression → expression binary_operator expression
binary_operator → '+' | '-' | '*' | '/' | '%' | '^' | '<' | '>' | '&'
ternary_expression → expression '?' expression expression
quaternary_expression → expression '#' expression expression expression
operand → literal | variable | expression
assignments → assignments ',' assignment | assignment
assignment → variable '=' literal
```

#### Tasks
- [x] Task 1
    - [x] Add * for multiplication
    - [x] Add / for division
    - [x] Add % for remainder
    - [x] Add ^ for exponents
    - [x] Add < to return min
    - [x] Add > to return max
    - [x] Add & to return avg
    - [x] Add ~ as a postfix urinary operator
    - [x] Add ? ternary operator
        - [x] ex ? exTrue exFalse  
    - [x] Add #
        - expression #
        - < 0 expression
        - == 0 expression
        - \> 0 expression

- [x] Task 2
    - [x] Modify the variable token so that underscores are premitted after the first character
    - [x] Assignments and literals should be able to accept floats rather than only ints

- [x] Task 3 
    - [x] The symbol table should be initialized before each statement is evaluated
    - [x] Statements with uninitialized variables should be reported as an error. UninitException
    - [x] Double assignments should result in an error. AlreadyAssignedException