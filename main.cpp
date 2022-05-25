#include "course.h"
#include "vehicle.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::istringstream;
using std::string;
using std::vector;

int main()
{

    string const s = R"(
..****.
..*..*.
..*..F.
..S....
.......
)";
    Course c1(s);

    Course c2 = c1;

    cout << c1 << endl;
    cout << c2 << endl;

    return 0;
}