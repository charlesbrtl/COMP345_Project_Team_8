//
// Created by Charles on 17-09-20.
//

#include "riskMap.h"
#include <iostream>

riskMap::riskMap() {
}

riskMap::~riskMap() {

}

void riskMap::setImage(const std::string &image) {
    riskMap::image = image;
}

void riskMap::setWrap(const std::string &wrap) {
    riskMap::wrap = wrap;
}

void riskMap::setScroll(const std::string &scroll) {
    riskMap::scroll = scroll;
}

void riskMap::setAuthor(const std::string &author) {
    riskMap::author = author;
}

void riskMap::setWarn(const std::string &warn) {
    riskMap::warn = warn;
}

void riskMap::load(std::unordered_map<std::string, Territory *> &tmap, std::unordered_map<std::string, Continent *> &cmap) {
    for (auto& i: tmap){
        this->territorieslist.push_back(i.second);
    }
    for (auto& j: cmap){
        this->continentslist.push_back(j.second);
    }
}
bool riskMap::isGraph() {
    //uses depth first search to assign ispartOfGraph to true for zach territory visited
    DFS(this->territorieslist[0]);
    //iterates through all the territories from the map, return false if one or mare haven't been traversed
    for(auto&i:this->territorieslist){
        if(!i->isPartofGraph())
            return false;
    }
    return true;
}

void riskMap::DFS(Territory *territory) {
    for(auto & i:territory->getAdjacentTerritorries()){
        //iterates through adjacency list
        if(!i->isPartofGraph())
            //doesn't revisit visited territories
        {
            i->setIsPartofGraph(true);
            //if wanted the traversal could print names
            //std::cout<<i->getName()<<std::endl;
        DFS(i);
        }
    }
}

const std::vector<Continent *> &riskMap::getContinentslist() const {
    return continentslist;
}

void riskMap::addtoTerritorieslist(Territory * territory) {
this->territorieslist.push_back(territory);
}

void riskMap::addtoContinentslist(Continent *continent) {
this->continentslist.push_back(continent);
}




