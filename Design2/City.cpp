#include "City.h"
#include <iostream>

City::City() : resources(100) {
    buildings["Runesmith"] = 0;
    buildings["Library"] = 0;
    buildings["Barracks"] = 0;
    npcTasks["Gathering"] = 0;
    npcTasks["Building"] = 0;
}

void City::assignNPCs(const std::string& task, int count) {
    npcTasks[task] += count;
    std::cout << count << " NPCs assigned to " << task << ".\n";
}

void City::gatherResources() {
    int gathered = npcTasks["Gathering"] * 10;
    resources += gathered;
    std::cout << "NPCs gathered " << gathered << " resources. Total: " << resources << "\n";
}

void City::upgradeBuilding(const std::string& building) {
    if (resources >= 50) {
        buildings[building]++;
        resources -= 50;
        std::cout << building << " upgraded to level " << buildings[building]
            << ". Remaining resources: " << resources << "\n";
    }
    else {
        std::cout << "Not enough resources to upgrade " << building << ".\n";
    }
}

void City::displayStatus() const {
    std::cout << "City Status:\nResources: " << resources << "\nBuildings:\n";
    for (const auto& building : buildings) {
        std::cout << "  " << building.first << ": Level " << building.second << "\n";
    }
    std::cout << "NPC Assignments:\n";
    for (const auto& task : npcTasks) {
        std::cout << "  " << task.first << ": " << task.second << " NPCs\n";
    }
}