#include "BST.hpp"
lista* makeList(ifstream &, int &);
coada* makeCoada();
BST* makeTree(winners *);
void showList(lista *, ofstream&);
void deleteMemberMin(lista *&);
void addMembers(coada*, lista*);
int deleteAll(lista *&, int);
int main(int argc, char **argv){
    string in_File = argv[2];
    string out_File = argv[3];
    string checker_File = argv[1];
    ifstream file_In(in_File);
    ifstream checker_In(checker_File);
    ofstream file_Out(out_File);
    BST *root;
    lista *l;
    coada *c=NULL;
    int nr, n, m=1, checker[5];
    //ifstream file_In("d.in");
    if(!checker_In){
        cerr<<"Eroare la deschiderea fisierului!";
    }
    for(int i=0; i<5; i++){
        checker_In>>checker[i];
    }
    if(!file_In){
        cerr<<"Eroare la deschiderea fisierului!";
    }
    if(!file_Out){
        cerr<<"Eroare la deschiderea fisierului!";
    }
    if(checker[0]==1){
        l=makeList(file_In, nr);
    }
    if(checker[1]==1)
        n=deleteAll(l, nr);
    showList(l, file_Out);
    //cout<<nr;
    //showList(l, "Lista_Intreaga.out");
    //n=deleteAll(l, nr);
    //showList(l, file_Out);
    if(checker[2]==1){
        c=makeCoada();
        addMembers(c, l);
        winners* top_Winners=NULL;
        losers* top_Losers=NULL;
        while(n>=2){
            showCoada(c, file_Out, m);
            addStive(c, top_Winners, top_Losers);
            if(n==16){
                root=makeTree(top_Winners);
            }
            //showLosers(top_Losers, "r.out", m);
            showWinners(top_Winners, file_Out, m);
            deleteLosers(top_Losers);
            deleteCoada(c);
            if(n>=4)
                addWinners(c, top_Winners);
            deleteWinners(top_Winners);
            m++;
            n/=2;
        }
        if(checker[3]==1){
            file_Out<<endl<<"TOP 8 TEAMS:"<<endl;
            showTree(root, file_Out);
        }
    }
    /*ofstream file("r.out", ios::app);
    if(!file){
        cerr<<"Eroare la deschiderea fisierului!";
    }*/
    //file.close();
    return 0;
}
