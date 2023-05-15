#include "OldNinja.hpp"

using namespace ariel;

/**
 * Constructor for YoungNinja
 * @param name YoungNinja name
 * @param location YoungNinja location
 */
OldNinja::OldNinja(std::string name, const Point &location) : Character(location,name,100) , speed(0){}

/**
 * Copy Constructor
 * @param other OldNinja to Copy
 */
OldNinja::OldNinja(const OldNinja &other) : Character(other){}

/**
 * destructor for OldNinja
 */
OldNinja::~OldNinja() {}

/**
 * assignment operator
 * @param other OldNinja to assignment
 * @return new OldNinja
 */
OldNinja &OldNinja::operator=(const OldNinja &other) {return *this;}

/**
 *  move YoungNinja to enemy
 * @param enemy pointer of the enemy
 */
void OldNinja::move(const Character *enemy) {}

/**
 * Hit the enemy by 31 hit point
 * @param enemy pointer to enemy
 */
void OldNinja::slash(Character *enemy) const {}

/**
 * Print the values of the OldNinja
 * @return string to print
 */
std::string OldNinja::print() {return " ";}