#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Character.hpp"
#include "Team.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ariel {
    class Team2 :public Team{
    public:
        Team2(const Character *captain);
        ~Team2() override;
        Team2(const Team2 &other);
        Team2 & operator=(const Team2 &other);
        Team2(Team2 &&) = default;
        Team2 &operator=(Team2 &&) = default;
        void add(Character *character) override;
        void attack(Team *enemyteam) override;
        std::string print() override;
    };
}
#endif //TEAM2_HPP
