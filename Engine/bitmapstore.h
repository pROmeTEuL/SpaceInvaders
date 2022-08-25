#ifndef BITMAPSTORE_H
#define BITMAPSTORE_H

#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;
using namespace std;

class BitmapStore
{
    map<string, Texture> m_BitmapsMap;
    BitmapStore() = default;
    Texture getBitmap(const string& filename);
public:
    static BitmapStore& instance();
};

#endif // BITMAPSTORE_H
