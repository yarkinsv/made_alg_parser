# Грамматика, описывающая набор выражений

```
S -> ASSIGNMENT '\n' ASSIGNMENT | ASSIGNMENT | e
ASSIGNMENT -> VARIABLE '=' EXPRESSION
EXPRESSION -> TERM '+' EXPRESSION | TERM '-' EXPRESSION | TERM
TERM -> VALUE '/' TERM | VALUE '*' TERM | VALUE
VALUE -> '-' VALUE | NUMBER | VARIABLE
NUMBER -> DIGIT NUMBER | DIGIT
VARIABLE -> 'a' | 'b' | 'c' | ... | 'z'
DIGIT -> '0' | '1' | ... | '9'
```

# Результаты тестов
```
Test case 0:

a = 2
b = 3
c = 2 * 5
d = c * a

Results:

a = 2
b = 3
c = 10
d = 20

----------

Test case 1:

a = 1 + 2
b = 3 - 2
c = a * b

Results:

a = 3
b = 1
c = 3

----------

Test case 2:

a = 1 + 2
b = 3 - 2
c = a * b

Results:

a = 3
b = 1
c = 3

----------

Test case 3:

a = 1
b = 2
c = 3
d = -3
a = a * b
b = b * c
d = c * d

Results:

a = 2
b = 6
c = 3
d = -9

----------

Test case 4:

a = 1 + {
b = 3 - 2
c = a * b

Results:

Got error: Expected number, got {, at index 8

----------

Test case 5:

a = 12 - 12
b = 3 - 2
c = b / a

Results:

Got error: Division by zero

----------

Test case 6:

a = 1 + 2b = 3 - 2
c = a * b

Results:

Got error: Expected variable, got =, at index 11

----------


Process finished with exit code 0
/Users/s.yarkin/CLionProjects/made_parser/cmake-build-debug/made_parser
Test case 0:

a = 2
b = 3
c = 2 * 5
d = c * a

Results:

a = 2
b = 3
c = 10
d = 20

----------

Test case 1:

a = 1 + 2
b = 3 - 2
c = a * b

Results:

a = 3
b = 1
c = 3

----------

Test case 2:

a = 1 + 2
b = 3 - 2
c = a * b

Results:

a = 3
b = 1
c = 3

----------

Test case 3:

a = 1
b = 2
c = 3
d = -3
a = a * b
b = b * c
d = c * d

Results:

a = 2
b = 6
c = 3
d = -9

----------

Test case 4:

a = 1 + {
b = 3 - 2
c = a * b

Results:

Got error: Expected number, got {, at index 8

----------

Test case 5:

a = 12 - 12
b = 3 - 2
c = b / a

Results:

Got error: Division by zero

----------

Test case 6:

a = 1 + 2b = 3 - 2
c = a * b

Results:

Got error: Expected variable, got =, at index 11

----------
```
