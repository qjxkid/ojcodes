#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;

struct DListNode{
    DListNode *next;
    DListNode *previous;
    int value;
    int key;
    DListNode(int k,int v) : key(k) ,value(v), next(NULL), previous(NULL) {}
};

class LRUCache{
private:
    DListNode *m_head;
    DListNode *m_end;
    int m_capcity;
    unordered_map<int, DListNode *> m_cachemap;
    unordered_map<int, DListNode *>::iterator m_it;
    //map<int, DListNode *> m_cachemap;
    //map<int, DListNode *>::iterator m_it;
public:
    LRUCache(int capacity) {
        m_capcity = capacity;
        m_head = NULL;
        m_end = NULL;
    }
    
    int get(int key) {
        m_it = m_cachemap.find(key);
        if (m_it != m_cachemap.end()) {
            DListNode *tmp = m_it->second;
            if (m_head == m_end) {
                return tmp->value;
            }
            if (tmp->previous) {
                if (tmp == m_end) {
                    m_end = tmp->previous;
                }
                tmp->previous->next = tmp->next;
            }
            if (tmp->next) {
                if (tmp == m_head) {
                    return tmp->value;
                }
                tmp->next->previous = tmp->previous;
            }
            tmp->previous = NULL;
            tmp->next = m_head;
            m_head->previous = tmp;
            m_head = tmp;
            return tmp->value;
        }
        else return -1;
    }
    
    void set(int key, int value) {
        m_it = m_cachemap.find(key);
        if (m_it != m_cachemap.end()) {
            DListNode *tmp = m_it->second;
            if (m_head == m_end) {
                tmp->value = value;
                return;
            }
            if (tmp->previous) {
                if (tmp == m_end) {
                    m_end = tmp->previous;
                }
                tmp->previous->next = tmp->next;
            }
            if (tmp->next) {
                if (tmp == m_head) {
                    tmp->value = value;
                    return;
                }
                tmp->next->previous = tmp->previous;
            }
            tmp->previous = NULL;
            tmp->next = m_head;
            m_head->previous = tmp;
            m_head = tmp;
            tmp->value = value;
        }
        else {
            if (m_capcity) {
                m_capcity--;
                if (m_head == NULL) {
                    m_head = new DListNode(key, value);
                    m_end = m_head;
                    m_cachemap[key] = m_head;
                }
                else {
                    DListNode * tmp = new DListNode(key, value);
                    tmp->next = m_head;
                    m_head->previous = tmp;
                    m_head = tmp;
                    m_cachemap[key] = m_head;
                }
            }
            else {
                DListNode * tmp = m_end;
                int tmpkey = tmp->key;
                if (m_end != m_head) {
                    m_end = m_end->previous;
                    m_end->next = NULL;
                    tmp->previous = NULL;
                    tmp->next = m_head;
                    m_head->previous = tmp;
                }
                m_cachemap.erase(tmpkey);
                tmp->value = value;
                tmp->key = key;
                m_cachemap[key] = tmp;
                m_head = tmp;
            }
        }
    }
};

int main(){
    //LRUCache a(2);
    //a.set(2,2);
    //a.set(1,1);
    //cout<<a.get(2)<<endl;
    //a.set(4,4);
    //cout<<a.get(1)<<endl;
    //cout<<a.get(2)<<endl;
    //
    LRUCache a(10);

a.set(10,13);
a.set(3,17);
a.set(6,11);
a.set(10,5);
a.set(9,10);
cout<<"\n"<<a.get(13);
a.set(2,19);
cout<<"\n"<<a.get(2);
cout<<"\n"<<a.get(3);
a.set(5,25);
cout<<"\n"<<a.get(8);
a.set(9,22);
a.set(5,5);
a.set(1,30);
cout<<"\n"<<a.get(11);
a.set(9,12);
cout<<"\n"<<a.get(7);
cout<<"\n"<<a.get(5);
cout<<"\n"<<a.get(8);
cout<<"\n"<<a.get(9);
a.set(4,30);
a.set(9,3);
cout<<"\n"<<a.get(9);
cout<<"\n"<<a.get(10);
cout<<"\n"<<a.get(10);
a.set(6,14);
a.set(3,1);
cout<<"\n"<<a.get(3);
a.set(10,11);
cout<<"\n"<<a.get(8);
a.set(2,14);
cout<<"\n"<<a.get(1);
cout<<"\n"<<a.get(5);
cout<<"\n"<<a.get(4);
a.set(11,4);
a.set(12,24);
a.set(5,18);
cout<<"\n"<<a.get(13);
a.set(7,23);
cout<<"\n"<<a.get(8);
cout<<"\n"<<a.get(12);
a.set(3,27);
a.set(2,12);
cout<<"\n"<<a.get(5);
a.set(2,9);
a.set(13,4);
a.set(8,18);
a.set(1,7);
cout<<"\n"<<a.get(6);
a.set(9,29);
a.set(8,21);
cout<<"\n"<<a.get(5);
a.set(6,30);
a.set(1,12);
cout<<"\n"<<a.get(10);
a.set(4,15);
a.set(7,22);
a.set(11,26);
a.set(8,17);
a.set(9,29);
cout<<"\n"<<a.get(5);
a.set(3,4);
a.set(11,30);
cout<<"\n"<<a.get(12);
a.set(4,29);
cout<<"\n"<<a.get(3);
cout<<"\n"<<a.get(9);
cout<<"\n"<<a.get(6);
a.set(3,4);
cout<<"\n"<<a.get(1);
cout<<"\n"<<a.get(10);
a.set(3,29);
a.set(10,28);
a.set(1,20);
a.set(11,13);
cout<<"\n"<<a.get(3);
a.set(3,12);
a.set(3,8);
a.set(10,9);
a.set(3,26);
cout<<"\n"<<a.get(8);
cout<<"\n"<<a.get(7);
cout<<"\n"<<a.get(5);
a.set(13,17);
a.set(2,27);
a.set(11,15);
cout<<"\n"<<a.get(12);
a.set(9,19);
a.set(2,15);
a.set(3,16);
cout<<"\n"<<a.get(1);
a.set(12,17);
a.set(9,1);
a.set(6,19);
cout<<"\n"<<a.get(4);
cout<<"\n"<<a.get(5);
cout<<"\n"<<a.get(5);
a.set(8,1);
a.set(11,7);
a.set(5,2);
a.set(9,28);
cout<<"\n"<<a.get(1);
a.set(2,2);
a.set(7,4);
a.set(4,22);
a.set(7,24);
a.set(9,26);
a.set(13,28);
a.set(11,26);
    return 0;
}
