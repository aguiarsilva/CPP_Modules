#include "Point.hpp"

static Fixed crossProduct(Point const& p1, Point const& p2, Point const& p3)
{
     Fixed x1 = p2.getX() - p1.getX();
     Fixed y1 = p2.getY() - p1.getY();
     Fixed x2 = p3.getX() - p1.getX();
     Fixed y2 = p3.getY() - p1.getY();

     return (x1 * y2 - y1 * x2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed area1 = crossProduct(a, b, point);
    Fixed area2 = crossProduct(b, c, point);
    Fixed area3 = crossProduct(c, a, point);

    if ((area1 > 0 && area2 > 0 && area3 > 0)||(area1 < 0 && area2 < 0 && area3 < 0))
        return true;
    return false;
}