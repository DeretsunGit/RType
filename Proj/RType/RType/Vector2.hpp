#pragma once

template<typename T>
class Vector2
{
public:
  Vector2()
  {}

  Vector2(const T& x, const T& y)
    : _x(x), _y(y)
  {}

  Vector2(const Vector2& v)
    : _x(v._x), _y(v._y)
  {}

  Vector2&  operator=(const Vector2& v)
  {
    if (this != &v)
    {
      this->_x = v._x;
      this->_y = v._y;
    }
    return (*this);
  }

  ~Vector2()
  {}

  T&  getX()
  {
    return (this->_x);
  }

  T&  getY()
  {
    return (this->_y);
  }

  void	setX(const T& x)
  {
    this->_x = x;
  }

  void	setY(const T& y)
  {
    this->_y = y;
  }

  void	set(const T& x, const T&y)
  {
    this->_x = x;
    this->_y = y;
  }

  Vector2&  operator+=(const Vector2& v)
  {
    this->_x += v._x;
    this->_y += v._y;
    return (*this);
  }

  Vector2   operator+(const Vector2& v)
  {
    return (Vector2(this->_x + v._x, this->_y + v._y));
  }

  Vector2&  operator-=(const Vector2& v)
  {
    this->_x -= v._x;
    this->_y -= v._y;
    return (*this);
  }

  Vector2   operator-(const Vector2& v)
  {
    return (Vector2(this->_x - v._x, this->_y - v._y));
  }

  template<typename V>
  Vector2&  operator*=(const V& m)
  {
    this->_x *= m;
    this->_y *= m;
    return (*this);
  }

  template<typename V>
  Vector2 operator*(const V& m)
  {
    return (Vector2(this->_x * m, this->_y * m));
  }

  template<typename V>
  Vector2&  operator/=(const V& m)
  {
    this->_x /= m;
    this->_y /= m;
    return (*this);
  }

  template<typename V>
  Vector2 operator/(const V& m)
  {
    return (Vector2(this->_x / m, this->_y / m));
  }

private:
  T   _x;
  T   _y;
};

typedef Vector2<int>	Vector2i;
typedef Vector2<float>	Vector2f;