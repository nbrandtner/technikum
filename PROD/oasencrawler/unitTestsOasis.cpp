#define CATCH_CONFIG_MAIN // Dies definiert den Hauptteil einmal in einer cpp-Datei
#include "catch_amalgamated.hpp"
#include "game.h"


TEST_CASE("Character health increases when increaseHealth is called", "[Character]") {
    Character character;
    int initialHealth = character.getHealth();
    character.increaseHealth();
    REQUIRE(character.getHealth() == initialHealth + 1);
}

TEST_CASE("Character health decreases when decreaseHealth is called", "[Character]") {
    Character character;
    int initialHealth = character.getHealth();
    character.decreaseHealth();
    REQUIRE(character.getHealth() == initialHealth - 1);
}

TEST_CASE("Character relics increase when increaseRelics is called", "[Character]") {
    Character character;
    int initialRelics = character.getRelics();
    character.increaseRelics();
    REQUIRE(character.getRelics() == initialRelics + 1);
}

TEST_CASE("Enemy position changes when move is called", "[Enemy]") {
    Enemy enemy;
    int initialX = enemy.getX();
    int initialY = enemy.getY();
    enemy.move(-1, -1);
    REQUIRE(enemy.getX() == initialX - 1);
    REQUIRE(enemy.getY() == initialY - 1);
}

TEST_CASE("Character attributes are correctly initialized", "[Character]") {
    Character character;
    REQUIRE(character.getAttributeValue(Attribute::STRENGTH) >= 1);
    REQUIRE(character.getAttributeValue(Attribute::AGILITY) >= 1);
    REQUIRE(character.getAttributeValue(Attribute::INTELLIGENCE) >= 1);
}

TEST_CASE("Character addition operator works correctly", "[Character]") {
    Character character1;
    character1.increaseHealth();
    character1.increaseRelics();

    Character character2;
    character2.increaseHealth();
    character2.increaseRelics();

    Character character3 = character1 + character2;

    REQUIRE(character3.getHealth() == character1.getHealth() + character2.getHealth());
    REQUIRE(character3.getRelics() == character1.getRelics() + character2.getRelics());
}

TEST_CASE("Character equality operator works correctly", "[Character]") {
    Character character1;
    character1.increaseHealth();
    character1.increaseRelics();

    Character character2;
    character2.increaseHealth();
    character2.increaseRelics();
    
    REQUIRE(character1 == character2);
}

TEST_CASE("Character less than operator works correctly", "[Character]") {
    Character character1;
    character1.increaseHealth();  // Health is now 2

    Character character2;
    character2.increaseHealth();
    character2.increaseHealth();  // Health is now 3

    REQUIRE(character1 < character2);
}
