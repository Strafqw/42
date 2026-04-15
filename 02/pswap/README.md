*This project has been created as part of the 42 curriculum by joasampa*

## Description

Push_swap is a sorting algorithm project. The goal is to sort a stack of integers using a limited set of operations (sa, sb, pa, pb, ra, rb, rra, rrb) in the fewest moves possible. The program receives a list of integers as arguments and outputs the sequence of operations needed to sort them.

The algorithm uses radix sort for large inputs (>5 numbers), sorting by individual bits after normalizing values to consecutive ranks. For small inputs (2-5 numbers), it uses optimized hardcoded sorting strategies.

## Instructions

Compilation

```
make        # compile
make clean  # remove object files
make fclean # remove object files and binary
make re     # recompile from scratch
```

Usage

```
./push_swap 4 2 7 1 3
```

The program prints the list of operations to stdout, one per line.

Testing

```
# Check if the output sorts correctly
ARG="4 2 7 1 3"; ./push_swap $ARG | ./checker_linux $ARG

# Count number of operations
./push_swap 4 2 7 1 3 | wc -l

# Test with 100 random numbers
ARG=$(shuf -i 1-1000 -n 100); ./push_swap $ARG | wc -l
```

## Resources

- [Push_swap subject - 42](https://projects.intra.42.fr)
- [Radix sort - Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Bitwise operations in C](https://en.wikipedia.org/wiki/Bitwise_operations_in_C)
