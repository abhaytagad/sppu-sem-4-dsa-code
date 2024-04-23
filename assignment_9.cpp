
#include<iostream>
#include<map>
#include<stack>
using namespace std;

class node{
    friend class AVL_tree;
    string key,value;
    node *right,*left;
public:
    node(){
        right = left = NULL;
    }
};
 

class AVL_tree{

    node* rootNode;
    int height(node* rootnode   ){

        if (rootnode == NULL){
            return 0;
        }
        
        int lh = height(rootnode->left);
        int rh = height(rootnode->right);
       
        return max(lh +1,rh+1);
    }


    void check(stack<node*> st){

        map<node*,bool> m1;
       while (!st.empty())
       {
            node* rootnode = st.top();
            m1[rootnode] = true;
            int left_height;
            int right_height;

            if(rootnode->left != NULL){
                left_height = height(rootnode->left);
            }
            else{
                left_height = 0;
            }
            
            if(rootnode->right != NULL){
                
                right_height = height(rootnode->right);
            }
            else{
                right_height = 0;
            }

            if ( abs(right_height -left_height) != 1 && abs(right_height -left_height) != 0 ){
              
                if(right_height > left_height){
                    if(m1[rootnode->right->right]){
                        rotate(rootnode,rootnode->right,rootnode->right->right,"RR");
                    }
                    else{
                        rotate(rootnode,rootnode->right,rootnode->right->left,"RL");
                    }

                }
                else{
                    if(m1[rootnode->left->right]){
                        rotate(rootnode,rootnode->left,rootnode->left->right,"LR");
                    }
                    else{
                        rotate(rootnode,rootnode->left,rootnode->left->left,"LL");
                    }

                }
            }
             
            st.pop();
       }
       

        return;
    }

    void rotate(node* temp1, node* temp2, node* temp3 ,string type){

        node *temp11,*temp22, *temp3l,*temp3r;
        cout<<temp1->key<<' '<<temp2->key<<" "<<temp3->key<<' ';
        if (temp1->left != temp2){
            temp11 = temp1->left;
        }
        else{
            temp11 = temp1->right;
        }
        if (temp2->left != temp3){
            temp22 = temp2->left;
        }
        else{
            temp22 = temp2->right;
        }
        temp3l = temp3->left;
        temp3r = temp3->right;

        if (type == "RR" || type == "LL"){
            string key = temp1->key , value = temp1->value;
            temp1->key = temp2->key;
            temp1->value = temp2->value;
            temp2->key = key;
            temp2->value = value;

            if (type == "RR"){
                temp1->left = temp2;
                temp1->right = temp3;
                temp1->left->right = temp22;
                temp1->left->left = temp11;
                cout<<"condition RR done "<<"\n";
                return;
            }
            else{
                temp1->right = temp2;
                temp1->left = temp3;
                temp1->right->left = temp22;
                temp1->right->right = temp11;
                cout<<"condition LL done "<<"\n";
                return;
            }

        }
        else{
            string key = temp1->key , value = temp1->value;
            temp1->key = temp3->key;
            temp1->value = temp3->value;
            temp3->key = key;
            temp3->value = value;
            if (type == "RL"){
                temp1->left = temp3;
                temp3->left = temp11;
                temp3->right = NULL;
                if(temp3l != NULL){
                    temp2->left = temp3l;
                }
                else{
                    temp2->left = temp3r;
                }
                cout<<"condition RL done "<<"\n";
                return;
            }
            else{
                temp1->right = temp3;
                temp3->right = temp11;
                temp3->left = NULL;
                if(temp3l != NULL){
                    temp2->right = temp3l;
                }
                else{
                    temp2->right = temp3r;
                }
                cout<<"condition LR done "<<"\n";
                return;

            }
        }
        

        return;
    }

    void inorderTraversal(node *rootnode){
        if (rootnode == NULL){
            return;
        }
        inorderTraversal(rootnode->left);
        cout<<rootnode->key<<' '<<rootNode->value<<'\n';
        inorderTraversal(rootnode->right);
    }
    
public:

    AVL_tree(){
        rootNode = NULL;
    }

    void insert(string key,string val){
        node* new_node = new node();
        new_node->key = key;
        new_node->value = val;

        if (rootNode == NULL){
            rootNode = new_node;
            return;
        }

        node* temp = rootNode;
        node* prev = rootNode;
        stack<node*> st;

        while(temp){
            st.push(temp);
            if (temp->key > new_node->key){
                if (temp->left == NULL){
                    temp->left = new_node;
                    st.push(new_node);
                    check(st);
                    cout<<"inserted succesfully\n";
                    return;
                }
                else{
                    prev = temp;
                    temp = temp->left;
                }
            }
            else if (temp->key < new_node->key){
                if (temp->right == NULL){
                    temp->right = new_node;
                    st.push(new_node);
                    check(st);
                    cout<<"inserted succesfully\n";
                    return;
                }
                else{
                    prev = temp;
                    temp = temp->right;
                }
            }

        }
       
    }

    void reccursive_inorder(){
        node* temp = rootNode;
        inorderTraversal(temp);
    }

    void search(string key){
        int comparisions = 0 ;;
        if (rootNode == NULL){
            return;
        }
        node* temp = rootNode;
        while(temp){
            comparisions ++;
            if (temp->key == key){
                cout<<"Key found ["<<key<<' '<<temp->value<<"] and the comparisions required are :"<<comparisions<<'\n';
                return;
            }
            else if (temp->key < key){
                temp = temp->right;
            }
            else{
                temp = temp->left;
            }

        } 
    }


}; 
int main(){ 
 
    AVL_tree b;
    b.insert("a","x");
    b.insert("b","x");
    b.insert("c","x");
    b.insert("d","x");
    b.insert("e","x");
    b.insert("f","x");
    b.insert("g","x");
    b.insert("h","x");
    b.search("h");

    b.reccursive_inorder();
 
 
} 
