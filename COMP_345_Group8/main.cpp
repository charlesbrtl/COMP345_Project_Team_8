#include <iostream>
#include "Maploader.h"
#include "riskMap.h"
int main() {
    std::string file="/Users/charles/CLionProjects/Risk2/World.map";

    Maploader* maploader=new Maploader(file);
    riskMap* map=maploader->getMymap();

    std::cout<<"is map a graph: "<<map->isGraph()<<std::endl;
    for(auto &i: map->getContinentslist())
        std::cout<<"is "<<i->getName()<<" a valid subgraph?: "<<i->isSubGraph()<<std::endl;
    std::cout<<"is map file Valid: "<<maploader->isvalidmap()<<std::endl;
    delete maploader;
    delete map;
    return 0;
}