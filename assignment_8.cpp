#include<iostream>
#include<vector>
using namespace std;


class data{
    friend class OBST;
    int cost,weight,root;
public:
    data(){}
};

class node{
    friend class OBST;
    int val;
    node *left, *right;
public:
    node(int val){
        this->val = val;
        left = right = NULL;
    }
};


class OBST{
    vector<vector<data>> table;
    vector<int> keys;
    vector<int> p;
    vector<int> q;
    node* rootNode;

    void createOBST(){

        int itr = keys.size();
        while(itr >= 0){

            int i = 0;
            int j = keys.size() - itr;
            
            while(i != itr+1){
                
                if (i == j){
                    data d ;
                    d.weight = q[j];
                    d.cost = 0;
                    d.root = 0;
                    table[i][j] = d;
                }
                else{
                    data  d ;
                    d.weight = table[i][j-1].weight + p[j-1] + q[j];
                    int min_val = INT16_MAX;
                    int root;
                    for(int k = i+1; k <=j ; k++){
                        int cost = table[i][k-1].cost + table[k][j].cost;
                        if (cost < min_val){
                            min_val = cost;
                            root = k;
                        }
                    }
                    d.root = root;
                    d.cost = min_val + d.weight;
                    table[i][j] = d;
                }
                i++;
                j++;
            }
            itr -- ;
        }

        itr = keys.size();
        
        while(itr >= 0){

            int i = 0;
            int j = keys.size() - itr;
            
            while(i != itr+1){
                cout<<'['<<table[i][j].weight<<' '<<table[i][j].cost<<' '<<table[i][j].root<<"] ";
                i++;
                j++;
            }
            cout<<'\n';
            itr -- ;
        }
        bst(0,keys.size());
    }

    void bst(int i , int j){

        if (rootNode == NULL){
            rootNode = new node(keys[table[i][j].root-1]);
            bst(i,table[i][j].root-1);
            bst(table[i][j].root,j);
            return;
        }
        if (table[i][j].root == 0 || i == j){
            return;
        }

        node* temp = rootNode;
        node* new_node = new node(keys[table[i][j].root-1]);

        while (temp)
        { 
            if(new_node->val > temp->val ){
                if(temp->right == NULL){
                    temp->right = new_node;
                    bst(i,table[i][j].root-1);
                    bst(table[i][j].root,j);
                    return;
                }
                else{
                    temp = temp->right;
                }
            }
            else if(new_node->val < temp->val ){
                if(temp->left == NULL){
                    temp->left = new_node;
                    bst(i,table[i][j].root-1);
                    bst(table[i][j].root,j);
                    return;
                }
                else{
                    temp = temp->left;
                }
            }
        }  
    }

public:

    OBST(){
        rootNode = NULL;
        int n;
        cout<<"Enter the number of Keys to be enter :";
        cin>> n;
        cout<<"Enter the  Keys :";
        for (int i = 0; i < n; i++){
            int key;
            cin>>key;
            keys.push_back(key);
        }
        cout<<"Enter the  probability of succesfull :";
        for (int i = 0; i < n; i++){
            int val;
            cin>>val;
            p.push_back(val);
        }
        cout<<"Enter the  probability of unsuccesfull :";
        for (int i = 0; i <= n; i++){
            int val;
            cin>>val;
            q.push_back(val);
        } 
        table.resize(keys.size()+1, vector<data>(keys.size()+1));
        createOBST();
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
};
 
int main(){ 
 
    OBST b;
    b.reccursive_inorder();
 
} 