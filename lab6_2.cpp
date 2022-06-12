#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct ll_node {
    ll digits;
    ll_node *nxtNode;
};

ll_node *createNewNode(ll digits);

void insert_node(ll_node **refToHead, ll new_data);

ll_node *add(ll_node *l1, ll_node *l2);

ll_node *flip(ll_node *head);


int main() {
    ll n1, n2, temp;
    ll_node *answer, *l1 = nullptr, *l2 = nullptr;


    cin >> n1;
    for (ll i{0}; i < n1; i++) {
        cin >> temp;
        insert_node(&l1, temp);
    }

    cin >> n2;
    for (ll i{0}; i < n2; i++) {
        cin >> temp;
        insert_node(&l2, temp);
    }

    answer = flip(add(l1, l2));

    while (true) {
        if (answer == nullptr) {
            return 0;
        }
        cout << answer->digits << " ";
        answer = answer->nxtNode;
    }
}

ll_node *createNewNode(ll digits) {
    ll_node *new_node = new ll_node();
    new_node->digits = digits;
    new_node->nxtNode = nullptr;
    return new_node;
}

void insert_node(ll_node **refToHead, ll new_data) {
    ll_node *new_node = createNewNode(new_data);

    new_node->nxtNode = (*refToHead);

    *refToHead = new_node;
}

ll_node *add(ll_node *l1, ll_node *l2) {

    ll carry{0}, sum{0};
    ll_node *answer = nullptr, *tempNode, *prevNode = nullptr;

    while (true) {
        if (l1 == nullptr
            && l2 == nullptr) {
            break;
        } else {
            sum = carry + (l1 ? l1->digits : 0)
                  + (l2 ? l2->digits : 0);

            if ((sum > 9)) {
                carry = 1;
            } else {
                carry = 0;
            }
            sum %= 10;

            tempNode = createNewNode(sum);

            if (answer == nullptr)
                answer = tempNode;

            else
                prevNode->nxtNode = tempNode;

            prevNode = tempNode;

            if (l1)
                l1 = l1->nxtNode;
            if (l2)
                l2 = l2->nxtNode;
        }

        if (!(carry <= 0))
            tempNode->nxtNode = createNewNode(carry);
    }

    return answer;
}

ll_node *flip(ll_node *head) {
    if (head == nullptr)
        return head;
    else if (head->nxtNode == nullptr)
        return head;

    ll_node *rev_list = flip(head->nxtNode);
    head->nxtNode->nxtNode = head;
    head->nxtNode = nullptr;

    return rev_list;
}
