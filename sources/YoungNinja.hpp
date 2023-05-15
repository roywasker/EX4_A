#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include "Character.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ariel {
    class YoungNinja : public Character{
    public:
        YoungNinja(std::string name, const Point &location);
        ~YoungNinja() override;
        YoungNinja(const YoungNinja &other);
        YoungNinja(YoungNinja &&) = default;
        YoungNinja &operator=(YoungNinja &&) = default;
        YoungNinja & operator = (const YoungNinja &other);
        void move(const Character *enemy);
        void slash(Character *enemy)const;
        std::string print() override;

    private:
        int speed;
    };
}
#endif //YOUNGNINJA_HPP
