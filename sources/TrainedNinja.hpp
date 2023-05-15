#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Character.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ariel {
    class TrainedNinja : public Character{
    public:
        TrainedNinja(std::string name, const Point &location);
        ~TrainedNinja() override;
        TrainedNinja(const TrainedNinja &other);
        TrainedNinja(TrainedNinja &&) = default;
        TrainedNinja &operator=(TrainedNinja &&) = default;
        TrainedNinja & operator = (const TrainedNinja &other);
        void move(const Character *enemy);
        void slash(Character *enemy)const;
        std::string print() override;

    private:
        int speed;
    };
}

#endif //TRAINEDNINJA_HPP