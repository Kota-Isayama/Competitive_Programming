#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long double LD;

const LD EPS = 1e-10;

//aの符号を返す
int sgn(LD a) {
    return (a < -EPS ? -1 : (a > EPS ? 1 : 0));
}

struct Vec2 {
    LD x, y;

    Vec2() {};
    Vec2(LD _x, LD _y) : x(_x), y(_y) {};
    
    //ベクトルの長さを返す
    LD norm() const { return sqrt(dot(*this)); }
    //ベクトルotherとの内積を返す
    LD dot(const Vec2 &other) const { return x * other.x + y * other.y; }
    //ベクトルotherとの外積this x otherを返す
    LD cross(const Vec2 &other) const { return x * other.y - y * other.x; }
    //ゼロベクトルかどうかを判定
    bool isZero() {return (!sgn(norm()));}

    LD arg() { return atan2(y, x);}

    Vec2 operator +() const { return *this; }

    Vec2 operator -() const { return Vec2(-x, -y); }

    Vec2 operator +(const Vec2 &other) const { return Vec2(x+other.x, y+other.y); }

    Vec2& operator *= (LD s) {
        x *= s; y *= s;
        return *this;
    }
    Vec2& operator /= (LD s) {
        x /= s; y /= s;
        return *this;
    }
    Vec2& operator += (const Vec2& other) {
        x += other.x;   y += other.y;
        return *this;
    }
    Vec2& operator -= (const Vec2& other) {
        x -= other.x;   y -= other.y;
        return *this;
    }

};
inline Vec2 operator *(LD s, const Vec2& v) {return Vec2(s*v.x, s*v.y);}

