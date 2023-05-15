#include "TrainedNinja.hpp"

using namespace ariel;

/**
 * Constructor for TrainedNinja
 * @param name TrainedNinja name
 * @param location TrainedNinja location
 */
TrainedNinja::TrainedNinja(std::string name, const Point &location) : Character(location,name,100) , speed(0) {}

/**
 * Copy Constructor
 * @param other TrainedNinja to Copy
 */
TrainedNinja::TrainedNinja(const TrainedNinja &other) : Character(other) {}

/**
 * destructor for TrainedNinja
 */
TrainedNinja::~TrainedNinja() {}

/**
 * assignment operator
 * @param other TrainedNinja to assignment
 * @return new TrainedNinja
 */
TrainedNinja &TrainedNinja::operator=(const TrainedNinja &other) {return *this;}

/**
 *  move TrainedNinja to enemy
 * @param enemy pointer of the enemy
 */
void TrainedNinja::move(const Character *enemy) {}

/**
 * Hit the enemy by 31 hit point
 * @param enemy pointer to enemy
 */
void TrainedNinja::slash(Character *enemy) const {}

/**
 * Print the values of the TrainedNinja
 * @return string to print
 */
std::string TrainedNinja::print() {return " ";}



