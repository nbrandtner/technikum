#include "game.h"

int levelCounter = 1;

int main() {
    World world;
    Character character;
    Enemy enemy;
    Game game;

    do {
        while (character.life > 0 && character.relicCounter < world.getTotalRelics() && (character.x != enemy.x || character.y != enemy.y)) {
            world.print_interface(character, enemy);
            game.move_character(character);
            game.move_enemy(enemy, character);
            world.handle_field(character);
        }

        if (character.life <= 0) {
            std::cout << "Out of Lives!\n";
                std::cout << "  __   _______ _   _  ______ _____ ___________ _ \n";
                std::cout << "  \\ \\ / /  _  | | | | |  _  \\_   _|  ___|  _  \\ |\n";
                std::cout << "   \\ V /| | | | | | | | | | | | | | |__ | | | | |\n";
                std::cout << "    \\ / | | | | | | | | | | | | | |  __|| | | | |\n";
                std::cout << "    | | \\ \\_/ / |_| | | |/ / _| |_| |___| |/ /|_|\n";
                std::cout << "    \\_/  \\___/ \\___/  |___/  \\___/\\____/|___/ (_)\n";
            break;
        } else if (character.x == enemy.x && character.y == enemy.y) {
            std::cout << "The enemy caught you!\n";
            std::cout << "   _____   ___  ______ _____ _   _______ ___________ _ \n";
            std::cout << "  /  __ \\ / _ \\ | ___ \\_   _| | | | ___ \\  ___|  _  \\ |\n";
            std::cout << "  | /  \\// /_\\ \\| |_/ / | | | | | | |_/ / |__ | | | | |\n";
            std::cout << "  | |    |  _  ||  __/  | | | | | |    /|  __|| | | | |\n";
            std::cout << "  | \\__/\\| | | || |     | | | |_| | |\\ \\| |___| |/ /|_|\n";
            std::cout << "   \\____/\\_| |_/\\_|     \\_/  \\___/\\_| \\_\\____/|___/ (_)\n";
            break;
        } else {
            std::cout << "Level complete! Congrats!\n";
            // Reset character + enemy position and relic counter
            character.x = 0;
            character.y = 0;
            enemy.x = 4;
            enemy.y = 4;
            character.relicCounter = 0;
            // Generate a new world
            world = World();
            // Level up
        game.level_up(character);

        }
    } while (true);

    return 0;
}
