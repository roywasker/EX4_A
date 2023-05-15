#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Character.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ariel {
    class OldNinja : public Character{
    public:
        OldNinja (std::string name, const Point &location);
        ~OldNinja() override;
        OldNinja(const OldNinja &other);
        OldNinja(OldNinja &&) = default;
        OldNinja &operator=(OldNinja &&) = default;
        OldNinja & operator = (const OldNinja &other);
        void move(const Character *enemy);
        void slash(Character *enemy)const;
        std::string print() override;

    private:
        int speed;
    };
}
#endif //OLDNINJA_HPP
