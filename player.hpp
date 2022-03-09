#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
class player {
    string firstName;
    string secondName;
    int points;
public:
    friend istream & operator>>(istream &, player&);
    friend ostream & operator<<(ostream &, player&);
    int getPoints();
    void setPoints(int);
};
