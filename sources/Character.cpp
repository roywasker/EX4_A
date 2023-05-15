#include "Character.hpp"

using namespace ariel;


/**
 * Constructor for Character
 * @param location Character location
 * @param hitpoint Character hitpoint
 * @param name Character name
 */
Character::Character(const Point&location, std::string name, int hitpoint){}

/**
 * Copy Constructor
 * @param other Character to Copy
 */
Character::Character(const Character &other) {}

/**
 * destructor for Character
 */
Character::~Character() {}

/**
 * assignment operator
 * @param other Character to assignment
 * @return new Character
 */
Character &Character::operator=(const Character &other){return *this;}

/**
 * Check if  Character is alive
 * @return return ture if he alive , otherwise false
 */
bool Character::isAlive() const {
    return false;
}

/**
 * Calculation of distance between 2 Character
 * @param other location of second Character
 * @return return the distance
 */
double Character::distance(const Character &other) const {return 0;}

/**
 * Subtracts the hit points from the character
 * @param hitpoint how much hit point to subtracts
 */
void Character::hit(int hitpoint) {}

/**
 * return Character name
 * @return Character name
 */
std::string Character::getname() const {
    return this->name;
}

/**
 * return Character location
 * @return Character location
 */
Point Character::getLocation() const {
    return this->location;
}

/**
 * Print the values of the Character
 * @return return the values of the Character
 */
std::string Character::print() {return "";}
