#include <iostream>
#include <Matrix.hpp>

int main(int, char**){
    hw06::Matrix<int, 0> matrix;
    for(int i = 0; i < 10; ++i){
        matrix[i][i]=i;
    }

    for (auto i = 0, j = 9; i < 10; ++i, --j){
        matrix[i][j] = j;
    }
    for(auto i = 1; i < 9; i++){
        for (auto j = 1; j < 9; j++){
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<matrix.size()<<'\n';

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (matrix[i][j] != matrix.getDefaultValue()) {
                std::cout << "[" << i << "][" << j << "] = " << matrix[i][j] << std::endl;
            }
        }
    }
}
