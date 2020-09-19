#include <iostream> 
#include "linkedList.h"

int main(){
    linkedList<int> list1; 
    list1.insertNode(5); 
    list1.insertNode(6); 
    list1.insertNode(7); 

    list1.displayList(); 

    list1.deleteNode(7); 

    list1.displayList(); 

    /*std::cout << "Found in the list " << list1.searchItem(6) << std::endl; 

    linkedList<int> list2; 

    list2 = list1; */

    list1.displayList(); 

    return 0; 
};