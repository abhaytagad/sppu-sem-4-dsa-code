#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 


class heapSort{

    vector<int> heapData;
    int n;
    void heapify(int size){
        
        int n = size/2;
        for(int i = n ; i >= 0; i--){
            
            int j = 2*i + 1;
            int max_ele;
            if (j < size){
                if (j+1 < size){
                    max_ele = max(heapData[j], heapData[j+1]);
                }
                else{
                    
                    max_ele = heapData[j];
                }

                if (heapData[i] < max_ele){

                    if (heapData[j] == max_ele){
                        int temp = heapData[i];
                        heapData[i] = heapData[j];
                        heapData[j] = temp;
                    }
                    else{
                        int temp = heapData[i];
                        heapData[i] = heapData[j+1];
                        heapData[j+1] = temp;
                    }

                    i = n +1;
                }   
            }
            
        }
    }


public:

    heapSort(){
        int n;
        cout<<"enter the number of elements wants to enter : ";
        cin>>n;
        cout<<"enter the elements :\n";
        for(int i= 0; i < n; i++){
            int ele;
            cin>>ele;
            heapData.push_back(ele);
        }
        
    }

    void sort(){
        
        for (int i = heapData.size() - 1; i>=0 ; i-- ){
            heapify(i+1);
            int temp = heapData[i];
            heapData[i] = heapData[0];
            heapData[0] = temp;
        }
    }
    
    void display(){

        for (auto i:heapData){
            cout<<i<<' ';
        }
    }
    
} ;
 
int main(){ 
 
    heapSort h;
    h.sort();
    h.display();
} 