#include "YoungNinja.hpp"

using namespace ariel;

/**
 * Constructor for YoungNinja
 * @param name YoungNinja name
 * @param location YoungNinja location
 */
YoungNinja::YoungNinja(std::string name, const Point &location) : Character(location,name,100) , speed(0) {}

/**
 * Copy Constructor
 * @param other YoungNinja to Copy
 */
YoungNinja::YoungNinja(const YoungNinja &other) : Character(other){}

/**
 * destructor for YoungNinja
 */
YoungNinja::~YoungNinja() {}

/**
 * assignment operator
 * @param other YoungNinja to assignment
 * @return new YoungNinja
 */
YoungNinja &YoungNinja::operator=(const YoungNinja &other) {return *this;}

/**
 *  move YoungNinja to enemy
 * @param enemy pointer of the enemy
 */
void YoungNinja::move(const Character *enemy) {}

/**
 * Hit the enemy by 31 hit point
 * @param enemy pointer to enemy
 */
void YoungNinja::slash(Character *enemy) const {}

/**
 * Print the values of the YoungNinja
 * @return string to print
 */
std::string YoungNinja::print() {return " ";}