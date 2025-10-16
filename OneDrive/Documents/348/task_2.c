#include <stdio.h>

// Function prototypes
double toCelsius(double temp, char scale);
double fromCelsius(double tempC, char targetScale);
void categorizeTemperature(double tempC);

int main() {
    double tempInput, tempConverted;
    char scaleInput, scaleTarget;

    printf("Enter the temperature value: ");
    scanf("%lf", &tempInput);

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &scaleInput);  // Space before %c to skip newline

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &scaleTarget);

    // Convert input to Celsius first
    double tempC = toCelsius(tempInput, scaleInput);

    // Convert from Celsius to target scale
    tempConverted = fromCelsius(tempC, scaleTarget);

    printf("\nConverted temperature: %.2f %c\n", tempConverted, scaleTarget);

    // Categorize and give advisory using Celsius value
    categorizeTemperature(tempC);

    return 0;
}

// Convert any scale to Celsius
double toCelsius(double temp, char scale) {
    switch (scale) {
        case 'C': case 'c':
            return temp;
        case 'F': case 'f':
            return (temp - 32) * 5.0 / 9.0;
        case 'K': case 'k':
            return temp - 273.15;
        default:
            printf("Invalid input scale. Assuming Celsius.\n");
            return temp;
    }
}

// Convert from Celsius to target scale
double fromCelsius(double tempC, char targetScale) {
    switch (targetScale) {
        case 'C': case 'c':
            return tempC;
        case 'F': case 'f':
            return (tempC * 9.0 / 5.0) + 32;
        case 'K': case 'k':
            return tempC + 273.15;
        default:
            printf("Invalid target scale. Assuming Celsius.\n");
            return tempC;
    }
}

// Categorize and provide weather advisory
void categorizeTemperature(double tempC) {
    printf("Temperature category: ");

    if (tempC < 0) {
        printf("Freezing\n");
        printf("Weather advisory: Stay warm and avoid icy areas!\n");
    }
    else if (tempC < 10) {
        printf("Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    }
    else if (tempC < 25) {
        printf("Comfortable\n");
        printf("Weather advisory: Enjoy the nice weather!\n");
    }
    else if (tempC < 35) {
        printf("Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    }
    else {
        printf("Extreme Heat\n");
        printf("Weather advisory: Stay indoors and avoid the sun!\n");
    }
}
