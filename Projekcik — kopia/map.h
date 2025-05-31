#ifndef MAP_H
#define MAP_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class Map
{
public:
    Map(int rows, int cols);
    void resizeToWindow(const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
private:
    int m_rows;
    int m_cols;
    float m_tileSizeX;
    float m_tileSizeY;
    std::vector<sf::RectangleShape> m_tiles;
    std::vector<std::vector<int>> m_mapData;

    void generateMapData();
    void generateTiles();
};

#endif // MAP_H
