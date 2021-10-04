#include<bits/stdc++.h>
using namespace std;

/* question

given a integer n indicating the number of patterns. 
then follow n lines each containing non empty strings representing patterns.
Then comes a non empty string representing text.

output n lines where ith line contains the positions of all occurences of 
the ith pattern in text.
*/



struct node{
    map<char, node*> child;
    node* suffix_link;
    node* output_link;
    int pattern_int;
    node(){
        suffix_link = NULL;
        output_link = NULL;
        pattern_int = -1;
    }
};

void build_tree(node* root, vector<string> patterns, int n){
    for (int i = 0; i < n; i++){
        node* curr = root;
        for (int j = 0; j < patterns[i].length(); j++){
            char c = patterns[i][j];
            if(curr->child.find(c) !=  curr->child.end()) curr = curr->child[c];
            else{
                node* nn = new node();
                curr->child[c] = nn;
                curr = nn;
            }
        }
        curr->pattern_int = i;
    }
}

void build_suffix_and_ouput_link(node* root){
    root->suffix_link = root;
    queue<node*> qu;
    for(auto rc: root->child){
        qu.push(rc.second);
        rc.second->suffix_link = root; // roots childrens suffix link will point to root only
    }
    while(qu.size() > 0){
         node* curState = qu.front();
        qu.pop();

        for(auto cc: curState->child){
            node* cchild = cc.second;
            node* tmp = curState->suffix_link;
            while((tmp->child.end() == tmp->child.find(cc.first)) && tmp != root){
                tmp = tmp->suffix_link;
            }
            if(tmp->child.end() != tmp->child.find(cc.first)){
                cchild->suffix_link = tmp->child[cc.first];
            }
            else cchild->suffix_link = root;
            qu.push(cchild);
        }
        if(curState->suffix_link->pattern_int >= 0) curState->output_link = curState->suffix_link;
        else curState->output_link = curState->suffix_link->output_link;
    }
}

void search(node* root, string s, vector<vector<int>> &res){
    node* parent = root;
    for (int i = 0; i < s.length(); i++){
        char c = s[i];
        if(parent->child.end() != parent->child.find(c)){
            parent = parent->child[c];
            if(parent->pattern_int > -1){
                res[parent->pattern_int].push_back(i);
            }
            node* mol = parent->output_link;
            while(mol != NULL){
                res[mol->pattern_int].push_back(i);
                mol = mol->output_link;
            }
        }else{
            while(parent!= root && (parent->child.find(c) == parent->child.end())){
                parent = parent->suffix_link;
            }
            if(parent->child.find(c) != parent->child.end()) i--;
        }
    }
    
}

int main(){
    int n; cin >> n;
    vector<string> patterns(n);
    for(int i=0;i<n;i++){
        cin >> patterns[i];
    }
    string txt; cin >> txt;
    vector<vector<int>> res(n);

    node* root = new node();
    build_tree(root,patterns,n);
    build_suffix_and_ouput_link(root);
    search(root, txt ,res);
    for (int i = 0; i < n; i++){
        if(res[i].size() == 0) cout << -1 << endl;
        else{
            for (auto x: res[i]) cout << (x - patterns[i].size() + 1) << " ";
            cout << endl;
        }
    }
    
    return 0;
}

/*
INPUT:
6
ACC
ATC
CAT
GCG
C
T
GCATCG  

OUTPUT:
-1
2
1
-1
1 4
3
*/