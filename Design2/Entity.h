#pragma once
#include <string>

class Entity {
public:
    std::string type;
    std::string behavior;
    int health;
    int baseAttackPower;

    Entity(std::string t, std::string b, int h, int ap);
    int attack() const;
    void takeDamage(int damage);
    void changeBehavior();
    bool isAlive() const;
};