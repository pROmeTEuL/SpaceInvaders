#include "bitmapstore.h"

BitmapStore &BitmapStore::instance()
{
    static BitmapStore bs;
    return bs;
}

Texture &BitmapStore::getBitmap(const std::string &filename)
{
    auto it = m_BitmapsMap.find(filename);
    if (it == m_BitmapsMap.end()) {
        m_BitmapsMap[filename].loadFromFile(filename);
        return m_BitmapsMap[filename];
    }
    return it->second;
}
