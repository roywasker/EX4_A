#include "doctest.h"
#include <stdexcept>
#include "sources/Team.hpp"
#include "sources/Cowboy.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Point.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"

#include <cmath>

using namespace ariel;

TEST_SUITE("Point") {
    TEST_CASE("Test constructor"){
        Point p1(1, 5);
        CHECK(p1.getx() == 1);
        CHECK(p1.gety() == 5);
    }

    TEST_CASE("Test distance") {
        Point p1(1, 2);
        Point p2(3, 4);
        CHECK(p1.distance(p2) == sqrt(8));
    }

    TEST_CASE("Test print") {
        Point p1(1, 2);
        CHECK(p1.print().compare("(1, 2)") == 0);
    }

    TEST_CASE("Test moveTowards") {
        Point p1(1, 2);
        Point p2(1, 4);
        Point p3 = p1.moveTowards(p1, p2, 1);

        CHECK(p3.getx() == 1);
        CHECK(p3.gety() == 3);
    }
}
TEST_SUITE("Character") {
    TEST_CASE("Test hit") {
        Point p(1, 2);
        Character c1(p,"roy", 100);
        c1.hit(50);
        CHECK(c1.isAlive()== true);
        c1.hit(49);
        CHECK(c1.isAlive() == true);
        c1.hit(1);
        CHECK(c1.isAlive()== false);
        CHECK_THROWS(c1.hit(1)); // Character is not alive
    }

    TEST_CASE("Test get location") {
        Point p1(1, 2);
        Character c1(p1, "roy", 100);
        Point p2 = c1.getLocation();
        CHECK(p1.getx()==p2.getx());
        CHECK(p1.gety()==p2.gety());
    }

    TEST_CASE("Test is alive") {
        Point p(1, 2);
        Character c1(p, "roy", 100);
        c1.hit(50);
        CHECK(c1.isAlive()== true);
        c1.hit(51);
        CHECK(c1.isAlive() == false);
    }

}
TEST_SUITE("Cowboy") {
    TEST_CASE("Test copy constructor and assignment operator") {
        Point p;
        Cowboy c1("roy", p);

        Cowboy c2(c1);
        CHECK(c2.getname() == "roy");
        CHECK(c2.getLocation().getx() == 0);
        CHECK(c2.getLocation().gety() == 0);
        CHECK(c2.hasboolets() == true);

        Point p1(1,1);
        Cowboy c3("bob", p1);
        c3 = c1;
        CHECK(c3.getname() == "roy");
        CHECK(c3.getLocation().getx() == 0);
        CHECK(c3.getLocation().gety() == 0);
        CHECK(c3.hasboolets() == true);
    }

    TEST_CASE("Test reload") {
        Point p(1, 2);
        Cowboy c1("roy", p);
        Cowboy c2("bob", p);
        for (int i = 0; i < 6; ++i) {
            c1.shoot(&c2);
        }
        CHECK(c1.hasboolets() == false);
        c1.reload();
        CHECK(c1.hasboolets() == true);
    }

    TEST_CASE("Test shoot") {
        Point p(1, 2);
        Cowboy c1("roy", p);
        CHECK(c1.hasboolets() == true);
        Cowboy c2("bob", p);
        for (int i = 0; i < 6; ++i) {
            c1.shoot(&c2);
        }
        CHECK_THROWS(c1.shoot(&c2)); // no bullets
        CHECK(c1.hasboolets() == false);
        c1.reload();
        for (int i = 0; i < 6; ++i) {
            c1.shoot(&c2);
        }
        CHECK(c2.isAlive() == false);
        CHECK_THROWS(c1.shoot(&c2)); //c2 i not alive
        CHECK_THROWS(c2.shoot(&c1)); //dead cowboy can not shoot
    }
}

TEST_SUITE("Ninja") {
    TEST_CASE("Test copy constructor and assignment operator") {
        Point p;
        OldNinja n1("roy", p);

        OldNinja n2(n1);
        CHECK(n2.getname() == "roy");
        CHECK(n2.getLocation().getx() == 0);
        CHECK(n2.getLocation().gety() == 0);

        Point p1(1, 1);
        OldNinja  n3("bob", p1);
        n3 = n1;
        CHECK(n3.getname() == "roy");
        CHECK(n3.getLocation().getx() == 0);
        CHECK(n3.getLocation().gety() == 0);
    }

    TEST_CASE("Test move") {
        Point p1(1, 2);
        Point p2(3, 4);
        TrainedNinja n1("alise", p1);
        OldNinja n2("bob", p2);

        n1.move(&n2);
        CHECK(n1.getLocation().getx() == 3);
        CHECK(n1.getLocation().gety() == 4);
    }

    TEST_CASE("Test slash") {
        Point p1(1, 2);
        Point p2(1, 3);
        OldNinja n1("alise", p1);
        YoungNinja n2("bob", p2);
        TrainedNinja n3("roy",p1);

        for (int i = 0; i <12 ; ++i) {
            n3.slash(&n2);
            n3.slash(&n1);
        }
        CHECK(n2.isAlive() == false);
        CHECK(n1.isAlive() == false);
        CHECK_THROWS(n3.slash(&n2)); // not alive
        CHECK_THROWS(n3.slash(&n1)); // not alive
        CHECK_THROWS(n3.slash(&n3)); // can not  slash itself
        CHECK_THROWS(n1.slash(&n3)); // dead ninja can not slash
    }
}

TEST_SUITE("Team") {

    TEST_CASE("Test constructor and add") {
        Point p(1, 2);
        Cowboy c1("roy", p);
        OldNinja c2("bob", p);
        TrainedNinja c3("alise", p);

        Team t1(&c1);
        Character captain = t1.getCaptain();
        CHECK_EQ(captain.getname(), "roy");
        CHECK(t1.stillAlive() == 1);

        t1.add(&c2);
        t1.add(&c3);
        CHECK(t1.stillAlive() == 3);
    }

    TEST_CASE("Test select enemy") {
        Point p1(1, 2);
        Point p2(5,16);
        Point p3(2,3);
        Cowboy c1("roy", p1);
        OldNinja c2("bob", p2);
        TrainedNinja c3("alise", p3);
        YoungNinja c4("ninja", p2);

        Team t1(&c1);
        t1.add(&c2);
        Team t2(&c3);
        t2.add(&c4);
        Character enemy = t1.selectenemy();
        CHECK(enemy.getname() == "alise");
    }

    TEST_CASE("Test new captain") {
        Point p1(1, 2);
        Point p2(5,16);
        Point p3(2,3);
        Cowboy c1("roy", p1);
        OldNinja c2("bob", p2);
        TrainedNinja c3("alise", p3);

        Team t1(&c1);
        t1.add(&c2);
        t1.add(&c3);
        t1.newcaptain();
        Character newc = t1.getCaptain();
        CHECK(newc.getname() == "alise");
    }

    TEST_CASE("Test attack") {
        Point p1(1, 2);
        Point p2(5,16);
        Point p3(2,3);
        Cowboy c1("roy", p1);
        OldNinja c2("bob", p2);
        TrainedNinja c3("alise", p3);

        Team t1(&c1);
        t1.add(&c2);

        Team t2(&c3);
        CHECK(t2.stillAlive() == 1);
        for (int i = 0 ; i<4 ;i++){
            t1.attack(&t2);
        }
        CHECK(t2.stillAlive() == 0);
    }

    TEST_CASE("Test attack empty team") {
        Point p1(1, 2);
        Cowboy c1("roy", p1);
        OldNinja c2("bob", p1);

        Team t1(&c1);
        Team t2(&c2);
        CHECK(t2.stillAlive() == 1);

        for (int i = 0 ; i<15 ;i++){
            t1.attack(&t2);
        }
        CHECK(t2.stillAlive() == 0);
        CHECK_THROWS(t1.attack(&t2));
    }

    TEST_CASE("Test add same Character to team ") {
        Point p1(1, 2);
        Cowboy c1("roy", p1);

        Team t1(&c1);
        CHECK(t1.stillAlive() == 1);
        CHECK_THROWS(t1.add(&c1));
    }

    TEST_CASE("Test change change automatic") {
        Point p1(1, 2);
        Cowboy c1("roy", p1);
        OldNinja c2("bob", p1);

        Team t1(&c1);
        t1.add(&c2);

        CHECK(t1.stillAlive() == 2);
        t1.getCaptain().hit(200);
        CHECK(t1.stillAlive() == 1);
        Character newc = t1.getCaptain(); // check if captain change after first captain dead
        CHECK(newc.getname() == "bob");
    }

    TEST_CASE("Test print team stats different between 2 team have same  character") {
        Point p1(1, 2);
        Cowboy c1("roy", p1);
        OldNinja c2("bob", p1);

        Team t1(&c1);
        t1.add(&c2);
        Team2 t2(&c1);
        t2.add(&c2);
        SmartTeam t3(&c1);
        t3.add(&c2);
        CHECK_NE(t1.print(),t2.print());
        CHECK_NE(t1.print(),t3.print());
        CHECK_NE(t2.print(),t3.print());
    }
}