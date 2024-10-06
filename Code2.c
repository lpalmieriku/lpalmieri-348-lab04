/*
Name: Lena Palmieri
KUID: 3115099
Date: 10/2/24
Lab: lab04
Last Modified: 10/6/24
Purpose: Asks the user for a temperature, the scale it is in, and the scale it would like the temperature to be converted to. The program outputs the converted temperature and the weather type of the day plus a weather advisory based on the temperature.
*/

#include <stdio.h>

//Function that takes in the temp and the scale and checks if the temperature at that scale is impossible (below absolute zero) or extreme (above boiling point of water or below lowest recorded temp ever).
//If this is true, then the user must reinput a valid temperature value for that scale
float checkValidTemp(int temp, int scale) {
    while ((scale == 2 && (temp > 212 || temp < -200)) || (scale == 1 && (temp > 100 || temp < -100)) || (scale == 3 && (temp > 400 || temp < 0))) {
        printf("Extreme temperature input!\nPlease enter a lower temperature: ");
        scanf("%lu", &temp);
    }
    return temp;
}

//Function that takes in both the scales and checks if the program is being told to convert to the same temperature scale it was given
//Also checks if the user inputed an invalid/unknown scale
//If true, then the user must input a different conversion scale
int checkEqualScale(int scale1, int scale2) {
    while (scale1 == scale2 || scale2 < 1 || scale2 > 3) {
        printf("Cannot convert temperature to same or unknown scale!\nPlease enter a different scale to convert to: ");
        scanf("%lu", &scale2);
    }
    return scale2;
}

//Function that takes in a scale and checks if it was a valid option given for the user to input
//If false, then the user must input a valid temperature scale
int checkTempScale(int scale) {
    while (scale < 1 || scale > 3) {
        printf("Cannot use unknown scale!\nPlease enter a valid temperature scale: ");
        scanf("%lu", &scale);
    }
    return scale;
}

//Returns the given celsius temperature converted to fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (9*celsius)/5 + 32;
}

//Returns the given fahrenheit temperature converted to celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (5*(fahrenheit-32))/9;
}

//Returns the given celsius temperature converted to kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

//Returns the given kelvin temperature converted to celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

//Returns the given fahrenheit temperature converted to kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    return (((fahrenheit - 32)*5)/9) + 273.15;
}

//Returns the given kelvin temperature converted to fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    return (((kelvin - 273.15)*9)/5) + 32;
}

int main() {
    //Initializes all the variables and asks the user to input the temperature, its scale, and the conversion scale
    float convertTemp, advisoryTemp;
    int temp, startScale, returnScale;
    printf("Enter temperature value: ");
    scanf("%lu", &temp);
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%lu", &startScale);
    //Checks if the temperature given for that scale is valid
    temp = checkValidTemp(temp, startScale);
    //Checks if the scale given is valid
    startScale = checkTempScale(startScale);
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%lu", &returnScale);
    //Checks if the scale given is valid
    returnScale = checkTempScale(returnScale);
    //Checks that the user did not give same temperature and conversion scale
    returnScale = checkEqualScale(startScale, returnScale);

    //Dependent upon which scales the user inputs, the program converts the temperature using the above functions
    //It also calculates the advisory temperature by converting whichever temperature is inputted to celsius or just using the given temperature if it is in celsius
    //Prints the converted temperature with the correct label
    if (startScale == 1 && returnScale == 2) {
        convertTemp = celsius_to_fahrenheit(temp);
        advisoryTemp = temp;
        printf("Converted Temperature: %.2f°F\n", convertTemp);
    }
    else if (startScale == 1 && returnScale == 3) {
        convertTemp = celsius_to_kelvin(temp);
        advisoryTemp = temp;
        printf("Converted Temperature: %.2fK\n", convertTemp);
    }
    else if (startScale == 2 && returnScale == 1) {
        convertTemp = fahrenheit_to_celsius(temp);
        advisoryTemp = convertTemp;
        printf("Converted Temperature: %.2f°C\n", convertTemp);
    }
    else if (startScale == 2 && returnScale == 3) {
        convertTemp = fahrenheit_to_kelvin(temp);
        advisoryTemp = fahrenheit_to_celsius(temp);
        printf("Converted Temperature: %.2fK\n", convertTemp);
    }
    else if (startScale == 3 && returnScale == 1) {
        convertTemp = kelvin_to_celsius(temp);
        advisoryTemp = convertTemp;
        printf("Converted Temperature: %.2f°C\n", convertTemp);
    }
    else {
        convertTemp = kelvin_to_fahrenheit(temp);
        advisoryTemp = kelvin_to_celsius(temp);
        printf("Converted Temperature: %.2f°F\n", convertTemp);
    }

    //Compares the advisory temperature to given celsius scale and prints the weather type and advisory note for the specific weather type
    //If temperature is on the boundary of a range: 35 = Extreme Heat, 25 = Hot, 10 = Comfortable, 0 = Cold
    if (advisoryTemp >= 35) {
        printf("Temperature category: Extreme Heat\nWeather advisory: Stay indoors");
    }
    else if (advisoryTemp >= 25) {
        printf("Temperature category: Hot\nWeather advisory: Put on sunscreen");
    }
    else if (advisoryTemp >= 10) {
        printf("Temperature category: Comfortable\nWeather advisory: Enjoy the weather");
    }
    else if (advisoryTemp >= 0) {
        printf("Temperature category: Cold\nWeather advisory: Wear a jacket");
    }
    else {
        printf("Temperature category: Freezing\nWeather advisory: Wear a winter coat");
    }
    
    return 0;
}