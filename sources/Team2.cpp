#include "Team2.hpp"

using namespace ariel;

/**
 * Copy Constructor
 * @param other team to Copy
 */
Team2::Team2(const Team2 &other) : Team(other) {}

/**
 * Constructor for team
 * @param captain Character to be a captain
 */
Team2::Team2(const Character *captain) : Team(captain){}

/**
 * destructor for Character
 */
Team2::~Team2() {}

/**
 * assignment operator
 * @param other team to assignment
 * @return new team
 */
Team2 &Team2::operator=(const Team2 &other) {
    return *this;
}

/**
 * add Character to team
 * @param character Character to add
 */
void Team2::add(Character *character) {}

/**
 * attack enemy team
 * @param enemyteam pointer to enemy team
 */
void Team2::attack(Team *enemyteam) {}


/**
 * print all the Character in the team
 * @return string to print
 */
std::string Team2::print() {
    return NULL;
}
