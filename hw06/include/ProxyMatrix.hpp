#pragma once
#include <memory>


namespace hw06{
    /// @brief Предварительное объявление шаблонного класса Matrix
    /// @tparam T тип элментов в матрице
    /// @tparam DefaultValue значение по умолчанию
    template<class T, T DefaultValue>
    class Matrix;

    template<class T, T DefaultValue>
    class ProxyMatrix
    {
    public:
        ProxyMatrix(Matrix<T, DefaultValue>* matrix, T row)
            : matrix_(matrix), row_(row), col_(DefaultValue) {}

        ProxyMatrix<T, DefaultValue>& operator[](T col) {
            col_ = col;
            return *this;
        }

        void operator=(T value) {
            if (matrix_) {
                matrix_->insertElement(row_, col_, value);
            }
        }

        operator T() const {
            if (matrix_) {
                return matrix_->getElement(row_, col_);
            }
            return DefaultValue;
        }

    private:
        T row_;
        T col_;
        Matrix<T, DefaultValue>* matrix_;
    };
} //namespace hw06
