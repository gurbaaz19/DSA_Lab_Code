#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Node {
public:
    int data;
    Node* next;
};

typedef Node node;


void enter(Node** head_ref, int new_data)
{

    Node* new_node = new Node[(sizeof(Node))];


    new_node->data = new_data;


    new_node->next = (*head_ref);


    (*head_ref) = new_node;
}


void printout(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}


void swap(Node** a, Node** b)
{
    node* t = *a;
    *a = *b;
    *b = t;
}


int getSize(Node* node)
{
    int size = 0;
    while (node != NULL) {
        node = node->next;
        size++;
    }
    return size;
}


node* addSameSize(Node* head1, Node* head2, int* carry)
{

    if (head1 == NULL)
        return NULL;

    int sum;


    Node* result = new Node[(sizeof(Node))];


    result->next
            = addSameSize(head1->next, head2->next, carry);


    sum = head1->data + head2->data + *carry;
    *carry = sum / 10;
    sum = sum % 10;


    result->data = sum;

    return result;
}


void Carry(Node* head1, Node* cur, int* carry,
           Node** result)
{
    int sum;


    if (cur != head1) {
        Carry(head1->next, cur, carry,
              result);

        sum = head1->data + *carry;
        *carry = sum / 10;
        sum %= 10;


        enter(result, sum);
    }
}


void add(Node* head2, Node* head1, Node** result)
{
    Node* cur;


    if (head1 == NULL) {
        *result = head2;
        return;
    }


    else if (head2 == NULL) {
        *result = head1;
        return;
    }

    int size1 = getSize(head1);
    int size2 = getSize(head2);

    int carry = 0;


    if (size1 == size2)
        *result = addSameSize(head1, head2, &carry);

    else {
        int diff = abs(size1 - size2);


        if (size1 < size2)
            swap(&head1, &head2);


        for (cur = head1; diff--; cur = cur->next)
            ;


        *result = addSameSize(cur, head2, &carry);


        Carry(head1, cur, &carry, result);
    }


    if (carry)
        enter(result, carry);
}


int main()
{
    Node *head1 = NULL, *head2 = NULL, *result = NULL;

    long long size1,size2;
    cin >> size1;
    long long arr1[size1];
    for(long long i=0;i<size1;i++){
        cin >> arr1[i];
    }
    cin >> size2;
    long long arr2[size2];
    for(long long i=0;i<size2;i++){
        cin >> arr2[i];
    }





    long long i;
    for (i = size1 - 1; i >= 0; --i)
        enter(&head1, arr1[i]);


    for (i = size2 - 1; i >= 0; --i)
        enter(&head2, arr2[i]);

    add(head2, head1, &result);

    printout(result);

    return 0;
}