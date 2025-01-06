# 🔃↔️ Push_swap

## 🔷 Mandatory Part:

1. We are given two stacks named `a` and `b`.
2. Create a program that accepts as input a random set of numbers (negative or positive) without duplicates. The input can be provided in two formats:
   - A variable number of command-line arguments.
   - A single string containing space-separated numbers.
3. Implement an algorithm to sort the input numbers in ascending order.
4. The sorting algorithm will use the following operations: `swap`, `rotate`, `reverse rotate`, and `push`.
5. After processing the input through the sorting algorithm, the program will output the sequence of operations (instructions).

## 🔷 Pseudo Code

```plaintext
// Declare pointers for two data structures/linked lists representing stack `a` and stack `b`
    // Set both pointers to NULL to start with empty stacks

// Handle input validation:
    // Ensure at least two arguments are provided, and the second argument is not empty
    // If validation fails, return an error

// Parse the input:
    // If input is a string, split it into substrings

// Initialize stack `a` by appending each input number as a node
    // Validate input for integer overflow, duplicates, and syntax errors (e.g., invalid characters)
    // If errors are found, free stack `a` and return an error
    // Convert valid input strings to integers and append to stack `a`

// Check if stack `a` is already sorted
    // If not sorted, apply the sorting algorithm:
        // For 2 numbers: simply swap if needed
        // For 3 numbers: use a simple sorting algorithm
        // For more than 3 numbers: implement the "Turk Algorithm"

// Clean up memory and exit
```

## 🔷 Using a Push_swap Visualizer

1. A visualizer is highly recommended for debugging and understanding how the program works.
2. A popular visualizer can be found here: [Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer).

### Steps to Use:

1. Clone the repository inside your main `push_swap` directory (where your `push_swap` executable resides):
   ```bash
   git clone https://github.com/o-reo/push_swap_visualizer.git
   ```
2. Install the required packages as mentioned in the visualizer's `README.md`:
   ```bash
   sudo apt update
   sudo apt install cmake
   ```
3. Navigate to the visualizer's directory and build it:
   ```bash
   cd push_swap_visualizer
   mkdir build
   cd build
   cmake ..
   make
   ```
4. Resolve any build errors by installing missing packages. Use error messages as a guide and search for solutions if necessary.
5. After a successful build, run the visualizer:
   ```bash
   ./bin/visualizer
   ```
6. Update the "push_swap file path" in the visualizer to `../../push_swap`.

## 🔷 Using the Checker Provided by 42

1. Download the appropriate checker for your operating system (e.g., `checker_Mac` or `checker_Linux`).
2. Place the file in the same directory as your `push_swap` executable.
3. Ensure the checker file has executable permissions:
   ```bash
   chmod +x <checker_filename>
   ```
4. Test your program with the checker:
   - Verify correct error handling:
     ```bash
     ARG="4 10 1 3 2"; ./push_swap $ARG | ./checker_Mac $ARG
     ```
   - Count the number of instructions:
     ```bash
     ARG="4 10 1 3 2"; ./push_swap $ARG | wc -l
     ```
5. To pass evaluation, the number of instructions must meet the following requirements:
   - For `x = 3`, `n <= 3`
   - For `x = 5`, `n <= 12`
   - For `x = 100`, `n < 1500`
   - For `x = 500`, `n < 11500`

## 🔷 Understanding Algorithms

### What is an Algorithm?
A set of instructions designed to solve a specific problem.

### Algorithm Complexity
- **Algorithm Analysis**: Evaluating the step-by-step performance of an algorithm.
- **Algorithm Efficiency**: Measuring how quickly an algorithm solves a problem and its resource usage (time and memory).
- **Asymptotic Notation**: Using mathematical symbols (Big O, Omega, Theta) to describe an algorithm's performance as input size grows.
- **Time Complexity**: Assessing the best, worst, and average runtime of an algorithm.
- **Space Complexity**: Evaluating the memory usage of an algorithm.
