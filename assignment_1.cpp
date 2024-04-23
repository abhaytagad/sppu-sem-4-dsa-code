#include<iostream>
using namespace std;
#include<stack>
#include<map>
#include<queue>
class node{
    friend class bianary_tree;
    int val;
    node* left ,*right;
public:
    node(int val){
        this->val = val;
        left = right = NULL;
    }
};

class bianary_tree{
    node* rootNode ;
public:
    bianary_tree(){
        rootNode = NULL;
    }

    void operator=(bianary_tree b){
        this->rootNode = deepCopyTree(b.rootNode);
    }

    node* deepCopyTree(node* root) {
        if (root == NULL){
            return NULL;
        }  
        map<node*, node*> nodeMap;
        queue<node*> q;
        q.push(root);
        node* newRoot = new node(root->val);
        nodeMap[root] = newRoot;
        while (!q.empty()) {
            node* curr = q.front();
            q.pop();
            if (curr->left) {
                q.push(curr->left);
                node* newNode = new node(curr->left->val);
                nodeMap[curr->left] = newNode;
                nodeMap[curr]->left = newNode;
            }
            if (curr->right) {
                q.push(curr->right);
                node* newNode = new node(curr->right->val);
                nodeMap[curr->right] = newNode;
                nodeMap[curr]->right = newNode;
            }
        }
        return newRoot;
}

    void insert(int val){
        if (rootNode == NULL){
            rootNode = new node(val);
            cout<<"Inserted Succesfully\n ";
            return;
        }

        node* temp = rootNode;

        while(true){

            int ch ;
            cout<<"1.left\n2.right\n of "<<temp->val<<'\n';
            cin>>ch;
            cout<<'\n';
            if (ch == 1){
                if (temp->left != NULL){
                    temp = temp->left;
                }
                else{
                    temp->left = new node(val);
                    cout<<"Inserted Succesfully\n ";
                    break;
                }
            }
            else if (ch == 2){

                if (temp->right != NULL){
                    temp = temp->right;
                }
                else{
                    temp->right = new node(val);
                    cout<<"Inserted Succesfully"<<'\n';
                    break;
                }
            }
            cout<<'\n';
        }
    }

    void iterative_preorder(){

        if (rootNode == NULL){
            return;
        }
        stack<pair<node*,bool>> st;
        st.push(make_pair(rootNode,false));
        cout<<st.top().first->val<<' ';
        bool flag = false;
        
        while(!st.empty()){

            if (st.top().first->left != NULL && !flag){
                st.push(make_pair(st.top().first->left,false));
                cout<<st.top().first->val<<' ';
            }
            else if(st.top().first->right != NULL && !st.top().second){
                st.top().second = true;
                if (flag){
                    flag = false;
                }
                st.push(make_pair(st.top().first->right,false));
                cout<<st.top().first->val<<' ';
                
            }
            else{
               
                st.pop();
                flag = true;
            }  
        }
    }

     void iterative_inorder(){

        if (rootNode == NULL){
            return;
        }
        stack<pair<node*,bool>> st;
        st.push(make_pair(rootNode,false));
        
        bool flag = false;
        
        while(!st.empty()){

            if (st.top().first->left != NULL && !flag){
                st.push(make_pair(st.top().first->left,false));
                
            }
            else if(st.top().first->right != NULL && !st.top().second){
                cout<<st.top().first->val<<' ';
                st.top().second = true;
                if (flag){
                    flag = false;
                }
                st.push(make_pair(st.top().first->right,false));   
            }
            else{
                
                if (st.top().second != true){
                    cout<<st.top().first->val<<' ';
                }
                st.pop();
                
                flag = true;
            } 
        }
    }

     void iterative_postorder(){

        if (rootNode == NULL){
            return;
        }
        stack<pair<node*,bool>> st;
        st.push(make_pair(rootNode,false));
        bool flag = false;
        int i = 10;
        while(!st.empty()){

            if (st.top().first->left != NULL && !flag){
                st.push(make_pair(st.top().first->left,false));
                
            }
            else if(st.top().first->right != NULL && !st.top().second){
                st.top().second = true;
                if (flag){
                    flag = false;
                }
                st.push(make_pair(st.top().first->right,false));   
            }
            else{
                cout<<st.top().first->val<<' ';
                st.pop();
                flag = true;
            }  
        }
    }

    void  preTraversal(node* rootnode){

        if (rootnode == NULL){
            return;
        }
        cout<<rootnode->val<<' ';
        preTraversal(rootnode->left);
        preTraversal(rootnode->right);
    }
    void  reccursive_preorder(){
        node* temp = rootNode;
        preTraversal(temp);
        return;
    }
    void inorderTraversal(node *rootnode){
        if (rootnode == NULL){
            return;
        }

        inorderTraversal(rootnode->left);
        cout<<rootnode->val<<' ';
        inorderTraversal(rootnode->right);
    }

    void reccursive_inorder(){
        node* temp = rootNode;
        inorderTraversal(temp);
    }

    void  postTraversal(node* rootnode){

        if (rootnode == NULL){
            return;
        }
        postTraversal(rootnode->left);
        postTraversal(rootnode->right);
        cout<<rootnode->val<<' ';
    }

    void reccursive_postorder(){
        node* temp = rootNode;
        postTraversal(temp);
        return;
    }

    int height(node* rootnode ){

        if (rootnode == NULL){
            return 0;
        }
        
        int lh = height(rootnode->left);
        int rh = height(rootnode->right);
        return max(lh +1,rh+1);
    }

    int Tree_height(){
        node* temp = rootNode;
        return height(temp);
    }

    int noLeaves(node* rootnode){
        if (rootnode == NULL){
            return 0;
        }
        else if(rootnode->left == NULL && rootnode->right == NULL){
            return 1;
        }
        int l = noLeaves(rootnode->left);
        int r = noLeaves(rootnode->right);
        return (l+r);
    }

    int NumberOfLeafNodes(){
        node* temp = rootNode;
        return noLeaves(temp);
    }

    void internal(node* rootnode , int &nodes){

        if(rootnode == NULL){
            return ;
        }
        else if(rootnode->left != NULL || rootnode->right != NULL){
            nodes++;
        }
        internal(rootnode->left,nodes);
        internal(rootnode->right,nodes);
    }

    int NumberOfInternalNodes(){
        int nodes = 0;
        node* temp = rootNode;
        internal(temp,nodes);
        return nodes;
    }

    void swapNodes(node* rootnode){
        if (rootnode == NULL){
            return;
        }

        if (rootnode->left != NULL && rootnode->right != NULL){
            node* temp = rootnode->left;
            rootnode->left = rootnode->right;
            rootnode->right = temp;
        }
        else if(rootnode->left != NULL){
            rootnode->right = rootnode->left;
            rootnode->left = NULL;
        }
        else if (rootnode->right != NULL){
            rootnode->left = rootnode->right;
            rootnode->right = NULL;
        }
        swapNodes(rootnode->left);
        swapNodes(rootnode->right);
    }

    void swap_nodes(){
        node* temp = rootNode;
        swapNodes(temp);
    }

    void erasenodes(node* rootnode){

        if (rootnode == NULL){
            return;
        }
        erasenodes(rootnode->left);
        erasenodes(rootnode->right);
        delete rootnode; 
    }

    void reccursive_erase(){
        node* temp = rootNode;
        erasenodes(temp);
        rootNode = NULL;
        cout<<"erased succesfully";
    }
};




int main(){ 
 
    bianary_tree b ;
    bianary_tree copied;  
    while (true)
    {
        int ch ;
        cout<<"enter the choice\n1.insert data\n2. inorder traversal\n3. postorder traversal\n4. preorder traversal\n5.change tree\n6.height\n7.copy tree\n8.Number of Leaves\n9.internal nodes\n10.erase all nodes\n";
        cin>>ch;
        if (ch == 1){
            int val;
            cout<<"enter the value\n";
            cin>>val;
            b.insert(val);
        }
        else if (ch == 2){
            cout<<"1.reccursively\n2.iterative\n ";
            int type;
            cin>>type;
            if (type == 1){
                b.reccursive_inorder();
            }
            else{
                b.iterative_inorder();
            }
        }
         else if (ch == 3){
            cout<<"1.reccursively\n2.iterative\n ";
            int type;
            cin>>type;
            if (type == 1){
                b.reccursive_postorder();
            }
            else{
                b.iterative_postorder();
            }
        }
         else if (ch == 4){
            cout<<"1.reccursively\n2.iterative\n ";
            int type;
            cin>>type;
            if (type == 1){
                b.reccursive_preorder();
            }
            else{
                b.iterative_preorder();
            }
        }
        else if (ch == 5){
            b.swap_nodes();
            cout<<"swaped succesfully\n";
        }
        else if (ch == 6){
            cout<<"the height is : "<<b.Tree_height();
        }
        else if(ch == 7){
            bianary_tree copied;
            copied = b;
            cout<<"copied succesfully\n";
        }
        else if(ch == 8){
            cout<<"the number of leaf :"<<b.NumberOfLeafNodes();
        }
        else if(ch == 9){
            cout<<"the number of internal :"<<b.NumberOfInternalNodes();
        }
        else if(ch == 10){
            b.reccursive_erase();
        }
        else{
            cout<<"Invalid input try again\n";
        }
        cout<<'\n';
        cout<<'\n';
        cout<<'\n';
    }
    
} 