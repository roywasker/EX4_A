//
// Created by royx5 on 07/05/2023.
//

#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Character.hpp"
#include "Team.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ariel {
    class SmartTeam :public Team{
    public:
        SmartTeam(const Character *captain);
        ~SmartTeam() override;
        SmartTeam(const SmartTeam &other);
        SmartTeam & operator=(const SmartTeam &other);
        SmartTeam(SmartTeam &&) = default;
        SmartTeam &operator=(SmartTeam &&) = default;
        void add(Character *character) override;
        void attack(Team *enemyteam) override;
        std::string print() override;
    };
}

#endif //SMARTTEAM_HPP
