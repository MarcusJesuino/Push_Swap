*This project has been created as part of the 42 curriculum by masantos*

# Push_Swap

>##   Description


The **push_swap** project consists of creating a program that sorts a stack of integers using a limited set of operations, following strict rules and constraints defined by the 42 curriculum.

The goal of the project is to sort the numbers in ascending order with the minimum number of operations possible, using two stacks:

- **Stack A** (initially contains all numbers)
- **Stack B** (initially empty)

># Instructions

The following commands are the commands that you will need to use to run the project.

### Compiling commands:

- Compile the project: `make all`.

- Remove object files: `make clean`.

- Remove all generated files: `make fclean` .

- Recompile the project: `make re`.

## Running the code

Run the program using:

> ./push_swap 2 1 3 6 5 8

You can pass as many integer arguments as needed, separated by spaces.

Example:

> ./push_swap 4 67 3 87 23

The program will output the list of operations needed to sort the numbers.

## Allowed Operations

### Swap

- `sa`: Swap the first 2 elements at the top of stack A
- `sb` : Swap the first 2 elements at the top of stack B
- `ss` : sa and sb at the same time

### Push

- `pa` : Take the first element at the top of B and put it at the top of A
- `pb` : Take the first element at the top of A and put it at the top of B

### Rotate

- `ra` : Shift up all elements of stack A by 1
- `rb` : Shift up all elements of stack B by 1
- `rr` : ra and rb at the same time

### Reverse Rotate

- `rra` : Shift down all elements of stack A by 1
- `rrb` : Shift down all elements of stack B by 1
- `rrr` : rra and rrb at the same time

## Rules

- The program must handle only valid integer arguments.
- No duplicates are allowed.
- The program must handle errors properly.
- If no arguments are given, nothing should be displayed.
- The goal is to sort stack A in ascending order.
- The number of operations must be as low as possible.

## Error Handling

The program must display:

>Error

In the following cases:

- Non-integer arguments
- Integer overflow
- Duplicate numbers
- Invalid input format

># resources

### references

- 42 subject PDF
- Algorithm and data structure documentation
- Sorting algorithm studies (Radix sort, Turk algorithm, etc.)

### AI usage

AI was used for:

- Generating random test cases
- Understanding optimization strategies
- Debugging memory leaks and edge cases
