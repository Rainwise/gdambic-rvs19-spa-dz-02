#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include "GameLogic.h"

const int WIDTH = 1200;
const int HEIGHT = 800;
const int CELL_SIZE = 10;

int main() {
    srand(time(NULL));
    int gridSizeX = WIDTH / CELL_SIZE;
    int gridSizeY = HEIGHT / CELL_SIZE;
    GameLogic game(gridSizeX, gridSizeY);

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Game of life !");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        game.update();

        // crna pozadina da se uklopi sa crnim mrtvim stanicama
        window.clear(sf::Color::Black);
        const auto& grid = game.getGrid();
        for (int i = 0; i < gridSizeX; i++) {
            for (int j = 0; j < gridSizeY; j++) {
                sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
                cell.setPosition(i * CELL_SIZE, j * CELL_SIZE);
                // ako je stanica ziva onda je plave boje, ako je mrtva onda je crne
                cell.setFillColor(grid[i][j] ? sf::Color(0x65, 0xb1, 0xb3) : sf::Color::Black);
                window.draw(cell);
            }
        }
        window.display();

        // // Refresh svake 2 sekunde
        sf::sleep(sf::seconds(2)); 

    }
    return 0;
}
