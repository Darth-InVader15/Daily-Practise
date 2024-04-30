//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head){
        Node* cur=head;
        Node* next=NULL;
        Node* prev=NULL;
        
        while(cur){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        
        return prev;
        
    }
    
    void insertAtTail(Node* &ansh,Node* &anst,int val){
        Node* temp = new Node(val);
        if(ansh==NULL){
        ansh=temp;
        anst=temp;
            return ;
        }
        
        else{
            anst->next=temp;
            anst=temp;
        }
        
    }
    Node* add(Node* h1, Node* h2){
        
        int carry=0;
        Node* ansh=NULL;
        Node* anst=NULL;
        while(h1!=NULL || h2!=NULL || carry!=0){
            int val1=0;
            if(h1!=NULL)
            val1=h1->data;
            
            int val2=0;
            if(h2!=NULL)
            val2=h2->data;
            
            int sum=carry+val1+val2;
            int digit=sum%10;
            
            insertAtTail(ansh,anst,digit);
            
            carry=sum/10;
            
            if(h1!=NULL)
            h1=h1->next;
            
            if(h2!=NULL)
            h2=h2->next;
            
            
        }
        
        return ansh;
    }
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        while(num1 && num1->data==0){
            num1=num1->next;
        }
        
        while(num2 && num2->data==0){
            num2=num2->next;
        }
        
        if(num1==NULL && num2==NULL){
            Node* ans= new Node(0);
            return ans;
        }
        num1=reverse(num1);
        num2=reverse(num2);
        
        Node* ans=add(num1,num2);
        
        ans = reverse(ans);
        
        Node* head=ans;
        Node* tail=ans;
        if(head->data==0){
            head=head->next;
            delete(tail);
            ans=head;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends