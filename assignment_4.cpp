#include<iostream>
#include<vector>
using namespace std;
 
class Client{
    string name,telephone_no;
    friend class hashMap;
public:
    Client(string name,string tellephone){
        this->name = name;
        this->telephone_no = tellephone;
    }
};


class hashMap{
    int N;
    vector<Client*> database;
    int hashValue(string str){
        int value = 0;
        for (auto c:str){
            value += int(c);
        }
        return value % N;
    }

public:
    hashMap(){
        cout<<"enter the size of database\n";
        cin>>N;
        for (int i = 0; i < N; i++){ database.push_back(nullptr);}     
    }

    void insert(string name , string tellephone){
        int index = hashValue(name);
        Client *c1 = new Client(name,tellephone);
        int probe = 0,count = 0;
        while(count < N){
            if (database[index] == nullptr){
                database[index] = c1 ;
                cout<<" Client Added succesfully\n";
               return;
            }
            else{
                probe++;
                index = (index + probe)%N;
                
                if(index >= N){
                    index = 0;
                    probe = 0;
                }
            } 
            count++;    
        }
        cout<<"database is full\n";
        return;
    }

    void get(string name){

        int index = hashValue(name);
        int probe = 0,count = 0;

        while (count < N)
        {
            if (database[index]->name == name){
                cout<<database[index]->telephone_no<<'\n';
                return;
            }
            else{
                probe++;
                index = (index + probe)%N;
               
                if(index >= N){
                    index = 0;
                    probe = 0;
                }
            }
            count++;
       }
        cout<<"data is not present\n";
        return;
    }
};

int main(){ 
 
    hashMap h;
    while (true)
    {
        int ch;
        cout<<"enter the choice\n1.add client\n2.get client details\n3.exit\n";
        cin>>ch;
       
        
        if (ch == 1){
            string name, tell;
            cout<<"enter the client name :";
            cin>>name;
            cout<<"enter the client tellephone number :";
            cin>>tell;
            h.insert(name,tell);
        }
        else if (ch == 2){
            string name;
            cout<<"enter the client name :";
            cin>>name;
            h.get(name);
        }
        else if (ch == 3){
            break;
        }
        else{
             cout<<"Invalid input\n";
        }
    }
} 