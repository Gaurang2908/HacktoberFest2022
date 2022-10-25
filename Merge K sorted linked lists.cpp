/*
Input:
K = 4
value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8
Explanation:
The test case has 4 sorted linked 
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be
1->2->3->4->5->5->6->7->8.
*/
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


class Solution{
  public:
   .
    Node * mergeKLists(Node *arr[], int K)
    {
           if(K==0)
           return NULL;
           vector<pair<int , Node*>> a;
           for(int i=0;i<K;i++)
           {
               Node* n=arr[i];
               while(n!=NULL)
               {
                   a.push_back({n->data,n});
                   n=n->next;
               }
           }
           if(a.size()==0)
           return NULL;
           
           sort(a.begin(),a.end());
           for(int i=0;i<a.size()-1;i++)
           {
               a[i].second->next=a[i+1].second;
           }
           a[a.size()-1].second->next=NULL;
           return a[0].second;
    }
};
