#include "Chess.h"
#include <iostream>
#include <string>

Chess::Chess()
{
    row = 0;
    column = 0;
    prevrow = 0;
    prevcol = 0;
    matrix[0][0] = "bR";
    matrix[0][1] = "bN";
    matrix[0][2] = "bB";
    matrix[0][3] = "bQ";
    matrix[0][4] = "bK";
    matrix[0][5] = "bB";
    matrix[0][6] = "bN";
    matrix[0][7] = "bR";
    for (int i = 0; i < 8; i++)
    {
        matrix[1][i] = "bP";
    }
    matrix[7][0] = "wR";
    matrix[7][1] = "wN";
    matrix[7][2] = "wB";
    matrix[7][3] = "wQ";
    matrix[7][4] = "wK";
    matrix[7][5] = "wB";
    matrix[7][6] = "wN";
    matrix[7][7] = "wR";
    for (int j = 0; j < 8; j++)
    {
        matrix[6][j] = "wP";
    }
    for (int k = 0; k < 8; k++)
    {
        for (int m = 0; m < 8; m++)
        {
            if (matrix[m][k] != "wR" && matrix[m][k] != "wN" && matrix[m][k] != "wB" && matrix[m][k] != "wQ" && matrix[m][k] != "wK" && matrix[m][k] != "wP" && matrix[m][k] != "bR" && matrix[m][k] != "bN" && matrix[m][k] != "bB" && matrix[m][k] != "bQ" && matrix[m][k] != "bK" && matrix[m][k] != "bP")
            {
                matrix[m][k] = "  ";
            }
        }
    }
}

void Chess::Showboard()
{
    std::cout << "   ---------------------------------------" << std::endl;
    int row = 0;
    int sym1 = 1;
    int i = 0;
    while (row != 8)
    {
        std::cout << " " << sym1 << "|  " << matrix[i][0] << "|  " << matrix[i][1] << "|  " << matrix[i][2] << "|  " << matrix[i][3] << "|  " << matrix[i][4] << "|  " << matrix[i][5] << "|  " << matrix[i][6] << "|  " << matrix[i][7] << "|  " << std::endl;
        std::cout << "   ---------------------------------------" << std::endl;
        sym1++;
        row++;
        i++;
    }
    std::cout << "    a "
              << "   b "
              << "   c "
              << "   d "
              << "   e "
              << "   f "
              << "   g "
              << "   h " << std::endl;
}

bool Chess::Check(int row, int column)
{
    if (matrix[row][column] == "wP")
    {
        if (matrix[row - 1][column + 1] == "bK")
        {
            std::cout << "CHECK";
            return true;
        }
        if (matrix[row - 1][column - 1] == "bK")
        {
            std::cout << "CHECK";
            return true;
        }
    }
    if (matrix[row][column] == "bP")
    {
        if (matrix[row + 1][column + 1] == "wK")
        {
            std::cout << "CHECK";
            return true;
        }
        if (matrix[row + 1][column - 1] == "wK")
        {
            std::cout << "CHECK";
            return true;
        }
    }
    if (matrix[row][column] == "wR")
    {
        int j = row + 1;
        while (matrix[j][column] == "  ")
        {
            ++j;
        }
        if (matrix[j][column] != "  ")
        {
            if (matrix[j][column] == "bK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        j = row - 1;
        while (matrix[j][column] == "  ")
        {
            --j;
        }
        if (matrix[j][column] != "  ")
        {
            if (matrix[j][column] == "bK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        j = column + 1;
        while (matrix[row][j] == "  ")
        {
            ++j;
        }
        if (matrix[row][j] == "bK")
        {
            std::cout << "CHECK" << std::endl;
            return true;
        }
        j = column - 1;
        while (matrix[row][column] == "  ")
        {
            --j;
        }
        if (matrix[row][j] == "bK")
        {
            std::cout << "CHECK" << std::endl;
            return true;
        }
    }

    if (matrix[row][column] == "bR")
    {
        int j = row + 1;
        while (matrix[j][column] == "  ")
        {
            ++j;
        }
        if (matrix[j][column] != "  ")
        {
            if (matrix[j][column] == "wK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        j = row - 1;
        while (matrix[j][column] == "  ")
        {
            --j;
        }
        if (matrix[j][column] != "  ")
        {
            if (matrix[j][column] == "wK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        j = column + 1;
        while (matrix[row][j] == "  ")
        {
            ++j;
        }
        if (matrix[row][j] == "wK")
        {
            std::cout << "CHECK" << std::endl;
            return true;
        }
        j = column - 1;
        while (matrix[row][column] == "  ")
        {
            --j;
        }
        if (matrix[row][j] == "wK")
        {
            std::cout << "CHECK" << std::endl;
            return true;
        }
    }
    if (matrix[row][column] == "wN")
    {
        if (matrix[row - 2][column - 1] == "bK" || matrix[row - 2][column + 1] == "bK" || matrix[row - 1][column + 2] == "bK" || matrix[row - 1][column - 2] == "bK" || matrix[row + 1][column + 2] == "bK" || matrix[row + 1][column - 2] == "bK" || matrix[row + 2][column - 1] == "bK" || matrix[row + 2][column + 1] == "bK")
        {
            std::cout << "check" << std::endl;
            return true;
        }
    }
    if (matrix[row][column] == "bN")
    {
        if (matrix[row - 2][column - 1] == "wK" || matrix[row - 2][column + 1] == "wK" || matrix[row - 1][column + 2] == "wK" || matrix[row - 1][column - 2] == "wK" || matrix[row + 1][column + 2] == "wK" || matrix[row + 1][column - 2] == "wK" || matrix[row + 2][column - 1] == "wK" || matrix[row + 2][column + 1] == "wK")
        {
            std::cout << "CHECK" << std::endl;
            return true;
        }
    }
    if (matrix[row][column] == "bB")
    {
        int i = 1;
        while (matrix[row - i][column - i] == "  ")
        {
            ++i;
        }
        if (matrix[row - i][column - i] != "  ")
        {
            if (matrix[row - i][column - i] == "wK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        i = 1;
        while (matrix[row - i][column + i] == "  ")
        {
            ++i;
        }
        if (matrix[row - i][column + i] != "  ")
        {
            if (matrix[row - i][column + i] == "wK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        i = 1;
        while (matrix[row + i][column - i] == "  ")
        {
            ++i;
        }
        if (matrix[row + i][column - i] != "  ")
        {
            if (matrix[row - i][column + i] == "wK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        i = 1;
        while (matrix[row + i][column + i] == "  ")
        {
            ++i;
        }
        if (matrix[row + i][column + i] != "  ")
        {
            if (matrix[row - i][column + i] == "wK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
    }

    if (matrix[row][column] == "wB")
    {
        int i = 1;
        while (matrix[row - i][column - i] == "  ")
        {
            ++i;
        }
        if (matrix[row - i][column - i] != "  ")
        {
            if (matrix[row - i][column - i] == "bK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        i = 1;
        while (matrix[row - i][column + i] == "  ")
        {
            ++i;
        }
        if (matrix[row - i][column + i] != "  ")
        {
            if (matrix[row - i][column + i] == "bK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        i = 1;
        while (matrix[row + i][column - i] == "  ")
        {
            ++i;
        }
        if (matrix[row + i][column - i] != "  ")
        {
            if (matrix[row - i][column + i] == "bK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        i = 1;
        while (matrix[row + i][column + i] == "  ")
        {
            ++i;
        }
        if (matrix[row + i][column + i] != "  ")
        {
            if (matrix[row - i][column + i] == "bK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
    }
    if (matrix[row][column] == "wQ")
    {
        int j = row + 1;
        while (matrix[j][column] == "  ")
        {
            ++j;
        }
        if (matrix[j][column] != "  ")
        {
            if (matrix[j][column] == "bK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        j = row - 1;
        while (matrix[j][column] == "  ")
        {
            --j;
        }
        if (matrix[j][column] != "  ")
        {
            if (matrix[j][column] == "bK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        j = column + 1;
        while (matrix[row][j] == "  ")
        {
            ++j;
        }
        if (matrix[row][j] == "bK")
        {
            std::cout << "CHECK" << std::endl;
            return true;
        }
        j = column - 1;
        while (matrix[row][column] == "  ")
        {
            --j;
        }
        if (matrix[row][j] == "bK")
        {
            std::cout << "CHECK" << std::endl;
            return true;
        }
        int i = 1;
        while (matrix[row - i][column - i] == "  ")
        {
            ++i;
        }
        if (matrix[row - i][column - i] != "  ")
        {
            if (matrix[row - i][column - i] == "bK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        i = 1;
        while (matrix[row - i][column + i] == "  ")
        {
            ++i;
        }
        if (matrix[row - i][column + i] != "  ")
        {
            if (matrix[row - i][column + i] == "bK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        i = 1;
        while (matrix[row + i][column - i] == "  ")
        {
            ++i;
        }
        if (matrix[row + i][column - i] != "  ")
        {
            if (matrix[row - i][column + i] == "bK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        i = 1;
        while (matrix[row + i][column + i] == "  ")
        {
            ++i;
        }
        if (matrix[row + i][column + i] != "  ")
        {
            if (matrix[row - i][column + i] == "bK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
    }

    if (matrix[row][column] == "bQ")
    {
        int j = row + 1;
        while (matrix[j][column] == "  ")
        {
            ++j;
        }
        if (matrix[j][column] != "  ")
        {
            if (matrix[j][column] == "wK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        j = row - 1;
        while (matrix[j][column] == "  ")
        {
            --j;
        }
        if (matrix[j][column] != "  ")
        {
            if (matrix[j][column] == "wK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        j = column + 1;
        while (matrix[row][j] == "  ")
        {
            ++j;
        }
        if (matrix[row][j] == "wK")
        {
            std::cout << "CHECK" << std::endl;
            return true;
        }
        j = column - 1;
        while (matrix[row][column] == "  ")
        {
            --j;
        }
        if (matrix[row][j] == "wK")
        {
            std::cout << "CHECK" << std::endl;
            return true;
        }
        int i = 1;
        while (matrix[row - i][column - i] == "  ")
        {
            ++i;
        }
        if (matrix[row - i][column - i] != "  ")
        {
            if (matrix[row - i][column - i] == "wK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        i = 1;
        while (matrix[row - i][column + i] == "  ")
        {
            ++i;
        }
        if (matrix[row - i][column + i] != "  ")
        {
            if (matrix[row - i][column + i] == "wK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        i = 1;
        while (matrix[row + i][column - i] == "  ")
        {
            ++i;
        }
        if (matrix[row + i][column - i] != "  ")
        {
            if (matrix[row - i][column + i] == "wK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
        i = 1;
        while (matrix[row + i][column + i] == "  ")
        {
            ++i;
        }
        if (matrix[row + i][column + i] != "  ")
        {
            if (matrix[row - i][column + i] == "wK")
            {
                std::cout << "CHECK" << std::endl;
                return true;
            }
        }
    }
    return false;
}

bool Chess::IsValidPawnWite(int row, int column, int prevrow, int prevcol)
{
    if (row == prevrow - 1 && column == prevcol + 1)
    {
        if (matrix[row][column] == "bR" || matrix[row][column] == "bN" || matrix[row][column] == "bB" || matrix[row][column] == "bQ" || matrix[row][column] == "bK", matrix[row][column] == "bP")
        {
            return true;
        }
    }
    if (row == prevrow - 1 || row == prevrow - 2)
    {
        if (matrix[row][column] == "  " && column == prevcol)
        {
            return true;
        }
    }
    if (row == prevrow - 1 && column == prevcol - 1 && matrix[row][column] != "  ")
    {
        return true;
    }
    if (row == 0)
    {
        std::string piece;
        std::cout << "enter the piece ";
        std::cin >> piece;
        if (piece == "wQ")
        {
            matrix[row][column] = "wQ";
        }
        if (piece == "wN")
        {
            matrix[row][column] = "wN";
        }
        if (piece == "wR")
        {
            matrix[row][column] = "wR";
        }
        if (piece == "wB")
        {
            matrix[row][column] = "wB";
        }
    }
    return false;
}

bool Chess::IsValidPawnBlack(int row, int column, int prevrow, int prevcol)
{
    if (row == prevrow + 1 && column == prevcol + 1)
    {
        if (matrix[row][column] == "wR" || matrix[row][column] == "wN" || matrix[row][column] == "wB" || matrix[row][column] == "wQ" || matrix[row][column] == "wK" || matrix[row][column] == "wP")
        {
            return true;
        }
    }
    if (row == prevrow + 1 || row == prevrow + 2)
    {

        if (matrix[row][column] == "  " && column == prevcol)
        {
            return true;
        }
    }
    if (row == prevrow + 1 && column == prevcol - 1 && matrix[row][column] != "  ")
    {
        return true;
    }
    if (row == 7)
    {
        std::string piece;
        std::cout << "enter the piece ";
        std::cin >> piece;
        if (piece == "bQ")
        {
            matrix[row][column] = "bQ";
        }
        if (piece == "bN")
        {
            matrix[row][column] = "bN";
        }
        if (piece == "bR")
        {
            matrix[row][column] = "bR";
        }
        if (piece == "bB")
        {
            matrix[row][column] = "bB";
        }
    }
    return false;
}

bool Chess::IsValidKnight(int row, int column, int prevrow, int prevcol)
{
    if (row == prevrow - 2 && column == prevcol - 1)
    {
        return true;
    }
    if (row == prevrow - 2 && column == prevcol + 1)
    {
        return true;
    }
    if (row == prevrow - 1 && column == prevcol + 2)
    {
        return true;
    }
    if (row == prevrow - 1 && column == prevcol - 2)
    {
        return true;
    }
    if (row == prevrow + 1 && column == prevcol - 2)
    {
        return true;
    }
    if (row == prevrow + 1 && column == prevcol + 2)
    {
        return true;
    }
    if (row == prevrow + 2 && column == prevcol + 1)
    {
        return true;
    }
    if (row == prevrow + 2 && column == prevcol - 1)
    {
        return true;
    }
    return false;
}

bool Chess::IsValidRook(int row, int column, int prevrow, int prevcol)
{
    if (prevrow > row && column == prevcol)
    {
        for (int j = prevrow - 1; j > row; j--)
        {
            if (matrix[j][column] != "  ")
            {
                return false;
            }
        }
        for (int i = 0; i < 8; i++)
        {
            if (row == prevrow - i && column == prevcol)
            {
                return true;
            }
        }
    }
    if (prevrow < row && column == prevcol)
    {
        for (int j = prevrow + 1; j < row; j++)
        {
            if (matrix[j][column] != "  ")
            {
                return false;
            }
        }
        for (int i = 0; i < 8; i++)
        {
            if (row == prevrow + i && column == prevcol)
            {
                return true;
            }
        }
    }

    if (row == prevrow && column > prevcol)
    {
        for (int j = prevcol + 1; j < column; j++)
        {
            if (matrix[row][j] != "  ")
            {
                return false;
            }
        }
        for (int i = 0; i < 8; i++)
        {
            if (row == prevrow && column == prevcol + i)
            {
                return true;
            }
        }
    }

    if (row == prevrow && column < prevcol)
    {
        for (int j = column + 1; j != prevcol; j++)
        {
            if (matrix[row][j] != "  ")
            {
                return false;
            }
        }
        for (int i = 0; i < 8; i++)
        {
            if (row == prevrow && column == prevcol - i)
            {
                return true;
            }
        }
    }
    return false;
}

bool Chess::IsValidBishop(int row, int column, int prevrow, int prevcol)
{
    if (row < prevrow && column < prevcol)
    {
        int j = 1;
        while (matrix[prevrow - j][prevcol - j] != matrix[row][column])
        {
            if (matrix[prevrow - j][prevcol - j] != "  ")
            {
                return false;
            }
            j++;
        }
        for (int i = 0; i < 8; i++)
        {
            if (row == prevrow - i && column == prevcol - i)
            {
                return true;
            }
        }
    }
    if (row < prevrow && column > prevcol)
    {
        int j = 1;
        while (matrix[prevrow - j][prevcol + j] != matrix[row][column])
        {
            if (matrix[prevrow - j][prevcol + j] != "  ")
            {
                return false;
            }
            j++;
        }
        for (int i = 0; i < 8; i++)
        {
            if (row == prevrow - i && column == prevcol + i)
            {
                return true;
            }
        }
    }
    if (row > prevrow && column > prevcol)
    {
        int j = 1;
        while (matrix[prevrow + j][prevcol + j] != matrix[row][column])
        {
            if (matrix[prevrow + j][prevcol + j] != "  ")
            {
                return false;
            }
            j++;
        }
        for (int i = 0; i < 8; i++)
        {
            if (row == prevrow + i && column == prevcol + i)
            {
                return true;
            }
        }
    }
    if (row > prevrow && column < prevcol)
    {
        int j = 1;
        while (matrix[prevrow + j][prevcol - j] != matrix[row][column])
        {
            if (matrix[prevrow + j][prevcol - j] != "  ")
            {
                return false;
            }
            j++;
        }
        for (int i = 0; i < 8; i++)
        {
            if (row == prevrow + i && column == prevcol - i)
            {
                return true;
            }
        }
    }
    return false;
}

bool Chess::IsValidQueen(int row, int column, int prevrow, int prevcol)
{
    if (prevrow > row && column == prevcol)
    {
        for (int j = prevrow - 1; j > row; j--)
        {
            if (matrix[j][column] != "  ")
            {
                return false;
            }
        }
        for (int i = 0; i < 8; i++)
        {
            if (row == prevrow - i && column == prevcol)
            {
                return true;
            }
        }
    }
    if (prevrow < row && column == prevcol)
    {
        for (int j = prevrow + 1; j < row; j++)
        {
            if (matrix[j][column] != "  ")
            {
                return false;
            }
        }
        for (int i = 0; i < 8; i++)
        {
            if (row == prevrow + i && column == prevcol)
            {
                return true;
            }
        }
    }
    if (row == prevrow && column > prevcol)
    {
        for (int j = prevcol + 1; j < column; j++)
        {
            if (matrix[row][j] != "  ")
            {
                return false;
            }
        }
        for (int i = 0; i < 8; i++)
        {
            if (row == prevrow && column == prevcol + i)
            {
                return true;
            }
        }
    }

    if (row == prevrow && column < prevcol)
    {
        for (int j = column + 1; j != prevcol; j++)
        {
            if (matrix[row][j] != "  ")
            {
                return false;
            }
        }
        for (int i = 0; i < 8; i++)
        {
            if (row == prevrow && column == prevcol - i)
            {
                return true;
            }
        }
    }
    if (row < prevrow && column < prevcol)
    {
        int j = 1;
        while (matrix[prevrow - j][prevcol - j] != matrix[row][column])
        {
            if (matrix[prevrow - j][prevcol - j] != "  ")
            {
                return false;
            }
            j++;
        }
        for (int i = 0; i < 8; i++)
        {
            if (row == prevrow - i && column == prevcol - i)
            {
                return true;
            }
        }
    }
    if (row < prevrow && column > prevcol)
    {
        int j = 1;
        while (matrix[prevrow - j][prevcol + j] != matrix[row][column])
        {
            if (matrix[prevrow - j][prevcol + j] != "  ")
            {
                return false;
            }
            j++;
        }
        for (int i = 0; i < 8; i++)
        {
            if (row == prevrow - i && column == prevcol + i)
            {
                return true;
            }
        }
    }
    if (row > prevrow && column > prevcol)
    {
        int j = 1;
        while (matrix[prevrow + j][prevcol + j] != matrix[row][column])
        {
            if (matrix[prevrow + j][prevcol + j] != "  ")
            {
                return false;
            }
            j++;
        }
        for (int i = 0; i < 8; i++)
        {
            if (row == prevrow + i && column == prevcol + i)
            {
                return true;
            }
        }
    }
    if (row > prevrow && column < prevcol)
    {
        int j = 1;
        while (matrix[prevrow + j][prevcol - j] != matrix[row][column])
        {
            if (matrix[prevrow + j][prevcol - j] != "  ")
            {
                return false;
            }
            j++;
        }
        for (int i = 0; i < 8; i++)
        {
            if (row == prevrow + i && column == prevcol - i)
            {
                return true;
            }
        }
        if (prevrow > row && column == prevcol)
        {
            for (int j = prevrow - 1; j > row; j--)
            {
                if (matrix[j][column] != "  ")
                {
                    return false;
                }
            }
            for (int i = 0; i < 8; i++)
            {
                if (row == prevrow - i && column == prevcol)
                {
                    return true;
                }
            }
        }
        if (prevrow < row && column == prevcol)
        {
            for (int j = prevrow; j < row; j++)
            {
                if (matrix[j][column] != "  ")
                {
                    return false;
                }
            }
            for (int i = 0; i < 8; i++)
            {
                if (row == prevrow + i && column == prevcol)
                {
                    return true;
                }
            }
        }
        if (row == prevrow && column > prevcol)
        {
            for (int j = prevcol; j < column; j++)
            {
                if (matrix[j][column] != "  ")
                {
                    return false;
                }
            }
            for (int i = 0; i < 8; i++)
            {
                if (row == prevrow && column == prevcol + i)
                {
                    return true;
                }
            }
        }
        if (row == prevrow && column < prevcol)
        {
            for (int j = column; j != prevcol; j--)
            {
                if (matrix[j][column] != "  ")
                {
                    return false;
                }
            }
            for (int i = 0; i < 8; i++)
            {
                if (row == prevrow && column == prevcol - i)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Chess::IsValidKing(int row, int column, int prevrow, int prevcol)
{
    if (row == prevrow - 1 && column == prevcol)
    {
        return true;
    }
    if (row == prevrow - 1 && column == prevcol + 1)
    {
        return true;
    }
    if (row == prevrow - 1 && column == prevcol - 1)
    {
        return true;
    }
    if (row == prevrow && column == prevcol + 1)
    {
        return true;
    }
    if (row == prevrow && column == prevcol - 1)
    {
        return true;
    }
    if (row == prevrow + 1 && column == prevcol)
    {
        return true;
    }
    if (row == prevrow + 1 && column == prevcol + 1)
    {
        return true;
    }
    if (row == prevrow + 1 && column == prevcol - 1)
    {
        return true;
    }
    return false;
}

void Chess::Play()
{
    std::string turn = "white";
    std::cout << "turn = " << turn << std::endl;
    while (true)
    {
        if (turn == "white")
        {
            std::cin >> prevrow;
            std::cin >> prevcol;
            if (matrix[prevrow][prevcol] == "wP")
            {
                std::cin >> row;
                std::cin >> column;
                std::cout << std::endl;
                if (IsValidPawnWite(row, column, prevrow, prevcol))
                {
                    if (matrix[row][column] == "bK")
                    {
                        matrix[row][column] = "wP";
                        std::cout << "MATE" << std::endl
                                  << turn << " WON" << std::endl;
                        break;
                    }
                    matrix[row][column] = "wP";
                    matrix[prevrow][prevcol] = "  ";
                    Check(row, column);
                    Showboard();
                }
            }
            if (matrix[prevrow][prevcol] == "wN")
            {
                std::cin >> row;
                std::cin >> column;
                std::cout << std::endl;
                if (IsValidKnight(row, column, prevrow, prevcol))
                {
                    if (matrix[row][column] != "wR" && matrix[row][column] != "wN" && matrix[row][column] != "wB" && matrix[row][column] != "wQ" && matrix[row][column] != "wK" && matrix[row][column] != "wP")
                    {
                        if (matrix[row][column] == "bK")
                        {
                            matrix[row][column] = "wN";
                            std::cout << "MATE" << std::endl
                                      << turn << " WON" << std::endl;
                            break;
                        }
                        matrix[row][column] = "wN";
                        matrix[prevrow][prevcol] = "  ";
                        Check(row, column);
                        Showboard();
                    }
                }
            }
            if (matrix[prevrow][prevcol] == "wR")
            {
                std::cin >> row;
                std::cin >> column;
                std::cout << std::endl;
                if (IsValidRook(row, column, prevrow, prevcol))
                {
                    if (matrix[row][column] != "wR" && matrix[row][column] != "wN" && matrix[row][column] != "wB" && matrix[row][column] != "wQ" && matrix[row][column] != "wK" && matrix[row][column] != "wP")
                    {
                        if (matrix[row][column] == "bK")
                        {
                            matrix[row][column] = "wR";
                            std::cout << "MATE" << std::endl
                                      << turn << " WON" << std::endl;
                            break;
                        }
                        matrix[row][column] = "wR";
                        matrix[prevrow][prevcol] = "  ";
                        Check(row, column);
                        Showboard();
                    }
                }
            }
            if (matrix[prevrow][prevcol] == "wB")
            {
                std::cin >> row;
                std::cin >> column;
                std::cout << std::endl;
                if (IsValidBishop(row, column, prevrow, prevcol))
                {
                    if (matrix[row][column] != "wR" && matrix[row][column] != "wN" && matrix[row][column] != "wB" && matrix[row][column] != "wQ" && matrix[row][column] != "wK" && matrix[row][column] != "wP")
                    {
                        if (matrix[row][column] == "bK")
                        {
                            matrix[row][column] = "wB";
                            std::cout << "MATE" << std::endl
                                      << turn << " WON" << std::endl;
                            break;
                        }
                        matrix[row][column] = "wB";
                        matrix[prevrow][prevcol] = "  ";
                        Check(row, column);
                        Showboard();
                    }
                }
            }
            if (matrix[prevrow][prevcol] == "wQ")
            {

                std::cin >> row;
                std::cin >> column;
                std::cout << std::endl;
                if (IsValidQueen(row, column, prevrow, prevcol))
                {
                    if (matrix[row][column] != "wR" && matrix[row][column] != "wN" && matrix[row][column] != "wB" && matrix[row][column] != "wK" && matrix[row][column] != "wP")
                    {
                        if (matrix[row][column] == "bK")
                        {
                            matrix[row][column] = "wQ";
                            std::cout << "MATE" << std::endl
                                      << turn << " WON" << std::endl;
                            break;
                        }
                        matrix[row][column] = "wQ";
                        matrix[prevrow][prevcol] = "  ";
                        Check(row, column);
                        Showboard();
                    }
                }
            }
            if (matrix[prevrow][prevcol] == "wK")
            {

                std::cin >> row;
                std::cin >> column;
                std::cout << std::endl;
                if (IsValidKing(row, column, prevrow, prevcol))
                {
                    if (matrix[row][column] != "wR" && matrix[row][column] != "wN" && matrix[row][column] != "wB" && matrix[row][column] != "wQ" && matrix[row][column] != "wP")
                    {

                        matrix[row][column] = "wK";
                        matrix[prevrow][prevcol] = "  ";
                        Showboard();
                    }
                }
            }
            turn = "black";
            std::cout << "turn = " << turn << std::endl;
        }
        if (turn == "black")
        {
            std::cin >> prevrow;
            std::cin >> prevcol;
            if (matrix[prevrow][prevcol] == "bP")
            {
                std::cin >> row;
                std::cin >> column;
                std::cout << std::endl;
                if (IsValidPawnBlack(row, column, prevrow, prevcol))
                {
                    if (matrix[row][column] == "wK")
                    {
                        matrix[row][column] = "bP";
                        std::cout << "MATE" << std::endl
                                  << turn << " WON" << std::endl;
                        break;
                    }
                    matrix[row][column] = "bP";
                    matrix[prevrow][prevcol] = "  ";
                    Check(row, column);
                    Showboard();
                }
            }
            if (matrix[prevrow][prevcol] == "bN")
            {
                std::cin >> row;
                std::cin >> column;
                std::cout << std::endl;
                if (IsValidKnight(row, column, prevrow, prevcol))
                {
                    if (matrix[row][column] != "bR" && matrix[row][column] != "bN" && matrix[row][column] != "bB" && matrix[row][column] != "bQ" && matrix[row][column] != "bK" && matrix[row][column] != "bP")
                    {
                        if (matrix[row][column] == "wK")
                        {
                            matrix[row][column] = "bN";
                            std::cout << "MATE" << std::endl
                                      << turn << " WON" << std::endl;
                            break;
                        }
                        matrix[row][column] = "bN";
                        matrix[prevrow][prevcol] = "  ";
                        Check(row, column);
                        Showboard();
                    }
                }
            }
            if (matrix[prevrow][prevcol] == "bR")
            {
                std::cin >> row;
                std::cin >> column;
                std::cout << std::endl;
                if (IsValidRook(row, column, prevrow, prevcol))
                {
                    if (matrix[row][column] != "bR" && matrix[row][column] != "bN" && matrix[row][column] != "bB" && matrix[row][column] != "bQ" && matrix[row][column] != "bK" && matrix[row][column] != "bP")
                    {
                        if (matrix[row][column] == "wK")
                        {
                            matrix[row][column] = "bR";
                            std::cout << "MATE" << std::endl
                                      << turn << " WON" << std::endl;
                            break;
                        }
                        matrix[row][column] = "bR";
                        matrix[prevrow][prevcol] = "  ";
                        Check(row, column);
                        Showboard();
                    }
                }
            }
            if (matrix[prevrow][prevcol] == "bB")
            {
                std::cin >> row;
                std::cin >> column;
                std::cout << std::endl;
                if (IsValidBishop(row, column, prevrow, prevcol))
                {
                    if (matrix[row][column] != "bR" && matrix[row][column] != "bN" && matrix[row][column] != "bB" && matrix[row][column] != "bQ" && matrix[row][column] != "bK" && matrix[row][column] != "bP")
                    {
                        if (matrix[row][column] == "wK")
                        {
                            matrix[row][column] = "bB";
                            std::cout << "MATE" << std::endl
                                      << turn << " WON" << std::endl;
                            break;
                        }
                        matrix[row][column] = "bB";
                        matrix[prevrow][prevcol] = "  ";
                        Check(row, column);
                        Showboard();
                    }
                }
            }
            if (matrix[prevrow][prevcol] == "bQ")
            {
                std::cin >> row;
                std::cin >> column;
                std::cout << std::endl;
                if (IsValidQueen(row, column, prevrow, prevcol))
                {
                    if (matrix[row][column] != "bR" && matrix[row][column] != "bN" && matrix[row][column] != "bB" && matrix[row][column] != "bK" && matrix[row][column] != "bP")
                    {
                        if (matrix[row][column] == "wK")
                        {
                            matrix[row][column] = "bQ";
                            std::cout << "MATE" << std::endl
                                      << turn << " WON" << std::endl;
                            break;
                        }
                        matrix[row][column] = "bQ";
                        matrix[prevrow][prevcol] = "  ";
                        Check(row, column);
                        Showboard();
                    }
                }
            }
            if (matrix[prevrow][prevcol] == "bK")
            {
                std::cin >> row;
                std::cin >> column;
                std::cout << std::endl;
                if (IsValidKing(row, column, prevrow, prevcol))
                {
                    if (matrix[row][column] != "bR" && matrix[row][column] != "bN" && matrix[row][column] != "bB" && matrix[row][column] != "bQ" && matrix[row][column] != "bP")
                    {
                        if (matrix[row][column] == "wK")
                        {
                            matrix[row][column] = "bK";
                            std::cout << "MATE" << std::endl
                                      << turn << "  WON" << std::endl;
                            break;
                        }
                        matrix[row][column] = "bK";
                        matrix[prevrow][prevcol] = "  ";
                        Showboard();
                    }
                }
            }
            turn = "white";
            std::cout << "turn = " << turn << std::endl;
        }
    }
}