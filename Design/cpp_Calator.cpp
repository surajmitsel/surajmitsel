#include <iostream>
#include <cmath>
using namespace std;

void showMenu() {
    cout << "Scientific Calculator" << endl;
    cout << "---------------------" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Sine (sin)" << endl;
    cout << "6. Cosine (cos)" << endl;
    cout << "7. Tangent (tan)" << endl;
    cout << "8. Logarithm (log)" << endl;
    cout << "9. Exponentiation (exp)" << endl;
    cout << "10. Power (^)" << endl;
    cout << "11. Square Root (sqrt)" << endl;
    cout << "12. Exit" << endl;
    cout << "Choose an operation: ";
}

int main() {
    int choice;
    double num1, num2, result;

    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 12) {
            cout << "Exiting the calculator. Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 12) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        if (choice >= 1 && choice <= 4 || choice == 10) {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
        } else if (choice >= 5 && choice <= 9 || choice == 11) {
            cout << "Enter the number: ";
            cin >> num1;
        }

        switch (choice) {
            case 1:
                result = num1 + num2;
                cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                break;
            case 2:
                result = num1 - num2;
                cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                break;
            case 3:
                result = num1 * num2;
                cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                break;
            case 4:
                if (num2 == 0) {
                    cout << "Error: Division by zero is not allowed." << endl;
                } else {
                    result = num1 / num2;
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                }
                break;
            case 5:
                result = sin(num1);
                cout << "Result: sin(" << num1 << ") = " << result << endl;
                break;
            case 6:
                result = cos(num1);
                cout << "Result: cos(" << num1 << ") = " << result << endl;
                break;
            case 7:
                result = tan(num1);
                cout << "Result: tan(" << num1 << ") = " << result << endl;
                break;
            case 8:
                if (num1 <= 0) {
                    cout << "Error: Logarithm of non-positive numbers is not defined." << endl;
                } else {
                    result = log(num1);
                    cout << "Result: log(" << num1 << ") = " << result << endl;
                }
                break;
            case 9:
                result = exp(num1);
                cout << "Result: exp(" << num1 << ") = " << result << endl;
                break;
            case 10:
                result = pow(num1, num2);
                cout << "Result: " << num1 << " ^ " << num2 << " = " << result << endl;
                break;
            case 11:
                if (num1 < 0) {
                    cout << "Error: Square root of negative numbers is not defined." << endl;
                } else {
                    result = sqrt(num1);
                    cout << "Result: sqrt(" << num1 << ") = " << result << endl;
                }
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}