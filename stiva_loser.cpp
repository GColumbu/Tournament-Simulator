#include "stiva_loser.hpp"
void addLoser(losers *& top, echipa temp){
    losers* newNode;
    newNode=new losers;
    newNode->team=temp;
    newNode->next=top;
    top=newNode;
}
echipa losers::getTeam(){
    return team;
}
losers* losers::getNext(){
    return next;
}
echipa deleteLoser(losers *& top){
    losers* temp=top;
    echipa aux;
    aux=temp->team;
    top=top->next;
    delete temp;
    return aux;
}
void showLosers(losers *top, char *cale, int m){
    losers *p;
    int n;
    ofstream file(cale, ios::app);
    if(!file){
        cerr<<"Eroare la deschiderea fisierului!";
    }
    file<<"---LOSERS OF ROUND NO:"<<m<<endl;
    for(p=top; p!=NULL; p=p->next){
        file<<p->team.getTeamName();
        n=p->team.getTeamName().length();
        for(int i=0; i< 35-n; i++){
            file<<" ";
        }
        file<<"-   "<<p->team.getPoints()<<endl;
    }
    file<<endl;
    file.close();
}
void deleteLosers(losers *& top){
    losers *q;
    for(q=top; q!=NULL; q=q->getNext()){
        deleteLoser(top);
    }
}
