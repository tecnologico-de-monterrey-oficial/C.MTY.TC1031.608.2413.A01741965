#include <iostream>

//suma iterativa
int sumaIterativa(int n) {
    int suma = 0;
    for (int i = 1; i <= n; i++) {
        suma += i;
    }
    return suma;
}

//suma recursiva
int sumaRecursiva(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sumaRecursiva(n - 1);
    }
}

int bacteriasRecursivas(int dia) {
    if (dia == 0) {
        return 1;
    } else {
        return bacteriasRecursivas(dia - 1) * ((3.78 - 2.34) + 1);
    }
}

int bacteriasIterativo(int dia) {
    int bacterias = 1;
    for (int i = 1; i <= dia; i++) {
        bacterias = bacterias * (3.78 - 2.34) + bacterias;
    }
    return bacterias;
}

double dineroRecursive(int dia, double monto) {
    if (dia == 0) {
        return monto;
    } else {
        return dineroRecursive(dia - 1, monto) * 1.1875;
    }
}
double dineroIterativo(int dia, double monto) {
    for (int i = 1; i <= dia; i++) {
        monto = monto * 1.1875;
    }
    return monto;
}
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int fibonacciIterativo(int n) {
    int a = 0;
    int b = 1;
    int c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int powerRecursive (int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return base * powerRecursive(base, exponent - 1);
    }
}
int powerIterative (int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
int factorialRecursive(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorialRecursive(n - 1);
    }
}
int factorialIterative(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int sumFormula(int n) {
    return n * (n + 1) / 2;
}
int main() {
    int a = 5;
    std::cout << "Suma de 1 hasta 5 es: " << sumaIterativa(a) << std::endl;
    std::cout << "Suma de 1 hasta 5 es: " << sumaRecursiva(a) << std::endl;

    std::cout << "Bacterias en el dia 5: " << bacteriasRecursivas(5) << std::endl;
    std::cout << "Bacterias en el dia 5: " << bacteriasIterativo(5) << std::endl;

    std::cout << "Dinero en el dia 2: " << dineroRecursive(1, 1000000) << std::endl;
    std::cout << "Dinero en el dia 2: " << dineroIterativo(1, 1000000) << std::endl;

    std::cout << "Fibonacci de 5: " << fibonacci(5) << std::endl;
    std::cout << "Fibonacci de 5: " << fibonacciIterativo(5) << std::endl;

    std::cout << "2^3: " << powerRecursive(2, 3) << std::endl;
    std::cout << "2^3: " << powerIterative(2, 3) << std::endl;

    std::cout << "5!: " << factorialRecursive(5) << std::endl;
    std::cout << "5!: " << factorialIterative(5) << std::endl;

    std::cout << "Suma de 1 hasta 5 es: " << sumFormula(a) << std::endl;

    return 0;
}