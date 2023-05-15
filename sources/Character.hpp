#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "Point.hpp"

using namespace std;

namespace ariel {
    class Character{
    public:
        Character(const Point&location, std::string name, int hitpoint);
        virtual ~Character();
        Character(const Character &other);
        Character(Character &&) = default;
        Character &operator=(Character &&) = default;
        Character & operator = (const Character &other);
        bool isAlive() const;
        double distance(const Character &other) const;
        void hit(int hitpoint);
        std::string getname() const;
        Point getLocation() const;
        virtual std::string print();

    private:
        Point location;
        int hitpoint;
        std::string name;
    };
}

#endif //CHARACTER_HPP
