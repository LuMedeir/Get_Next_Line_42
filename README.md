# Get Next Line

<p align="center">
<img src="image.png">
</p>

<p align="center">
</p>

</br>

## Description  

This projects is about creating a function that, allows to read a line ending with
a newline character ('\\n') from a file descriptor, without knowing its size beforehand. 
One of the goal of this project is to learn a highly interesting new concept in C 
programming: static variables, and to gain a deeper understanding of allocations,
the manipulation and the life cycle of a buffer, the unexpected complexity implied 
in the use of one or many static variables.

## Makefile rules

| Rule         |                 Description                             |
|:------------:|:-------------------------------------------------------:|
| `make`       | Compile the program.                                    |
| `make clean` | Remove every objects of compilation                     |
| `make fclean`| Do `clean` rule and remove the executable program       |
| `make re`    | Do `fclean` rule and compile the program mandatory      |
