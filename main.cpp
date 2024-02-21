//
// Created by COP3503C - Instructor for LinkedList project
//

#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
using namespace std;

void TestRemove();
void TestRemoveHeadTail();
void TestOtherRemoval();
void TestRecursion();
bool TestClear();
void TestInsertBeforeAfter();
void TestInsertAt();
void TestEqualityOperator();
void TestFindAll();
void TestCopyCtor();
void TestAssignment();
void TestAddHead();
void TestAddTail();
void TestAddingArrays();
void addHeadFullTest();
void addTailFullTest();

int main()
{
    int testNum;
    cin >> testNum;
    if (testNum == 1)
        TestRemove();
    else if (testNum == 2)
        TestRemoveHeadTail();
    else if (testNum == 3)
        TestOtherRemoval();
    else if (testNum == 4)
        TestRecursion();
    else if (testNum == 5)
        if(TestClear()) {
            cout << "The Clear() function works properly" << endl;
        }
    if (testNum == 6)
        TestInsertBeforeAfter();
    else if (testNum == 7)
        TestInsertAt();
    else if(testNum == 8)
        TestEqualityOperator();
    if (testNum == 9)
        TestFindAll();
    else if (testNum == 10)
        TestCopyCtor();
    else if (testNum == 11)
        TestAssignment();
    if (testNum == 12)
        TestAddHead();
    else if (testNum == 13)
        TestAddTail();
    else if (testNum == 14)
        TestAddingArrays();
    else if (testNum == 15)
        addHeadFullTest();
    else if (testNum == 16)
        addTailFullTest();

    return 0;
}

void TestRemove()
{
    cout << "=====Testing Remove() functionality=====" << endl;
    LinkedList<string> data;
    string test = "Test RemoveMe to RemoveMe find RemoveMe all RemoveMe matching ";
    test.append("RemoveMe nodes RemoveMe completed RemoveMe with RemoveMe no ");
    test.append("RemoveMe \"RemoveMe\" RemoveMe nodes RemoveMe remaining.");
    stringstream x(test);
    string tmp;
    while (getline(x, tmp, ' '))
        data.AddTail(tmp);

    cout << "Initial list: " << endl;
    data.PrintForward();
    string val = "RemoveMe";
    int count = data.Remove(val);
    cout << "\nRemoving " << val << " from the list." << endl;
    cout << "Removed " << count << " nodes from the list.\n" << endl;
    data.PrintForward();
    cout << "\nNodes removed: " << count << endl;

    count = data.Remove(val);
    cout << "Removing " << val << " from the list again." << endl;
    cout << "Nodes removed: " << count << endl;

}

void TestRemoveHeadTail()
{
    cout << "=====Testing RemoveHead()/RemoveTail() functionality=====" << endl;
    LinkedList<int> data;
    for (unsigned int i = 0; i < 70; i += 5)
        data.AddTail(i);

    cout << "Initial list: " << endl;
    data.PrintForward();

    cout << "Removing 2 Tail and 2 Head Nodes..." << endl;
    data.RemoveHead();
    data.RemoveTail();
    data.RemoveHead();
    data.RemoveTail();
    data.PrintForward();
}

void TestOtherRemoval()
{
    cout << "=====Testing RemoveAt() and clearing with RemoveHead()/RemoveTail() functionality=====" << endl;
    LinkedList<string> data;
    data.AddTail("Batman");
    data.AddTail("RemoveMe");
    data.AddTail("Superman");
    data.AddTail("RemoveMe");
    data.AddTail("Wonder Woman");
    data.AddTail("RemoveMe");
    data.AddTail("The Flash");

    cout << "Initial list: " << endl;
    data.PrintForward();
    cout << "\nRemoving using RemoveAt()..." << endl;
    data.RemoveAt(1);
    data.RemoveAt(2);
    data.RemoveAt(3);

    data.PrintForward();

    cout << "\nAttempting to remove out of range using RemoveAt()..." << endl;
    if (!data.RemoveAt(100))
        cout << "Attempt to RemoveAt(100) failed." << endl;
    else
        cout << "Successfully removed node 100? Weird, there are only 4 nodes..." << endl;

    cout << "\nClearing list using RemoveHead()..." << endl;
    while (data.RemoveHead()){}

    if (data.NodeCount() == 0)
        cout << "List is empty!" << endl;
    else
        cout << "List not empty!" << endl;

    cout << "Adding additional nodes..." << endl;
    data.AddTail("Robin");
    data.AddTail("Batgirl");
    data.AddTail("Nightwing");
    data.AddTail("Red Hood");
    data.AddTail("Bluebird");

    data.PrintForward();

    cout << "Clearing list using RemoveTail()..." << endl;
    while (data.RemoveTail()) {}

    if (data.NodeCount() == 0)
        cout << "List is empty!" << endl;
    else
        cout << "List not empty!" << endl;
}

void TestRecursion()
{
    LinkedList<int> power2;
    int val = 2;
    for (int i = 0; i < 10; i++)
    {
        power2.AddTail(val);
        val *= 2;
    }
    cout << "Initial list: " << endl;
    power2.PrintForward();
    cout << "Printing recursively forward from 64: " << endl;
    LinkedList<int>::Node *node = power2.Find(64);
    power2.PrintForwardRecursive(node);

    cout << "Printing recursively in reverse from 512: " << endl;
    node = power2.Find(512);
    power2.PrintReverseRecursive(node);
}

bool TestClear(){
    LinkedList<float> data;
    data.AddHead(1.21f);
    data.AddHead(3.1f);
    data.AddHead(4.7f);
    data.AddHead(12.23f);
    data.AddHead(7.78f);
    int nodeCountBefore = data.NodeCount();
    if (nodeCountBefore == 0)
    {
        cout << "Data not properly added to lists, no data present to test clearing.";
        return false;
    }
    data.Clear();
    if (data.getHead() != nullptr || data.getTail() != nullptr || data.NodeCount() != 0)
    {
        cout << "List not cleared properly. Did you forget a variable?";
        return false;
    }
    return true;
}

void TestInsertBeforeAfter()
{
    LinkedList<int> data;
    data.AddTail(10);
    data.AddHead(9);
    data.AddTail(11);
    data.AddHead(8);
    data.AddTail(12);

    cout << "Initial list: " << endl;
    data.PrintForward();

    LinkedList<int>::Node * node = data.Find(10);
    cout << "\nSearching for node with value of 10..." << endl;

    if (node != nullptr)
    {
        cout << "Node found! Value: " << node->data << endl;
        cout << "Prev value: " << node->prev->data << endl;
        cout << "Next value: " << node->next->data << endl;
    }
    else
        cout << "Error! Returned node was a nullptr.";

    cout << "\nInserting 2048 before node and 4096 after node." << endl;
    data.InsertBefore(node, 2048);
    data.InsertAfter(node, 4096);
    data.PrintForward();
}

void TestInsertAt()
{
    cout << "=====Testing InsertAt() functionality=====" << endl;
    LinkedList<string> data;
    string test = "great benefit linked is the ability to easily into the";
    stringstream x(test);
    string tmp;
    while (getline(x, tmp, ' '))
        data.AddTail(tmp);

    cout << "Initial list: " << endl;
    data.PrintForward();
    cout << "Node count: " <<  data.NodeCount() << endl;

    cout << "\nInserting words into the list with InsertAt()..." << endl;

    data.InsertAt("One", 0);
    data.InsertAt("of", 3);
    data.InsertAt("lists", 5);
    data.InsertAt("insert", 10);
    data.InsertAt("nodes", 11);
    data.InsertAt("list.", 15);

    data.PrintForward();
    cout << "Node count: " << data.NodeCount() << endl;
}

void TestEqualityOperator(){
    LinkedList<int> a;
    a.AddHead(5);
    a.AddHead(20);
    a.AddHead(39);

    LinkedList<int> b;
    b.AddHead(5);
    b.AddHead(20);
    b.AddHead(39);

    if (a == b)
        cout << "Equality check for two identical lists passed." << endl;
    else
        cout << "Equality check for two identical lists failed." << endl;
}

void TestFindAll()
{
    cout << "=====Testing FindAll() functionality=====" << endl;
    LinkedList<int> data;
    int searchVal = 256;

    data.AddTail(searchVal);
    data.AddTail(10);
    data.AddTail(20);
    data.AddTail(searchVal);
    data.AddTail(30);
    data.AddTail(searchVal);
    data.AddTail(40);
    data.AddTail(searchVal);

    cout << "Initial list: " << endl;
    data.PrintForward();

    vector<LinkedList<int>::Node *> nodes;
    data.FindAll(nodes, searchVal);

    cout << "\nNodes found: " << nodes.size() << endl;
    for (unsigned int i = 0; i < nodes.size(); i++)
    {
        cout << "Node #" << (i + 1) << ":\n";
        cout << "Value: " << nodes[i]->data << endl;

        cout << "Prev value: ";
        if (nodes[i]->prev != nullptr)
            cout << nodes[i]->prev->data;
        else
            cout << "nullptr";

        cout << "\nNext value: ";
        if (nodes[i]->next != nullptr)
            cout << nodes[i]->next->data;
        else
            cout << "nullptr";
        cout << endl;
    }
}

void TestCopyCtor()
{
    cout << "=====Testing Copy Constructor functionality=====" << endl;
    LinkedList<int> original;
    for (int i = 0; i <= 10; i += 5)
        original.AddTail(i);

    cout << "Printing original:" << endl;
    original.PrintForward();
    cout << endl;

    cout << "Printing copy:" << endl;
    LinkedList<int> copy = original;
    copy.PrintForward();
    cout << endl;

    cout << "Changing copy... adding to head and tail..." << endl;
    copy.AddHead(99);
    copy.AddTail(-102);
    cout << "Printing copy again:" << endl;
    copy.PrintForward();
    cout << endl;

    cout << "Printing original again:" << endl;
    original.PrintForward();
    cout << endl;
}

void TestAssignment()
{
    cout << "=====Testing Copy Assignment Operator functionality=====" << endl;
    LinkedList<int> first;
    LinkedList<int> second;

    for (int i = 20; i <= 30; i += 5)
        first.AddTail(i);
    for (int i = 17; i < 100; i += 22)
        second.AddTail(i);

    cout << "Printing first list:" << endl;
    first.PrintForward();
    cout << endl;

    cout << "Printing second list:" << endl;
    second.PrintForward();
    cout << endl;

    cout << "Assigning one list to another..." << endl;
    first = second;

    cout << "Printing after copying:" << endl;
    first.PrintForward();
    cout << endl;

    cout << "Changing both lists..." << endl;
    first.AddTail(66);
    second.AddTail(19);
    first.AddHead(-100);
    second.AddHead(-512);
    cout << "Printing first list: " << endl;
    first.PrintForward();
    cout << endl;
    cout << "Printing second list: " << endl;
    second.PrintForward();
}

void TestAddHead()
{
    cout << "=====Testing AddHead() functionality====" << endl;
    LinkedList<int> data;
    for (int i = 0; i < 12; i += 2)
        data.AddHead(i);
    cout << "Node count: " << data.NodeCount() << endl;
    cout << "Print list forward:" << endl;
    data.PrintForward();
    cout << "Print list in reverse:" << endl;
    data.PrintReverse();
}

void TestAddTail()
{
    cout << "=====Testing AddTail() functionality====" << endl;
    LinkedList<int> data;
    for (int i = 0; i <= 21; i += 3)
        data.AddTail(i);
    cout << "Node count: " << data.NodeCount() << endl;
    cout << "Print list forward:" << endl;
    data.PrintForward();
    cout << "Print list in reverse:" << endl;
    data.PrintReverse();
}

void TestAddingArrays()
{
    cout << "=====Testing AddNodesHead() and AddNodesTail() =====" << endl;

    string values[5];
    values[0] = "*";
    values[1] = "**";
    values[2] = "***";
    values[3] = "****";
    values[4] = "*****";

    LinkedList<string> list;
    list.AddHead("**");
    list.AddHead("***");
    list.AddHead("****");
    list.AddHead("*****");
    list.AddHead("******");
    list.AddHead("*******");
    list.AddHead("********");
    list.AddHead("*********");
    list.AddHead("********");
    list.AddHead("*******");
    list.AddHead("******");

    list.AddNodesHead(values, 5);
    list.AddNodesTail(values, 5);
    list.PrintForward();
}

void addHeadFullTest() {
    LinkedList<int> list;
    list.AddHead(1);
    list.AddHead(2);
    list.AddHead(3);
    list.AddHead(4);
    LinkedList<int>::Node* start = list.getHead();

    if(start->prev!=nullptr){
        std::cout << "Your head doesnt have a prev pointer to nullptr after using AddHead";
        return;
    }


    int count = 4;
    while(start!=nullptr){

        if(start->data == count){
            count--;
            start = start->next;
        }
        else{
            std::cout << "Numbers are not in the right order" << std::endl;
            return;
        }
    }

    if(count != 0){
        std::cout << "The while loop above didn't good through 4 iterations" << std::endl;
    }

    std::cout << "Passed Test Case" << std::endl;
}

void addTailFullTest() {
    LinkedList<int> list;
    list.AddTail(4);
    list.AddTail(3);
    list.AddTail(2);
    list.AddTail(1);
    LinkedList<int>::Node* start = list.getHead();

    if(start->prev!=nullptr){
        std::cout << "Your head doesnt have a prev pointer to nullptr after using AddTail";
        return;
    }


    int count = 4;
    while(start!=nullptr){

        if(start->data == count){
            count--;
            start = start->next;
        }
        else{
            std::cout << "Numbers are not in the right order" << std::endl;
            return;
        }
    }

    if(count != 0){
        std::cout << "The while loop above didn't good through 4 iterations" << std::endl;
    }

    std::cout << "Passed Test Case" << std::endl;
}
