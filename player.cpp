#include "player.hpp"
istream & operator>>(istream & dev, player &temp){
    char buf[256];
    dev.getline(buf, 256, ' ');
    temp.firstName=buf;
    dev.getline(buf, 256, ' ');
    temp.secondName=buf;
    dev>>temp.points;
    return dev;
}
ostream & operator<<(ostream & dev, player &temp){
    dev<<temp.firstName<<" ";
    dev<<temp.secondName<<" ";
    dev<<temp.points;
    return dev;
}
int player::getPoints(){
    return points;
}
void player::setPoints(int a){
    this->points=a;
}
