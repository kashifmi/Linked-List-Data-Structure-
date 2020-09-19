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
        // void copyList(const linkedList<T> &otherList);
        
    protected: 
        nodeType<T> *first; 
        nodeType<T> *last; 
        int count;
    public: 
        linkedList();
        //const linkedList<T>& operator=(const linkedList<T> &otherList);
        bool isEmpty(); 
        void initList();  
        void insertNode(const T &item); 
        void deleteNode(const T &item);
        bool searchItem(const T &item); 
        void displayList() const; 
        void deleteList();
        //~linkedList();
};

/*template <class T> 
void linkedList<T>::copyList(const linkedList<T> &otherList){
    if (!this->isEmpty()){
        deleteList(); 
    }

    if (otherList.isEmpty()){
        std::cout << "List to copy is empty. Both lists are now empty. \n"; 
        return; 
    }

    nodeType<T> *lista_iterator, *listb_iterator, node_creator; 

    lista_iterator = otherList.first; 
    listb_iterator = new nodeType<T>; 
    listb_iterator->info = listb_iterator->info; 
    listb_iterator->link = nullptr; 
    first = listb_iterator; 
    lista_iterator = lista_iterator->link;

    while (lista_iterator){
        node_creator = new nodeType<T>; 
        node_creator->info = lista_iterator->info;
        node_creator->link = nullptr; 
        listb_iterator->link = node_creator; 
        listb_iterator = node_creator; 
        lista_iterator = lista_iterator->link; 
    }
    last = listb_iterator; 
    count = otherList.count;
}*/

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
linkedList<T>::linkedList(){
    initList(); 
};

/*template <class T> 
const linkedList<T>& linkedList<T>::operator=(const linkedList<T> &otherList){
    copyList(otherList);

    return *this; 
}*/

/*template <class T>
linkedList<T> linkedList<T>::operator=(const linkedList<T> &otherList){
    copyList(otherList);
}*/

template <class T> 
void linkedList<T>::initList(){
    /*if (!this->isEmpty()){
        deleteList(); 
    }*/
    first = nullptr; 
    last = nullptr; 
    count = 0; 
}

template <class T>
bool linkedList<T>::isEmpty(){
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

/*template <class T> 
linkedList<T>::~linkedList(){
    deleteList(); 
}*/