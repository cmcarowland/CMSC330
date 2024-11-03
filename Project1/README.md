# Project 1

- Add types
    - Text
    - SolidPolygon
    - IsoscelesTriangle
    - Parallelogram
    - RegularPolygon
- Add new terms to lexer
- Build tests for each new item
- Implement drawing
- Test scenes manually
- Complete PDF

```
scene → SCENE IDENTIFIER number_list images END '.'
images → image images | image
image → right_triangle | rectangle
right_triangle →
RIGHT_TRIANGLE COLOR number_list AT number_list HEIGHT NUMBER WIDTH
NUMBER ';'
rectangle →
RECTANGLE_ COLOR number_list AT number_list HEIGHT NUMBER WIDTH
NUMBER ';'
number_list → '(' numbers ')'
numbers → NUMBER | NUMBER ',' numbers
```

```
scene → SCENE IDENTIFIER number_list images END '.'
images → image images | image
image →
right_triangle | rectangle | parallelogram | regular_polygon | isosceles
| text
right_triangle →
RIGHT_TRIANGLE COLOR number_list AT number_list HEIGHT NUMBER WIDTH
NUMBER ';'
rectangle →
RECTANGLE_ COLOR number_list AT number_list HEIGHT NUMBER WIDTH
NUMBER ';'
parallelogram →
PARALLELOGRAM COLOR number_list AT number_list number_list OFFSET
NUMBER ';'
regular_polygon →
REGULAR_POLYGON COLOR number_list AT number_list SIDES NUMBER RADIUS
NUMBER ';'
isosceles →
ISOSCELES COLOR number_list AT number_list HEIGHT NUMBER WIDTH
NUMBER ';'
text →
TEXT COLOR number_list AT number_list STRING ';'
number_list → '(' numbers ')'
numbers → NUMBER | NUMBER ',' numbers
```