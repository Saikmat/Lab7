/*
 * Copyright 2024 - Howard Community College All rights reserved; Unauthorized duplication prohibited.
 * Name: Sai Matukumalli
 * Program name: Planets
 * Program description: This planet class defines objects to store information about a planet. It can store the planet
 * name, the planet number from the sun, and the number of moons it has. It includes getters for all parameters but
 * only a setter for the name, since the other information is updated using methods based on the name. It also includes
 * overrides for many of the common unary and binary operators to work with the object.
 */


#include <iostream>
#include <string>



class Planet{

private:
    /*
     * Private data members for the name, planet number from the sun, and number of moons, and methods to set them
     */
    std::string name;
    int planetNumber;
    int numberOfMoons;
    int radius;

    void numberSetter();

    void moonSetter();

    void nameFromNumber();

public:

    Planet();

    Planet(int);

    std::string getName() const;

    int getPlanetNumber() const;

    int getNumberOfMoons() const;

    void setRadius();

    int getRadius() const;

    void setName(std::string name);

    Planet* operator+();

    Planet* operator-();

    Planet* operator++();

    Planet* operator++(int);

    Planet& operator=(Planet*);

    friend std::istream& operator>>(std::istream&, Planet&);

    friend std::ostream& operator<<(std::ostream&, Planet&);

    static void printCopyright();


};