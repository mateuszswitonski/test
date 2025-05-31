#include "map.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

Map::Map(int rows, int cols)
    : m_rows(rows), m_cols(cols)
{
    generateMapData();
}

void Map::resizeToWindow(const sf::RenderWindow& window) {
    int windowWidth = window.getSize().x;
    int windowHeight = window.getSize().y;

    m_tileSizeX = static_cast<float>(windowWidth) / m_cols;
    m_tileSizeY = static_cast<float>(windowHeight) / m_rows;

    generateTiles();
}

void Map::draw(sf::RenderWindow& window) {
    for (const auto& tile : m_tiles) {
        window.draw(tile);
    }
}

void Map::generateMapData() {
    m_mapData.resize(m_rows, std::vector<int>(m_cols, 0));

    int midRow = m_rows / 2;
    for (int col = 0; col < m_cols; ++col) {
        m_mapData[midRow][col] = 1;
    }
}

void Map::generateTiles() {
    m_tiles.clear();

    for (int row = 0; row < m_rows; ++row) {
        for (int col = 0; col < m_cols; ++col) {
            sf::RectangleShape tile(sf::Vector2f(m_tileSizeX, m_tileSizeY));
            tile.setPosition(col * m_tileSizeX, row * m_tileSizeY);

            if (m_mapData[row][col] == 1) {
                tile.setFillColor(sf::Color(128, 128, 128));
            } else {
                tile.setFillColor(sf::Color::Green);
            }

            tile.setOutlineColor(sf::Color::Black);
            tile.setOutlineThickness(1);
            m_tiles.push_back(tile);
        }
    }
}
