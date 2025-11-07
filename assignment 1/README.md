# Programming Assignment 1

## 1. Name and Description of the Project

This project contains two C++ programs that demonstrate fundamental programming concepts including input/output, branching, loops, and mathematical operations:

- **verifier.cpp**: A program that compares the result of calculating exponents using the `<cmath>` library's `pow()` function versus a manual loop-based calculation. It demonstrates how different approaches to the same mathematical operation can yield different results, especially when dealing with integer types and negative exponents.

- **calculator.cpp**: An interactive calculator program that performs basic arithmetic operations (addition, subtraction, multiplication, division, exponentiation, and modulo) on two integers. The program continues to prompt for calculations until the user chooses to quit, and includes error handling for invalid inputs and edge cases like division by zero.

## 2. Identifying Information

- **Student Name**: gabriel Giancarlo
- **Course**: CPSC 298 C++
- **Semester**: Fall 2025
- **Assignment**: Programming Assignment 1
- **Date**: September 2025

## 3. Source Files

The following source code files are included in this submission:

1. `verifier.cpp` - Program that verifies exponent calculations using pow() vs loop
2. `calculator.cpp` - Interactive calculator program with multiple operations
3. `README.md` - This documentation file

## 4. References

- C++ Standard Library documentation for `<cmath>` functions
- Course materials (Lecture 3 slides) for exponent calculation concepts

**Note**: No external websites or AI tools were used in the development of this code.

## 5. Known Errors

- **verifier.cpp**: When dealing with negative exponents, the loop-based calculation and `pow()` function may produce different results due to integer type limitations. This is expected behavior as negative exponents produce fractional results that cannot be properly represented as integers. The program correctly identifies and reports these mismatches.

- **calculator.cpp**: The program handles most error cases, but extremely large integer inputs may cause overflow issues. Division by zero is handled by outputting "inf" for floating-point division.

## 6. Build Instructions

To compile the programs, use the following commands in a terminal:

### Compiling verifier.cpp:
```bash
g++ verifier.cpp -o verifier
```

### Compiling calculator.cpp:
```bash
g++ calculator.cpp -o calculator
```

**Requirements**:
- A C++ compiler that supports C++11 or later (g++, clang++, etc.)
- Standard C++ library with `<cmath>` and `<iomanip>` support

## 7. Execution Instructions

### Running verifier.cpp:
```bash
./verifier
```

The program will prompt you to enter two integers. It will then:
1. Calculate the first number to the power of the second using `pow()`
2. Calculate the same using a loop
3. Compare the results and indicate if they match

**Example usage**:
- Enter: `5` and `3` → Should match (125)
- Enter: `2` and `-1` → Should not match (demonstrates negative exponent limitation)

### Running calculator.cpp:
```bash
./calculator
```

The program will repeatedly:
1. Prompt for two integers
2. Prompt for an operation (+, -, *, /, ^, or %)
3. Display the result
4. Ask if you wish to quit (y/n)

**Example usage**:
- Enter: `1`, `2`, `/` → Output: `1 / 2 = 0.50`
- Enter: `9`, `7`, `%` → Output: `9 % 7 = 2`
- Enter: `2`, `-2`, `^` → Output: `2 ^ -2 = 0.25`
- Enter: `1`, `0`, `/` → Output: `1 / 0 = inf`
- Enter: `y` to quit

**Note**: The program uses floating-point division (not integer division) for the `/` operation, and handles invalid operations with error messages.

