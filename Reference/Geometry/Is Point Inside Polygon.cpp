// 13
// assumes the polygon is given counter-clockwise
// if point is exactly in edge, it's considered inside
// change "0 >" to "0 >=" to not consider it inside.
#include "Data Structures/Point.cpp"

bool isPointInPolygon(vector<Point> &ps, Point &p) {
  assert(ps.size() >= 3);
  for (int i = 0; i < ps.size(); i++)
    if (0 > (ps[(i + 1) % ps.size()] - ps[i])
                .positionOf(p - ps[i]))
      return false;
  return true;
}