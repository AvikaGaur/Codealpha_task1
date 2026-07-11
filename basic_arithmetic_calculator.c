#include <stdio.h>

int main() {
    float number1, number2, result;
    int choose_one;

    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%f %f", &number1, &number2);

    // Display menu
    printf("\nChoose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choose_one);

    // Perform operation using switch-case
    switch(choose_one) {
        case 1:
            result = number1 + number2;
            printf("Result = %.2f\n", result);
            break;

        case 2:
            result = number1 - number2;
            printf("Result = %.2f\n", result);
            break;

        case 3:
            result = number1 * number2;
            printf("Result = %.2f\n", result);
            break;

        case 4:
            if(number2 != 0)
                printf("Result = %.2f\n", number1 / number2);
            else
                printf("Error! Division by zero is not allowed.\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}