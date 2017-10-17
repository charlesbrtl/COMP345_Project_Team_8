//
// Created by Charles on 17-09-20.
//

#include "Maploader.h"
#include <regex>
#ifdef linux
const char END_LINE_CHARACTER = (char)13;
#else
const char END_LINE_CHARACTER = '\r';
#endif
Maploader::Maploader() {}
Maploader::~Maploader() {
}
void Maploader::openFile(std::string &path) {
this->instream.open(path.c_str());
    if(!instream.good()) {
        std::cerr << "Error opening File" << std::endl;
        exit(0);
    }
}
void Maploader::closeFile() {
this->instream.close();
}
void Maploader::readfile(std::string &path) {
    //open the file
    openFile(path);
    std::regex regexdelimiter ("^\\[", std::regex_constants::icase);
    std::string line;
    //flag enum to know how the line should be read
    flag current;
    while(instream.peek()!=-1){
    std::getline(instream,line);
//if the line isn't empty
   if (line.at(0)!=END_LINE_CHARACTER){
//searches for a the regexdelimiter: [ that declares a change in how the variables are read
if (std::regex_search(line,regexdelimiter)) {
        std::string category = line.substr(1, line.length() - 3);
        if (category.compare("Map") == 0) {
            current = MAP;
        } else if (category.compare("Continents") == 0) {
            current = CONTINENTS;
        } else if (category.compare("Territories") == 0) {
            current = TERRITORRIES;
        }
}
    else{
        switch (current){
            case MAP:
                this->readInfo(line);
                this->hasinfo=true;
                break;
            case CONTINENTS:
                this->readcontinent(line);
                this->hascontinents=true;
                break;
            case TERRITORRIES:
                this->readterritory(line);
                this->hasterritories=true;
                break;
            default :
                break;
        }
    }
}
}
}
void Maploader::readInfo(std::string &infoline) {
    size_t pos = 0;
    std::string delimiter="=";
    //isolating the type of info
    std::string current=infoline.substr(0, infoline.find(delimiter));
    infoline.erase(0, infoline.find(delimiter) + delimiter.length());
    if(current.compare("author")==0){
        this->mymap->setAuthor(infoline.substr(0, infoline.length()-1).c_str());
    }
    else if(current.compare("image")==0){
        this->mymap->setImage(infoline.substr(0, infoline.length()-1).c_str());
    }
    else if(current.compare("wrap")==0){
        this->mymap->setWrap(infoline.substr(0, infoline.length()-1).c_str());
    }
    else if(current.compare("scroll")==0){
        this->mymap->setScroll(infoline.substr(0, infoline.length()-1).c_str());
    }
    else if(current.compare("warn")==0) {
        this->mymap->setWarn(infoline.substr(0, infoline.length()-1).c_str());
    }
}
void Maploader::readcontinent(std::string &continentline) {
    //splitting the line in 2 to define name and bonus
    size_t pos = 0;
    std::string delimiter="=";
    std::string token=continentline.substr(0, continentline.find(delimiter));
    continentline.erase(0, continentline.find(delimiter) + delimiter.length());
    Continent* continent=new Continent(token,std::stoi(continentline));
    std::pair<std::string, Continent*> pair (continent->getName(),continent);
    this->continentsmap.insert(pair);
}
void Maploader::readterritory(std::string &territoryline) {
    Territory* territory=new Territory;
    size_t pos = 0;
    std::string token;
    std::string delimiter=",";
    int tokenid=0;
    //while the line has more tokens and is not the end ine character
    while (((pos = territoryline.find(delimiter)) != std::string::npos  || territoryline.find(END_LINE_CHARACTER) != std::string::npos)&&territoryline.at(0)!=END_LINE_CHARACTER) {
        if((pos = territoryline.find(delimiter)) == std::string::npos){
            //if it has no more delimiters but still tokens
            pos=(territoryline.find(END_LINE_CHARACTER));
        }
        //setting the token
  token = territoryline.substr(0, pos);
        if (tokenid == 0) {
//iterates through the territories map to see if the name has already come up, and the object was created
        auto territorysearch = this->territoriesmap.find(token);
        //if it exists (but not yet initialized->initialize
        if (territorysearch != this->territoriesmap.end()) {
            territory=territorysearch->second;

        } else {
            territory->setName(token);
            std::pair<std::string, Territory *> pair(territory->getName(), territory);
            this->territoriesmap.insert(pair);
        }}
        else if (tokenid==1) {
            //sets X
            territory->setX(std::stoi(token));

        }
        else if (tokenid==2) {
            //sets Y
            territory->setY(std::stoi(token));

        }
        else if (tokenid==3){
            //iterates through the continents
                auto csearch=this->continentsmap.find(token);
                if(csearch!=this->continentsmap.end()){
                    //adds the territory to the corresponding continent
                    csearch->second->addTerritory(territory);
                    territory->setContinentname(token);
                }
                else {
                    //if the continent the country belongs to doesn't exist, should not occur, continent should exist
                    std::cerr<<"No match for existing continent"<<std::endl;
                    exit(0);}
                }
        else {
                auto tsearch=this->territoriesmap.find(token);
                if(tsearch!=this->territoriesmap.end()){
                    //if the adjacent territory exists in the unordered_map
                    //add its territory pointer to the adjacencylist
                    territory->addtoAdjacentTerritories(tsearch->second);}
                else {
                    //if it doesn't exist, create a new Territory with the name and insert it in the map
                    Territory* newterritory=new Territory(token);
                    std::pair<std::string, Territory*> newpair (token, newterritory);
                    this->territoriesmap.insert(newpair);
                    territory->addtoAdjacentTerritories(newpair.second);
                }
        }
        //deleting the token
        territoryline.erase(0, pos + delimiter.length());
        //token id keeps track of what the token has to be assigned to
        tokenid++;
    }
}
Maploader::Maploader(std::string &path) {
    //initializes the riskmap to construct it
    this->mymap = new riskMap();
    this->readfile(path);

    for (auto &i:this->territoriesmap) {
        this->mymap->addtoTerritorieslist(i.second);
    }
    for (auto &i:this->continentsmap) {
        this->mymap->addtoContinentslist(i.second);

        //opens file and reads file


    }
    this->closeFile();
}
bool Maploader::isvalidmap() {
    //checks for the map's validity
    return this->hasterritories&&this->hascontinents&&this->hasinfo&&this->mymap->isGraph();
}

riskMap *Maploader::getMymap() const {
    return mymap;
}




