#ifndef TEAM_HPP
#define TEAM_HPP

#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

#include <iostream>
#include <string>
#include <vector>

#define maxCharacter 10;

using namespace std;
namespace ariel {
    class Team{
    public:
        Team(const Character *captain);
        virtual ~Team();
        Team(const Team &other);
        Team & operator=(const Team &other);
        Team(Team &&) = default;
        Team &operator=(Team &&) = default;
        virtual void add(Character *character);
        virtual void attack(Team *enemyteam);
        void newcaptain();
        Character& selectenemy() const;
        int stillAlive();
        Character& getCaptain();
        virtual std::string print();

    private:
        Character *captain;
        std::vector <Character*> list;
    };
}

#endif //TEAM_HPP
