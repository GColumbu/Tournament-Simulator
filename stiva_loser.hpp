#include "echipe.hpp"
class losers{
    echipa team;
    losers *next;
public:
    friend void addLoser(losers*&, echipa);
    friend echipa deleteLoser(losers *&);
    friend void deleteLosers(losers *&);
    friend void showLosers(losers *, char*, int);
    echipa getTeam();
    losers* getNext();
};
