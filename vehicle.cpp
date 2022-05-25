#include "course.h"
#include "vehicle.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

Vehicle::Vehicle(char ch)
{
    vehicle = ch;
}

void Vehicle::SetBearing(char X)
{
    if (X == 'N' || X == 'S' || X == 'E' || X == 'W')
    {
        direction = X;
    }
    else
    {
        throw std::invalid_argument("Invalid Argument");
    }
}

void Vehicle::MoveForward(int X)
{
    if (direction == 'N')
    {
        position.first = position.first - X;
    }

    else if (direction == 'S')
    {
        position.first = position.first + X;
    }

    else if (direction == 'E')
    {
        position.second = position.second + X;
    }

    else if (direction == 'W')
    {
        position.second = position.second - X;
    }
}

void Vehicle::TurnRight()
{
    if (direction == 'N')
    {
        direction = 'E';
    }

    else if (direction == 'E')
    {
        direction = 'S';
    }

    else if (direction == 'S')
    {
        direction = 'W';
    }

    else if (direction == 'W')
    {
        direction = 'N';
    }
}

void Vehicle::TurnLeft()
{
    if (direction == 'N')
    {
        direction = 'W';
    }

    else if (direction == 'W')
    {
        direction = 'S';
    }

    else if (direction == 'S')
    {
        direction = 'E';
    }

    else if (direction == 'E')
    {
        direction = 'N';
    }
}

bool Vehicle::operator<(const Vehicle &c2) const
{
    return (vehicle < c2.vehicle);
}

std::ostream &operator<<(std::ostream &o, const Vehicle &x)
{
    o << x.vehicle;
    return o;
}

bool operator==(const Vehicle &c1, const Vehicle &c2)
{
    return (c1.vehicle == c2.vehicle);
}

bool operator!=(const Vehicle &c1, const Vehicle &c2)
{
    return (c1.vehicle != c2.vehicle);
}
