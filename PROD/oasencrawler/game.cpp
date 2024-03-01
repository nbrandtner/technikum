
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring> // for memset
#include "game.h"
#include <conio.h>

using namespace std;
bool launchGame = true;
int gameRound=1;
int trackRelics = 0;
int main(){
    srand(time(nullptr));
    Character player;
    Enemy enemy;
    if(launchGame){
        system("cls");
        std::cout << "\033[1;38;2;31;240;175mWelcome to OasenCrawler!\033[0m" << endl;
        std::cout << "You are the green '\033[0;32mP\033[0m' and the enemy is the red '\033[0;31mE\033[0m'." << endl;
        std::cout << "You can move up, down, left, or right using the W, A, S, and D keys." << endl;
        std::cout << "You can collect relics ('\033[1;38;2;212;175;55mR\033[0m') and restore health at fountains ('\033[1;38;2;139;197;247mF\033[0m')." << endl;
        std::cout << "Avoid dangers ('\033[1;38;2;182;102;126mX\033[0m') and the enemy!" << endl;
        std::cout << "Press any key to start the game..." << endl;
        getch();
        launchGame = false;
    }
    GameWorld game(&player);
    game.play();
    return 0;
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
const char* GameWorld::attributeToString(Attribute attribute) const {
    switch (attribute) {
        case Attribute::STRENGTH:
            return "\033[0;31mStrength\033[0m";
            break;
        case Attribute::AGILITY:
            return "\033[1;38;2;139;197;247mAgility\033[0m";
            break;
        case Attribute::INTELLIGENCE:
            return "\033[1;38;2;212;175;55mIntelligence\033[0m";
            break;
    }
    return "";
}
void Character::printAttributes() const {
    for(int i = 0; i < 3; i++){
        if(i == 0){
            std::cout << "\033[0;31mStrength:\033[0m " << attributes[0] << std::endl;
        }else if(i == 1){
            std::cout << "\033[1;38;2;139;197;247mAgility:\033[0m " << attributes[1] << std::endl;
        }else{
            std::cout << "\033[1;38;2;212;175;55mIntelligence:\033[0m " << attributes[2] << std::endl;
        }
        std::cout << std::endl;
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
    if(world[0][0] == FieldType::RELIC){
        relicsRemaining--;
    }
    world[0][0] = FieldType::EMPTY; // Starting position
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
            cout << "You encountered a danger! It requires " << attributeToString(dangerAttribute) << " " << difficulty << " to avoid." << endl;
            // Check if the character has an item that matches the danger's attribute
            if(player->getAttributeValue(dangerAttribute) < difficulty){
                cout << "You don't have enough " << attributeToString(dangerAttribute) << " to avoid danger." << endl;
                if (player->useItem(dangerAttribute)) {
                    cout << "You used a Potion of " << attributeToString(dangerAttribute) << " to avoid danger!" << endl;
                } else {
                    cout << "You got hurt by a danger!" << endl;
                    player->decreaseHealth();
                    if (player->getHealth() <= 0) {
                        cout << "Game over! You lost all your health." << endl;
                        return;
                    }
                }
            } else {
                cout << "You avoided danger!" << endl;
            }
            break;
        case FieldType::FOUNTAIN:
            cout << "You found a fountain! Restoring health." << endl;
            player->increaseHealth();
            // Find an item at the fountain
            itemAtt=static_cast<Attribute>(rand() % 3);
            player->addItem(itemAtt);
            cout << "You found an item of type: " << attributeToString(itemAtt) << " at the fountain." << endl;
            break;
        case FieldType::RELIC:
            cout << "You found a relic!" << endl;
            trackRelics++;
            player->increaseRelics();
            relicsRemaining--;
            cout << "Relics remaining: " << relicsRemaining << endl;
            // Find an item at the relic
            itemAtt=static_cast<Attribute>(rand() % 3);
            player->addItem(itemAtt);
            cout << "You found an item of type: " << attributeToString(itemAtt) << " at the relic." << endl;
            if (relicsRemaining == 0) {
                cout << "Congratulations! You found all relics and won the game!" << endl;
                gameRound++;
                cout << "You have " << player->getHealth() << " health and " << player->getRelics() << " relics." << endl;
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
            cout << "You were caught by the enemy! Game over!" << endl;
            while(player->getHealth() > 0){
                player->decreaseHealth();
            }
            cout << "Relics collected: " << trackRelics << endl;
            cout << "Press any key to continue..." << endl;
            _getch();
            main();
        }
        printWorld(x, y, enemyX, enemyY);

        handleFieldInteraction(x, y);

        cout << "Health: " << player->getHealth() << endl;
        cout << "Relics: " << player->getRelics() << endl;
        cout << "Attribute values: " << endl;
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
                    cout << "Relics collected: " << player->getRelics() << endl;
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
                    enemy->move(0, -1); // move down
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
                    enemy->move(0, 1); // move up
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
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
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
        cout << endl;
    }
    cout << endl;
}