#include <iostream> 
#include "linkedList.h"

int main(){
    linkedList<int> list1; 
    list1.insertNode(5); 
    list1.insertNode(6); 
    list1.insertNode(7); 

    list1.displayList(); 

    std::cout << "Break \n"; 

    linkedList<int> list2; 

    list2 = list1; 
    list2.displayList();

    list1.deleteNode(5); 

    list1.displayList(); 

    std::cout << "Found in the list " << list1.searchItem(3) << std::endl; 

    list2 = list1;
    list1.initList(); 
    list1.displayList();

    list2.displayList(); 

    list2.insertNodeOrdered(10);
    list2.displayList();
    list2.insertNodeOrdered(0);
    list2.displayList();
    list2.insertNodeOrdered(9);

    list2.printReverse();


    return 0; 
};