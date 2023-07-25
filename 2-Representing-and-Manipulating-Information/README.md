Decimal (base-10):

- developed in India
- improved by Arab in 12th century
- brought to the West in 13th century by Fibonacci

# 2.1 Information Storage

## 2.1.2 Data Sizes

## 2.1.3 Addressing and Byte Ordering

- little endian: from least significant byte to most
- big endian: from most to least

> Suppose the variable x of type int and at address 0x100 has a hexadecimal value of 0x01234567. 
> The ordering of the bytes within the address range 0x100 through 0x103 depends on the type of machine:

Big endian:

```
0x100    0x101    0x102    0x103
  01       23       45       67
```

Little endian:

```
0x100    0x101    0x102    0x103
  67       45       23       01
```

```c
#include "stdio.h"

int main() {
    unsigned int x = 0x01234567;
    char *c = (char*) &x;

    if (*c == 0x01) {
        println("big endian");
    } else {
        println("little endian");
    }
}
```

```sh
$ clang -Wall -g -O3 endianness.c -o endianness
$ $ ./endianness
little endian
```

```sh
$ set byteorder (sysctl -a hw.byteorder | awk '{ print $2 }'); if [ $byteorder = "1234" ]; echo "little endian"; else; echo "big endian"; end
little endian
```

## 2.1.7 Bit-Level Operations in C

Practice Problem 2.11

> For an array of odd length cnt = 2k + 1, what are the values of variables first and last in the final iteration of function reverse_array?

It is the middle element.

> Why does this call to function inplace_swap set the array element to 0?

Because `a ^ a = 0`

> What simple modification to the code for reverse_array would eliminate this problem?

Just change the condition to `first < last`.