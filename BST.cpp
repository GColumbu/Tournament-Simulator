#include "BST.hpp"
BST::BST(echipa a){
    team=a;
    left=right=NULL;
}
BST* Insert(BST* root, echipa a){
    if (!root){
        return new BST(a);
    }
    if (a.getPoints()>root->team.getPoints())  {
        root->right=Insert(root->right, a);
    }
    else if(a.getPoints()<root->team.getPoints()){
        root->left=Insert(root->left, a);
    }
    else if(a.getPoints()==root->team.getPoints()){
        if (a.getTeamName()>root->team.getTeamName())  {
            root->right=Insert(root->right, a);
        }
        else if(a.getTeamName()<root->team.getTeamName()){
            root->left=Insert(root->left, a);
        }
    }
    return root;
}
BST* makeTree(winners *w){
    BST *root=NULL;
    winners *p;
    p=w;
    root=Insert(root, p->getTeam());
    p=p->getNext();
    for(; p!=NULL; p=p->getNext()){
        Insert(root, p->getTeam());
    }
    return root;
}
void showTree(BST* root, ofstream &file){
    /*ofstream file("r.out", ios::app);
    if(!file){
        cerr<<"Eroare la deschiderea fisierului!";
    }*/
    int n;
    if(!root){
        return;
    }
    showTree(root->right, file);
    file<<root->team.getTeamName();
        n=root->team.getTeamName().length();
        for(int i=0; i<34-n; i++){
            file<<" ";
        }
    file<<"-  "<<setprecision(2)<<fixed<<root->team.getPoints()<<endl;
    showTree(root->left, file);
}
