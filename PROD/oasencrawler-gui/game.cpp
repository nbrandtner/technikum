#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstring> // for memset
#include "game.h"
#include <conio.h>
#include <windows.h>

using namespace std;
int gameRound=1;
int trackRelics = 0;
sf::Texture PCtexture;
sf::Texture Enemytexture;
sf::Texture youDied;
// create a 5x5 grid
sf::RectangleShape youDiedRect;
sf::RectangleShape grid[5][5];
sf::Text healthText;
sf::Text relicsText;
sf::Text strengthText;
sf::Text agilityText;
sf::Text intelligenceText;
sf::Text inventoryText;
sf::Text strPotText;
sf::Text agiPotText;
sf::Text intPotText;
sf::Text levelText;
sf::Text introtext;
sf::Text eventtext;
sf::Text stdtext;
sf::Text fieldMessage;
sf::Text endText;
std::string message="";
bool firstTime = true;
sf::Event keypressEvent;

int main(){
    srand(time(nullptr));
    play();
}

int play(){
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Oasiscrawler by nik", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
    HWND hwnd = window.getSystemHandle();
    ShowWindow(hwnd, SW_MAXIMIZE);
    // create a font
    sf::Font font;
    if (!font.loadFromFile("rss\\minecraft-font\\Minecraft.otf")) {
        // error...
    }
    sf::Texture texture;
    if (!texture.loadFromFile("rss\\grid-board.png")){
        // error...
    }
    sf::Texture visitedTexture;
    if (!visitedTexture.loadFromFile("rss\\grid-board-visited.png")){
        // error...
    }
    sf::Image icon;
    if (!icon.loadFromFile("rss\\icon.png")) {
        // handle error...
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // create a text
    sf::Text title("Oasencrawler", font, 50);
    title.setFillColor(sf::Color(48, 125, 227));
    title.setPosition(630, 50);
 

    youDiedRect.setSize(sf::Vector2f(1600.0f, 900.0f));
    youDiedRect.setPosition(0, 0);
    if (!youDied.loadFromFile("rss\\youDied.png")) {
        // handle error...
    }
    youDiedRect.setTexture(&youDied, true); // set the texture
    youDiedRect.setTextureRect(sf::IntRect(0, 0, 1600, 900));

    // Set the font for each text
    healthText.setFont(font);
    relicsText.setFont(font);
    strengthText.setFont(font);
    agilityText.setFont(font);
    intelligenceText.setFont(font);
    inventoryText.setFont(font);
    strPotText.setFont(font);
    agiPotText.setFont(font);
    intPotText.setFont(font);
    levelText.setFont(font);

    // Set the character size for each text
    healthText.setCharacterSize(24);
    relicsText.setCharacterSize(24);
    strengthText.setCharacterSize(24);
    agilityText.setCharacterSize(24);
    intelligenceText.setCharacterSize(24);
    inventoryText.setCharacterSize(24);
    strPotText.setCharacterSize(24);
    agiPotText.setCharacterSize(24);
    intPotText.setCharacterSize(24);
    levelText.setCharacterSize(24);

    // Set the color for each text
    healthText.setFillColor(sf::Color::Red);
    relicsText.setFillColor(sf::Color(255, 165, 0));  // Orange color
    strengthText.setFillColor(sf::Color(158, 104, 227)); // Fix: Remove redundant Color:: qualifier
    agilityText.setFillColor(sf::Color::Cyan);  // Light blue color
    intelligenceText.setFillColor(sf::Color::Green);
    inventoryText.setFillColor(sf::Color::White);
    strPotText.setFillColor(sf::Color(158, 104, 227));
    agiPotText.setFillColor(sf::Color::Cyan);
    intPotText.setFillColor(sf::Color::Green);
    levelText.setFillColor(sf::Color(55, 161, 145));

    // Set the position for each text
    healthText.setPosition(1100, 360);
    relicsText.setPosition(1100, 390);
    strengthText.setPosition(1100, 420);
    agilityText.setPosition(1100, 450);
    intelligenceText.setPosition(1100, 480);
    inventoryText.setPosition(230, 390);
    strPotText.setPosition(230, 420);
    agiPotText.setPosition(230, 450);
    intPotText.setPosition(230, 480);
    levelText.setPosition(230, 300);


    endText.setFont(font);
    endText.setCharacterSize(32); 
    endText.setFillColor(sf::Color::White); 
    fieldMessage.setFont(font);
    fieldMessage.setCharacterSize(24);
    fieldMessage.setFillColor(sf::Color::White);
    fieldMessage.setPosition(450, 700);
    endText.setPosition(600, 360); 
    stdtext.setFont(font);
    stdtext.setCharacterSize(24); 
    stdtext.setFillColor(sf::Color::Red); 
    stdtext.setPosition(1100, 360); 
    introtext.setFont(font); 
    introtext.setCharacterSize(24); 
    introtext.setFillColor(sf::Color(161, 55, 74));
    introtext.setString("                                      Welcome to the Oasencrawler!\n        You are a blue little Slime and a fiery enemy Slime is trying to catch you!\n                       Avoid the Enemy and Collect Relics along the way.\nCollect all Relics to finish a Level, Rest at Fountains and Avoid Danger at Danger Fields!\n                                       Press any key to continue...\n"); // set the string to display
    introtext.setPosition(260, 400);
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; ++j){
            grid[i][j].setSize(sf::Vector2f(100.0f, 100.0f)); // adjust size as needed
            grid[i][j].setOutlineColor(sf::Color::White);
            grid[i][j].setOutlineThickness(1.0f); // adjust thickness as needed
            grid[i][j].setPosition(i * 100.0f+550.0f, j * 100.0f+200.0f); // adjust position as needed

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
    GameWorld game(&player, &enemy);

    stdtext.setString("Health: " + to_string(player.getHealth()) + "\nRelics: " + to_string(player.getRelics()) + "\nAttribute values: \nStrength: " + to_string(player.getAttributeValue(Attribute::STRENGTH)) + "\nAgility: " + to_string(player.getAttributeValue(Attribute::AGILITY)) + "\nIntelligence: " + to_string(player.getAttributeValue(Attribute::INTELLIGENCE))); // set the string to display
    // run the program as long as the window is open

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (firstTime == true){
                title.move(-100, 200);
                title.setCharacterSize(80);
                window.draw(title);
                
                window.draw(introtext);
                window.display();
                if (waitForAnyKey(window)) {
                    firstTime = false;
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                game.update();
            }
        }
        // draw all game objects here
        title.setCharacterSize(50);
        title.setPosition(630, 50);
        window.draw(title);
        for (int i = 0; i < 5; ++i){
            for (int j = 0; j < 5; ++j){
                if(game.fieldVisited[i][j] == true){
                    grid[i][j].setTexture(&visitedTexture, true); // set the texture
                    if(j<2){
                        grid[i][j].setTextureRect(sf::IntRect(i*96+362,j*93+70, 96, 93));
                    }else{
                        grid[i][j].setTextureRect(sf::IntRect(i*96+362,(j-2)*85+266, 96, 85));
                    }
                }else{
                    grid[i][j].setTexture(&texture, true);
                    if(j<2){
                        grid[i][j].setTextureRect(sf::IntRect(i*96+362,j*93+70, 96, 93));
                    }else{
                        grid[i][j].setTextureRect(sf::IntRect(i*96+362,(j-2)*85+266, 96, 85));
                    }
                }
                window.draw(grid[i][j]);
            }
        }

        healthText.setString("Health: " + to_string(player.getHealth()));
        relicsText.setString("Relics: " + to_string(player.getRelics()));
        strengthText.setString("Strength: " + to_string(player.getAttributeValue(Attribute::STRENGTH)));
        agilityText.setString("Agility: " + to_string(player.getAttributeValue(Attribute::AGILITY)));
        intelligenceText.setString("Intelligence: " + to_string(player.getAttributeValue(Attribute::INTELLIGENCE)));
        inventoryText.setString("Inventory: ");
        strPotText.setString("Potion of Strength: " + to_string(player.getPotionCount(Attribute::STRENGTH)));
        agiPotText.setString("Potion of Agility: " + to_string(player.getPotionCount(Attribute::AGILITY)));
        intPotText.setString("Potion of Intelligence: " + to_string(player.getPotionCount(Attribute::INTELLIGENCE)));
        levelText.setString("Level: " + to_string(gameRound));
        if(gameRound > 2){
            levelText.setString("Level: " + to_string(gameRound) + "\nIncreased Difficulty!\n2x Danger Field Dmg!");
        }

        window.draw(healthText);
        window.draw(relicsText);
        window.draw(strengthText);
        window.draw(agilityText);
        window.draw(intelligenceText);
        window.draw(inventoryText);
        window.draw(strPotText);
        window.draw(agiPotText);
        window.draw(intPotText);
        window.draw(levelText);

        window.draw(player.getSprite());
        window.draw(enemy.getSprite());
        window.draw(fieldMessage);
        if(player.getHealth() <= 0){
            window.draw(youDiedRect);
            window.display();
            waitForAnyKey(window);
            window.clear();
            title.move(-100, 200);
            title.setCharacterSize(80);
            window.draw(title);
            endText.setString(game.gameOver());
            window.draw(endText);
            window.display();
            // wait for key press with sfml
            waitForAnyKey(window);
            window.close();
        }
        // display the game screen
        window.display();
        
        // clear the window at the end of each frame
        window.clear();
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

bool waitForAnyKey(sf::RenderWindow& window) {
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return false;
            }
            // If any key is pressed, return true
            if (event.type == sf::Event::KeyPressed) {
                return true;
            }
        }
    }
    return false;
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

sf::Sprite& Character::getSprite(){
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

sf::Sprite& Enemy::getSprite(){
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
            return "Strength";
            break;
        case Attribute::AGILITY:
            return "Agility";
            break;
        case Attribute::INTELLIGENCE:
            return "Intelligence";
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
int Character::getPotionCount(Attribute attribute) const {
    auto it = inventory.find(attribute);
    if (it != inventory.end()) {
        return it->second;
    }
    return 0;
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

GameWorld::GameWorld(Character* player, Enemy* enemy) : player(player), enemy(enemy), relicsRemaining(0) {
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
    world[player->getX()][player->getY()] = FieldType::EMPTY; // Starting position
    if(!hasRelic){
        world[rand() % 5][rand() % 5] = FieldType::RELIC;
    }
}

FieldType GameWorld::getRandomFieldType() const {
    int randNum = rand() % 100;
    int Danger = 40;
    int Fountain = 10;
    int Relic = 10;
    for(int i = 0; i < gameRound; i++){ // Increase the chance of danger and decrease the chance of fountain as the game progresses
        Danger += 3;
        Fountain -= 3;
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
    fieldMessage.setFont(*stdtext.getFont());
    fieldMessage.setCharacterSize(24);
    fieldMessage.setFillColor(sf::Color::White);

    if (fieldVisited[x][y] == true) {
        return;
    }
    switch (fieldType) {
        case FieldType::EMPTY:
            message="You are safe.\n";
            break;
        case FieldType::DANGER:
            message="You encountered a danger! It requires " + to_string(difficulty) + " " + attributeToString(dangerAttribute) + " to avoid.\n";
            // Check if the character has an item that matches the danger's attribute
            if(player->getAttributeValue(dangerAttribute) < difficulty){
                message+="Oh No! You don't have enough " + string(attributeToString(dangerAttribute)) + " to avoid danger.\n";
                if (player->useItem(dangerAttribute)) {
                    message+="You used a Potion of " + string(attributeToString(dangerAttribute)) + " to avoid danger!\n";
                } else {
                    message+="You got hurt by a danger!\n";
                    player->decreaseHealth();
                    if(gameRound > 2){
                        player->decreaseHealth();
                    }
                    if (player->getHealth() <= 0) {
                        gameOver();
                        return;
                    }
                }
            } else {
                message+="You avoided danger!";
            }
            break;
        case FieldType::FOUNTAIN:
            message="You found a fountain! Restoring health.\n";
            player->increaseHealth();
            // Find an item at the fountain
            itemAtt=static_cast<Attribute>(rand() % 3);
            player->addItem(itemAtt);
            message+="You found a Potion of " + string(attributeToString(itemAtt)) + " at the fountain.\n";
            break;
        case FieldType::RELIC:
            message="You found a relic!\n";
            trackRelics++;
            player->increaseRelics();
            relicsRemaining--;
            message+="Relics remaining: " + to_string(relicsRemaining) + string("\n");
            // Find an item at the relic
            itemAtt=static_cast<Attribute>(rand() % 3);
            player->addItem(itemAtt);
            message+="You found a Potion of " + string(attributeToString(itemAtt)) + " at the relic.\n";
            if (relicsRemaining == 0) {
                message+="Congratulations! You found all relics and won the round!\n";
                gameRound++;
                message+="You have " + to_string(player->getHealth()) +" health and " + to_string(player->getRelics()) + " relics.\n";
                message+="Generating new world...";
                srand(time(nullptr));
                generateWorld();
                memset(fieldVisited, false, sizeof(fieldVisited));
            }
            break;
    }
    fieldMessage.setString(message);
}


void GameWorld::moveEnemySmartly(int x, int y) {
    int playerX = x;
    int playerY = y;
    int enemyX = enemy->getX();
    int enemyY = enemy->getY();
    bool worked = false;
    while(worked==false){
        int randNum = rand() % 10; // random number between 0 and 9
        if (randNum<4){ // add a bit of randomness to the enemy movement
            switch(randNum){
                case 0: // up is (0, -1) down is (0, 1) left is (-1, 0) right is (1, 0)
                    if(enemyX > 0){
                        enemy->move(-1, 0); // move left
                        enemy->getSprite().move(-100, 0);
                        worked = true;
                    }
                    break;
                case 1:
                    if(enemyY > 0){
                        enemy->move(0, -1); // move up
                        enemy->getSprite().move(0, -100);
                        worked = true;
                    }
                    break;
                case 2:
                    if(enemyX < 4){
                        enemy->move(1, 0); // move right
                        enemy->getSprite().move(100, 0);
                        worked = true;
                    }
                    break;
                case 3:
                    if(enemyY < 4){
                        enemy->move(0, 1); // move down
                        enemy->getSprite().move(0, 100);
                        worked = true;
                    }
                    break;
                default:    
                    break;
            }
        }else{ // move enemy towards the player
            if (enemyX < playerX && enemyX < 4){ // right
                enemy->move(1, 0);
                enemy->getSprite().move(100, 0);
                worked = true;
            }else if (enemyX > playerX && enemyX > 0){ // left
                enemy->move(-1, 0);
                enemy->getSprite().move(-100, 0);
                worked = true;
            }else if (enemyY < playerY && enemyY < 4){ // down
                enemy->move(0, 1);
                enemy->getSprite().move(0, 100);
                worked = true;
            }else if (enemyY > playerY && enemyY > 0){ // up
                enemy->move(0, -1);
                enemy->getSprite().move(0, -100);
                worked = true;
            }
        }
    }
}

void GameWorld::update() {
    int oldX = player->getX();
    int oldY = player->getY();
    bool keys[4] = {false, false, false, false};
    // update the player's position based on user input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (!keys[0]) {
            if(player->getY() > 0){
                player->move(0, -1);
                player->getSprite().move(0, -100);
                keys[0] = true;
            }
        }
    } else {
        keys[0] = false;
    }if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (!keys[1]) {
            if(player->getX() > 0){
                player->move(-1, 0);
                player->getSprite().move(-100, 0);
                keys[1] = true;
            }
        }
    } else {
        keys[1] = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (!keys[2]) {
            if(player->getY() < 4){
                player->move(0, 1);
                player->getSprite().move(0, 100);
                keys[2] = true;
            }
        }
    } else {
        keys[2] = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (!keys[3]) {
            if(player->getX() < 4){
                player->move(1, 0);
                player->getSprite().move(100, 0);
                keys[3] = true;
            }
        }
    } else {
        keys[3] = false;
    }

    // handle collisions with grid boundaries
    if (player->getX() < 0 || player->getX() > 4 || player->getY() < 0 || player->getY() > 4) {
        player->setPosition(0, 0);
    }
    if(enemy->getX() < 0 || enemy->getX() > 4 || enemy->getY() < 0 || enemy->getY() > 4){
        enemy->setPosition(4, 4);
    }

    // update the enemy's position based on its movement algorithm
    for(int i = 0; i < 4; i++){
        if(keys[i] == true){
            moveEnemySmartly(oldX, oldY);
        }
    }
    // handle collisions between the player and the enemy
    if (player->getX() == enemy->getX() && player->getY() == enemy->getY()) {
        while(player->getHealth() > 0){
            player->decreaseHealth();
        }
        if (player->getHealth() <= 0) {
            gameOver();
        }
    }
    fieldVisited[oldX][oldY] = true;

    handleFieldInteraction(player->getX(), player->getY());
    // update the text display based on the player's current health and relic count
    stdtext.setString("Health: " + to_string(player->getHealth()) + "\nRelics: " + to_string(player->getRelics()) + "\nAttribute values: \nStrength: " + to_string(player->getAttributeValue(Attribute::STRENGTH)) + "\nAgility: " + to_string(player->getAttributeValue(Attribute::AGILITY)) + "\nIntelligence: " + to_string(player->getAttributeValue(Attribute::INTELLIGENCE)));
}

string GameWorld::gameOver() {
    string end;
    end+="       Game over!\n";
    end+="   Relics collected: " + to_string(player->getRelics()) + string("\n");
    end+=" Press any key to end...";
    return end;
}