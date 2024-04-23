
#include<iostream>
#include<set>
#include<list>
#include<map>
#include<stack>
#include<queue>
#include<typeinfo>
#include <limits.h> 
using namespace std;

template<class T>

class Graph
{
    map<T,list<T>> graph;
public:

    Graph(){}

    void insert(T src, T dest , bool bi_dire){
        
        graph[src].push_back(dest);
        if (!bi_dire){
           graph[dest].push_back(src); 
        }
        cout<<"inserted succesfully\n";
    }

    

    
    void bfs(T start){

        map<T,bool> visited;
        queue<T> path;

        visited[start] = true;
        path.push(start);

        while(!path.empty()){

            for(auto i:graph[path.front()]){
                if (!visited[i]){
                    
                    path.push(i);
                    visited[i] = true;
                }
            }
            cout<<path.front()<<"->";
            path.pop();
        }
    }

    void display(){
         for(auto i = graph.begin(); i != graph.end();++i){
            
                cout<<i->first<<"->";
                for(auto j:i->second){
                    cout<<j<<" ";
                }
                cout<<""<<'\n';
        }
        
    }

    bool search(T start ,T end , map<T,bool> &visited){
        
        if (start == end){
            return true;
        }
        
        visited[start] = true;

        for(auto i : graph[start]){
            
            if (!visited[i]){
                
                return search(i,end,visited);
            }
            
        }
        return false;
    }

    void dfs(T start,T end){
        map<T,bool> visited;
        cout<<search(start,end,visited);

    }

     bool cycleDetection(T start){

        map<T,bool> visited;
        queue<T> path;

        visited[start] = true;
        path.push(start);

        while(!path.empty()){
            int count = 0;
            for(auto i:graph[path.front()]){
                if (!visited[i]){
                    //cout<<i<<" ";
                    path.push(i);
                    visited[i] = true;
                }
                else{
                    count++;
                }
            }

            if (count > 1){
                return true;
            }
            
            path.pop();
        }
        return false;
    }

     bool check(T start ,T prev , map<T,bool> &visited){
        
        visited[start] = true;
        
        for(auto i : graph[start]){
           
            if (!visited[i]){
                prev = start;
                return check(i,prev,visited);
            }
            else if (i != prev){
                
                return true;
            }
            
        }
        return false;
    }

    void iscycle(T start,T prev ){
        map<T,bool> visited;

        cout<<check(start,prev,visited);

    }

     void sort(T start , map<T,bool> &visited,stack<T> &st){
        
        visited[start] = true;
        for(auto i : graph[start]){
           
            if (!visited[i]){
                
                sort(i,visited,st);
            }   
        }
        st.push(start);
        return;   
    }

    void topologicalSort(T start ){
        map<T,bool> visited;
        stack<T> st;
        sort(start,visited,st);
        while (!st.empty())
        {
            cout<<st.top()<<' ';
            st.pop();
        }
        cout<<'\n';
    }

     void kahnsAlgorithm(){
        queue<T> path;
        map<T,int> frequency;
        frequency[graph.begin()->first] = 0;

        for (auto i = graph.begin(); i!= graph.end();i++){
           for(auto j : i->second){
            
             frequency[j] += 1;
             
           }
        }
        
        for  (auto i = frequency.begin(); i!= frequency.end();i++){
            if (i->second ==0 ){
                
                path.push(i->first);
            }
        }
        

        while(!path.empty()){

            cout<<path.front()<<' ';

            for(auto i : graph[path.front()]){
                frequency[i] -= 1;
                if (frequency[i] == 0){
                     path.push(i);
                }
            }

            path.pop();
        }
    }


     void unorder_shortest_path(T start,T end){

        map<T,bool> visited;
        queue<T> path;
        map<T,T> parent;

        visited[start] = true;
        path.push(start);

        while(!path.empty()){

            for(auto i:graph[path.front()]){
                if (!visited[i]){
                    parent[i] = path.front();
                    path.push(i);
                    visited[i] = true;
                }
            }
            
            path.pop();
        }
        stack<T> v;
        T i = end;
        v.push(end);
        while(true){
            
            v.push(parent[i]);
            i = parent[i];
           
            if (i == start){
                break;
            }
        }
        while(!v.empty()){
            cout<<v.top()<<"<->";
            v.pop();
        }
    }

     void DAG_shortest_path(T start ){
        map<T,bool> visited;
        stack<T> st;
        
        sort(start,visited,st);
       
        while (!st.empty())
        {
            
        }
        cout<<'\n';
    }

};


template<class T>
class weighted_graph{
    map<T,list<pair<int,T>>> graph;
public:
    weighted_graph(){};

    void insert(T src,T dest,int weight, bool directed ){

        graph[src].push_back(make_pair(weight,dest));

        if (!directed){
           graph[dest].push_back(make_pair(weight,src)); 
        }
    }

     void display(){
         for(auto i = graph.begin(); i != graph.end();++i){
            
                cout<<i->first<<"->";
                for(auto j:i->second){
                    cout<<'['<<j.first<<","<<j.second<<"] ";
                }
                cout<<""<<'\n';
        }
        
    }

    void Dijkstras_algorithm(T start){

        map<T,int> dist;
        for(auto i = graph.begin(); i != graph.end(); i++){
            for (auto j : i->second){
                dist[j.second] = INT32_MAX;
            }
        }
        dist[start] = 0;
        set<pair<int,T>> s;

        s.insert(make_pair(0,start));

        for (auto i:s){
           
            for (auto j:graph[i.second]){
                if (dist[j.second] > (i.first + j.first)){
                    dist[j.second] = i.first + j.first;
                    s.insert(make_pair(dist[j.second],j.second));
                }
            }
            
        }

         for(auto i = dist.begin(); i != dist.end(); i++){
           cout<<i->first<<' '<<i->second<<'\n';
        }

    }

    void prims(T start){

        map<T,list<pair<int,T>>> mst;
        map<T,bool> visited;

        visited[start] = true;
        
        while(true){

            pair<int,T> temp;
            temp.first = INT16_MAX;

            for(auto j : graph[start]){
                if (!visited[j.second] && temp.first > j.first ){
                    
                    temp = j;
                }
            }

            if (temp.first == INT16_MAX){
                
                break;
            }


            for(auto i = mst.begin() ; i != mst.end(); i++){

                for (auto j : graph[i->first]){
                    if ( !visited[j.second] && j.second != start && j.first < temp.first){
                        
                        temp = j;
                        start = i->first;
                    }
                }
            }
            
            
            mst[start].push_back(temp);
            start = temp.second;
            visited[start] = true;
        }


         for(auto i = mst.begin(); i != mst.end();++i){
            
                cout<<i->first<<"->";
                for(auto j:i->second){
                    cout<<'['<<j.first<<","<<j.second<<"] ";
                }
                cout<<""<<'\n';
        }
    }

    
    bool search(T start ,T end ,map<T,list<pair<int,T>>> &mst){

        map<T,bool> visited;
        stack<T> st;
        st.push(start);
        while (!st.empty())
        {
            if (st.top() == end){
                return true;
            }
            visited[st.top()] = true;
            bool flag = false;
            for(auto i : mst[st.top()]){
                
                if (!visited[i.second]){
                    flag = true;
                    st.push(i.second);
                    break;
                }
                
            }
            if(!flag){
                st.pop();
            }
        }

        return false;
    }
   

    void kruskals(){

        set<pair<int,pair<T,T>>> pairs;
        map<T,list<pair<int,T>>> mst;

        int total_cost = 0;

        for (auto i = graph.begin(); i != graph.end(); i++){

            for (auto j: i->second){
                pairs.insert(make_pair(j.first,make_pair(i->first,j.second)));
            }
        }

        for (auto i : pairs){

            if (! search(i.second.first,i.second.second,mst)){
                total_cost += i.first;
                mst[i.second.first].push_back(make_pair(i.first,i.second.second));
                mst[i.second.second].push_back(make_pair(i.first,i.second.first));
            }            
        }

        for(auto i = mst.begin(); i != mst.end();++i){

                cout<<i->first<<"->";
                for(auto j:i->second){
                    cout<<'['<<j.first<<","<<j.second<<"] ";
                }
                cout<<""<<'\n';
        }

        cout<<"Total cost is : "<<total_cost<<'\n';
    }
};

int main(){

    // Graph<int> g;

    // g.insert(1,2,false);
    // g.insert(2,3,false);
    // g.insert(3,4,false);
    // //g.insert(1,4,false);
    // //g.bfs(1,4);
    // g.display();
    // //g.dfs(1,4);
    // //cout<<g.cycleDetection(1);
    // //g.iscycle(1,-1);
    // //g.topologicalSort(1);
    // //g.kahnsAlgorithm();
    // g.unorder_shortest_path(1,4);

    weighted_graph<int> g;

    g.insert(5,4,9,false);
    g.insert(4,1,1,false);
    g.insert(5,1,4,false);
    g.insert(1,2,2,false);
    g.insert(2,6,7,false);
    g.insert(3,2,3,false);
    g.insert(3,6,8,false);
    g.insert(4,3,5,false);
    g.insert(4,2,3,false);
    
    g.display();
    g.kruskals();
    //g.prims('b');
    // g.Dijkstras_algorithm(1);
}
