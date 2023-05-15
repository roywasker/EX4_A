#include "Team.hpp"

using namespace ariel;

/**
 * Copy Constructor
 * @param other team to Copy
 */
Team::Team(const Team &other) {}

/**
 * Constructor for team
 * @param captain Character to be a captain
 */
Team::Team(const Character *captain) {}

/**
 * destructor for Character
 */
Team::~Team() {}

/**
 * assignment operator
 * @param other team to assignment
 * @return new team
 */
Team &Team::operator=(const Team &other) {
    return *this;
}

/**
 * add Character to team
 * @param character Character to add
 */
void Team::add(Character *character) {}

/**
 * attack enemy team
 * @param enemyteam pointer to enemy team
 */
void Team::attack(Team *enemyteam) {}

/**
 * if captain is not alive select new captain
 */
void Team::newcaptain(){}

/**
 * select new enemy that he closest to the captain
 * @return pointer to enemy
 */
Character& Team::selectenemy() const{return *captain;}

/**
 *  how much Character in team are alive
 * @return number of Character in team are alive
 */
int Team::stillAlive() {return 0;}

/**
 * getter fo team captain
 * @return pointer to captain
 */
Character& Team::getCaptain() {
    return *captain;
}
/**
 * print all the Character in the team
 * @return string to print
 */
std::string Team::print() {return NULL;}
