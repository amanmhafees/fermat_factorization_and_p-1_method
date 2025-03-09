#include <stdio.h>
#include <math.h>

// Function to check if a number is a perfect square
int isPerfectSquare(int num) {
    int sqrtNum = (int)sqrt(num);
    return (sqrtNum * sqrtNum == num);
}

// Fermat's factorization method
void fermatFactorization(int n) {
    int x = (int)ceil(sqrt(n)); // Smallest integer greater than sqrt(n)
    int w, y, a, b;

    while (1) {
        w = x * x - n;
        if (isPerfectSquare(w)) { // Check if w is a perfect square
            y = (int)sqrt(w);
            a = x + y;
            b = x - y;
            printf("Factors of %d: %d and %d\n", n, a, b);
            return;
        }
        x++;
    }
}

int main() {
    int n;
    printf("Enter a number to factorize: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    fermatFactorization(n);
    return 0;
}
