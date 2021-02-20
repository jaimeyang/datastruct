//
// Created by jaime on 2021/2/18.
//

#ifndef ALGORITHM_EIGHTQUEENS_H
#define ALGORITHM_EIGHTQUEENS_H

#include <array>
#include <vector>

const int QUEENS = 8;

using namespace std;

class EightQueens {
public:
    EightQueens() {

    }

    ~EightQueens() {

    }

    void recall_eight(int row);
    bool is_valid(int row,int column);
    vector<array<int,QUEENS>>& getResult(){
        return this->m_result;
    }
private:
    //下表表示第几行，值表示在第几列
    array<int,QUEENS> m_queens;
    //结果
    vector<array<int,QUEENS>> m_result;
};


#endif //ALGORITHM_EIGHTQUEENS_H
