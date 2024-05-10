#include "GameLogic.h"
#include <cstdlib>

using namespace std;

GameLogic::GameLogic(int x, int y) : gridSizeX(x), gridSizeY(y), grid(x, vector<int>(y, 0)), nextGrid(x, vector<int>(y, 0)) {
    // random init za stanice
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            // 20% sansa da prezivi
            grid[i][j] = (rand() % 4 == 0) ? 1 : 0; 
        }
    }
}

void GameLogic::update() {
    for (int x = 0; x < gridSizeX; x++) {
        for (int y = 0; y < gridSizeY; y++) {
            int liveNeighbors = countLiveNeighbors(x, y);
            if (grid[x][y] == 1) { 
                // stanica ziva
                nextGrid[x][y] = (liveNeighbors == 2 || liveNeighbors == 3) ? 1 : 0;
            }
            else { 
                // stanica mrtva
                nextGrid[x][y] = (liveNeighbors == 3) ? 1 : 0;
            }
        }
    }
    grid.swap(nextGrid);
}

const vector<vector<int>>& GameLogic::getGrid() const {
    return grid;
}

int GameLogic::countLiveNeighbors(int x, int y) const {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int nx = x + i, ny = y + j;
            if (nx >= 0 && nx < gridSizeX && ny >= 0 && ny < gridSizeY) {
                count += grid[nx][ny];
            }
        }
    }
    return count;
}
