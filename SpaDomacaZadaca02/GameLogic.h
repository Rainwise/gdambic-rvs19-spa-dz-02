#pragma once
#include <vector>
using namespace std;

class GameLogic {
private:
    int gridSizeX, gridSizeY;
    vector<vector<int>> grid;
    vector<vector<int>> nextGrid;

    int countLiveNeighbors(int x, int y) const;

public:
    GameLogic(int x, int y);
    void update();
    const vector<vector<int>>& getGrid() const;
};

