// Name:  Yinxia Shi
// Email: shi.yinx@northeastern.edu

#include <stdio.h>

int main() {
    int a, b, c, choice;
    
    printf("Enter your choice\n");
    printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n");
    scanf("%d", &choice);
    
    printf("Enter a and b values ");
    scanf("%d%d", &a, &b);
    
    // Add your code here using switch
    switch (choice) {
    case 1:
        printf("Addition\n");
        c = a + b;
        printf("Sum=%d\n", c);
        break;
    case 2:
        printf("Subtraction\n");
        c = a - b;
        printf("Difference=%d\n", c);
        break;
    case 3:
        printf("Multiplication\n");
        c = a * b;
        printf("Product=%d\n", c);
        break;
    case 4:
        printf("Division\n");
        if (b == 0) {
            printf("divide by zero error\n");
            break;
        }
        c = a / b;
        printf("Quotient=%d\n", c);
        c = a % b;
        printf("Remainder=%d\n", c);
        break;
    default:
        printf("Invalid option");
        break;
    }
           
    return 0;
}
