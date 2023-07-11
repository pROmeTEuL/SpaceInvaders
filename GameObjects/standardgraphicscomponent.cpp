#include "standardgraphicscomponent.h"
#include "bitmapstore.h"

string StandardGraphicsComponent::getSpecificType()
{
    return m_specificType;
}

void StandardGraphicsComponent::start(GameObjectSharer *gos, GameObject *self)
{

}

void StandardGraphicsComponent::draw(RenderWindow &window, std::shared_ptr<TransformComponent> t)
{
    m_sprite.setPosition(t->getLocation());
    window.draw(m_sprite);
}

void StandardGraphicsComponent::initializeGraphics(string bitmapName, Vector2f objectSize)
{
    m_sprite.setTexture(BitmapStore::instance().getBitmap("graphics/" + bitmapName + ".png"));
    auto textureSize = m_sprite.getTexture()->getSize();
    m_sprite.setScale(float(objectSize.x) / textureSize.x, float(objectSize.y) / textureSize.y);
    m_sprite.setColor(Color(0, 255, 0));
}
