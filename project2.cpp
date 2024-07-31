#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node{
    string n;
    int l;
    Node *next;
    Node *prev;
};

class List{
    private:
    Node *head;
    Node *tail;
    public:
    List(){
        head = NULL;
        tail = NULL;
    };
    ~List(){};
    void show(){
        Node *tmp;
        tmp = head;
        while (tmp!= NULL){
            cout << "[ data:"<<tmp->n<<" "<<tmp->l<<" | memory address of current node:"<<tmp<<" | memory address of next node:"<<tmp->next<<" | memory address of previous node:"<<tmp->prev<<" ]"<<endl;
            tmp = tmp->next;
        }
        cout<<endl;
    }
    void print(){
        Node *tmp;
        tmp = head;
        while (tmp!= NULL){
            cout << "[\""<<tmp->n<<"\", "<<tmp->l<<"]"<<endl;
            tmp = tmp->next;
        }
        cout<<endl;
    }
    void insert_node(string value, int len){
        Node *new_node = new Node();
        new_node->n = value;
        new_node->l = len;
        new_node->next=NULL;
        new_node->prev=NULL;
        if (head==NULL){
            head=tail=new_node;
        }else{
            tail->next=new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
    void generate_list(vector<string> s){
        for (auto x = s.begin();x!=s.end();++x){
            this->insert_node(*x,(*x).length());
        }
    }
    string longest_string(){
        Node *tmp;
        string result;
        tmp = head;
        result = tmp->n;
        while (tmp->next != NULL){
            if (result.length() < tmp->next->l){
                result = tmp->next->n;
            }
            tmp = tmp->next;
        }
        return result;
    }
    string shortest_string(){
        Node *tmp;
        string result;
        tmp = head;
        result = tmp->n;
        while (tmp->next != NULL){
            if (result.length() > tmp->next->l){
                result = tmp->next->n;
            }
            tmp = tmp->next;
        }
        return result;
    }
    double average_word_length(){
        Node *tmp;
        double sum = 0;
        double count = 0;
        tmp = head;
        while (tmp!=NULL){
            sum += tmp->l;
            count++;
            tmp = tmp->next;
        }
        return sum/count;
    }
    string build_sentence(){
        Node *tmp;
        string result;
        tmp = head;
        while (tmp!=NULL){
            if (tmp->next!=NULL){
                result.append(tmp->n);
                result.append(" ");
            } else{
                result.append(tmp->n);
            }
            tmp = tmp->next;
        }
        return result;
    }
    void prioritize_list(){
        string longest = this->longest_string();
        string shortest = this->shortest_string();
        Node *tmp = head;
        while (tmp!=NULL){
            if (tmp->n == longest){
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                head->prev = tmp;
                tmp->next = head;
                tmp->prev = NULL;
                head = tmp;
                break;    
            }
            tmp=tmp->next;
        }
        tmp = head;
        while (tmp!=NULL){
            if (tmp->n == shortest){
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                tail->next = tmp;
                tmp->prev = tail;
                tmp->next = NULL;
                tail = tmp;
                break;
            }
            tmp=tmp->next;
        }
    }
    void delete_string(string s){
        Node *tmp = head;
        while (tmp != NULL){
            if(tmp->n == s){
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                delete tmp;
            }
            tmp=tmp->next;
        }
    }
};

int main(){
    List L;
    vector<string> v = {"chicago", "is", "located", "in", "northeastern", "illinois",
        "on", "the", "southwestern", "shores", "of", "freshwater", "lake",
        "michigan", "and", "it", "is", "the", "principal", "city", "in",
        "the", "chicago", "metropolitan", "area", "situated", "in", "both",
        "the", "midwestern", "united", "states", "and", "the", "great",
        "lakes", "region"};
    L.generate_list(v);
    L.print();
    cout << "-------------------" << endl;
    cout << L.longest_string() << endl;
    cout << "-------------------" << endl;
    cout << L.average_word_length() << endl;
    cout << "-------------------" << endl;
    cout << L.build_sentence() << endl;
    cout << "-------------------" << endl;
    L.prioritize_list();
    L.print();
    cout << "-------------------" << endl;
    L.delete_string("the");
    L.print();
    cout << "-------------------" << endl;
    return 0;
}