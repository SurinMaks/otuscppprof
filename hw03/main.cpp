#include <iostream>
#include "MyList.hpp"

int main(int, char**){
    std::cout << "Hello, from hw03!\n";
    hw03::MyList<int> mylist;
    mylist.push_back(1);
    mylist.push_back(3);
    mylist.printList();
    mylist.insertIntoBegin(5);
    mylist.printList();
    mylist.insertIntoEnd(7);
    mylist.printList();
    mylist.insertIntoPosition(2,7);
    mylist.printList();
    std::cout << "Тест оператора []: "  << mylist[1] << "\n";
    mylist.eraseInBegin();
    mylist.printList();
    mylist.eraseInEnd();
    mylist.printList();
    mylist.eraseInPosition(0);
    // mylist.eraseInPosition(0);
    mylist.printList();
}
