#include <vector>
#include <stdio.h>
using namespace std;


bool locate_queen(vector<int> &board, int row, int col) {
    for (int i = 0; i < row; i++) 
    {
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row)  // Проверка на возможность размещения ферзя
        {  
            return false;
        }
    }
    return true;
}


void place_queens(vector<int> &board, int row, int &count) {
    if (row == 8)
    {
        count++;  // Как только вариант решён, добавляет его к общему количеству
    }

    for (int col = 0; col < 8; col++)
    {
        if (locate_queen(board, row, col))  // Проверяет, можно ли разместить ферзя
        {
            board[row] = col;
            place_queens(board, row + 1, count);  // Передаёт ферзя с безопасной позицией, опуская на 1 строку
        }
    }
}


int main()
{
    vector<int> board(8, 0);  // Вектор, отвечающий за поле
    int count = 0;  // Количество решений

    place_queens(board, 0, count);
    printf("Всего решений: %d\n", count);  // Вывод
    
    return 0;
}
