#include <iostream> 

template <class T>
struct nodeType{
    T info; 
    nodeType *link; 
};

template <class T> 
class linkedList{
    private: 
        nodeType<T> *first; 
        nodeType<T> *last; 
        int count;
    public: 
        linkedList();
        bool isEmpty(); 
        void insertNode(const T &item); 
        void displayList() const; 
        void deleteNode(const T &item);
        // ~linkedList(); *feature to add later  
        // copy constructor 
};

template <class T> 
linkedList<T>::linkedList(){
    first = nullptr; 
    last = nullptr; 
    count = 0; 
};

template <class T>
bool linkedList<T>::isEmpty(){
    return (count == 0); 
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
    
    while(finder->link->info != item || finder == nullptr){
        finder = finder->link; 
    }
    if (!finder){
        std::cout << "Item to delete not found."; 
        return; 
    }
    nodeType<T> *deleter = finder->link; 
    finder->link = deleter->link; 
    delete deleter; 
};

template <class T>
void linkedList<T>::displayList() const{
    nodeType<T> *displayer; 
    displayer = first; 

    while (displayer != nullptr){
        std::cout << displayer->info << ", ";
        displayer = displayer->link; 
    }
    std::cout << std::endl;
}

int main(){
    linkedList<int> list1; 
    list1.insertNode(5); 
    list1.insertNode(6); 
    list1.insertNode(7); 

    list1.displayList(); 

    list1.deleteNode(5); 

    list1.displayList(); 

    return 0; 
}