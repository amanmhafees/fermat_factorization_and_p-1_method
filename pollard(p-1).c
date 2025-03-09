#include <stdio.h>
#include <math.h>

long long gcd(long long a, long long b) {
    while (b) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long pollard_p_minus_1(long long n, long long B) {
    long long a = 2;
    long long e = 2;

    while (e <= B) {
        a = mod_exp(a, e, n); // a ← a^e mod n
        e++;
    }

    long long p = gcd(a - 1, n);

    if (p > 1 && p < n)
        return p;  // Return the factor found
    else
        return -1; // Failure
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
