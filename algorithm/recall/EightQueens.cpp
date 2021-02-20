//
// Created by jaime on 2021/2/18.
//

#include "EightQueens.h"

void EightQueens::recall_eight(int row) {
    if ( row >= QUEENS ){
        this->m_result.push_back(this->m_queens);
        return;
    }

    for (int column = 0; column < QUEENS; ++column) {
        if ( this->is_valid(row,column) ) {
            this->m_queens.at(row) = column;
            this->recall_eight(row + 1);
        }
    }
}

bool EightQueens::is_valid(int row, int column) {
    auto left_up = column - 1;
    auto right_up = column + 1;
    for (int i = row - 1; i >= 0; --i) {
        if (this->m_queens.at(i) == column) {
            return false;
        }
        if (left_up >= 0) {
            if (this->m_queens.at(i) == left_up) {
                return false;
            }
        }
        if (right_up < QUEENS) {
            if (this->m_queens.at(i) == right_up) {
                return false;
            }
        }
        --left_up;
        ++right_up;
    }
    return true;
}


