# Different-Base-Calculator
A simple calculator to perform operations on numbers in different bases.

Input and output can be binary, octal, decimal, or hexidecimal in the form b,o,d, and x respectively.

```
calc <op> <number1> <number2> <output base>

$ ./calc + d1111111111111111 d1111111111111111 d
d2222222222222222

$ ./calc + b1101 b1 d
d14

$ ./calc + d999999999 d1 d
d1000000000

$ ./calc - d10 -d4 b
b1110

$ ./calc + -d10 -d4 b
-b1110
```
