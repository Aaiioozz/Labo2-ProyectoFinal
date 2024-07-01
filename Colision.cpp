#include "Colision.h"

bool Colision::isCollision(Colision& obj) const{
    return getBounds().intersects(obj.getBounds());
}
