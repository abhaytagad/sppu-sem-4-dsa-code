#include<iostream>
using namespace std;
#include<stack>

class node{
    
    string key,value;
    node* left,*right;
    friend class Dictionary;
public:
    node(string word,string mean){

        value = mean;
        key = word;
        left = right = NULL;
    }

};
 
 

class Dictionary{

    node* rootnode;
public:

    Dictionary(){
        rootnode = NULL;
    }

    void insert(string word,string mean){

        node* new_node = new node(word,mean);

        if (rootnode == NULL){
            rootnode = new_node;
            cout<<"added succesfully\n";
            return;
        }

        node* temp = rootnode;

        while (true)
        {
            if (temp->key > word){
                if (temp->left == NULL){
                    temp->left = new_node;
                    cout<<"added succesfully\n";
                    return;
                }
                temp = temp->left;
                
            }
            else{

                if (temp->right == NULL){
                    temp->right = new_node;
                    cout<<"added succesfully\n";
                    return;
                }
                temp = temp->right;
                

            }
        }
        
    }


    void update(string word,string mean){

        if (rootnode == NULL){
            cout<<"keyword is not present\n";
            return;
        }

        node* temp = rootnode;

        while (true)
        {
            if (temp->key > word){
                if (temp->left == NULL){
                    cout<<"keyword is not present\n";
                    return;
                }
                temp = temp->left;
                
            }
            else if (temp->key < word){

                if (temp->right == NULL){
                    cout<<"keyword is not present\n";
                    return;
                }
                temp = temp->right;
                

            }
            else if (temp->key == word){

                temp->value = mean;
                cout<<"updated succesfully\n";
                return;
            }
        }
        
    }
    

    void inorderTraversal(node *rootNode){
        if (rootNode == NULL){
            return;
        }

        inorderTraversal(rootNode->left);
        cout<<rootNode->key<<':'<<rootNode->value<<'\n';
        inorderTraversal(rootNode->right);
    }

    void reccursive_inorder(){
        node* temp = rootnode;
        inorderTraversal(temp);
    }

    node* succesur(node* Node) {

        node* current = Node->left;

        if (current->right != NULL){
            while (true ){
                if (current->right->right == NULL){
                    node* temp = current;
                    temp->right = NULL;
                    current=current->right;
                    break;
                }
                current=current->right;   
            }
        }
        else{
            Node->left = NULL;
        } 
            
        return current;
    }

    void deleteNode(string word) {

        if (rootnode == NULL){
            cout<<"tree is empty";
            return;
        }

        stack<node*> st;
        node* temp = rootnode;
        
        while (true)
        {
            if (temp->key == word){

                if (temp->left == NULL && temp->right == NULL){
                    
                    if (st.top()->left == temp){
                       
                        st.top()->left =NULL;
                    }
                    else{
                        st.top()->right = NULL;
                    }
                    cout<<"delete succesfully\n";
                    return;
                }
                else if (temp->left == NULL){
                    if (st.top()->left == temp){
                        st.top()->left = temp->right;
                    }
                    else{
                        st.top()->right = temp->right;
                    }
                    cout<<"delete succesfully\n";
                    return;
                }
                else if (temp->right == NULL){

                    if (st.top()->left == temp){
                        st.top()->left = temp->left;
                    }
                    else{
                        st.top()->right = temp->left;
                    }

                    cout<<"delete succesfully\n";
                    return;
                }
                else{

                    node* curre = succesur(temp);
                    temp->key = curre->key;
                    temp->value = curre->value;
                    delete curre;
                    cout<<"delete succesfully\n";
                    return;
                }
            }
            else if (temp->key > word){
                st.push(temp);
                temp = temp->left;  
            }
            else{
                st.push(temp);
                temp = temp->right;
            }
            
        }
        
        return ;
    }

    

};

int main(){ 
 
    Dictionary d;

    while (true)
    {
        int ch ;
        cout<<"enter the choice\n1.add key\n2.update value\n3.delete key\n4.print in assending order\n";
        cin>>ch;

        if (ch == 1){
            string key,value;
            cout<<"enter the key\n";
            cin>>key;
            cout<<"enter the value\n";
            cin>>value;
            d.insert(key,value);
        }
        else if (ch == 2){
            string key,value;
            cout<<"enter the key\n";
            cin>>key;
            cout<<"enter the value\n";
            cin>>value;
            d.update(key,value);
        }
        else if (ch == 3){
            string key;
            cout<<"enter the key\n";
            cin>>key;
            d.deleteNode(key);
        }
        else if(ch == 4){
            d.reccursive_inorder();
        }
        else{
            cout<<"Invalid input Please try again\n";
        }
        cout<<'\n';
        cout<<'\n';
    }
    
 
} 