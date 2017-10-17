//
// Created by Charles on 17-09-20.
//

#include "Territory.h"
#include <iostream>


Territory::Territory() {
}

Territory::~Territory() {

}

const std::string &Territory::getName() const {
    return name;
}

void Territory::setName(const std::string &name) {
    Territory::name = name;
}

void Territory::setX(int X) {
    Territory::X = X;
}

void Territory::setY(int Y) {
    Territory::Y = Y;
}

void Territory::addtoAdjacentTerritories(Territory * territory) {
this->adjacentTerritorries.push_back(territory);
}


Territory::Territory(const std::string &name) : name(name) {}


const std::vector<Territory *> &Territory::getAdjacentTerritorries() const {
    return adjacentTerritorries;
}

bool Territory::isPartofGraph() const {
    return PartofGraph;
}

void Territory::setIsPartofGraph(bool isPartofGraph) {
    Territory::PartofGraph = isPartofGraph;
}

bool Territory::isIspartofSubGraph() const {
    return ispartofSubGraph;
}

void Territory::setIspartofSubGraph(bool ispartofSubGraph) {
    Territory::ispartofSubGraph = ispartofSubGraph;
}

const std::string &Territory::getContinentname() const {
    return continentname;
}

void Territory::setContinentname(const std::string &continentname) {
    Territory::continentname = continentname;
}

