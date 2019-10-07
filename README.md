# ft\_printf @ 42

This project aims at rebuilding the printf library with basic functionality. I
tried to implement as much of the original as possible, and also have a few
extra things which I found to be rather useful.

## What is it?
Function which writes the string pointed by format to the standard output (stdout). If format includes format specifiers (subsequences beginning with %), the additional arguments following format are formatted and inserted in the resulting string replacing their respective specifiers.
![alt text](https://he-s3.s3.amazonaws.com/media/uploads/c22b4d1.png)

## Example
```c
#include "includes/ft_printf.h"

int		main(void)
{
	ft_printf("TEST: %s\n", "Hello, World!");
	return (0);
}
```

## Updates

### 2019-10-07 10:06:20
Outlined work for project

### 2019-10-07 10:11:17
Testing python push script
