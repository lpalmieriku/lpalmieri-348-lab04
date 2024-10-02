/*
Name: Lena Palmieri
KUID: 3115099
Date: 10/2/24
Lab: lab04
Last Modified:
Purpose:
*/

#include <stdio.h>

float checkValidTemp(float temp, char scale[]) {
    while ( (scale == "Fahrenheit" && (temp > 212 || temp < -200)) || (scale == "Celsius" && (temp > 100 || temp < -100)) || (scale == "Kelvin" && (temp > 400 || temp < 0))) {
        printf("Invalid temperature input!\nPlease enter a lower temperature: ");
        scanf("%f", temp);
    }
    return temp;
}

float celsius_to_fahrenheit(float celsius) {
    return (9*celsius)/5 + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5/9)*(fahrenheit-32);
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return (fahrenheit - 459.67)*(5/9);
}

float kelvin_to_fahrenheit(float kelvin) {
    return (9/5)*kelvin - 459.67;
}

void categorize_temperature(float celsius) {
    if (celsius > 35) {
        printf("Extreme Heat. Stay indoors.");
    }
    else if (celsius >= 25) {
        printf("Hot. Put on sunscreen.");
    }
    else if (celsius >= 10) {
        printf("Comfortable. Enjoy the weather.");
    }
    else if (celsius >= 0) {
        printf("Cold. Bring a jacket.");
    }
    else {
        printf("Freezing. Wear a coat");
    }
}

int main() {
    float temp;
    char startScale[10], returnScale[10];
    printf("Enter temperature value: ");
    scanf("%f", temp);
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", startScale);
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", returnScale);

    temp = checkValidTemp(temp, startScale);
    //check valid conversion scale
    //do rest of program

    return 0;
}