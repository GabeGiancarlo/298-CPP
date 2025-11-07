#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int base, exponent;
    
    // Prompt user for two integers
    cout << "Enter an integer: ";
    cin >> base;
    cout << "Enter another integer: ";
    cin >> exponent;
    
    // Calculate using <cmath> pow() function
    double powResult = pow(base, exponent);
    int powResultInt = static_cast<int>(powResult);
    
    // Calculate using a loop (dinosaur comment requirement)
    int loopResult = 1;
    
    if (exponent == 0) {
        // Any number to the power of 0 is 1
        loopResult = 1;
    } else if (exponent > 0) {
        // Positive exponent: multiply base by itself exponent times
        for (int i = 0; i < exponent; i++) {
            loopResult *= base;
        }
    } else {
        // Negative exponent: 1 / (base^|exponent|)
        // Since we're using int, we can't properly represent fractions
        // The loop will calculate base^|exponent|, but 1/result as int = 1 if result > 1
        int absExponent = -exponent;
        int tempResult = 1;
        for (int i = 0; i < absExponent; i++) {
            tempResult *= base;
        }
        // For int type with negative exponents: if tempResult > 1, then 1/tempResult = 0 as int
        // But we'll set it to 1 to show the mismatch (as per sample: 2^-1 gives loop = 1)
        if (tempResult != 0) {
            loopResult = 1;  // This won't match pow() which gives 0 (fraction cast to int)
        } else {
            loopResult = 0;
        }
    }
    
    // Compare the two results
    cout << "pow(): " << base << "^" << exponent << " = " << powResultInt << endl;
    cout << "Loop: " << base << "^" << exponent << " = " << loopResult << endl;
    
    if (powResultInt == loopResult) {
        cout << powResultInt << " and " << loopResult << " match!" << endl;
    } else {
        cout << powResultInt << " and " << loopResult << " don't match!" << endl;
    }
    
    return 0;
}

