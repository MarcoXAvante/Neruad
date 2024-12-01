#pragma once
#include <string>
#include <map>

class City {
private:
    int resources;
    std::map<std::string, int> buildings;
    std::map<std::string, int> npcTasks;

public:
    City();

    void assignNPCs(const std::string& task, int count);
    void gatherResources();
    void upgradeBuilding(const std::string& building);
    void displayStatus() const;
};