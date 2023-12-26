#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <string>
#include <fstream>
#include <sstream>

struct Bomb 
{
    int x, y, r;
    bool detonated;

    Bomb(int x, int y, int r) : x(x), y(y), r(r), detonated(false) {}
};

class Detonation 
{
public:
    std::pair<int, std::vector<int>> findMaxDetonatedBomb(std::vector<Bomb>& bombs) 
    {
        int maxDetonatedBombs = 0;
        std::vector<int> maxDetonatedBombCoords;

        for (size_t i = 0; i < bombs.size(); ++i) {
            bombs[i].detonated = true;
            int r = 1 + triggerDetonation(bombs, i);
            if (r > maxDetonatedBombs) {
                maxDetonatedBombs = r;
                maxDetonatedBombCoords = { bombs[i].x, bombs[i].y, bombs[i].r };
            }
            bombs[i].detonated = false;
        }
        return std::make_pair(maxDetonatedBombs, maxDetonatedBombCoords);
    }

private:
    int triggerDetonation(std::vector<Bomb>& bombs, size_t i) 
    {
        int detonations = 0;
        for (size_t j = 0; j < bombs.size(); j++) {
            if (!bombs[j].detonated) {
                int distance = pow(bombs[i].x - bombs[j].x, 2) + pow(bombs[i].y - bombs[j].y, 2);
                if (distance <=(int)bombs[i].r * bombs[i].r) 
                    {
                    bombs[j].detonated = true;
                    detonations += 1 + triggerDetonation(bombs, j);
                }
            }
        }
        return detonations;
    }
};


//int main() 
// {
//    std::ifstream inputFile("bombs.txt");
//
//    if (!inputFile.is_open()) {
//        std::cout << "Unable to open file!\n";
//        return 1;
//    }
//
//    std::vector<Bomb> bombs;
//    std::string line;
//    while (std::getline(inputFile, line)) {
//        std::istringstream iss(line);
//        int x, y, r;
//        if (!(iss >> x >> y >> r)) {
//            std::cout << "Incorrect file format!\n";
//            return 1;
//        }
//        bombs.push_back(Bomb(x, y, r)); 
//    }
//
//    inputFile.close();
//
//    Detonation d;
//    auto result = d.findMaxDetonatedBomb(bombs);
//
//    int maxDetonatedBombs = result.first;
//    std::vector<int> maxDetonatedBombCoords = result.second;
//
//    std::cout << "Coordinates: " << maxDetonatedBombCoords[0] << ", " << maxDetonatedBombCoords[1] << "\n";
//    std::cout << "Radius: " << maxDetonatedBombCoords[2] << "\n";
//    std::cout << "Count: " << maxDetonatedBombs << "\n";
//
//    return 0;
//}

