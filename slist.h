#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"

template <class T>
class SListIterator : public Iterator<T> {     
    public: 
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++(){
            this -> current = this -> current -> next;
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
            if (head == NULL) {
                throw ("Empty List");
            }
            else {
                while ((*pointer) != NULL){
                    if (cmp(search, (*pointer) -> data)) {
                        if (search == (*pointer) -> data)
                            return true;
                        else
                            pointer = &((*pointer) -> next);
                    }
                    else
                        return false;
                }
                return false;
            }

        }
             
        bool insert(T data) {
            if (head == NULL){
                Node<T>* temp = new Node<T>(data);
                temp -> next = NULL;
                head = temp;
                return true;
            }
            else {
                Node<T>** aux = &head;
                if (find(data, aux))
                    return false;
                else {
                    Node<T>* temp = new Node<T>(data);
                    temp -> next = (*aux);
                    (*aux) = temp;
                    return true;
                }
            }


        }
             
        bool remove(T item) {
            if (head == NULL)
                throw ("Empty List");
            else {
                Node<T>** aux = &head;
                if (find(item, aux)) {
                    Node<T>* temp = (*aux);
                    (*aux) = (*aux) -> next;
                    delete temp;
                    return true;
                }
                else
                    throw ("Element Not Found");
            }


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