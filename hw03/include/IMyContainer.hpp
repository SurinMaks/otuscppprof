#ifndef HW03_IMYCONTAINER_HPP_
#define HW03_IMYCONTAINER_HPP_
namespace hw03{

    /// @brief Интерфейс для односвязного списка
    /// @tparam T тип
    template<typename T>
    class IMyContainer {
        public:
        virtual ~IMyContainer(){};
        virtual void push_back(const T& value) = 0;
        // virtual void insertIntoPosition(const T& value, const unsigned int position) = 0;
        // virtual void insertIntoEnd(const T& value) = 0;
        // virtual void insertIntoBegin(const T& value) = 0;
        // virtual void eraseInPosition(const unsigned int position) = 0;
        // virtual void eraseInEnd() = 0;
        // virtual void eraseInBegin() = 0;
        // virtual unsigned int size() const = 0;
        // virtual void printList() const = 0;
        // virtual T operator[](unsigned int index) const = 0;
    };

} //namespace hw03

#endif
