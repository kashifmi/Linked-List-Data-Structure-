#pragma once

#include <iostream> 

template <class T>
struct nodeType{
    T info; 
    nodeType *link_forward; 
    nodeType *link_backward;
};

template <class T> 
class linkedList{
    private: 
        void copyList(const linkedList<T> &otherList);
        void deleteList();
        void displayListReverse(nodeType<T> *current) const;
    protected: 
        nodeType<T> *first; 
        nodeType<T> *last; 
        int count;
    public: 
        linkedList();
        const linkedList<T>& operator=(const linkedList<T> &otherList);
        bool isEmpty() const; 
        void initList();  
        void insertNodeOrdered(const T &item); 
        void deleteNode(const T &item);
        bool searchItem(const T &item); 
        void displayList() const;  
        void printReverse() const; 
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
    listB_iterator->link_forward = nullptr; 
    first = listB_iterator; 
    listA_iterator = listA_iterator->link_forward;

    while (listA_iterator){
        node_creator = new nodeType<T>; 
        node_creator->info = listA_iterator->info;
        node_creator->link_forward = nullptr; 
        listB_iterator->link_forward = node_creator; 
        listB_iterator = node_creator; 
        listA_iterator = listA_iterator->link_forward; 
    }
    last = listB_iterator; 
    count = otherList.count;
}

template <class T> 
void linkedList<T>::deleteList(){
    nodeType<T> *deleter; 

    while (first){
        deleter = first; 
        first = first->link_forward; 
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
void linkedList<T>::insertNodeOrdered(const T &item){
    nodeType<T> *inserter = new nodeType<T>;
    inserter->info = item; 
    inserter->link_forward = nullptr; 
    inserter->link_backward = nullptr;
    if (isEmpty()){
        first = inserter; 
        last = inserter;
        ++count; 
        return; 
    }
    nodeType<T> *placeFinder = first; 
    while (placeFinder->link_forward != nullptr && inserter->info > placeFinder->link_forward->info){
        placeFinder = placeFinder->link_forward; 
    }
    if (placeFinder == first){
        inserter->link_forward = first;
        first = inserter; 
        ++count; 
        return; 
    }
    if (placeFinder == last){
        inserter->link_backward = last; 
        last->link_forward = inserter; 
        last = inserter; 
        ++count; 
        return; 
    }
    inserter->link_forward = placeFinder->link_forward;
    inserter->link_backward = placeFinder;
    placeFinder->link_forward = inserter; 
    ++count; 
    
    return; 
}

template <class T> 
void linkedList<T>::deleteNode(const T &item){
    nodeType<T> *finder = first; 

    if (first->info == item){
        first = first->link_forward; 
        first->link_backward = nullptr; 
        delete finder;
        count = count - 1; 
        return;  
    }
    
    while(finder->link_forward->info != item || finder == nullptr){
        finder = finder->link_forward; 
    }
    if (!finder){
        std::cout << "Item to delete not found."; 
        return; 
    }
    nodeType<T> *deleter = finder->link_forward; 
    finder->link_forward = deleter->link_forward; 
    finder->link_backward = deleter->link_backward; 
    delete deleter;
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
            finder = finder->link_forward; 
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
        displayer = displayer->link_forward; 
    }
    std::cout << std::endl;
};

template <class T> 
void linkedList<T>::displayListReverse(nodeType<T> *current) const{
    if (current != nullptr){
        displayListReverse(current->link_forward);
        std::cout << current->info << ", ";
    }
};

template <class T> 
void linkedList<T>::printReverse() const{
    displayListReverse(first);
    std::cout << std::endl; 
}

template <class T> 
linkedList<T>::~linkedList(){
    deleteList(); 
}