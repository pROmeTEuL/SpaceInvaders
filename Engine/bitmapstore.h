#ifndef BITMAPSTORE_H
#define BITMAPSTORE_H

#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;

class BitmapStore
{
    std::map<std::string, Texture> m_BitmapsMap;
    BitmapStore() = default;
public:
    BitmapStore instance();
    Texture& getBitmap(const std::string& filename);
    void addBitmap(const std::string& filename);
};

#endif // BITMAPSTORE_H
