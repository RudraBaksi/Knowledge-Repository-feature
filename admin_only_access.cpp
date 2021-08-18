//Program to manage article by Rudra Prasad Baksi//
#include<iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>

using namespace std;

int main(){
    cout << "------WELCOME TO MY FILE MANAGER------" <<'\n';
    cout << "------THIS IS THE INTEFACE DESIGNED FOR ADMINISTRATOR ONLY-------"<<'\n';
    cout << "\nProceed to add an article to the repository:"<< '\n' ;
    ofstream fout;
    ifstream fin; 
   ofstream file;
   cout << "Give a name to the article:" << '\n';
   string name;
   cin >> name;
   int siz=name.size()+1;
   cin.ignore(siz,'\n');
   ifstream ifile(name);
   if(ifile){
       cout << "Article already exists and proceed to modify function in general user module to modify it\n";
       return 0;
   }
   cout << "Enter contents of the article you have created:" << '\n';
   file.open(name);
   string text;
   getline(cin,text);
   file << text;
   file.close();
   cout << "Article was created and contents were added successfully" << '\n';
   fin.close();
    fout.close(); 
}