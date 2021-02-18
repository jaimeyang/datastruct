//
// Created by jaime on 2021/2/18.
//

#ifndef ALGORITHM_EIGHTQUEENS_H
#define ALGORITHM_EIGHTQUEENS_H

#include <array>

const int QUEENS = 8;

using namespace std;

class EightQueens {
public:
    EightQueens() {

    }

    ~EightQueens() {

    }

    void recall_eight(int row);
    //bool is_valid(const array<>)

private:
    array<int,QUEENS> m_queens;
};


#endif //ALGORITHM_EIGHTQUEENS_H
