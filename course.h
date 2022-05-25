#ifndef Course_A
#define Course_A

#include "vehicle.h"
#include <iostream>
#include <vector>
#include <string>
#include <set>

using std::pair;
using std::set;
using std::string;
using std::vector;

class Course
{
    vector<vector<char> > course;
    vector<vector<char> > map;
    pair<int, int> start;
    pair<int, int> finish;
    vector<Vehicle *> vehicles;

    const vector<char> &operator[](int m) const { return course.at(m); }
    vector<char> &operator[](int m) { return course.at(m); }
    void VehicleAccessor(const Course &c, vector<vector<char> > &m);

public:
    Course(){};
    Course(string);
    void AddVehicleToStart(Vehicle *v);
    set<Vehicle> VehiclesAtFinish();
    Course(const Course &);
    Course &operator=(Course &);
    int ReturnOffTrackVehiclesToStart();

    bool operator<(const Course &c2) const;
    friend std::ostream &operator<<(std::ostream &o, const Course &x);
};

#endif