#include "Entity.h"

Entity::Entity(std::string t, std::string b, int h, int ap)
    : type(t), behavior(b), health(h), baseAttackPower(ap) {}

int Entity::attack() const {
    if (behavior == "aggressive") {
        return baseAttackPower + 5;
    }
    else if (behavior == "defensive") {
        return baseAttackPower - 5;
    }
    return baseAttackPower;
}

void Entity::takeDamage(int damage) {
    if (behavior == "defensive") {
        damage -= 3;
    }
    health -= (damage > 0 ? damage : 0);
}

void Entity::changeBehavior() {
    if (behavior == "balanced") {
        behavior = "aggressive";
    }
    else if (behavior == "aggressive") {
        behavior = "defensive";
    }
    else {
        behavior = "balanced";
    }
}

bool Entity::isAlive() const {
    return health > 0;
}
