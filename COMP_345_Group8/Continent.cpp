//
// Created by Charles on 17-09-20.
//

#include <unordered_map>
#include "Territory.h"

Continent::Continent() {}

Continent::~Continent() {

}
//accessor for the continent's name
const std::string &Continent::getName() const {
    return name;
}
//function to add a territory to a continent
void Continent::addTerritory(Territory *territory) {
this->territories.push_back(territory);
}
//parametrized constructor
Continent::Continent(const std::string &name, int bonus) : name(name), bonus(bonus) {}

bool Continent::isSubGraph() {
    ContinentDFS(this->territories[0]);
for (auto &i:this->territories){
    if(!i->isIspartofSubGraph())
        return false ;
}
    return true;
}

void Continent::ContinentDFS(Territory *territory) {
    for(auto & i:territory->getAdjacentTerritorries()){
        //iterates through adjacency list
        if(!i->isIspartofSubGraph()&&(i->getContinentname().compare(territory->getContinentname())==0))
            //visits the countries that haven't been visited and are part of the continent
        {
            i->setIspartofSubGraph(true);
            //if wanted the traversal could print names
            //std::cout<<i->getName()<<std::endl;
            ContinentDFS(i);
        }
    }
}

const std::vector<Territory *> &Continent::getTerritories() const {
    return territories;
}


