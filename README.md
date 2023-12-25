# monty

## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## AUTHORS
1. [Gideon Oba](https://github.com/DeyonOba)
2. [Bilal Oyeleke](https://github.com/Sobilo34)

![image](images/DALL·E_2023-12-25.png)

## What does LIFO and FIFO mean?
### LIFO (Last In, First Out):
This is a data structure principle where the element added most recently (i.e Last) is the one that is removed first. This principle is similar to stacking of plates, what approach would you use to safely add and remove plates?.
### FIFO (First In, First Out)
This is also a data structure principle where the element that has been in the structure the longest is the first to be removed. In an unjust world with exception of the elderly, nursing mothers, or disabled, what approach would you use to call on people on a queue?.

In this project we created a stack and queue structure, with stacks working on the **LIFO** principle, and queue using the **FIFO** principle.

A stack typicall supports two main operations:
- **Push**: Adds an element to the top of the stack.
- **Pop**: Removes the element from the top of the stack.

In a queue the **pop** removes elements from the bottom of the stack.

## This are the data structures recommended by ALX.
```c
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
```
Above is a doubly linked list use to create a node of a stack or queue when required.
```c
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```
We utilized a list of the `instruction_t` structure to scan for the opcode pass per line in the bytecode file, we would be taking a walk with an example how this works.

## Compilation and Test
For this project we use the `gcc` compiler with the following flags.
```
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
For our project we wrote bash scripts for both compilation and test output from the bytefile. You can find the files `compiler`, and `valgrind_check` in the repo using link below.

- [**compiler**](https://github.com/DeyonOba/monty/blob/main/compiler)
- [**valgrind_check**](https://github.com/DeyonOba/monty/blob/main/valgrind_check)

**How to use `valgrind_check`**
```
# Executable + bytecode file
./valgrind_check 00.m
```

