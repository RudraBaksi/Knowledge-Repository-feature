//Program to manage article by Rudra Prasad Baksi//
#include<iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>

using namespace std;

class General_access{
public:
int choice;
void modify_article()
{
    ostringstream text;
    cout << "Enter the name of the article you want to edit:" << '\n';
    string filename;
    cin >> filename;
    int siz=filename.size()+1;
    cin.ignore(siz,'\n');
    ifstream in_file(filename);
    text << in_file.rdbuf();
    string str = text.str();
    cout << "Enter the text which you want to modify:" << '\n';
    string target;
    getline(cin,target);
    cout << "Enter the text you want to replace the old text with:" << '\n';
    string mod_txt;
    getline(cin,mod_txt);
    string str_search = target;
    string str_replace = mod_txt;
    size_t pos = str.find(str_search);
    if (pos == string::npos){
    cout << "Input given by user was not correct" << '\n';
    return;
    }
    cout << "Modification successfully performed" << '\n';
    str.replace(pos, string(str_search).length(), str_replace);
    in_file.close();
    ofstream out_file(filename);
    out_file << str;     
}

void delete_article()
{
    int status;
    char fileName[100];
    cout<<"Enter the Name of article: ";
    cin>>fileName;
    status = remove(fileName);
    if(status==0)
        cout<<"\nFile Deleted Successfully!";
    else
        cout<<"\nError Occurred! as the above file doesn't exist";
}

};

int main()
{
    cout << "------WELCOME TO MY FILE MANAGER------" <<'\n';
    cout << "------THIS IS THE INTEFACE DESIGNED FOR GENERAL USER-------";
    cout << "\nIf you want to delete an article then press 1----If you want to modify an article press 2:"<< '\n' ;
    General_access g;
    cin >> g.choice;
    cin.ignore(1, '\n');
   if(g.choice==1)
   {
   g.delete_article();    
   }
   else if(g.choice==2)
   {
   g.modify_article();    
   }
   return 0; 
}