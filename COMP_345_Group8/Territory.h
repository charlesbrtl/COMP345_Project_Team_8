//
// Created by Charles on 17-09-20.
//

#ifndef MAPUTILS_H
#define MAPUTILS_H


#include <string>
#include <vector>

class Territory {
public:
    Territory();
    virtual ~Territory();
    explicit Territory(const std::string &name);
    void addtoAdjacentTerritories(Territory* territory);
    const std::string &getName() const;
    void setName(const std::string &name);
    void setX(int X);
    void setY(int Y);
    const std::vector<Territory *> &getAdjacentTerritorries() const;
    bool isPartofGraph() const;

    void setIsPartofGraph(bool isPartofGraph);

    bool isIspartofSubGraph() const;

    void setIspartofSubGraph(bool ispartofSubGraph);

    const std::string &getContinentname() const;

    void setContinentname(const std::string &continentname);

private:
    //attributes
    std::string name;
    std::string continentname;
    std::vector<Territory*> adjacentTerritorries;
    int X,Y;
    //bool attributes to make graph checking easier
    bool PartofGraph;
    bool ispartofSubGraph;
};


    class Continent {
    public:
        Continent();
        virtual ~Continent();
        const std::string &getName() const;
        Continent(const std::string &name, int bonus);
        void addTerritory(Territory* territory);
        bool isSubGraph();
        static void ContinentDFS(Territory* territory);

        const std::vector<Territory *> &getTerritories() const;

    private:

        std::vector<Territory*> territories;
        std::string name;
        int bonus;

    };


#endif //RISK_TERRITORY_H
