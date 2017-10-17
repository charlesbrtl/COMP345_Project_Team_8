//
// Created by Charles on 17-09-20.
//

#ifndef RISK_MAPLOADER_H
#define RISK_MAPLOADER_H


#include <unordered_map>
#include <iostream>
#include <iostream>
#include <fstream>
#include "riskMap.h"
#include "Territory.h"

class Maploader {

private:
    enum flag{ CONTINENTS, MAP,TERRITORRIES};

    riskMap* mymap;
public:
    riskMap *getMymap() const;

private:

    std::ifstream instream;

    std::unordered_map<std::string, Territory*> territoriesmap;

    std::unordered_map<std::string, Continent*> continentsmap;

    bool hasinfo, hascontinents,hasterritories;

public:
    Maploader();
    Maploader(std::string &path);
    virtual ~Maploader();
    void openFile(std::string &path);
    void closeFile();
    void readfile(std::string &path);
    void readInfo(std::string &infoline);
    void readcontinent(std::string &continentline);
    void readterritory(std::string &territoryline);
    bool isvalidmap();
};


#endif //RISK_MAPLOADER_H
