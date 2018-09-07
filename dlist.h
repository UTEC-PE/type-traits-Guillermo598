#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {     
    public: 
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {};
        DListIterator<T> operator++(){
            this -> current = this -> current -> next;
            return *this;
        };
        DListIterator<T> operator--(){
            this -> current = this -> current -> prev;
            return *this;
        };
};

template <typename Tr>
class DList {     
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Node<T>* tail;
              
    public:
        DList() {
            head = tail = nullptr;
        };

        void push_front(T data) {
            Node<T>* temp = new Node<T>(data);
            if (head == NULL)
                head = tail = temp;
            else {
                temp -> next = head;
                head -> prev = temp;
                head = temp;
            }
        }

        void push_back(T data) {
            Node<T>* temp = new Node<T>(data);
            if (head == NULL)
                head = tail = temp;
            else {
                tail -> next = temp;
                temp -> prev = tail;
                tail = temp;
            }
        }
             
        void pop_front() {
            if (head == NULL)
                throw ("List Already Empty");
            else {
                Node<T>* temp = head;
                head = head -> next;
                delete temp;
            }
        }
             
        void pop_back() {
            if (head == NULL)
                throw ("List Already Empty");
            else {
                Node<T>* temp = tail;
                tail = tail -> prev;
                delete temp;
            }
        }
             
        iterator begin() {
            return DListIterator<T>(this -> head);
        }
             
        iterator end() {
            return DListIterator<T>(this -> tail);
        }
             
        ~DList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif