#include "lista.hpp"
lista* makeList(ifstream &file, int &nr){
    lista *head, *p;
    /*ifstream file("d.in");
    if(!file){
        cerr<<"Eroare la deschiderea fisierului!";
    }*/
    file>>nr;
    p=new lista;
    file>>p->team;
    p->next=NULL;
    head=p;
    for(int i=1;i<nr;i++){
 		p=new lista;
 		file>>p->team;
 		p->next=head;
 		head=p;
	}
    return head;
}
void showList(lista *head, ofstream &file){
    /*ofstream file(cale);
    if(!file){
        cerr<<"Eroare la deschiderea fisierului!";
    }*/
    lista *p;
    for(p=head; p!=NULL; p=p->next){
        file<<p->team.getTeamName()<<endl;
    }
}
void deleteMemberMin(lista *&head){
    lista* p;
    float minim=head->team.getPoints();
    for(p=head->next; p!=NULL; p=p->next){
        if(minim>p->team.getPoints()){
            minim=p->team.getPoints();
        }
    }
    for(p=head; p->next!=NULL; p=p->next){
        if(p->team.getPoints()==minim&&p==head){
            head=p->next;
            delete p;
            break;
        }
        if(p->next->team.getPoints()==minim&&p->next->next==NULL){
            delete p->next;
            p->next=NULL;
            break;
        }
        if(p->next->team.getPoints()==minim){
            lista *q;
            q=p->next;
            p->next=p->next->next;
            delete q;
            break;
        }
    }
}
int deleteAll(lista *&head, int nr){
    /*ifstream file("d.in");
    if(!file){
        cerr<<"Eroare la deschiderea fisierului!";
    }*/
    int nmax=1;
    while(true){
        nmax*=2;
        if(nmax>nr){
            nmax/=2;
            break;
        }
    }
    for(int i=0; i<(nr-nmax); i++){
        deleteMemberMin(head);
    }
    return nmax;
}
echipa lista::getTeam(){
    return team;
}
lista* lista::getNext(){
    return next;
}
