#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring> // for memset
#include "game.h"
#include <conio.h>

using namespace std;
int gameRound=1;
int trackRelics = 0;
sf::Texture PCtexture;
sf::Texture Enemytexture;
// create a 5x5 grid
sf::RectangleShape grid[5][5];
sf::RectangleShape icons[5][5];
sf::Text introtext;
sf::Text eventtext;
sf::Text stdtext;
bool firstTime = true;
sf::Event keypressEvent;
int main(){
    srand(time(nullptr));
    sf::RenderWindow window(sf::VideoMode(1600, 900), "My window");
    // create a font
    sf::Font font;
    if (!font.loadFromFile("rss\\samurai-blast-font\\SamuraiBlast-YznGj.ttf")){
        // error...
    }
    sf::Texture texture;
    if (!texture.loadFromFile("rss\\grid-board.png")){
        // error...
    }
    // create a text
    sf::Text title("Oasencrawler", font, 50);
    title.setFillColor(sf::Color::Blue);
    title.setPosition(630, 50);
    if (!font.loadFromFile("rss\\minecraft-font\\Minecraft.otf")) {
        // error...
    }
    stdtext.setFont(font);
    stdtext.setCharacterSize(24); 
    stdtext.setFillColor(sf::Color::White); 
    stdtext.setPosition(1100, 360); 
    introtext.setFont(font); 
    introtext.setCharacterSize(24); 
    introtext.setFillColor(sf::Color::White);
    introtext.setPosition(grid[3][5].getPosition());
    introtext.move(0, 100);
    introtext.setString("Welcome to Oasencrawler!\nYou are a blue little Slime and a fiery enemy Slime is trying to catch you!\nAvoid the Enemy and Collect Relics along the way.\nCollect all Relics to finish a Level, Rest at Fountains and Avoid Danger at Danger Fields!\nPress any key to continue..."); // set the string to display
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; ++j){
            grid[i][j].setSize(sf::Vector2f(100.0f, 100.0f)); // adjust size as needed
            grid[i][j].setOutlineColor(sf::Color::White);
            grid[i][j].setOutlineThickness(1.0f); // adjust thickness as needed
            grid[i][j].setPosition(i * 100.0f+550.0f, j * 100.0f+200.0f); // adjust position as needed

            icons[i][j].setSize(sf::Vector2f(100.0f, 100.0f)); 
            icons[i][j].setOutlineColor(sf::Color::White);
            icons[i][j].setFillColor(sf::Color::Transparent);
            icons[i][j].setOutlineThickness(1.0f);
            icons[i][j].setPosition(i * 100.0f+550.0f, j * 100.0f+200.0f);

            grid[i][j].setTexture(&texture, true); // set the texture
            if(j<2){
                grid[i][j].setTextureRect(sf::IntRect(i*96+362,j*93+70, 96, 93));
            }else{
                grid[i][j].setTextureRect(sf::IntRect(i*96+362,(j-2)*85+266, 96, 85));
            } 
        }
    }

    Character player;
    player.setSprite("rss\\PC.png"); // Change the parameter type of setSprite to const char*
    Enemy enemy;
    enemy.setSprite("rss\\Enemy.png"); // Change the parameter type of setSprite to const char*
    GameWorld game(&player);

    stdtext.setString("Health: " + to_string(player.getHealth()) + "\nRelics: " + to_string(player.getRelics()) + "\nAttribute values: \nStrength: " + to_string(player.getAttributeValue(Attribute::STRENGTH)) + "\nAgility: " + to_string(player.getAttributeValue(Attribute::AGILITY)) + "\nIntelligence: " + to_string(player.getAttributeValue(Attribute::INTELLIGENCE))); // set the string to display
    // run the program as long as the window is open
    while (window.isOpen()){
        sf::Event closeevent;
        while (window.pollEvent(closeevent)){
            if (closeevent.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(title);
        if(firstTime){
            while (window.pollEvent(keypressEvent)) {
                if (keypressEvent.type == sf::Event::Closed) {
                    window.close();
                }
                window.draw(introtext);
                // If any key is pressed, break the loop
                if (keypressEvent.type == sf::Event::KeyPressed) {
                    break;
                }
            }
            firstTime = false;
        }
        // draw the grid
        for (int i = 0; i < 5; ++i){
            for (int j = 0; j < 5; ++j){
                window.draw(grid[i][j]);
            }
        }
        game.play(window);
        window.draw(stdtext);
        window.draw(player.getSprite());
        window.draw(enemy.getSprite());
        window.display();
    }
    
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

void Character::setSprite(const char* path){
    if (!PCtexture.loadFromFile(path)) {
        // handle error...
    }
    pcSprite.setTexture(PCtexture);
    float targetWidth = 80.0f;
    float targetHeight = 80.0f;

    float scaleX = targetWidth / pcSprite.getGlobalBounds().width;
    float scaleY = targetHeight / pcSprite.getGlobalBounds().height;

    pcSprite.setScale(scaleX, scaleY);
    pcSprite.setPosition(grid[0][0].getPosition());
    pcSprite.move(10, 10);
}

sf::Sprite Character::getSprite() const{
    return pcSprite;
}

void Enemy::setSprite(const char* path){
    if (!Enemytexture.loadFromFile(path)) {
        // handle error...
    }
    enemySprite.setTexture(Enemytexture);
    float targetWidth = 80.0f;
    float targetHeight = 80.0f;

    float scaleX = targetWidth / enemySprite.getGlobalBounds().width;
    float scaleY = targetHeight / enemySprite.getGlobalBounds().height;

    enemySprite.setScale(scaleX, scaleY);
    enemySprite.setPosition(grid[4][4].getPosition());
    enemySprite.move(10, 15);
}

sf::Sprite Enemy::getSprite() const{
    return enemySprite;
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

void GameWorld::play(sf::RenderWindow& window) {
    while (player->getHealth() > 0 && relicsRemaining > 0) {
        int x = player->getX();
        int y = player->getY();
        int enemyX = enemy->getX();
        int enemyY = enemy->getY();

        // Enemy moves towards the player
        moveEnemySmartly();


        if(enemyX == x && enemyY == y){
            while(player->getHealth() > 0){
                player->decreaseHealth();
            }
            eventtext.setString("You were caught by the enemy! Game over!\nRelics collected: " + to_string(trackRelics) + "\nPress any key to continue..."); // set the string to display
            eventtext.setFillColor(sf::Color::Red); // set the color of the text
            while (window.pollEvent(keypressEvent)) {
                if (keypressEvent.type == sf::Event::Closed) {
                    window.close();
                }

                // If any key is pressed, break the loop
                if (keypressEvent.type == sf::Event::KeyPressed) {
                    break;
                }
            }
            main();
        }
        //print the game board
        handleFieldInteraction(x, y);

        if (player->getHealth() <= 0){
            break;
        }

        if (relicsRemaining == 0){
            break;
        }
        
        bool validMove = false;
        char move;
        while(!validMove){ // get user input (W/A/S/D) and move the player  
            
            move = 

            switch (move) {
                case 'W':
                case 'w':
                    if (x > 0){
                        player->move(-1, 0);
                        player->getSprite().move(0,-100);
                        validMove = true;
                    }else{
                        cout << "Invalid move!" << endl;
                    }
                    break;
                case 'A':
                case 'a':
                    if (y > 0){
                        player->move(0, -1);
                        player->getSprite().move(-100,0);
                        validMove = true;
                    }else{
                        cout << "Invalid move!" << endl;
                    }
                    break;
                case 'S':
                case 's':
                    if (x < 4){
                        player->move(1, 0);
                        player->getSprite().move(0,100);
                        validMove = true;
                    }else{
                        cout << "Invalid move!" << endl;
                    }
                    break;
                case 'D':
                case 'd':
                    if (y < 4){
                        player->move(0, 1);
                        player->getSprite().move(100,0);
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