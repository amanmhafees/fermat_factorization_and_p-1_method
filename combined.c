#include <stdio.h>
#include <math.h>

// Function to compute (base^exp) % mod using modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod; // Ensure base is within mod range

    while (exp > 0) {
        if (exp % 2 == 1)  // If exp is odd, multiply base with result
            result = (result * base) % mod;
        
        exp = exp >> 1; // Equivalent to exp /= 2
        base = (base * base) % mod; // Square the base modulo mod
    }
    return result;
}

// Function to compute GCD using Euclidean Algorithm
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Pollard's p-1 Factorization Method
long long pollard_p_minus_1(long long n, long long B) {
    long long a = 2; // Initial base

    // Compute a^(k!) % n iteratively
    for (long long e = 2; e <= B; e++) {
        a = mod_exp(a, e, n); // Iteratively exponentiate a
        long long p = gcd(a - 1, n);
        
        // Check if we found a non-trivial factor
        if (p > 1 && p < n) 
            return p;
    }
    
    return -1; // Factorization failed
}

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
    int choice;
    long long n, B;

    while (1) {
        printf("\nChoose a factorization method:\n");
        printf("1. Fermat's Factorization\n");
        printf("2. Pollard's p-1 Factorization\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n\nEnter a number to factorize using Fermat's method: ");
                scanf("%lld", &n);
                if (n <= 0) {
                    printf("Please enter a positive integer.\n");
                } else {
                    fermatFactorization(n);
                }
                break;
            case 2:
                printf("\n\nEnter the number to factorize (n): ");
                scanf("%lld", &n);
                printf("Enter the bound value (B): ");
                scanf("%lld", &B);
                if (n <= 0 || B <= 0) {
                    printf("Please enter positive integers for n and B.\n");
                } else {
                    long long factor = pollard_p_minus_1(n, B);
                    if (factor != -1)
                        printf("A non-trivial factor of %lld is %lld\n", n, factor);
                    else
                        printf("Factorization failed. Try a different bound value B.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}3