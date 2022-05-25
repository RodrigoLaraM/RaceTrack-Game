#include "course.h"
#include "vehicle.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

// Initialize the Vehicle
Vehicle::Vehicle(char ch)
{
    vehicle = ch;
}

// Setting Vehicles bearing(direction to move forward)
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

// Move number of steps forward
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

// Turn bearing to the right
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
// Turn bearing to the left
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

// Operator <
bool Vehicle::operator<(const Vehicle &c2) const
{
    return (vehicle < c2.vehicle);
}

// Operator <<
std::ostream &operator<<(std::ostream &o, const Vehicle &x)
{
    o << x.vehicle;
    return o;
}

// Operator ==
bool operator==(const Vehicle &c1, const Vehicle &c2)
{
    return (c1.vehicle == c2.vehicle);
}

// Operator !=
bool operator!=(const Vehicle &c1, const Vehicle &c2)
{
    return (c1.vehicle != c2.vehicle);
}
