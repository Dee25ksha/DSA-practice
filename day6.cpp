#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

//contrsuctior->to intialize 
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
}