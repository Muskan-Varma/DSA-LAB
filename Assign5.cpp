#include<iostream>
#include<bits/stdc++.h>
#include <string>
#include<fstream>
using namespace std;


class Node{
    public:
    char data;
    Node *left;
    Node *right;
    
    Node(char val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};


class BinaryTree{
    public:
    BinaryTree(){}
    
    Node* buildBinaryTree(string  s);
    void inorder(Node* root);
    int evalTree(Node* root);
    void postorderNonrecursive(Node* root);
    void deleteTree(Node* root);
    void menu();
};

int BinaryTree :: evalTree(Node* root){
    if(!root) return 0;

    if(!root->left && !root->right){
        return root->data - 48;
    }

    int left_value  = evalTree(root->left);
    int right_value = evalTree(root->right);

    if(root->data == '+'){
        return left_value + right_value;
    }
    else if (root->data == '*')
    {
        return left_value * right_value;
    }
    else if (root->data == '-')
    {
        return left_value - right_value;
    }
    else if (root->data == '/')
    {
        return left_value / right_value;
    }

    return 0;
}

void BinaryTree :: inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    cout << root->data << "\t";
    inorder(root->right);
}

Node* BinaryTree :: buildBinaryTree(string s){
    stack<Node*> st;
    Node *root = NULL,*left =NULL, *right = NULL;
    char ch;
    int n = s.size();

    for(int i=n-1;i>=0;i--){
        ch = s[i];
        root = new Node(ch);

        if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')){
            left  = st.top();st.pop();
            right = st.top();st.pop();
            root->left = left;
            root->right = right;
            st.push(root);
        }else{
            st.push(root);
        }

    }
    
    return root;
}


void BinaryTree :: postorderNonrecursive(Node* cur){
if (cur == NULL) return;

  stack<Node*> st;


  while(cur != NULL || !st.empty()) {
    if (cur != NULL) {
      st.push(cur);
      cur = cur -> left;
    }else{
      Node *temp = st.top()->right;
      if (temp == NULL) {
        temp = st.top();
        st.pop();
        cout << temp -> data << "\t";
        while (!st.empty() && temp == st.top() -> right) {
          temp = st.top();
          st.pop();
          cout << temp -> data << "\t";
        }
      } else cur = temp;
    }
  }
}

void BinaryTree :: deleteTree(Node* root){
    if (root == NULL) return;
 
 
    deleteTree(root->left);
    deleteTree(root->right);
     

    cout << "\n Deleting node: " << root->data;
    delete root;
}
 

 void BinaryTree :: menu(){
    int flag = 1;
    int ch;
    string s = "+--a*bc/def";
    
    string str = "";
    Node *root = buildBinaryTree(s);


    while (flag)
    {
        cout<<"\n\n\n------------------------------------\nMENU";
		cout<<"\n1. Enter a new prefix expression";
		cout<<"\n2. Display expression in inorder";
		cout<<"\n3. Display expression in postorder";
        cout<<"\n4. evaluate expression (only if numbers are inputed as an operands)";
		cout<<"\n5. Delete the tree";
        cout<<"\n6. Exit";
		cout<<"\n\nEnter the choice: ";
		cin>>ch;

        switch(ch)
        {
            case 1:
				cout<<"\nEnter a new prefix expression: ";
				cin>>str;
            	root = buildBinaryTree(str);
                break;

            case 2:
				inorder(root);
                break;
            case 3:
                postorderNonrecursive(root);
                break;
            case 4:
                if(root)
                    cout<<"\nevaluation of tree is :"<<evalTree(root);
                else
                    cout<<"\ntree is empty";
                break;
            case 5:
                deleteTree(root);
            	break;
            case 6:
                flag = 0;
                break;
            default:
                cout<<"\nenter the correct choice";
        }
    }
    
 }

int main(){
    string s = "+--a*bc/def";
    BinaryTree b1;
    b1.menu();

    // Node *root = b1.buildBinaryTree(s);
    // b1.inorder(root);
    // cout << endl;
    // cout << "Non reursive postorder: " ;
    // b1.postorderNonrecursive(root);
    // b1.deleteTree(root);
    // cout << endl <<"Inorder" << endl;
    // b1.inorder(root);

    return 0;
}

