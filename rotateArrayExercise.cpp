#include<iostream>
#include<vector>

using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        ListNode* temp = head;
        vector<int> arr;

        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;
        k = k % arr.size(); 

        while (k != 0) {
            int lastEle = arr.back();
            arr.pop_back();
            arr.insert(arr.begin(), lastEle);
            k--;
        }

        ListNode* newHead = new ListNode(arr[0]);
        ListNode* temp2 = newHead;

        for (int i = 1; i < arr.size(); i++) {
            ListNode* createdNode = new ListNode(arr[i]);
            temp2->next = createdNode;
            temp2 = createdNode;
        }

        return newHead;
    }
};

int main() {
    // Test cases or usage examples can be added here
    return 0;
}
