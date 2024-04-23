#include<iostream>
using namespace std;
 

class node{
    friend class threaded_BST;
    int val ;
    node *left,*right,*Lthread,*Rthread;
public:
    node (int val){
        this->val = val;
        left = right = Lthread = Rthread = NULL;
    }
};

class threaded_BST{
    node* rootNode;
public:

    threaded_BST(){
        rootNode = NULL;
    }

    void insert(int val){

        node* new_node = new node(val);

        if (rootNode == NULL){
            rootNode = new_node;
            cout<<val<<" inserted succesfully\n";
            return;
        }
        node* temp = rootNode;

        while(temp){
            if (temp->val > val){
                if (temp->left == NULL){
                    temp->left = new_node;
                    new_node->Rthread = temp;
                    new_node->Lthread = temp->Lthread;
                    temp->Lthread = NULL;
                    
                    cout<<val<<" inserted succesfully\n";
                    return;
                }
                else{
                   temp = temp->left;
                }
            }
            else{
                if (temp->right == NULL){
                    new_node->Lthread = temp;
                    temp->right = new_node;
                    new_node->Rthread = temp->Rthread;
                    temp->Rthread = NULL;
                  
                    cout<<val<<" inserted succesfully \n";
                    return;
                }
                else{
                   temp = temp->right;
                }
            }
        }
    }

    void inorder(){

        if (rootNode == NULL){
            return;
        }
        node* temp = rootNode;
        bool flag = false;
        while (temp)
        {
            
            if (temp->left != NULL && !flag){
                temp = temp->left;
            }
            else{
                flag = true;
                cout<<temp->val<<' ';
                if (temp->Rthread != NULL){
                    temp = temp->Rthread;
                }
                else{
                    temp = temp->right;
                    flag = false;
                }

            }
        }
        
    }

    void preorder(){

        if (rootNode == NULL){
            return;
        }
        node* temp = rootNode;
        cout<<temp->val<<' ';
        bool flag = false;
        while (temp)
        {
            if (temp->left != NULL && !flag ){
                temp = temp->left;
                cout<<temp->val<<' ';
            }
            else if (temp->right != NULL){
                temp = temp->right;
                cout<<temp->val<<' ';
                flag = false;
            }
            else{
                flag = true;
                temp = temp->Rthread;
            }   
        }
        
    }

    node* inorderSuccesor(node* temp){

        node* root = temp;
        temp = temp->left;
        while (temp)
        {
            if(temp->right == NULL){

                cout<<temp->val;
                return temp;
            }
           temp = temp->right;
        } 
    }


    void Delete(int val){

        if (rootNode == NULL){
            return;
        }
        node* temp = rootNode;

        while(temp){

            if (temp->val == val){
                
                if(temp->left != NULL && temp->right == NULL){
                    if (temp->left->Rthread == temp )
                    {
                        temp->val = temp->left->val;
                        temp->Lthread = temp->left->Lthread;
                        if (temp->left->left != NULL){
                            temp->left = temp->left->left;
                        }
                        else if (temp->left->right != NULL){
                            temp->right = temp->left->right;
                        }
                        
                        return;
                    }
                   
                }
                else if (temp->right != NULL && temp->left == NULL){

                    if (temp->right->Lthread == temp )
                    {
                        temp->val = temp->right->val;
                        temp->Rthread = temp->right->Rthread;
                        temp->right = temp->right->right;
                        return;
                    }  

                } else if (temp->right == NULL && temp->left == NULL){

                    if (temp->Lthread->right == temp )
                    {
                        temp->Lthread->Rthread = temp->Rthread;
                        temp->Lthread->right = NULL;
                        delete temp;
                        return;
                    }
                    else{
                        
                        temp->Rthread->Lthread = temp->Lthread;
                        temp->Rthread->left = NULL;
                        delete temp;
                        return;
                    }                    
                }
                else{
                    
                    node* succesor = inorderSuccesor(temp);
                    temp->val = succesor->val;
                    succesor->Lthread->Rthread = succesor->Rthread;
                    succesor->Lthread->right = NULL;
                    delete succesor;
                    return;
                    
                }
            }
            else if (temp->val > val){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
    } 
};
 
 
int main(){ 
 
    threaded_BST b;

    while(true){

        int ch;
        cout<<"enter the choice\n1.insert value\n2.preorder traversal\n3.inorder traversal\n4.delete node\n";
        cin>>ch;
        if (ch == 1){
            cout<<"enter the value :";
            int val;
            cin>>val;
            b.insert(val);
        }
        else if (ch == 2){
            cout<<"preorder : ";
            b.preorder();
        }
        else if (ch == 3){
            cout<<"inoder : ";
            b.inorder();
        }
        else if(ch == 4){
            int val;
            cout<<"enter the value\n";
            cin>>val;
            b.Delete(val);
            cout<<"deleted Succesfully\n";
        }
        cout<<"\n";
    }

  
 
    


    
} 

/*                      5
                     2      8 
                      3    7   9
                       4  6      10
*/