#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#define SIZE 5
#define EMPTY 0
#define DANGER 1
#define WELL 2
#define RELIC 3

extern int levelCounter;

class Character {
public:
    int x;
    int y;
    int life;
    int relics;
    int relicCounter;
    int strength;
    int dexterity;
    int wisdom;
    int strengthPotion = 0;
    int dexterityPotion = 0;
    int wisdomPotion = 0;

    Character() : x(0), y(0), life(5), relicCounter(0) {
        strength = rand() % 10 + 1;
        dexterity = rand() % 10 + 1;
        wisdom = rand() % 10 + 1;
    }
};

class Enemy {
public:
    int x;
    int y;
    // enemy start opposite player start
    Enemy() : x(SIZE - 1), y(SIZE - 1) {}
};

class Danger {
public:
    enum Type {ENEMY = 1, TRAP, RIDDLE};
    Type type;
    int difficulty;

    Danger() {
        int rand_num = rand() % 3 + 1;
        type = static_cast<Type>(rand_num);

        difficulty = rand() % 9 + 1 + levelCounter;
        /* for (int i = 0; i < levelCounter; i++) {
            difficulty = (rand() % 10 + 1) + i;
            // difficulty += rand() % 10 + 1;
            std::cout << difficulty << "right now\n";
            std::cin.get();
        } */
    }
};

class World {
private:
    int world[SIZE][SIZE];
    int originalWorld[SIZE][SIZE];
    bool visited[SIZE][SIZE];
    int totalRelics;

public:
    World() : totalRelics(0)  {
        srand(time(NULL));
        // Generate a random number between 1 and 5 for the amount of relics
        int relicCount = rand() % 5 + 1;
        totalRelics = relicCount;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int rand_num = rand() % 10;
                if (rand_num < 4) {
                    world[i][j] = EMPTY;
                } else if (rand_num < 8) {
                    world[i][j] = DANGER;
                } else if (rand_num == 8) {
                    world[i][j] = WELL;
                } else {
                    world[i][j] = EMPTY;
                }
            }
        }
        // ensure start is EMPTY
        world[0][0] = EMPTY;

        // ensure relic placement
        while (relicCount > 0) {
            int x = rand() % SIZE;
            int y = rand() % SIZE;
            // ensure relic not on start
            while ((x == 0 && y == 0) || world[x][y] == RELIC) {
                x = rand() % SIZE;
                y = rand() % SIZE;
            }
            world[x][y] = RELIC;
            relicCount--;
        }

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                visited[i][j] = false;
            }
        }
        visited[0][0] = true;

        // copy current game map (for relic)
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                originalWorld[i][j] = world[i][j];
            }
        }
    }

    // getTotalRelics to print them later
    int getTotalRelics() {
        return totalRelics;
    }


    void print_interface(Character &character, Enemy &enemy) {

        std::cout << "____________________________________________________________\n\n";

        std::cout << "Level: " << ::levelCounter << "\n\n";

        // Life and relic count display
        int life = character.life;
        bool firstLine = true;
        while (life > 0) {
            for (int i = 0; i < 7; i++) {
                if (life > 0) {
                    std::cout << "\x1b[1;31m<3 \x1b[0m"; // \033[31m starts red color output, \033[0m resets to default
                    life--;
                } else {
                    std::cout << "   "; // 3 spaces to match the width of "<3 "
                }
            }
            if (firstLine) {
                std::cout << "          " << character.relicCounter << " / " << totalRelics << " Relics found!";
                firstLine = false;
            }
            std::cout << "\n";
        }



        std::cout << "\n";

        // Grid and stats display
        for(int j = 0; j < SIZE; j++) {
            std::cout << " ___";
        }
        std::cout << "\n";
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                std::cout << "| ";
                if (i == character.y && j == character.x) {
                    std::cout << "\x1b[1;38;5;41mP \x1b[0m";
                } else if (i == enemy.y && j == enemy.x) {
                    std::cout << "\x1b[1;38;5;196mE \x1b[0m";
                } else {
                    if (visited[i][j]) {
                        switch (originalWorld[i][j]) {
                            case EMPTY:
                                std::cout << "* ";
                                break;
                            case DANGER:
                                std::cout << "\x1b[1;38;5;214mD \x1b[0m";
                                break;
                            case WELL:
                                std::cout << "\x1b[1;38;5;11mO \x1b[0m";
                                break;
                            case RELIC:
                                std::cout << "\x1b[1;38;5;136mR \x1b[0m";
                                break;
                        }
                    } else {
                        std::cout << "? ";
                    }
                }
            }
            std::cout << "|";

            // Add 8 spaces to the output
            std::cout << "          ";

            // Add different values to the output based on the row number
            switch(i) {
            case 0: std::cout << "\x1b[1;38;5;19mStrength: " << character.strength << "\x1b[0m"; break;
            case 1: std::cout << "\x1b[1;38;5;245mDexterity: " << character.dexterity << "\x1b[0m"; break;
            case 2: std::cout << "\x1b[1;38;5;5mWisdom: " << character.wisdom << "\x1b[0m"; break;
                case 3: std::cout << "+---+---+---+---+---+---+---+  "; break;
            case 4: std::cout << "\x1b[1;38;5;31mStrength Potions: " << character.strengthPotion << "\x1b[0m"; break;
                default: std::cout << "No option"; break;
            }
            std::cout << "\n";

            for(int j = 0; j < SIZE; j++) {
                std::cout << "|___";
            }
            std::cout << "|\n";
        }

        std::cout << "                               \x1b[1;38;5;250mDexterity Potions: " << character.dexterityPotion << "\x1b[0m\n";
        std::cout << "                                \n";
        std::cout << "                               \x1b[1;38;5;13mWisdom Potions: " << character.wisdomPotion << "\x1b[0m\n\n\n";
        std::cout << "____________________________________________________________\n\n";
        std::cout << "\n";
    }




    void handle_field(Character &character) {
        visited[character.y][character.x] = true;
        int field = world[character.y][character.x];
        world[character.y][character.x] = EMPTY;
        // pointer variable named danger that points to nothing (null pointer)
        Danger* danger = nullptr;
        std::cout << "\n";
        switch (field) {
            case EMPTY:
                std::cout << "Field is empty.\n";
                break;
            case DANGER:
                std::cout << "Danger!\n";
                // Assign the new Danger object
                danger = new Danger();

                // Handle danger based on its type and difficulty
                switch (danger->type) {


                    case Danger::ENEMY:
                        if (character.strength < danger->difficulty && character.strengthPotion > 0) {
                            character.strengthPotion--;
                            std::cout << "A level " << danger->difficulty << " enemy appeared! Strength Check!\nYou were too weak BUT had a Strength potion - no lives lost! Lucky!\n";
                        } else if (character.strength < danger->difficulty) {
                            character.life -= 1;
                            std::cout << "A level " << danger->difficulty << " enemy appeared! Strength Check!\nYou were too weak! -1 HP \n";
                        } else {
                            std::cout << "A level " << danger->difficulty << " enemy appeared! Strength Check!\nYou were stronger - no lives lost!\n";
                        }
                        break;



                    case Danger::TRAP:
                        if (character.dexterity < danger->difficulty && character.dexterityPotion > 0) {
                            character.dexterityPotion--;
                            std::cout << "A level " << danger->difficulty << " trap was set! Dexterity Check!\nYou were too slow BUT had a Dexterity potion - no lives lost! Lucky!\n";
                        } else if (character.dexterity < danger->difficulty) {
                            character.life -= 1;
                            std::cout << "A level " << danger->difficulty << " trap was set! Dexterity Check!\nYou were too slow! -1 HP \n";
                        } else {
                            std::cout << "A level " << danger->difficulty << " trap was set! Dexterity Check!\nYou were quick enough - no lives lost!\n";
                        }
                        break;



                    case Danger::RIDDLE:
                        if (character.wisdom < danger->difficulty && character.wisdomPotion > 0) {
                            character.wisdomPotion--;
                            std::cout << "A sphinx tests you with a level " << danger->difficulty << " riddle! Wisdom Check!\nYou were too stupid BUT had a Wisdom potion - no lives lost! Lucky!\n";
                        } else if (character.wisdom < danger->difficulty) {
                            character.life -= 1;
                            std::cout << "A sphinx tests you with a level " << danger->difficulty << " riddle! Wisdom Check!\nYou were too stupid! -1 HP \n";
                        } else {
                            std::cout << "A sphinx tests you with a level " << danger->difficulty << " riddle! Wisdom Check!\nYou were smart enough - no lives lost!\n";
                        }
                        break;


                }
                delete danger;

                break;
            case WELL:
                character.life += 1;
                std::cout << "You found an oasis and rested for a while! +1 HP\n";
                break;
            case RELIC:
                character.relicCounter += 1;
                std::cout << "You found a relic! Missing relics: " << totalRelics - character.relicCounter << "\n";
                int potionType = rand() % 3;
                switch (potionType) {
                    case 0:
                        character.strengthPotion++;
                        std::cout << "You found a strength potion!\n";
                        break;
                    case 1:
                        character.dexterityPotion++;
                        std::cout << "You found a dexterity potion!\n";
                        break;
                    case 2:
                        character.wisdomPotion++;
                        std::cout << "You found a wisdom potion!\n";
                        break;
                }
                break;
        }
    }
};

class Game {
public:

    // character
    void move_character(Character &character) {
        char direction;
        std::cout << "Move with WASD: ";
        std::cin >> direction;

        // ensure player can't leave the grid
        switch (direction) {
            case 'w':
                if (character.y > 0) {
                    character.y -= 1;
                }
                break;
            case 'a':
                if (character.x > 0) {
                    character.x -= 1;
                }
                break;
            case 's':
                if (character.y < SIZE - 1) {
                    character.y += 1;
                }
                break;
            case 'd':
                if (character.x < SIZE - 1) {
                    character.x += 1;
                }
                break;
            default:
                std::cout << "Invalid input!\n";
                move_character(character);
                break;
        }
    }

    // enemy
    void move_enemy(Enemy &enemy, Character &character) {
        // chance for random movement
        if (rand() % 100 < 80) {
            // random movement
            int direction = rand() % 4;
            switch (direction) {
                case 0: // up
                    if (enemy.y > 0) {
                        enemy.y--;
                    }
                    break;
                case 1: // down
                    if (enemy.y < SIZE - 1) {
                        enemy.y++;
                    }
                    break;
                case 2: // left
                    if (enemy.x > 0) {
                        enemy.x--;
                    }
                    break;
                case 3: // right
                    if (enemy.x < SIZE - 1) {
                        enemy.x++;
                    }
                    break;
            }
        } else {
            // enemy moves in direction of character
            if (enemy.x < character.x) {
                enemy.x++;
            } else if (enemy.x > character.x) {
                enemy.x--;
            }

            else if (enemy.y < character.y) {
                enemy.y++;
            } else if (enemy.y > character.y) {
                enemy.y--;
            }
        }
    }

    // level up
    void level_up(Character &character) {
        levelCounter++;
    character.strength += rand() % 4;
    character.dexterity += rand() % 4;
    character.wisdom += rand() % 4;
    // std::cout << "Level Up!\n";
    std::cout << "    _    _____   _____ _      _   _ ___ _ \n";
    std::cout << "   | |  | __\\ \\ / / __| |    | | | | _ \\ |\n";
    std::cout << "   | |__| _| \\ V /| _|| |__  | |_| |  _/_|\n";
    std::cout << "   |____|___| \\_/ |___|____|  \\___/|_| (_)\n";
    }
};

#endif // GAME_H
