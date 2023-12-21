# Push Swap

## Description

Push Swap is a sorting algorithm project where the goal is to sort a stack of integers using a limited set of operations. The project aims to find the most optimized solution in terms of the number of operations performed.

## Usage

To run the Push Swap program, follow these steps:

1. Clone the repository:
	```bash
	git clone https://github.com/yacoub-harkati/Push-Swap-42.git
	```

2. Navigate to the project directory:
	```bash
	cd Push-Swap-42
	```

3. Build the program using the Makefile:
	```bash
	make
	```

4. Run the tester script to test the program:
	```bash
	make && python3 tester.py
	```

The `make` command will compile the program, and the `python3 tester.py` command will run the tester script to validate the sorting algorithm.

Additionally, you can use the checker program to verify if the stack is sorted. Follow these steps:

1. Build the bonus program using the Makefile:
	```bash
	make bonus
	```

2. Run the checker program with a set of random numbers:
	```bash
	ARG="<set of random numbers>"; ./push_swap $ARG | ./checker $ARG
	```

The checker program will display "OK" if the stack is sorted correctly, or "KO" if it is not.

## Instructions

The following instructions are used by the Push Swap program:

- `sa`: Swap the first two elements of stack A.
- `sb`: Swap the first two elements of stack B.
- `ss`: Swap the first two elements of both stacks A and B.
- `pa`: Push the first element of stack B to stack A.
- `pb`: Push the first element of stack A to stack B.
- `ra`: Rotate stack A (move the first element to the end).
- `rb`: Rotate stack B (move the first element to the end).
- `rr`: Rotate both stacks A and B.
- `rra`: Reverse rotate stack A (move the last element to the beginning).
- `rrb`: Reverse rotate stack B (move the last element to the beginning).
- `rrr`: Reverse rotate both stacks A and B.

## Contributing

Contributions to this project are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
