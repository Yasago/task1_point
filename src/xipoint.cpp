////////////////////////////////////////////////////////////////////////////////
// Module Name:  xipoint.h/cpp
// Authors:      Sergey Shershakov
// Version:      0.2.1
// Date:         08.09.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////


#include "xipoint.h"

#include <algorithm>        // min
#include <cmath>

namespace xi {


    // Start Constructor and Methods of class Point
    Point::Point(int x, int y)
    {
        _x = x;
        _y = y;
    }

    // Start Methods
    void Point::shift(int shf)
    {
        _x += shf;
        _y += shf;
    }

    void Point::shift(int xSh, int ySh)
    {
        _x += xSh;
        _y += ySh;
    }

    void Point::shift(const Point &pt)
    {
        _x += pt._x;
        _y += pt._y;
    }

    double Point::dist(const Point &other) const
    {
        int distX = abs(_x - other._x);    // Gets distance between x-coordinates
        int distY = abs(_y - other._y);    // Gets distance between y-coordinates
        return sqrt(pow(distX, 2) + pow(distY, 2));
    }

    int Point::getX() const
    {
        return _x;
    }

    int Point::getY() const
    {
        return _y;
    }

    void Point::setX(int x)
    {
        _x = x;
    }

    void Point::setY(int y)
    {
        _y = y;
    }
    // End Methods
    // End Constructor and Methods of class Point

    // Start Constructors, Methods and Destructor of class PointArray
    // Start Constructors
    PointArray::PointArray()
    {
        _arr = nullptr;
        _size = 0;
    }

    PointArray::PointArray(const Point points[], PointArray::Uint n)
    {
        _arr = new Point[n];
        _size = n;

        for (Uint i = 0; i < _size; ++i)
        {
            _arr[i] = points[i];
        }

    }

    PointArray::PointArray(const PointArray &pv)
    {
        _size = pv._size;
        _arr = new Point[_size];

        for (Uint i = 0; i < _size; ++i)
        {
            _arr[i] = pv._arr[i];
        }
    }
    // End Constructors

    PointArray::~PointArray()
    {
        delete [] _arr;
        _arr = nullptr;
        _size = 0;
    }

    // Start Methods
    void PointArray::append(const Point &pt)
    {
        Point* arrCopy = _arr;
        _arr = new Point[_size + 1];

        for (Uint i = 0; i < _size; ++i)
        {
            _arr[i] = arrCopy[i];
        }

        _arr[_size] = pt;
        ++_size;

        delete [] arrCopy;
        arrCopy = nullptr;
    }

    void PointArray::insert(const Point &pt, PointArray::Uint pos)
    {
        if (pos > _size)
            pos = _size;

        Point* arrCopy = _arr;
        _arr = new Point[_size + 1];
        ++_size;

        for (Uint i = 0; i < pos; ++i)
        {
            _arr[i] = arrCopy[i];
        }
        _arr[pos] = pt;
        for (Uint i = pos + 1; i < _size; ++i)
        {
            _arr[i] = arrCopy[i - 1];
        }

        delete [] arrCopy;
        arrCopy = nullptr;
    }

    void PointArray::remove(PointArray::Uint pos)
    {
        if (pos >= _size)
            return;

        if (_size == 1)
        {
            _size = 0;
            delete [] _arr;
            _arr = nullptr;
            return;
        }

        Point* arrCopy = _arr;
        _arr = new Point[_size - 1];
        --_size;

        for (Uint i = 0; i < pos; ++i)
        {
            _arr[i] = arrCopy[i];
        }
        for (Uint i = pos; i < _size; ++i)
        {
            _arr[i] = arrCopy[i + 1];
        }

        delete [] arrCopy;
        arrCopy = nullptr;
    }

    void PointArray::clear()
    {
        delete [] _arr;
        _arr = nullptr;
        _size = 0;
    }

    double PointArray::computePath() const
    {
        double sumDistances = 0;    // The sum of distances between neighbouring points in the array

        if (_size == 0)
            return 0;

        for (Uint i = 0; i < _size - 1; ++i)
        {
            sumDistances += _arr[i].dist(_arr[i + 1]);
        }

        return sumDistances;
    }

    PointArray::Uint PointArray::getSize() const
    {
        return _size;
    }

    Point *PointArray::get(PointArray::Uint pos)
    {
        if (pos >= _size)
            return nullptr;

        return &_arr[pos];
    }

    const Point *PointArray::get(PointArray::Uint pos) const
    {
        if (pos >= _size)
            return nullptr;

        return &_arr[pos];
    }

    void PointArray::resize(PointArray::Uint n)
    {
        Point* arrCopy = _arr;
        _arr = new Point[n];
        Uint copySize = (Uint)fmin(_size, n);    // Amount of elements to copy

        for (Uint i = 0; i < copySize; ++i)
        {
            _arr[i] = arrCopy[i];
        }

        delete [] arrCopy;
        arrCopy = nullptr;
    }
    // End Methods
    // End Constructors, Methods and Destructor of class PointArray

} // namespace xi {
