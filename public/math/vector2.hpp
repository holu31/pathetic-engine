class Vector2 {
public:
    float x;
    float y;

    Vector2();
    Vector2(float x, float y);

    void setTransform(float x, float y);
    float length();
    void normalize();

    Vector2 operator *(const Vector2 &vec2);
};