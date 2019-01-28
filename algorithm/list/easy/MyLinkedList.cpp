#include <iostream>

using namespace std;

struct LinkedNode{
    LinkedNode(int value):val(value),next(nullptr),prev(nullptr) {}
    int val;
    LinkedNode *next;
    LinkedNode *prev;
};

class MyLinkedList{
public:
    MyLinkedList() : size(0) {
        head = tail = new LinkedNode(-1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int index){
        if(0 <= index && index <= size/2){
            return forward(0, index, head->next)->val;
        }else if(size / 2 < index && index < size){
            return backward(size, index, tail)->val;
        }
        return -1;
    }

    void addAtHead(int val){
        add(head, val);
    }

    void addAtTail(int val){
        add(tail->prev, val);
    }

    void addAtIndex(int index, int val){
        if(0 <= index && index <= size/2){
            add(forward(0, index, head->next)->prev, val);
        }else if(size / 2 < index && index <= size){
            add(backward(size, index, tail)->prev, val);
        }
    }

    void deleteAtIndex(int index){
        if(0 <= index && index <= size/2){
            remove(forward(0, index, head->next));
        }else if(size/2 < index && index < size){
            remove(forward(size, index, tail));
        }
    }

    void tranverse(){
        auto b = head->next;
        while(b != tail){
            cout << b->val << "\t";
            b = b->next;
        }
        cout << endl;
    }
private:
    void add(LinkedNode *preNode, int val){
        LinkedNode *node = new LinkedNode(val);
        node->prev = preNode;
        node->next = preNode->next;
        node->prev->next = node->next->prev = node;
        ++size;
    }

    void remove(LinkedNode *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        --size;
        delete node;
    }

    LinkedNode* forward(int start, int end, LinkedNode *curr){
        while(start != end){
            ++start;
            curr = curr->next;
        }
        return curr;
    }

    LinkedNode* backward(int start, int end, LinkedNode *curr){
        while(start != end){
            --start;
            curr = curr->next;
        }
        return curr;
    }

    LinkedNode *head;
    LinkedNode *tail;
    int size;
};

int main(){
    MyLinkedList linkedlist;
    linkedlist.addAtHead(1);
    linkedlist.tranverse();
    linkedlist.addAtTail(3);
    linkedlist.tranverse();
    linkedlist.addAtIndex(1,2);
    linkedlist.tranverse();
    cout << "pos 1: " << linkedlist.get(1) << endl;;
    linkedlist.deleteAtIndex(1);
    linkedlist.tranverse();
    cout << "pos 1: " << linkedlist.get(1) << endl;;
    return 0;
}