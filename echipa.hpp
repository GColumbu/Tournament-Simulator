#include "player.hpp"
class echipa {
    int numberPlayers;
    string teamName;
    player* players=NULL;
public:
    friend istream & operator>>(istream &, echipa&);
    friend ostream & operator<<(ostream &, echipa&);
    echipa & operator=(const echipa &);
    string getTeamName();
    int getNumberPlayers();
    player* getPlayers();
    float getPoints();
};
