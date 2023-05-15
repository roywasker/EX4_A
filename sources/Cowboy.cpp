#include "Cowboy.hpp"

using namespace ariel;

/**
 * Constructor for Cowboy
 * @param name Cowboy name
 * @param location  Cowboy location
 */
Cowboy::Cowboy(std::string  name, const Point &location) : Character(location,name,100) , bullets(6){}

/**
 * Copy Constructor
 * @param other Cowboy to Copy
 */
Cowboy::Cowboy(const Cowboy &other) : Character(other) {}

/**
 * destructor for Cowboy
 */
Cowboy::~Cowboy() {}

/**
 * assignment operator
 * @param other Cowboy to assignment
 * @return new Cowboy
 */
Cowboy &Cowboy::operator=(const Cowboy &other) {return *this;}

/**
 * Cowboy shoots the enemy, subtracting hit points from the enemy
 * @param enemy pointer to  enemy
 */
void Cowboy::shoot(Character *enemy) {}

/**
 * Check if cowboy have bullet
 * @return return ture if he have bullet , otherwise false
 */
bool Cowboy::hasboolets() const {return 0;}

/**
 * reload cowboy gun with 6 bullet
 */
void Cowboy::reload() {}

/**
 * Print the values of the cowboy
 * @return string to print
 */
std::string Cowboy::print() {return " ";}