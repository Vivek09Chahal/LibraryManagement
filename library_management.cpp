#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string id, name, author, search;
    fstream file;
    public:
        void add_book();
        void showAll();
        void extractBook();
}obj;

void temp::add_book(){
    cout << "Enter Book ID: ";
    getline(cin, id);
    cout << "\nEnter Book Name: ";
    getline(cin, name);
    cout << "\nEnter Book Author: ";
    getline(cin, author);

    file.open( "books.txt", ios::out | ios::app );
    file << id << "*" << name << "*" << author << endl;
    file.close();
}

void temp::showAll(){
    file.open( "books.txt", ios::in );
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, author, '*');
    cout << "\n\n";
    cout << "\t\t Book ID: \t\t Book Name \t\t\t Aurthor's Name" << endl;
    while (!file.eof()){
        cout <<"\t\t" << id << "\t\t\t" << name << "\t\t\t" << author << endl;
    }
    file.close();
}

void temp::extractBook(){

    showAll();
    cout << "Enter Book ID: ";
    getline(cin, search);

    file.open( "books.txt", ios::in );
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, author, '*');

    cout << "\n\n";
    cout << "\t\t Book ID: \t\t Book Name \t\t\t Aurthor's Name" << endl;
    while(!file.eof()){
        if(search == id){
            cout <<"\t\t" << id << "\t\t\t" << name << "\t\t\t" << author << endl;
            cout << "Book Extracted Successfullt...!";
        }
        getline(file, id, '*');
        getline(file, name, '*');
        getline(file, author, '*');
    }
    file.close();
}

int main(){

    char choice;
    cout << "---------------------------" << endl;
    cout << "1- Show all books" << endl;
    cout << "2- Select A  Book" << endl;
    cout << "3- Add A Book(ADMIN)" << endl;
    cout << "4- Exit" << endl;
    cout << "---------------------------" << endl;
    cin >> choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.showAll();
        break;
    case '2':
        cin.ignore();
        obj.extractBook();
    break;
    case '3':
        cin.ignore();
        obj.add_book();
    break;
    case '4':
        return 0;
    break;
    default:
        cout << "Invalid Choice...!" << endl;
    }

    return 0;
}