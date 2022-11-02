/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/
#include <bits/stdc++.h> 
using namespace std;


 /*Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };*/
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
         ListNode*Fhead=NULL;
         ListNode*temp=NULL;
        int carry=0;
        while(l1!=NULL && l2!=NULL){
            
           int sum=l1->val+l2->val;
            if(carry==1){
                sum+=1;
                carry=0;
            }
            if(sum>=0 && sum<=9){
                if(Fhead==NULL){
               ListNode*newnode=new ListNode(sum);
                    Fhead=newnode;
                    temp=newnode;
            }
                else{
                    ListNode*newnode=new ListNode(sum);
                    temp->next=newnode;
                    temp=temp->next;
                }
            
            }
            else{
                 if(Fhead==NULL){
               ListNode*newnode=new ListNode(sum%10);
                    Fhead=newnode;
                    temp=newnode;
            }
                else{
                    ListNode*newnode=new ListNode(sum%10);
                    temp->next=newnode;
                     temp=temp->next;
                }
              carry=1;  
               
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL) {
            if(carry==1){
                int sum=l1->val+1;
                carry=0;
                if(sum>=0 && sum<=9){
                  ListNode*newnode=new ListNode(sum);
                    temp->next=newnode; 
                     temp=temp->next;
                }
                else{
                    ListNode*newnode=new ListNode(sum%10);
                    temp->next=newnode;
                     temp=temp->next;
                    carry=1;
                }
            }
            else{
                 ListNode*newnode=new ListNode(l1->val);
                    temp->next=newnode;
                     temp=temp->next;
            }
         l1=l1->next; 
            
        }  
        while(l2!=NULL) {
            if(carry==1){
                int sum=l2->val+1;
                carry=0;
                if(sum>=0 && sum<=9){
                  ListNode*newnode=new ListNode(sum);
                    temp->next=newnode; 
                     temp=temp->next;
                }
                else{
                    ListNode*newnode=new ListNode(sum%10);
                    temp->next=newnode;
                     temp=temp->next;
                    carry=1;
                }
            }
            else{
                 ListNode*newnode=new ListNode(l2->val);
                    temp->next=newnode;
                     temp=temp->next;
            }
              l2=l2->next; 
        
        }  
        if(carry==1){
             ListNode*newnode=new ListNode(1);
            temp->next=newnode; 
            
        }
        return Fhead;
    }
};