#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
void manage(string libraryFile, string bookFile, string authorFile)
{
    fstream libary(libraryFile, ios_base::in);
    fstream book(bookFile, ios_base::in);
    fstream author(authorFile, ios_base::in);
    struct Library
    {
        string name;
        int listBook[5];
    };
    Library listLib[100];

    int inidexLib = 0;
    int numOfLib = 0;
    string str;
    getline(libary, str);
    stringstream ss(str);
    ss >> numOfLib;
    ss.clear();
    while (!libary.eof())
    {
        getline(libary, str);
        ss.str(str);
        ss >> listLib[inidexLib].name;
        for (int i = 0; i < 5; i++)
            ss >> listLib[inidexLib].listBook[i];
        inidexLib++;
        ss.clear();
    }
    libary.close();
    //cout << "num of lib: " << numOfLib << endl;
    /* for (int i = 0; i < numOfLib; i++)
    {
        cout << listLib[i].name << " ";
        for (int j = 0; j < 5; j++)
        {
            cout << listLib[i].listBook[j] << " ";
        }
        cout << endl;
    } */
    struct Book
    {
        int iD;
        int year;
        char type;
    };
    Book listBook[100];
    int indexBook = 0;
    int numOfBook = 0;
    str.clear();
    getline(book, str);
    ss.clear();
    ss.str(str);
    ss >> numOfBook;
    while (!book.eof())
    {
        ss.clear();
        getline(book, str);
        ss.str(str);
        ss >> listBook[indexBook].iD;
        ss >> listBook[indexBook].year;
        ss >> listBook[indexBook].type;
        ss.clear();
        indexBook++;
    }
    book.close();
   /*  for (int i = 0; i < numOfBook; i++)
    {
        cout << listBook[i].iD << " "
             << listBook[i].year << " "
             << listBook[i].type << endl;
    } */
    struct Author
    {
        string name;
        int book[100];
        int numBook = 0;
    };
    Author listAuthor[100];
    int indexAuthor = 0;
    int numOfAuthor = 0;
    int indexBookOfAuthor = 0;
    str.clear();
    ss.clear();
    getline(author, str);
    ss.str(str);
    ss >> numOfAuthor;
    while (!author.eof())
    {
        str.clear();
        ss.clear();
        getline(author, str);
        ss.str(str);
        ss >> listAuthor[indexAuthor].name;
        while (!ss.eof())
        {
            str.clear();
            ss.clear();
            ss >> listAuthor[indexAuthor].book[indexBookOfAuthor];
            listAuthor[indexAuthor].numBook++;
            indexBookOfAuthor++;
        }
        indexAuthor++;
        indexBookOfAuthor = 0;
    }
    /* for (int i = 0; i < numOfAuthor; i++)
    {
        cout << listAuthor[i].name << " ";
        for (int j = 0; j < listAuthor[i].numBook; j++)
            cout << listAuthor[i].book[j] << " ";
        cout << endl;
    } */
    string libName;
    string authorName;
    cin >> libName;
    cin >> authorName;
    for (int i = 0; i < numOfLib; i++)
    {
        if (libName == listLib[i].name)
        {
            for(int j = 0; j < numOfAuthor; j++)
            {
                if(authorName == listAuthor[j].name)
                {
                    for (int q = 0; q < listAuthor[j].numBook;q++)
                    {
                        for (int p = 0; p < 5; p++)
                        {
                            if (listAuthor[j].book[q] == listLib[i].listBook[p])
                                cout << "True";
                                return;
                        }        
                    }
                }
            }
        }
    }
    cout <<"False";
    return;
}
int main()
{
    fstream input("input.txt",ios_base::in);
    string str;
    getline(input,str);
    stringstream ss;
    ss.str(str);
    string output;
    output = ss.str();
    cout << output << endl << str;
}