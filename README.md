# Push_Swap

@42-Born2Code

## About

This is an algorithm project at 42 school.
The purpose of the project is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

## Common Instructions

- Must be written in C
- Should not quit unexpectedly
- No leaks will be tolerated.
- Makefile width flags -Wall -Wextra -Werror
- Makefile: all clean fclean re

## Mandatory

### The rules

- You have 2 stacks named a and b.
- At the beginning:
    - The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
    - The stack b is empty.
- The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:
    - sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
    - sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
    - ss : sa and sb at the same time.
    - pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
    - pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
    - ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
    - rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
    - rr : ra and rb at the same time.
    - rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
    - rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
    - rrr : rra and rrb at the same time.

### The "push_swap" program

The project must comply with the following rules:
- Global variables are forbidden.
- The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.
- Instructions must be separated by a ’\n’ and nothing else.
- The goal is to sort the stack with the lowest possible number of operations.
- If no parameters are specified, the program must not display anything and give the prompt back.
- In case of error, it must display "Error" followed by a ’\n’ on the standard error. 

## Bonus

### The "checker" program

The checker proogram will check if stack a is sorted correctly.

- "checker" takes as an argument the stack a formatted as a list of integers. If no argument as given it stops and displays nothing.
- It will then wait and read instructions on the standart input. Once all the instructions have been read, the program has to execute them on the stack received as an argument.
- If after executing those instructions, the stack a is actually sorted and the stack b is empty, then the program must display "OK". In every other case it must display "KO".
- In case of error, it must display "Error" in the standart error.

## Installation && Usage

### Requirements
The only Requirements are:
- GNU make
- CC

### Building the program
1. Download/Clone this repo

```bash
  git clone https://github.com/suhovhan/Push_Swap.git
```
2. `cd` into the root directory
```bash
cd Push_Swap
```

3. run programe ```make```
```bash
make
make bonus
```

### Running the program
After building the source, run `./push_swap <numbers>` from the project root.

## Usage/Examples

Usage Mondatory
```bash
./push_swap 5 800 -3 +45 0
./push_swap 2 1 3 6 5 8
./push_swap 2 one 3 6 5 8
ARG="4 67 3 87 23"; ./push_swap $ARG
./push_swap 2 3 "6 5 8" 2
```

Usage Bonus
```bash
./push_swap 5 800 -3 +45 0 | ./checker 5 800 -3 +45 0
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```
