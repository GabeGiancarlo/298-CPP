#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    char quit = 'n';
    int num1, num2;
    char operation;
    
    // Main loop - continue until user chooses to quit
    while (quit != 'y' && quit != 'Y') {
        // Prompt for first integer
        cout << "Enter first integer: ";
        cin >> num1;
        
        // Prompt for second integer
        cout << "Enter second integer: ";
        cin >> num2;
        
        // Prompt for operation (dinosaur comment requirement)
        cout << "Enter operation (+, -, *, /, ^, %): ";
        cin >> operation;
        
        // Clear any remaining input buffer
        cin.ignore(1000, '\n');
        
        // Perform the requested operation
        switch (operation) {
            case '+':
                cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
                break;
                
            case '-':
                cout << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
                break;
                
            case '*':
                cout << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
                break;
                
            case '/':
                if (num2 == 0) {
                    cout << num1 << " / " << num2 << " = inf" << endl;
                } else {
                    // Use floating point division, not integer division
                    cout << num1 << " / " << num2 << " = " 
                         << fixed << setprecision(2) 
                         << (static_cast<double>(num1) / num2) << endl;
                }
                break;
                
            case '^':
                // Handle negative exponents
                if (num2 < 0) {
                    double result = pow(num1, num2);
                    cout << num1 << " ^ " << num2 << " = " 
                         << fixed << setprecision(2) << result << endl;
                } else {
                    int result = static_cast<int>(pow(num1, num2));
                    cout << num1 << " ^ " << num2 << " = " << result << endl;
                }
                break;
                
            case '%':
                if (num2 == 0) {
                    cout << "Error: Cannot perform modulo with zero divisor." << endl;
                } else {
                    cout << num1 << " % " << num2 << " = " << (num1 % num2) << endl;
                }
                break;
                
            default:
                cout << "Error: Invalid operation. Please use +, -, *, /, ^, or %." << endl;
                break;
        }
        
        // Ask if user wants to quit
        cout << "Do you wish to quit? (y/n): ";
        cin >> quit;
        
        // Clear input buffer
        cin.ignore(1000, '\n');
    }
    
    return 0;
}

