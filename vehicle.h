#ifndef Vehicle_A
#define Vehicle_A

#include "course.h"
#include <iostream>
#include <vector>
#include <string>

using std::pair;
using std::string;
using std::vector;

class Vehicle
{
    char vehicle;
    char direction;
    pair<int, int> position;

public:
    Vehicle(char);
    Vehicle(char *);
    void SetBearing(char);
    void MoveForward(int X = 1);
    void TurnRight();
    void TurnLeft();
    bool operator<(const Vehicle &c2) const;

    friend class Course;

    friend std::ostream &operator<<(std::ostream &o, const Vehicle &x);
    friend bool operator==(const Vehicle &c1, const Vehicle &c2);
    friend bool operator!=(const Vehicle &c1, const Vehicle &c2);
};

#endif