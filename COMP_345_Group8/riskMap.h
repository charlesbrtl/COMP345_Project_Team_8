//
// Created by Charles on 17-09-20.
//

#ifndef RISK_RISKMAP_H
#define RISK_RISKMAP_H


#include <string>
#include <unordered_map>
#include <fstream>
#include "Territory.h"

class riskMap {
    friend class Maploader;
public:
    riskMap();
    virtual ~riskMap();
//mutators for the riskmap parameters
    void setImage(const std::string &image);

    void setWrap(const std::string &wrap);

    void setScroll(const std::string &scroll);

    void setAuthor(const std::string &author);

    void setWarn(const std::string &warn);
//to transfer data from maploader to map
    void load(std::unordered_map<std::string,Territory*> &tmap,std::unordered_map<std::string,Continent*> &cmap);
//check if the map is a graph
    bool isGraph();
//depth first search
    static void DFS(Territory* territory);
    const std::vector<Continent *> &getContinentslist() const;
    void addtoTerritorieslist(Territory* territory);
    void addtoContinentslist(Continent*continent);

private:
    //attributes
    std::string image,wrap,scroll,author,warn;
    //vector to store continents
    std::vector<Continent*> continentslist;
    //vector to store territories
    std::vector<Territory*> territorieslist;

};


#endif //RISK_MAP_H
