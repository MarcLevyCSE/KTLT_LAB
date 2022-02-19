#include <iostream>
using namespace std;
bool checkSubMatrix(int arr[][1000], int indexRow, int indexCol)
{
    int result = arr[indexRow][indexCol] + arr[indexRow][indexCol + 1] +
                 arr[indexRow + 1][indexCol] + arr[indexRow + 1][indexCol + 1];
    if (result % 2 == 1)
        return true;
    return false;
}
bool checkPrime(int num)
{
    if (num < 0)
        return false;
    if (num == 0 || num == 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (int i = 3; i < num / 2; i = i + 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
int specialCells(int arr[][1000], int row, int col)
{
    unsigned int countRow, countCol;
    countCol = countRow = 0;
    int sumRow, sumCol;
    sumRow = sumCol = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sumRow += arr[i][j];
        }
        if (checkPrime(sumRow))
            countRow++;
        sumRow = 0;
    }
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            sumCol += arr[j][i];
        }
        if (checkPrime(sumCol))
            countCol++;
        sumCol = 0;
    }
    return countCol * countRow;
}
int subMatrix(int arr[][1000], int row, int col)
{
    int result = 0;
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = 0; j < col - 1; j++)
        {
            if (checkSubMatrix(arr, i, j))
                result++;
        }
    }
    return result;
}
int main()
{
    int arr[][1000] = {{66, 16, 71}, 
                        {25, 81, 61}, 
                        {2, 10, 34}};
    cout << subMatrix(arr, 3, 3);
}
