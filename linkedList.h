#pragma once

#include <iostream> 

template <class T>
struct nodeType{
    T info; 
    nodeType *link; 
};

template <class T> 
class linkedList{
    private: 
        void copyList(const linkedList<T> &otherList);
        void deleteList();
    protected: 
        nodeType<T> *first; 
        nodeType<T> *last; 
        int count;
    public: 
        linkedList();
        const linkedList<T>& operator=(const linkedList<T> &otherList);
        bool isEmpty() const; 
        void initList();  
        void insertNode(const T &item); 
        void deleteNode(const T &item);
        bool searchItem(const T &item); 
        void displayList() const; 
        ~linkedList();
};

template <class T> 
void linkedList<T>::copyList(const linkedList<T> &otherList){
    deleteList(); 
    if (otherList.isEmpty()){
        std::cout << "List to copy is empty. Both lists are now empty. \n"; 
        return; 
    }

    nodeType<T> *listA_iterator, *listB_iterator, *node_creator; 

    listA_iterator = otherList.first; 
    listB_iterator = new nodeType<T>; 
    listB_iterator->info = listA_iterator->info; 
    listB_iterator->link = nullptr; 
    first = listB_iterator; 
    listA_iterator = listA_iterator->link;

    while (listA_iterator){
        node_creator = new nodeType<T>; 
        node_creator->info = listA_iterator->info;
        node_creator->link = nullptr; 
        listB_iterator->link = node_creator; 
        listB_iterator = node_creator; 
        listA_iterator = listA_iterator->link; 
    }
    last = listB_iterator; 
    count = otherList.count;
}

template <class T> 
void linkedList<T>::deleteList(){
    nodeType<T> *deleter; 

    while (first){
        deleter = first; 
        first = first->link; 
        delete deleter; 
    }
    first = nullptr; 
    last = nullptr; 
    count = 0; 
}

template <class T>
linkedList<T>::linkedList():
    first {nullptr}, last {nullptr}, count {0} {}

template <class T> 
void linkedList<T>::initList(){
    deleteList(); 
}

template <class T> 
const linkedList<T>& linkedList<T>::operator=(const linkedList<T> &otherList){
    copyList(otherList);

    return *this; 
}

template <class T>
bool linkedList<T>::isEmpty() const{
    return (first == nullptr); 
};

template <class T>
void linkedList<T>::insertNode(const T &item){
    nodeType<T> *inserter = new nodeType<T>; 
    inserter->info = item; 
    inserter->link = nullptr; 

    if (isEmpty()){
        first = inserter; 
        last = inserter; 
        ++count; 
        return;         
    }
    
    nodeType<T> *placefinder = first; 
    while (placefinder->link != nullptr){
        placefinder = placefinder->link; 
    }
    placefinder->link = inserter; 
    last = inserter; 
    ++count; 
};

template <class T> 
void linkedList<T>::deleteNode(const T &item){
    nodeType<T> *finder = first; 

    if (first->info == item){
        first = first->link; 
        delete finder;
        return;  
    }
    
    while(finder->link->info != item || finder == nullptr){
        finder = finder->link; 
    }
    if (!finder){
        std::cout << "Item to delete not found."; 
        return; 
    }
    nodeType<T> *deleter = finder->link; 
    finder->link = deleter->link; 
    delete deleter;\
    count = count - 1; 
};

template <class T> 
bool linkedList<T>::searchItem(const T &item){
    nodeType<T> *finder = first; 
    bool found = false; 

    while (finder){
        if (finder->info == item){
            found = true; 
            return found; 
        }
        else{
            finder = finder->link; 
        }
    }
    return found;
};

template <class T>
void linkedList<T>::displayList() const{
    if (first == nullptr){
        std::cout << "List is empty \n";
    }
    nodeType<T> *displayer; 
    
    displayer = first; 
    while (displayer != nullptr){
        std::cout << displayer->info << ", ";
        displayer = displayer->link; 
    }
    std::cout << std::endl;
};

template <class T> 
linkedList<T>::~linkedList(){
    deleteList(); 
}