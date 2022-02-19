#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
void printPrice(int arr[][2], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i][0] << " " << arr[i][1] << endl;
    }
}
void calMoney(string priceFile, string buyFile)
{
    fstream price(priceFile, ios_base::in);
    fstream buy(buyFile, ios_base::in);
    int numItem;
    int arrPrice[100][2];
    while (!price.eof())
    {
        price >> numItem;
        int priceOfItem = 0;
        for (int i = 0; i < numItem; i++)
        {
            price >> arrPrice[i][priceOfItem++];
            price >> arrPrice[i][priceOfItem++];
            priceOfItem = 0;
        }
    }
    price.close();
    struct customer
    {
        string name;
        int product[100][2];
        int numOfProduct = 0;
        int needToPay = 0;
    };
    customer data[100];
    int numOfCustomer;
    int indexCustomer = 0;
    string temp;
    getline(buy, temp);
    stringstream getnum(temp);
    getnum >> numOfCustomer;
    while (!buy.eof())
    {
        int indexProduct = 0;
        string getl;
        getline(buy, getl);
        stringstream ss(getl);
        ss >> data[indexCustomer].name;
        while (!ss.eof())
        {
            ss >> data[indexCustomer].product[indexProduct][0];
            ss >> data[indexCustomer].product[indexProduct++][1];
            data[indexCustomer].numOfProduct++;
        }
        indexProduct = 0;
        indexCustomer++;
    }
    buy.close();
    for (int i = 0; i < numOfCustomer; i++)
    {
        for (int j = 0; j < data[i].numOfProduct; j++)
        {
            data[i].needToPay += arrPrice[(data[i].product[j][0]-1)][1] * data[i].product[j][1];
        }
        cout << data[i].name << " " << data[i].needToPay << endl;
    }
}

int main()
{
    string price = "price.txt";
    string buy = "buy.txt";
    calMoney(price, buy);
}