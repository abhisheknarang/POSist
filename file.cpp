#include<bits/stdc++.h>
#include<fstream>
#include<cstdlib>
using namespace std;
int getID(){
int num;
cin>>num;
return;
}
int gethash(int id, float value, string name){
	int m = id;
	float val = value;
	string naming = name;
return ;
}
time_t getdate(){
	cin>>date;
return ;
}

int getNumber(){
	cin>>targetno;
return ; 
}
struct Node{
    time_t timestamp;
    int nodeNumber;
    vector <string> data;
    string nodeId;
    string referenceNodeId;
    string childReferenceNodeId;
    string genesisReferenceNodeId;
    vector <string> HashValue;
};

Node* GenesisNode=NULL;

class dynamic_list{
    private: 
	int id; 
	float value; 
	string name; 
	vector <string> data; 
	vector <string> HashValue;
    public: 
	dynamic_list(int flag){
                GenesisNode = new Node;
                GenesisNode->timestamp = getDate();
                cout<<"Owner Id :" ;cin>>id; data.push_back(id);
                cout<<"Value :" ; cin>>value; data.push_back(value);
                cout<<"Owner Name :"; getline(cin,name); data.push_back(name);
                int hashvalue = gethash(id,value, name); data.push_back(hashvalue); 
                GenesisNode->data = data;
                GenesisNode->nodeNumber = getNumber();
                GenesisNode->nodeId = getID();
                GenesisNode->referenceNodeId= NULL;
                GenesisNode->childReferenceNodeId = NULL;
                GenesisNode->genesisReferenceNodeId = 0;
                int hashvalue1; 
                hashvalue1 = gethash(timestamp, data, nodeNumber, nodeId, referenceNodeId, childReferenceNodeId,genesisReferenceNodeId);
                HashValue.push_back(hashvalue1);
                GenesisNode->HashValue = HashValue;
                }
               void newnode(String referenceNodeId){
                    Node newNode = new Node;
                    newNode->nodeNumber = getID();
                    
               } 
};
void createNode(int parent[], int i, Node *created[], Node **root)
{
    // If this node is already created
    if (created[i] != NULL)
        return;
 
    // Create a new node and set created[i]
    created[i] = newNode(i);
 
    // If 'i' is root, change root pointer and return
    if (parent[i] == -1)
    {
        *root = created[i];
        return;
    }
 
    // If parent is not created, then create parent first
    if (created[parent[i]] == NULL)
        createNode(parent, parent[i], created, root);
 
    // Find parent pointer
    Node *p = created[parent[i]];
 
    // If this is first child of parent
    if (p->left == NULL)
        p->left = created[i];
    else // If second child
        p->right = created[i];
}
 
// Creates tree from parent[0..n-1] and returns root of the created tree
Node *createTree(int parent[], int n)
{
    //  An array created[] to keep track
    // of created nodes, initialize all entries
    // as NULL
    Node *created[n];
    for (int i=0; i<n; i++)
        created[i] = NULL;
 
    Node *root = NULL;
    for (int i=0; i<n; i++)
        createNode(parent, i, created, &root);
 
    return root;
}
bool create_child_particular(struct node *GenesisNode, int target)
{
  /* base cases */
  if (GenesisNode == NULL)
     return false;
 
  if (GenesisNode->data == target)
     return true;
 
  /* If target is present in either left or right subtree of this node,
     then print this node */
  if (create_child_particular(GenesisNode->left, target) ||
       create_child_particular(GenesisNode->right, target) )
  {
    cout << root->data << " ";
    return true;
  }
 
  /* Else return false */
  return false;
}
void Encrypt(Node *targetNode)
{
	while(targetNode->next !=NULL )
	{
		cout<<targetNode->data;
		targetNode = targetNode->next;
	}
	  for(i = 0; (i < 100 && str[i] != '\0'); i++)
            str[i] = str[i] + 2; //the key for encryption is 3 that is added to ASCII value

         cout << "\nEncrypted string: " << str << endl;
}
void Decrypt(Node *targetNode)
{
		while(targetNode->next !=NULL )
	{
		cout<<targetNode->data;
		targetNode = targetNode->next;
	}
	 for(i = 0; (i < 100 && str[i] != '\0'); i++)
         str[i] = str[i] - 2; //the key for encryption is 3 that is subtracted to ASCII value

      cout << "\nDecrypted string: " << str << endl;
}
bool Verify(Node *targetNode, String EncryptedString)
{
	if(targetNode->data == EncryptedString)
	    return true;
	else
	    return false;
}
void longestConsecutiveUtil(Node* GenesisNode, int curLength,
                              int expected, int& res)
{
    if (root == NULL)
        return;
 
    // if root data has one more than its parent
    // then increase current length
    if (root->data == expected)
        curLength++;
    else
        curLength = 1;
 
    //  update the maximum by current length
    res = max(res, curLength);
 
    // recursively call left and right subtree with
    // expected value 1 more than root data
    longestConsecutiveUtil(root->left, curLength,
                           root->data + 1, res);
    longestConsecutiveUtil(root->right, curLength,
                           root->data + 1, res);
}
 
// method returns length of longest consecutive
// sequence rooted at node root
int longestConsecutive(Node* root)
{
    if (root == NULL)
        return 0;
 
    int res = 0;
 
    //  call utility method with current length 0
    longestConsecutiveUtil(root, 0, root->data, res);
 
    return res;
}
struct Node* Merge(struct Node* a, struct Node* b)
{
    /* a dummy first node to hang the result on */
    struct Node dummy;
 
    /* tail points to the last result node  */
    struct Node* tail = &dummy;
 
    /* so tail->next is the place to add new nodes
      to the result. */
    dummy.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
            /* if either list runs out, use the
               other list */
            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            MoveNode(&(tail->next), &a);
        else
            MoveNode(&(tail->next), &b);
 
        tail = tail->next;
    }
    return(dummy.next);
}
void MoveNode(struct Node** destRef, struct Node** sourceRef)
{
    /* the front source node  */
    struct Node* newNode = *sourceRef;
    assert(newNode != NULL);
 
    /* Advance the source pointer */
    *sourceRef = newNode->next;
 
    /* Link the old dest off the new node */
    newNode->next = *destRef;
 
    /* Move dest to point to the new node */
    *destRef = newNode;
}
 
int main()
{
	int parent[] =  {-1, 0, 0, 1, 1, 3, 5};
    int n = sizeof parent / sizeof parent[0];
    Node *root = createTree(parent, n);
    cout << "constructed tree\n";
	
  struct node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->left->left->left  = newnode(7);
 
  create_child_particular(root, 7);
 
  getchar();
  
  
    Node* root = newNode(6);
    root->right = newNode(9);
    root->right->left = newNode(7);
    root->right->right = newNode(10);
    root->right->right->right = newNode(11);
    Encrypt(root);
    Decrypt(root);
    verify(root, encrypt);
 
    printf("%d\n", longestConsecutive(root));
    
    struct Node* res = NULL;
    struct Node* a = NULL;
    struct Node* b = NULL;
 
    /* Let us create two sorted linked lists to test
      the functions
       Created lists, a: 5->10->15,  b: 2->3->20 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
 
    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
 
    /* Remove duplicates from linked list */
    res = SortedMerge(a, b);
 
    printf("Merged Linked List is: \n");
    printList(res);
    return 0;
}

