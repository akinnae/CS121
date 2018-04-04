#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace std;

class node{
public:
	string title;
	int startdate;
	int enddate;
	string category;
	string actor [15];
	node * left;
	node * right;
    node(){
        title = "TITLE";
        startdate = 0;
        enddate = 0;
        category = "CATEGORY";
        for(int i=0; i<15; i++){
            actor[i] = "ACTOR";}
        left = NULL;
        right = NULL;
    }
	void addnode(node * n){
        if ((n->title)<title){
            if(left==NULL){
                left=n;
            }else{
                left->addnode(n);}
        }else{
            if(right==NULL){
                right=n;
            }else{
                right->addnode(n);}
        }
    }
    void pdate(){cout<<startdate<<"-"<<enddate;}
    void ptitle(){cout<<title;}
    void pcategory(){cout<<category;}
    void pactors(){
        for(int i=0; i<15; i++){
            if(actor[i]!="ACTOR")
                cout<<actor[i]<<endl;
        }
    }
    void print(){
        ptitle();
        cout<<" (";
        pdate();
        cout<<")"<<endl;
        pcategory();
        cout<<endl;
        pactors();
        cout<<endl;
    }
    void printbytitles(){
        if(left!=NULL)
            left->printbytitles();
        if(title!="j")
            cout<<title<<endl;
        if(right!=NULL)
            right->printbytitles();
    }
    void printbyactor(string name){
        if(left!=NULL)
            left->printbyactor(name);
        for(int i=0; i<15; i++){
            if(actor[i]==name){
                ptitle();
                cout<<endl;
            }
        }
        if(right!=NULL)
            right->printbyactor(name);
    }
    void printbytitle(string name){
        if(left!=NULL)
            left->printbytitle(name);
        if(title==name){
            pactors();
            cout<<endl;
        }
        if(right!=NULL)
            right->printbytitle(name);
    }
    void printbydate(int date1, int date2){
        if(left!=NULL)
            left->printbydate(date1, date2);
        if((startdate>=date1)&&(startdate<=date2))
            cout<<title<<" "<<startdate<<"-"<<enddate<<endl;
        if(right!=NULL)
            right->printbydate(date1, date2);
    }
};
