#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char operation;
    bool running = true;

    cout << "Basic Calculator\n";
    cout << "Supported Operations: +, -, *, /\n";

    while (running) {
        cout << "\nEnter first number: ";
        cin >> num1;

        cout << "Enter an operation (+, -, *, /): ";
        cin >> operation;

        cout << "Enter second number: ";
        cin >> num2;

        switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed.\n";
            }
            break;
        default:
            cout << "Invalid operation. Please try again.\n";
        }

        char choice;
        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') {
            running = false;
            cout << "Exiting Calculator. Operation Done Successfully!\n";
        }
    }

    return 0;
}
