#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>

class Character;
void launchGameText();

enum class FieldType {
    EMPTY,
    DANGER,
    FOUNTAIN,
    RELIC
};
enum class Attribute { 
    STRENGTH=0, 
    AGILITY, 
    INTELLIGENCE
};

class Enemy;

class GameWorld {
private:
    FieldType world[5][5];
    bool fieldVisited[5][5];

    Character* player;
    Enemy* enemy;
    int relicsRemaining;

    void generateWorld();
    FieldType getRandomFieldType() const;
    void printWorld(int x, int y, int enemyX, int enemyY) const;
    void handleFieldInteraction(int x, int y);
    void moveEnemySmartly();
    Attribute getRandomAttribute() const;
    const char* attributeToString(Attribute attribute) const;    

public:
    GameWorld(Character* player);
    void play();
    ~GameWorld();
};
    
class Character {
private:
    int attributes[3];
    std::map<Attribute, int> inventory;
    int healthPoints;
    int relicPoints;
    int posX;
    int posY;

public:
    Character();
    void setPosition(int x, int y);
    void move(int dx, int dy);
    void increaseHealth();
    void increaseRelics();
    void decreaseHealth();
    int getHealth() const;
    int getRelics() const;
    int getX() const;
    int getY() const;
    void addItem(Attribute attribute);
    bool useItem(Attribute attribute);
    int getPotionCount(Attribute attribute) const;
    int getAttributeValue(Attribute attribute) const;
    void printAttributes() const;
};

class Enemy {
private:
    int posX;
    int posY;

public:
    Enemy();
    void setPosition(int x, int y);
    void move(int dx, int dy);
    int getX() const;
    int getY() const;
};

#endif // GAME_H