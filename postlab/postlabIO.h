#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int checkGrade(float *arr)
{

    float ave = 0;
    bool error = false;
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] < 5)
        {
            error = true;
            break;
        }
    }
    if (error)
    {
        return 1;
    }
    else
    {

        for (int i = 0; i < 4; i++)
            ave += arr[i];
        ave = ave / 4;
    }
    if (ave >= 8)
        return 4;
    if (ave >= 6.5)
        return 3;
    if (ave >= 5)
        return 2;
}
void studentGrading(string fileName)
{
    int a, b, c, d;
    a = b = c = d = 0;
    fstream fs(fileName, ios_base::in);
    float arr[100][4];
    int row;
    if (fs.is_open())
    {
        while (!fs.eof())
        {
            fs >> row;
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < 4; j++)
                    fs >> arr[i][j];
            }
        }
    }
    fs.close();
    for (int i = 0; i < row; i++)
    {
        int check = checkGrade(arr[i]);
        switch (check)
        {
        case 1:
            d++;
            break;
        case 2:
            c++;
            break;
        case 3:
            b++;
            break;
        default:
            a++;
            break;
        }
    }
    cout << "A " << a << endl;
    cout << "B " << b << endl;
    cout << "C " << c << endl;
    cout << "D " << d << endl;
}