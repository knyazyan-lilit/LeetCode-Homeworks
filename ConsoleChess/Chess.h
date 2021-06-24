#include <string>

class Chess
{
private:
    int row;
    int column;
    int prevrow;
    int prevcol;
    std::string matrix[8][8];

public:
    Chess();
    void Showboard();
    bool Check(int row, int column);
    bool IsValidPawnWite(int row, int column, int prevrow, int prevcol);
    bool IsValidPawnBlack(int row, int column, int prevrow, int prevcol);
    bool IsValidKnight(int row, int column, int prevrow, int prevcol);
    bool IsValidRook(int row, int column, int prevrow, int prevcol);
    bool IsValidBishop(int row, int column, int prevrow, int prevcol);
    bool IsValidQueen(int row, int column, int prevrow, int prevcol);
    bool IsValidKing(int row, int column, int prevrow, int prevcol);
    void Play();
};
