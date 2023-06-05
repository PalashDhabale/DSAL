#include<iostream>

using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;
    
    node(int data)
    {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }

};
node* insertintoBST(node* &root , int d)
{
    //base case
    if(root == NULL)
    {
        root = new node(d);
        return root;
    }
    //right part
    if(d> root-> data)
    {
        root -> right == insertintoBST(root -> right , d);
    }
    //left part
    else{
        root -> left == insertintoBST(root-> left , d);
    }

    return root ;
}

void takeinput(node* &root)
{
    int data;
    cin >> data;

    while(data !=-1)
    {
        insertintoBST(root , data);
        cin >> data;
    }
}

int main()
{
    node* root = NULL;

    int choice , value;
    cout <<"\t MENU \n";
    cout <<" \t 1.Insert Value into tree \n";
    cout<<" \t 2.Find the number of nodes in the longest path\n";
    cout<<" \t 3.find minimum value in the tree \n";
    cout<<" \t 4.Swap the left and right pointers at every node in the tree \n";
    cout<<" \t 5.Search for a value in tree \n";
    cout<<" \t 6.print the tree in inorder traversal \n";
    cout<<" \t 7. Exit \n";
    do
    {
        cout<<"Enter your Choice :\n";
        cin >> choice;
    switch (choice)
    {
    case 1:
        cout<<"Enter the data to insert into BST"<<endl;
        takeinput(root);
        break;
    
    default:
        break;
    }
    } while (choice != 0);
    


    // cout<<"Enter the data to insert into BST"<<endl;
    // takeinput(root);
    // return 0;
}