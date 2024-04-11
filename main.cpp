/*
 * Copyright 2024 - Howard Community College All rights reserved; Unauthorized duplication prohibited.
 * Name: Sai Matukumalli
 * Program name: Planets Driver
 * Program description: This driver is designed to test the planets class. It uses all methods in the class either
 * via calls within the function or by explicitly calling them. The program also introduces a template which is tested.
 */

#include <iostream>
#include <iomanip>
#include "main.h"
#include "planet.h"

using namespace std;

template<typename T> T radiusEarth(Planet *x, bool y, T &z);

int main() {
    // 1
    Planet::printCopyright();
    //2
    Planet *planet1 = new Planet(5);
    //3
    Planet *planet2;
    Planet *planet3;
    Planet *planet4;
    Planet *planet5;
    Planet *planet6;
    Planet *planet7;
    Planet *planet8;
    //4
    cout << "Non-overloaded print call" << endl;
    cout << "The name of the planet is: " << planet1->getName() <<
         "\nIt is planet number: " << planet1->getPlanetNumber() <<
         "\nIt has radius: " << planet1->getRadius() <<
         "\nIt has " << planet1->getNumberOfMoons() << " Moons.\n\n";
    //5
    cout << "Using overloaded output stream operator" << endl;
    cout << *planet1;
    //6a
    cout << "Using overloaded Prefix increment operator on planet 2" << endl;
    planet2 = ++*planet1;
    //6b
    cout << *planet2;
    //7a
    cout << "Using overloaded Postfix increment operator on Planet 3" << endl;
    planet3 = (*planet1)++;
    //7b
    cout << *planet3;
    //8a
    cout << "Using overloaded stream Input operator on Planet 4" << endl;
    cin >> *planet4;
    //8b
    cout << *planet4;
    //9a
    cout << "Using overloaded Minus operator on Planet 5" << endl;
    planet5 = -*planet5;
    //9b
    cout << *planet5;
    //10a
    cout << "Using overloaded Plus operator on Planet 6" << endl;
    planet6 = +*planet6;
    //10b
    cout << *planet6;
    //3
    cout << "Using the try..catch to get input for Planet 7" << endl;
    bool flag;
    do {
        int planet7Number;
        try {
            cout << "Enter a planet number: ";
            cin >> planet7Number;
            planet7 = new Planet(planet7Number);
            flag = false;
        } catch (invalid_argument &e) {
            cout << "Invalid value, enter a value between 1 and 8" << endl;
            flag = true;
        }
    } while (flag);
    cout << *planet7;
    //5
    cout << "Using template to display different radius values" << endl;
    planet8 = new Planet(6);

    cout << "Name: " << planet8->getName() << endl
         << "Number: " << planet8->getPlanetNumber() << endl
         << "Moons: " << planet8->getNumberOfMoons() << endl;

    double radius = 0;
    const bool MILES_WIDE_TEMPLATE_BOOL = true;
    const bool EARTH_EQUIVALENT_TEMPLATE_BOOL = false;

    radiusEarth(planet8, MILES_WIDE_TEMPLATE_BOOL, radius);
    cout << "Saturn is " << radius << " miles wide" << endl;

    radiusEarth(planet8, EARTH_EQUIVALENT_TEMPLATE_BOOL, radius);
    cout << setprecision(3) << "Saturn is " << radius << " Earth Radii" << endl;

    cout << "Thank you for using the planets class" << endl;

    delete planet1;
    delete planet8;
    return 0;
}




/*
 * Template to get the radius of a planet and set it equal to any passed reference
 * Requires that the equal operator be defined for doubles
 * Takes a Planet object
 * a boolean where true means that it returns the radius in miles and false returns the value with respect to the diameter of the earth
 * a reference to any type, to which the radius is set.
 */
template<typename T> T radiusEarth(Planet *x, bool y, T &z){
    if(y){
        z = x->getRadius();
        return z;
    } else {
        const double EARTH_RADIUS = 3959;
        z = x->getRadius() / EARTH_RADIUS;
        return z;
    }
}
