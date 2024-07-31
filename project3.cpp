#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

class Graph{
    private:
        vector<vector<int>> b;
    public:
    Graph(){
        b = {};
    };
    ~Graph(){};
    void build_graph(vector<vector<int>> v){
        for (auto x = v.begin();x!=v.end();++x){
            b.push_back(*x);
        }
    }
    void print_adjacency_matrix(){
        for (auto x = b.begin();x != b.end(); ++x){
            cout<<"[";
            for(auto z = (*x).begin(); z != (*x).end(); ++z){
                if (z == (*x).end()-1){
                    cout<<*z;
                } else
                    cout<<*z<<" ";
            }
            cout<<"]"<<endl;
        }
    }
    void largest_vertex_degree(){
        vector<int> size;
        int tmp = 0;
        int max= 0;
        int count = 0;
        for (auto x = b.begin();x != b.end(); ++x){
            for(auto z = (*x).begin(); z != (*x).end(); ++z){
                tmp += *z;
            }
            size.push_back(tmp);
            tmp = 0;
        }
        for (auto x = size.begin();x != size.end(); ++x){
            if (*x > max){
                max = *x;
            }
        }
        for (auto x = size.begin();x != size.end(); ++x){
            if (max == *x){
                break;
            }
            count++;
        }
        cout<<count<<","<<max<<endl;
    }
    Graph bsf(int s){
        vector<string> color(b.size(),"WHITE");
        vector<int> distance(b.size(),INFINITY);
        vector<int> pie(b.size(),NULL);
        queue<int> Q;
        vector<vector<int>> bsf_matrix(b.size(),vector<int>(b.size(),0));
        Graph bsf_graph;
        int u;
        color[s] = "GRAY";
        distance[s] = 0;
        pie[s] = NULL; 
        Q.push(s);
        while (!Q.empty()){
            u = Q.front();
            Q.pop();
            for (int i = 0;i<b[u].size();i++){
                if (b[u][i] == 1 && (color[i] == "WHITE")){
                    color[i] = "GRAY";
                    distance[i] = distance[u] + 1;
                    pie[i] = u;
                    Q.push(i);
                    bsf_matrix[u][i] = 1;
                    bsf_matrix[i][u] = 1;
                }
            }
            color[u] = "BLACK";
        }
        bsf_graph.build_graph(bsf_matrix);
        return bsf_graph;
    }
    void print_vector(vector<int> v){
        for (auto x = v.begin();x!=v.end();++x){
            cout<<*x<<" ";
        }
        cout<<endl;
    }
};

int main(){
    vector<vector<int>> v = {{0,0,1,1},
                             {0,0,1,1},
                             {1,1,0,1},
                             {1,1,1,0}};                    
    Graph G;
    G.build_graph(v);
    G.print_adjacency_matrix();
    G.largest_vertex_degree();
    Graph H;
    H = G.bsf(0);
    H.print_adjacency_matrix();
    H.largest_vertex_degree();
    return 0;
}