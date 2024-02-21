//
// Created by Peyton Hecht on 2/21/2024
//
#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class LinkedList {
public:
    class Node {
    public:
        Node* next;
        Node* prev;
        T data;
    };
    // constructor
    LinkedList() {
        nodeCount = 0;
        head = nullptr;
        tail = nullptr;
    }
    // destructor
    ~LinkedList() {
        Clear();
    }
    void Clear() {
        Node* deleteNode = head;
        Node* temp;

        while (deleteNode != nullptr) {
            temp = deleteNode->next;
            delete deleteNode;
            deleteNode = temp;
        }
        head = nullptr;
        tail = nullptr;
        nodeCount = 0;
    }

    void AddHead(const T& data) {
        if (head == nullptr) {
            head = new Node;
            head->data = data;
            tail = head;
        }
        else {
            Node* temp = new Node();
            temp->data = data;
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        nodeCount++;
    }

    void AddTail(const T& data) {
        if (tail == nullptr) {
            tail = new Node;
            tail->data = data;
            head = tail;
        }
        else {
            Node* temp = new Node();
            temp->data = data;
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        nodeCount++;
    }

    void AddNodesHead(const T* data, int count) {
        for (int i = count - 1; i >= 0; i--){
            AddHead(data[i]);
        }
    }

    void AddNodesTail(const T* data, int count) {
        for (int i = 0; i < count; i++){
            AddTail(data[i]);
        }
    }

    int NodeCount() const {
        return nodeCount;
    }

    Node* getHead() const {
        return head;
    }

    Node* getTail() const {
        return tail;
    }

    Node* GetNode(unsigned int index) const {
        if (index >= nodeCount) {
            throw out_of_range("out of range");
        }
        else {
            Node* returnThis = head;
            for (unsigned int i = 0; i < index; i++) {
                if (returnThis != nullptr) {
                    returnThis = returnThis->next;
                }
            }

            return returnThis;
        }

    }

    Node* Find(const T& val) {
        Node* iterator = head;

        while (iterator != nullptr) {
            if (iterator->data == val) {
                return iterator;
            }
            iterator = iterator->next;
        }

        return nullptr;
    }

    Node* Find(const T& val) const {
        Node* iterator = head;

        while (iterator != nullptr) {
            if (iterator->data == val) {
                return iterator;
            }
            iterator = iterator->next;
        }

        return nullptr;
    }

    void FindAll(std::vector<Node*>& outData, const T& value) const {
        Node* pointer = head;
        while (pointer != nullptr) {
            if (pointer->data == value) {
                outData.push_back(pointer);
            }
            pointer = pointer->next;
        }
    }

    void PrintForward() const {
        Node* printNode = head;

        while (printNode != nullptr) {
            cout << printNode->data << endl;
            printNode = printNode->next;
        }
    }

    void PrintReverse() const {
        Node* printNode = tail;

        while (printNode != nullptr) {
            cout << printNode->data << endl;
            printNode = printNode->prev;
        }
    }

    LinkedList(const LinkedList<T>& list) {
        nodeCount = 0;
        head, tail = nullptr;
        Node* temp = list.head;
        while (temp != nullptr) {
            AddTail(temp->data);
            temp = temp->next;
        }
    }

    LinkedList<T>& operator= (const LinkedList<T>& other) {
        if (this != &other) {
            Clear();
            Node* temp = other.head;
            while (temp != nullptr) {
                AddTail(temp->data);
                temp = temp->next;
            }
        }
        return *this;
    }

    // operators
    T& operator[](const unsigned int index) {
        if(head == nullptr){
            throw out_of_range("out of range");
        }
        if(index>=nodeCount){
            throw out_of_range("out of range");
        }
        Node *pointer = head;
        for (unsigned int i = 0; i < index; i++) {
            if(pointer==nullptr){
                throw out_of_range("out of range");
            }
            pointer = pointer->next;
        }
        if (pointer == nullptr) {
            throw out_of_range("out of range");
        }
        return pointer->data;

    }

    T& operator[](const unsigned int index) const {
        if(head==nullptr){
            throw out_of_range("out of range");
        }
        if(index>=nodeCount){
            throw out_of_range("out of range");
        }
        Node *pointer = head;
        for (unsigned int i = 0; i < index; i++) {
            if(pointer==nullptr){
                throw out_of_range("out of range");
            }
            pointer = pointer->next;
        }
        return pointer->data;

    }
    void InsertBefore(Node* nextNode, const T& data) {
        Node* nodeNew = new Node();
        nodeNew->data = data;
        nodeNew->prev = nextNode->prev;
        nodeNew->next = nextNode;
        if (nextNode->prev != nullptr) {
            nextNode->prev->next = nodeNew;
        }
        nextNode->prev = nodeNew;
        if (nodeNew->prev == nullptr) {
            head = nodeNew;
        }

        nodeCount++;
    }

    void InsertAfter(Node* prevNode, const T& data) {
        Node* nodeNew = new Node();
        nodeNew->data = data;
        nodeNew->next = prevNode->next;
        nodeNew->prev = prevNode;
        if (prevNode->next != nullptr) {
            prevNode->next->prev = nodeNew;
        }
        prevNode->next = nodeNew;
        if (nodeNew->next == nullptr) {
            tail = nodeNew;
        }
        nodeCount++;
    }

    void InsertAt(const T& data, unsigned int index) {
        if (index == 0) {
            AddHead(data);
        }
        else if (index == nodeCount) {
            AddTail(data);
        }
        else{
            Node* prevNode = GetNode(index - 1);
            InsertAfter(prevNode, data);
        }
    }


    bool operator==(const LinkedList<T>& other) const {
        if (nodeCount != other.nodeCount){
            return false;
        }
        Node* currentNode = head;
        Node* otherNode = other.head;
        while(currentNode != nullptr && otherNode != nullptr){
            if (currentNode->data != otherNode->data){
                return false;
            }
            currentNode = currentNode->next;
            otherNode = otherNode->next;
        }
        return true;
    }

    bool RemoveHead(){
        if(head==nullptr){
            return false;
        }

        Node* temp = head;
        head = head->next;

        if(head != nullptr){
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
        nodeCount--;
        return true;
    }

    bool RemoveTail(){
        if(tail==nullptr){
            return false;
        }

        Node* temp = tail;
        tail = tail->prev;

        if(tail != nullptr){
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
        nodeCount--;
        return true;
    }

    int Remove(const T& data) {
        int count = 0;
        Node* currentNode = head;
        int index = 0;
        while (currentNode != nullptr) {
            Node* temp = currentNode->next;
            if (currentNode->data == data) {
                RemoveAt(index);
                count++;
            } else {
                index++;
            }
            currentNode = temp;
        }
        return count;
    }

    bool RemoveAt(int index) {
        if (index < 0 or index >= nodeCount) {
            return false;
        }
        Node* nodeToRemove = GetNode(index);
        if (nodeToRemove == nullptr) {
            return false;
        }
        if (nodeToRemove->prev != nullptr) {
            nodeToRemove->prev->next = nodeToRemove->next;
        }
        if (nodeToRemove->next != nullptr) {
            nodeToRemove->next->prev = nodeToRemove->prev;
        }
        if (nodeToRemove == head) {
            head = nodeToRemove->next;
        }
        if (nodeToRemove == tail) {
            tail = nodeToRemove->prev;
        }
        delete nodeToRemove;
        nodeCount--;
        return true;
    }

    void PrintForwardRecursive(Node* node) const {
        if (node == nullptr) {
            return;
        }
        cout << node->data << endl;
        PrintForwardRecursive(node->next);
    }

    void PrintReverseRecursive(Node* node) const {
        if (node == nullptr) {
            return;
        }
        cout << node->data << endl;
        PrintReverseRecursive(node->prev);
    }





private:
    int nodeCount;
    Node* head;
    Node* tail;

};
#endif //LINKEDLIST_LINKEDLIST_H
