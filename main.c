#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

double celsiusParaFahrenheit(double celsius);
double celsiusParaKelvin(double celsius);
double fahrenheitParaCelsius(double fahrenheit);
double fahrenheitParaKelvin(double fahrenheit);
double kelvinParaFahrenheit(double kelvin);
double kelvinParaCelsius(double kelvin);
void tratarUnidadeInvalida();

int main() {
    setlocale(LC_ALL, "");

    char unidadeOrigem, unidadeDestino;
    double resultado, temperatura;

    printf("\nDigite a unidade de origem (C, F ou K): ");
    scanf(" %c", &unidadeOrigem);

    printf("\nDigite a unidade de destino (C, F ou K): ");
    scanf(" %c", &unidadeDestino);

    printf("\nDigite a temperatura: ");
    scanf("%lf", &temperatura);

    switch (unidadeOrigem)
    {
    case 'C':
    case 'c':
        switch (unidadeDestino)
        {
        case 'F':
        case 'f':
            resultado = celsiusParaFahrenheit(temperatura);
            printf("\nTemperatura convertida: %.2lf F\n", resultado);
            break;
        case 'K':
        case 'k':
            resultado = celsiusParaKelvin(temperatura);
            printf("\nTemperatura convertida: %.2lf K\n", resultado);
            break;
        default:
            tratarUnidadeInvalida();
        }
        break;
    case 'F':
    case 'f':
        switch (unidadeDestino)
        {
        case 'C':
        case 'c':
            resultado = fahrenheitParaCelsius(temperatura);
            printf("\nTemperatura convertida: %.4lf C\n", resultado);
            break;
        case 'K':
        case 'k':
            resultado = fahrenheitParaKelvin(temperatura);
            printf("\nTemperatura convertida: %.3lf K\n", resultado);
            break;

        default:
            tratarUnidadeInvalida();
        }
    break;
    case 'K':
    case 'k':
        switch (unidadeDestino)
        {
        case 'F':
        case 'f':
            resultado = kelvinParaFahrenheit(temperatura);
            printf("\nTemperatura convertida: %.2lf F\n", resultado);
            break;
        case 'C':
        case 'c':
            resultado = kelvinParaCelsius(temperatura);
            printf("\nTemperatura convertida: %.2lf C\n", resultado);
            break;
        default:
            tratarUnidadeInvalida();
        }
    break;
    default:
        tratarUnidadeInvalida();
    }
    return 0;
}


// Converte Celsius
double celsiusParaFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

double celsiusParaKelvin(double celsius) {
    return celsius + 273.15;
}


// Converter Fahrenheit
double fahrenheitParaCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

double fahrenheitParaKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}


// Converte Kelvin
double kelvinParaFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}

double kelvinParaCelsius(double kelvin) {
    return kelvin - 273.15;
}

void tratarUnidadeInvalida() {
    printf("Ocorreu um erro! Por favor, use 'K' para Kelvin, 'F' para Fahrenheit ou 'C' para Celsius.\n");
    exit(1);
}
