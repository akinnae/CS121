#include <iostream>
#include "class.cpp"
using namespace std;

node * readin(string);

int main(){
    node * root;
    root = readin("TVdata.txt");
    cout<<"All titles:"<<endl;
    root->printbytitles();
    cout<<endl<<"Printing shows with Majel Barrett..."<<endl;
    root->printbyactor("Majel Barrett");
    cout<<endl<<"Printing shows with Angela Cartwright..."<<endl;
    root->printbyactor("Angela Cartwright");
    cout<<endl<<"Printing shows with Mark Harmon..."<<endl;
    root->printbyactor("Mark Harmon");
    cout<<endl<<"Printing shows with Bill Mumy..."<<endl;
    root->printbyactor("Bill Mumy");
    cout<<endl<<"Printing shows with Alan Young..."<<endl;
    root->printbyactor("Alan Young");
    cout<<endl<<"Printing shows with Andy Griffith..."<<endl;
    root->printbyactor("Andy Griffith");
    cout<<endl<<"Printing actors in The Office..."<<endl;
    root->printbytitle("The Office  ");
    cout<<endl<<"Printing actors in The Prisoner..."<<endl;
    root->printbytitle("The Prisoner  ");
    cout<<endl<<"Printing actors in Lost..."<<endl;
    root->printbytitle("Lost ");
    cout<<endl<<"Printing shows released between 1972 & 1982..."<<endl;
    root->printbydate(1972, 1982);
    cout<<endl<<"Printing shows released between 2001 & 2011..."<<endl;
    root->printbydate(2001, 2011);
}

node * readin (string filename){
    char dump;
    string sdump;
    string stemp;
    ifstream infile;
    infile.open(filename);
    node * temp;
    node * root = new node;
    root->title="j";
    while(!infile.eof()){
        temp=new node;
        getline(infile, temp->title,'(');
        infile>>temp->startdate;
        infile>>dump;
        infile>>temp->enddate;
        infile>>dump;
        getline(infile,sdump);
        getline(infile,temp->category);
        getline(infile,sdump);
        for (int i=0; i<15; i++){
            getline(infile, stemp);
            if(stemp==""){i=15;}
            else{temp->actor[i]=stemp;}
        }
 //       temp->print();
        root->addnode(temp);
    }
    return root;
}

