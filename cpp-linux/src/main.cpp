#include <iostream>
#include <limits>

void showMenu() {
    std::cout << "\n--- C++ Calculator ---\n";
    std::cout << "1. Addition (+)\n2. Subtraction (-)\n3. Multiplication (*)\n4. Division (/)\n5. Exit\n";
    std::cout << "Enter choice: ";
}

int main() {
    double num1, num2;
    int choice;

    while (true) {
        showMenu();
        if (!(std::cin >> choice)) break;
        if (choice == 5) break;

        std::cout << "Enter two numbers: ";
        std::cin >> num1 >> num2;

        switch (choice) {
            case 1: std::cout << "Result: " << num1 + num2 << "\n"; break;
            case 2: std::cout << "Result: " << num1 - num2 << "\n"; break;
            case 3: std::cout << "Result: " << num1 * num2 << "\n"; break;
            case 4: 
                if (num2 != 0) std::cout << "Result: " << num1 / num2 << "\n";
                else std::cout << "Error: Division by zero!\n";
                break;
            default: std::cout << "Invalid choice.\n";
        }
    }
    return 0;
}
