#include "MyMath.h"

bool MyMath::Intersection(Vector2 pos1, Vector2 pos2, Vector2 pos3, Vector2 pos4, Vector2& cross)
{
    Vector2 a = pos2 - pos1;
    Vector2 b = pos4 - pos3;
    float s, t, deno = a.cross(b);
    if (deno == 0.0) {
        // ê¸ï™Ç™ïΩçs
        return false;
    }
    a = pos3 - pos1;
    s = a.cross(b) / deno;
    a = pos2 - pos1;
    b = pos1 - pos3;
    t = a.cross(b) / deno;
    if (s < 0.0 || 1.0 < s || t < 0.0 || 1.0 < t) {
        // ê¸ï™Ç™åç∑ÇµÇƒÇ¢Ç»Ç¢
        return false;
    }
    cross = { pos1.x + s * a.x, pos1.y + s * a.y };
    return true;
}

bool MyMath::PointOnLine(Vector2 line1, Vector2 line2, Vector2 pos)
{
    Vector2 ab = line2 - line1;
    Vector2 ac = pos - line1;
    Vector2 bc = pos - line2;
    float len = ab.length();
    if (len == ac.length() + bc.length()) return true;
    return false;
}