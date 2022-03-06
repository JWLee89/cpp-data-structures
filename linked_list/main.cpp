#include <iostream>
#include <string>
#include "LinkedList.h"

int main() {
    LinkedList<int> ls;
    ls.append(10);
    ls.append(20);
    ls.append(30);
    ls.append(40);
    ls.append(50);
    std::cout << "head: " << ls.peek() << std::endl;
    ls.print();
    ls.remove(4);
    ls.print();
    return 0;
}
