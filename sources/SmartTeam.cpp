#include "SmartTeam.hpp"

using namespace ariel;

/**
 * Copy Constructor
 * @param other team to Copy
 */
SmartTeam::SmartTeam(const SmartTeam &other) : Team(other){}

/**
 * Constructor for team
 * @param captain Character to be a captain
 */
SmartTeam::SmartTeam(const Character *captain) : Team(captain){}

/**
 * destructor for Character
 */
SmartTeam::~SmartTeam() {}

/**
 * assignment operator
 * @param other team to assignment
 * @return new team
 */
SmartTeam &SmartTeam::operator=(const SmartTeam &other) {
    return *this;
}

/**
 * add Character to team
 * @param character Character to add
 */
void SmartTeam::add(Character *character) {}

/**
 * attack enemy team
 * @param enemyteam pointer to enemy team
 */
void SmartTeam::attack(Team *enemyteam) {}


/**
 * print all the Character in the team
 * @return string to print
 */
std::string SmartTeam::print() {
    return NULL;
}
