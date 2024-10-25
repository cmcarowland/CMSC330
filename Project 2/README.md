# Project 2
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

- [x] Task 1
    - [x] Add * for multiplication
    - [x] Add / for division
    - [x] Add % for remainder
    - [x] Add ^ for exponents
    - [x] Add < to return min
    - [x] Add > to return max
    - [x] Add & to return avg
    - [x] Add ~ as a postfix urinary operator
    - [ ] Add ? ternary operator
        - [x] ex ? exTrue exFalse  
    - [x] Add #
        - expression #
        - < 0 expression
        - == 0 expression
        - \> 0 expression

- [ ] Task 2
    - [x] Modify the variable token so that underscores are premitted after the first character
    - [ ] Assignments should be able to accept floats rather than only ints

- [ ] Task 3 
    - [ ] The symbol table should be initialized before each statement is evaluated
    - [ ] Statements with uninitialized variables should be reported as an error. UninitException
    - [ ] Double assignments should result in an error. AlreadyAssignedException