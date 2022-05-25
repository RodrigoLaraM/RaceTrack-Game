#include "course.h"
#include "vehicle.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::string;
using std::vector;

Course::Course(string s)
{
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    vector<vector<char>> v;
    istringstream ss(s);
    string line;

    while (getline(ss, line))
    {
        if (line.size() == 0)
        {
            continue;
        }
        vector<char> ch(line.begin(), line.end());
        v.push_back(ch);
    }
    course = v;
    map = v;

    int row = 0;
    int column = 0;

    for (size_t i = 0; i < course.size(); i++)
    {
        row = i;
        for (size_t j = 0; j < course[i].size(); j++)
        {
            column = j;
            if (course[i][j] == 'S')
            {
                start.first = row;
                start.second = column;
            }
            else if (course[i][j] == 'F')
            {
                finish.first = row;
                finish.second = column;
            }
        }
    }
}

void Course::AddVehicleToStart(Vehicle *v)
{
    vehicles.push_back(v);
    course[start.first][start.second] = v->vehicle;
    v->position.first = start.first;
    v->position.second = start.second;
}

void Course::VehicleAccessor(const Course &c, vector<vector<char>> &temp_map)
{
    for (Vehicle *i : c.vehicles)
    {
        temp_map[i->position.first][i->position.second] = i->vehicle;
    }
}

set<Vehicle> Course::VehiclesAtFinish()
{
    set<Vehicle> v;
    for (Vehicle *i : vehicles)
    {
        if (i->position.first == finish.first && i->position.second == finish.second)
        {
            v.insert(*i);
        }
    }
    return v;
}

Course::Course(const Course &c)
{
    course = c.course;
    map = c.map;
    start = c.start;
    finish = c.finish;
}

Course &Course::operator=(Course &rhs)
{
    course = rhs.course;
    map = rhs.map;
    start = rhs.start;
    finish = rhs.finish;
    vehicles = rhs.vehicles;
    rhs.vehicles.clear();
    return (*this);
}

int Course::ReturnOffTrackVehiclesToStart()
{
    int num_off_vehicles = 0;
    for (Vehicle *i : vehicles)
    {
        if (course[i->position.first][i->position.second] == '.')
        {
            i->position.first = start.first;
            i->position.second = start.second;
            num_off_vehicles++;
        }
    }
    return (num_off_vehicles);
}

std::ostream &operator<<(std::ostream &o, const Course &c)
{
    vector<vector<char>> temp_map = c.map;
    Course object;

    object.VehicleAccessor(c, temp_map);

    o << string(temp_map[0].size() + 2, '+') << endl;
    for (size_t i = 0; i < temp_map.size(); i++)
    {
        o << '+';
        for (size_t j = 0; j < temp_map[i].size(); j++)
        {
            o << temp_map[i][j];
        }
        o << '+' << endl;
    }
    o << string(temp_map[0].size() + 2, '+') << endl;
    return o;
}