#include <iostream>
#include "Entity.h"
#include "City.h"

void simulateCombat() {
    Entity monster("Monster", "balanced", 100, 20);
    Entity enemy("Enemy", "balanced", 120, 15);

    std::cout << "Combat Simulation Begins!\n";

    int turn = 1;
    while (monster.isAlive() && enemy.isAlive()) {
        std::cout << "Turn " << turn << ":\n";

        int monsterAttack = monster.attack();
        enemy.takeDamage(monsterAttack);
        std::cout << monster.type << " (" << monster.health << ") attacks for " << monsterAttack
            << " damage! " << enemy.type << " health: "
            << enemy.health+monsterAttack << " - " << monsterAttack << " = " << enemy.health << "\n";

        if (!enemy.isAlive()) {
            std::cout << enemy.type << " defeated!\n";
            break;
        }

        int enemyAttack = enemy.attack();
        monster.takeDamage(enemyAttack);
        std::cout << enemy.type << " (" << enemy.health << ") (" << enemy.behavior
            << " behavior) attacks for " << enemyAttack
            << " damage! " << monster.type << " health: "
            << monster.health+enemyAttack << " - " << enemyAttack << " = " << monster.health << "\n";

        if (!monster.isAlive()) {
            std::cout << monster.type << " defeated!\n";
            break;
        }

        if (turn % 2 == 0) {
            enemy.changeBehavior();
            std::cout << enemy.type << " changes behavior to "
                << enemy.behavior << ".\n";
        }

        turn++;
    }
    std::cout << "Combat Simulation Ends!\n\n";
}

void simulateCityManagement() {
    City city;

    std::cout << "City Management Simulation Begins!\n";

    city.assignNPCs("Gathering", 5);
    city.gatherResources();

    city.upgradeBuilding("Runesmith");

    city.assignNPCs("Building", 3);
    city.upgradeBuilding("Library");
    city.gatherResources();

    city.displayStatus();
}

int main() {
    simulateCombat();
    simulateCityManagement();
    return 0;
}