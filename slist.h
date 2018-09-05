#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"

template <class T>
class SListIterator : public Iterator<T> {     
    public: 
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++(){
            current = current -> next;
            return *this;
        };
};

template <typename Tr>
class SList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        typedef SListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Operation cmp;
              
    public:
        SList() {
            head = nullptr;
        };

        bool find(T search, Node<T> **&pointer) {
            // TODO
        }
             
        bool insert(T data) {
            // TODO
        }
             
        bool remove(T item) {
            // TODO
        }  
             
        iterator begin() {
            return iterator(this -> head);
        }
             
        iterator end() {
            Node<T>* temp = head;
            while (temp -> next)
                temp = temp -> next;
            return iterator(temp);
        }
             
        ~SList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif