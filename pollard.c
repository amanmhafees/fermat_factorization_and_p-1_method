
#include <stdio.h>

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

int main() {
    long long n, B;
    
    printf("Enter the number to factorize (n): ");
    scanf("%lld", &n);
    
    printf("Enter the bound value (B): ");
    scanf("%lld", &B);

    long long factor = pollard_p_minus_1(n, B);

    if (factor != -1)
        printf("A non-trivial factor of %lld is %lld\n", n, factor);
    else
        printf("Factorization failed. Try a different bound value B.\n");

    return 0;
}