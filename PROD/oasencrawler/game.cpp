
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring> // for memset
#include "game.h"
#include <conio.h>

/*
Player: \033[0;32m
Enemy: \033[0;31m
Health: \033[0;38;2;186;53;48m
Relic: \033[1;38;2;212;175;55m
Fountain: \033[1;38;2;139;197;247m
Danger: \033[1;38;2;182;102;126m

Reset: \033[0m

Attributes: 
Strength: \033[1;38;2;181;131;235m
Agility: \033[1;38;2;139;197;247m
Intelligence: \033[1;38;2;69;138;85m

*/

using namespace std;
bool launchGame = true;
int gameRound=1;
int trackRelics = 0;

int main(){
    srand(time(nullptr));
    Character player;
    Enemy enemy;
    launchGameText();
    GameWorld game(&player);
    game.play();
    return 0;
}

void launchGameText(){
    if(launchGame){
        system("cls");
        std::cout << "\033[1;38;2;31;240;175mWelcome to OasenCrawler!\033[0m" << endl;
        std::cout << "You are the green Player '\033[0;32mP\033[0m' and the Enemy is the red '\033[0;31mE\033[0m'." << endl;
        std::cout << "You can move up, down, left, or right using the W, A, S, and D keys." << endl;
        std::cout << "You can collect \033[1;38;2;212;175;55mRelics\033[0m ('\033[1;38;2;212;175;55mR\033[0m') and restore \033[0;38;2;186;53;48mHealth\033[0m at \033[1;38;2;139;197;247mFountains\033[0m ('\033[1;38;2;139;197;247mF\033[0m')." << endl;
        std::cout << "Avoid \033[1;38;2;182;102;126mDangers\033[0m ('\033[1;38;2;182;102;126mX\033[0m') and the Enemy!" << endl;
        std::cout << "Press any key to start the game..." << endl;
        getch();
        launchGame = false;
    }
}

Character::Character() : healthPoints(5), relicPoints(0), posX(0), posY(0) {
    for (int i = 0; i < 3; ++i) {
        attributes[i] = rand() % 10+1;
    }
}
Enemy::Enemy() : posX(4), posY(4) {}

void Character::setPosition(int x, int y) {
    posX = x;
    posY = y;
}

void Character::move(int dx, int dy) {
    posX += dx;
    posY += dy;
}

void Character::increaseHealth() {
    healthPoints++;
}

void Character::increaseRelics() {
    relicPoints++;
}

void Character::decreaseHealth() {
    healthPoints--;
}

int Character::getHealth() const {
    return healthPoints;
}

int Character::getRelics() const {
    return relicPoints;
}

int Character::getX() const {
    return posX;
}

int Character::getY() const {
    return posY;
}

void Enemy::setPosition(int x, int y) {
    posX = x;
    posY = y;
}

void Enemy::move(int dx, int dy) {
    posX += dx;
    posY += dy;
}

int Enemy::getX() const {
    return posX;
}

int Enemy::getY() const {
    return posY;
}
Attribute GameWorld::getRandomAttribute() const {
    int randNum = rand() % 3;
    if(randNum == 0){
        return Attribute::STRENGTH; 
    }else if(randNum == 1){
        return Attribute::AGILITY;
    }else{
        return Attribute::INTELLIGENCE;
    }
}
int Character::getPotionCount(Attribute attribute) const {
    auto it = inventory.find(attribute);
    if (it != inventory.end()) {
        return it->second;
    }
    return 0;
}
const char* GameWorld::attributeToString(Attribute attribute) const {
    switch (attribute) {
        case Attribute::STRENGTH:
            return "\033[0;38;2;181;131;235mStrength\033[0m";
            break;
        case Attribute::AGILITY:
            return "\033[1;38;2;139;197;247mAgility\033[0m";
            break;
        case Attribute::INTELLIGENCE:
            return "\033[1;38;2;69;138;85mIntelligence\033[0m";
            break;
    }
    return "";
}
void Character::printAttributes() const {
    cout << "--------------------------------------------------" << endl;
    for(int i = 0; i < 3; i++){
        if(i == 0){
            std::cout << "|\033[0;38;2;181;131;235mStrength:\033[0m " << attributes[0] << "          | \033[0;38;2;181;131;235mPotion of Strength:\033[0m " << to_string(getPotionCount(Attribute::STRENGTH))+ "    |" << std::endl;
        }else if(i == 1){
            std::cout << "|\033[1;38;2;139;197;247mAgility:\033[0m " << attributes[1] << "           | \033[1;38;2;139;197;247mPotion of Agility:\033[0m " << to_string(getPotionCount(Attribute::AGILITY))+ "     |"<< std::endl;
        }else{
            std::cout << "|\033[1;38;2;69;138;85mIntelligence:\033[0m " << attributes[2] << "      | \033[1;38;2;69;138;85mPotion of Intelligence:\033[0m " << to_string(getPotionCount(Attribute::INTELLIGENCE))+ "|" << std::endl;
        }
        if(i<2){
             std::cout << "|---------------------|--------------------------|" << std::endl;
        }else{
            cout<<"|------------------------------------------------|"<<endl;
        }
    }
}

void Character::addItem(Attribute attribute) {
    inventory[attribute]++;
}

bool Character::useItem(Attribute attribute) {
    if (inventory[attribute] > 0) {
        inventory[attribute]--;
        return true;
    }
    return false;
}

int Character::getAttributeValue(Attribute attribute) const {
    if(attribute == Attribute::STRENGTH){
        return attributes[0];
    }else if(attribute == Attribute::AGILITY){
        return attributes[1];
    }else{
        return attributes[2];
    }
}

GameWorld::GameWorld(Character* player) : player(player), enemy(new Enemy()), relicsRemaining(0) {
    generateWorld();
    memset(fieldVisited, false, sizeof(fieldVisited));
}
GameWorld::~GameWorld() {
    delete enemy;
    delete player;
    delete this;
}

void GameWorld::generateWorld() {
    bool hasRelic = false;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
                world[i][j] = getRandomFieldType();
                if(world[i][j] == FieldType::RELIC){
                    hasRelic = true;
                    relicsRemaining++;
                }
        }
    }
    if(world[player->getX()][player->getY()]==FieldType::RELIC){
        hasRelic = false;
        relicsRemaining--;
    }
    world[player->getX()][player->getY()] = FieldType::EMPTY; // Starting position
    if(world[0][0] == FieldType::RELIC){
        relicsRemaining--;

    }
    if(!hasRelic){
        world[rand() % 5][rand() % 5] = FieldType::RELIC;
    }
}

FieldType GameWorld::getRandomFieldType() const {
    int randNum = rand() % 100;
    int Danger = 40;
    int Fountain = 10;
    int Relic = 10;
    for(int i = 0; i < gameRound; i++){
        Danger += 5;
        Fountain -= 2;
        Relic += 5;
    }
    if(randNum < Danger){
        return FieldType::DANGER;
    }else if(randNum < Danger + Fountain){
        return FieldType::FOUNTAIN;
    }else if(randNum < Danger + Fountain + Relic){
        return FieldType::RELIC;
    }else{
        return FieldType::EMPTY;
    }
}

void GameWorld::handleFieldInteraction(int x, int y) {
    FieldType fieldType = world[x][y];
    Attribute itemAtt;
    int difficulty = rand() % 5+gameRound;
    Attribute dangerAttribute = getRandomAttribute();
    if(fieldVisited[x][y]==true){
        return;
    }
    switch (fieldType) {
        case FieldType::EMPTY:
            cout << "You are safe." << endl;
            break;
        case FieldType::DANGER:
            cout << "You encountered a \033[1;38;2;182;102;126mDanger!\033[0m It requires " << attributeToString(dangerAttribute) << " " << difficulty << " to avoid." << endl;
            // Check if the character has an item that matches the danger's attribute
            if(player->getAttributeValue(dangerAttribute) < difficulty){
                cout << "You don't have enough " << attributeToString(dangerAttribute) << " to avoid danger." << endl;
                if (player->useItem(dangerAttribute)) {
                    cout << "You used a Potion of " << attributeToString(dangerAttribute) << " to avoid danger!" << endl;
                } else {
                    cout << "You got hurt by a " << attributeToString(dangerAttribute) << " Type \033[1;38;2;182;102;126mDanger!\033[0m" << endl;
                    player->decreaseHealth();
                    if (player->getHealth() <= 0) {
                        cout << "//    ________                        ________                    ._.\n   /  _____/_____    _____   ____   \\_____  \\___  __ ___________| |\n  /   \\  ___\\__  \\  /     \\_/ __ \\   /   |   \\  \\/ // __ \\_  __ \\ |\n  \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  /    |    \\   /\\  ___/|  | \\/\\|\n   \\______  (____  /__|_|  /\\___  > \\_______  /\\_/  \\___  >__|   __\n          \\/     \\/      \\/     \\/          \\/          \\/       \\/ " << endl;
                        return;
                    }
                }
            } else {
                cout << "You avoided danger!" << endl;
            }
            break;
        case FieldType::FOUNTAIN:
            cout << "You found a \033[1;38;2;139;197;247mFountain!\033[0m Restoring \033[0;38;2;186;53;48mHealth\033[0m." << endl;
            player->increaseHealth();
            // Find an item at the fountain
            itemAtt=static_cast<Attribute>(rand() % 3);
            player->addItem(itemAtt);
            cout << "You found a Potion of  " << attributeToString(itemAtt) << " at the \033[1;38;2;139;197;247mFountain\033[0m." << endl;
            break;
        case FieldType::RELIC:
            cout << "You found a \033[1;38;2;212;175;55mRelic!\033[0m" << endl;
            trackRelics++;
            player->increaseRelics();
            relicsRemaining--;
            cout << "\033[1;38;2;212;175;55mRelics\033[0m remaining: " << relicsRemaining << endl;
            // Find an item at the relic
            itemAtt=static_cast<Attribute>(rand() % 3);
            player->addItem(itemAtt);
            cout << "You found a Potion of " << attributeToString(itemAtt) << " at the \033[1;38;2;212;175;55mRelic\033[0m." << endl;
            if (relicsRemaining == 0) {
                cout << "Congratulations! You found all \033[1;38;2;212;175;55mRelics\033[0m and won the game!" << endl;
                gameRound++;
                cout << "You have " << player->getHealth() << " \033[0;38;2;186;53;48mHealth\033[0m and " << player->getRelics() << " \033[1;38;2;212;175;55mRelics\033[0m." << endl;
                cout << "Generating new world..." << endl;
                srand(time(nullptr));
                generateWorld();
                memset(fieldVisited, false, sizeof(fieldVisited));
            }
            break;
    }
    fieldVisited[x][y] = true;
}

void GameWorld::play() {
    while (player->getHealth() > 0 && relicsRemaining > 0) {
        system("cls");
        int x = player->getX();
        int y = player->getY();
        int enemyX = enemy->getX();
        int enemyY = enemy->getY();

        // Enemy moves towards the player
        moveEnemySmartly();


        if(enemyX == x && enemyY == y){
            cout << "You were caught by the enemy!" << endl;
            cout << "    ________                        ________                    ._.\n   /  _____/_____    _____   ____   \\_____  \\___  __ ___________| |\n  /   \\  ___\\__  \\  /     \\_/ __ \\   /   |   \\  \\/ // __ \\_  __ \\ |\n  \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  /    |    \\   /\\  ___/|  | \\/\\|\n   \\______  (____  /__|_|  /\\___  > \\_______  /\\_/  \\___  >__|   __\n          \\/     \\/      \\/     \\/          \\/          \\/       \\/ " << endl;
            while(player->getHealth() > 0){
                player->decreaseHealth();
            }
            cout << "\n" << endl;
            cout << "\033[1;38;2;212;175;55mRelics\033[0m collected: " << trackRelics << endl;
            cout << "Press any key to continue..." << endl;
            _getch();
            main();
        }
        printWorld(x, y, enemyX, enemyY);

        handleFieldInteraction(x, y);

        cout << "\n\033[0;38;2;186;53;48mHealth:\033[0m " << player->getHealth() << endl;
        cout << "\033[1;38;2;212;175;55mRelics:\033[0m " << player->getRelics() << endl;
        player->printAttributes();
        if (player->getHealth() <= 0){
            break;
        }

        if (relicsRemaining == 0){
            break;
        }
        
        bool validMove = false;
        char move;
        while(!validMove){ // get user input (W/A/S/D) and move the player  
            cout << "Enter move (W/A/S/D): ";
            move = getch();

            switch (move) {
                case 'W':
                case 'w':
                    if (x > 0){
                        player->move(-1, 0);
                        validMove = true;
                    }else{
                        cout << "Invalid move!" << endl;
                    }
                    break;
                case 'A':
                case 'a':
                    if (y > 0){
                        player->move(0, -1);
                        validMove = true;
                    }else{
                        cout << "Invalid move!" << endl;
                    }
                    break;
                case 'S':
                case 's':
                    if (x < 4){
                        player->move(1, 0);
                        validMove = true;
                    }else{
                        cout << "Invalid move!" << endl;
                    }
                    break;
                case 'D':
                case 'd':
                    if (y < 4){
                        player->move(0, 1);
                        validMove = true;
                    }else{
                        cout << "Invalid move!" << endl;
                    }
                    break;
                case '0':
                    // end the game by pressing 0
                    system("cls");
                    cout << "Game ended." << endl;
                    cout << "\033[1;38;2;212;175;55mRelics\033[0m collected: " << player->getRelics() << endl;
                    cout << "Press any key to continue..." << endl;
                    _getch();
                    return;
                default:
                    cout << "Invalid move!" << endl;
            }
        }
    }   
}

void GameWorld::moveEnemySmartly() {
    int playerX = player->getX();
    int playerY = player->getY();
    int enemyX = enemy->getX();
    int enemyY = enemy->getY();

    int randNum = rand() % 10; // random number between 0 and 9
    bool worked = true;
    if (randNum<3){ // add a bit of randomness to the enemy movement
        switch(randNum){
            case 0:
                if(enemyX > 0){
                    enemy->move(-1, 0); // move left
                }else{
                    worked = false;
                }
                break;
            case 1:
                if(enemyY > 0){
                    enemy->move(0, -1); // move up
                }else{
                    worked = false;
                }
                break;
            case 2:
                if(enemyX < 4){
                    enemy->move(1, 0); // move right
                }else{
                    worked = false;
                }
                break;
            case 3:
                if(enemyY < 4){
                    enemy->move(0, 1); // move down
                }else{
                    worked = false;
                }
                break;
            default:    
                break;
            if(!worked){
                moveEnemySmartly();
            }
        }
    }else{ // move enemy towards the player
        if (enemyX < playerX && enemyX < 4){
            enemy->move(1, 0);
        }else if (enemyX > playerX && enemyX > 0){
            enemy->move(-1, 0);
        }else if (enemyY < playerY && enemyY < 4){
            enemy->move(0, 1);
        }else if (enemyY > playerY && enemyY > 0){
            enemy->move(0, -1);
        }
    }
}


void GameWorld::printWorld(int x, int y, int enemyX, int enemyY) const {
    cout << "_____________________\n";
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << "| ";
            if(i == x && j == y){
                cout << "\033[0;32mP\033[0m ";
            }else{
                if(i == enemyX && j == enemyY){
                    cout << "\033[0;31mE\033[0m ";
                }else{
                    if(fieldVisited[i][j]){
                        switch (world[i][j]){
                            case FieldType::EMPTY:
                                cout << "\033[1;38;2;225;225;225m_\033[0m "; // Light Grey
                                break;
                            case FieldType::DANGER:
                                cout << "\033[1;38;2;182;102;126mX\033[0m "; // Red-Rose
                                break;
                            case FieldType::FOUNTAIN:
                                cout << "\033[1;38;2;139;197;247mF\033[0m "; // Cyan                
                                break;
                            case FieldType::RELIC:
                                cout << "\033[1;38;2;212;175;55mR\033[0m "; // Gold
                                break;
                        }
                    }else{
                        cout << "? ";
                    }
                }
            }
        }
        cout << "|\n|___|___|___|___|___|\n";
    }
    cout << endl;
}