#include<iostream>
using namespace std;
 
class node{
    friend class dictionary;
    string key,value;
    node* next;
    node(){
        key ="NA";
        value= "NA";
        next = nullptr;
    }
};

class dictionary{

    node** array;
    int size;

    int HashVlue(string key){
        int value = 0;
        for(auto i:key){
            value += int(i); 
        }
        return value % size;
    }
public:

    dictionary(){
        cout<<"Enter the size of Hashtable :";
        cin>> size;
        array = new node*[size];
        for(int i = 0; i<size; i++){array[i] = nullptr;}
    }
    void insert(string key, string value){

        int hashValue = HashVlue(key);
        node* new_node = new node();
        new_node->key = key;
        new_node->value = value;
        if (array[hashValue] == nullptr){
            array[hashValue] = new_node;
            cout<<"inserted succesfully\n";
            return;
        }
        else{
            node* temp = array[hashValue];
            while(temp->next != NULL){
                 
                if (temp->key == key){
                    cout<<"key already present\n";
                    return;
                } 
                temp = temp->next;
            }
            temp->next = new_node;
            cout<<"inserted succesfully\n";
        }
    }

    void find(string key){

        int hashValue = HashVlue(key);
        
        if (array[hashValue] == nullptr){
            cout<<"Key is not present\n";
        }else if (array[hashValue]->key == key){
            cout<<array[hashValue]->key<<" : "<<array[hashValue]->value<<"\n";
        }
        else{
            node* temp = array[hashValue];
            while(temp){ 
                if (temp->next->key == key){
                    cout<<array[hashValue]->key<<" : "<<array[hashValue]->value<<"\n";
                    return;
                } 
                temp = temp->next; 
            }
           cout<<"Key is not present\n";
        }
    }
    void Delete(string key){

        int hashValue = HashVlue(key);
        
        if (array[hashValue] == nullptr){
            cout<<"Key is not present\n";
        }else if (array[hashValue]->key == key){
            array[hashValue] = array[hashValue]->next;
            cout<<"key deleted succesfully\n";
        }
        else{
            node* temp = array[hashValue];
            while(temp){ 
                if (temp->next->key == key){
                    cout<<"key deleted succesfully\n";
                    temp->next = temp->next->next ;
                    return;
                } 
                temp = temp->next; 
            }
           cout<<"Key is not present\n";
        }
    }
};
 
int main(){ 
 
    dictionary d;
    while (true)
    {
        int ch;
        cout<<"Enter the choice\n1.Add info\n2.find key\n3.delete key\n";
        cin>>ch;
        if (ch == 1){
            string key, value;
            cout<<"enter the key\n";
            cin>>key;
            cout<<"enter the value\n";
            cin>>value;
            d.insert(key,value); 
        }
        else if (ch == 2){
            string key;
            cout<<"enter the key\n";
            cin>>key;
            d.find(key);
        }
        else if (ch == 3){
            string key;
            cout<<"enter the key\n";
            cin>>key;
            d.Delete(key);
        }
        else{
            cout<<"invalid input\n";
        }
    }
} 
