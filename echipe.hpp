#include "lista.hpp"
class echipe{
    echipa team1;
    echipa team2;
    echipe *next;
public:
    void setTeam1(echipa);
    void setTeam2(echipa);
    void setNext(echipe*);
    echipa getTeam1();
    echipa getTeam2();
    echipe* getNext();
};
