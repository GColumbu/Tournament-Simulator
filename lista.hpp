#include "echipa.hpp"
class lista{
    echipa team;
    lista *next;
public:
    friend lista* makeList(ifstream &, int &);
    friend void showList(lista *, ofstream&);
    friend void deleteMemberMin(lista *&);
    friend int deleteAll(lista *&, int);
    echipa getTeam();
    lista* getNext();
};
