// date: Mon Mar 1 21:27:42 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

struct node{
    int row,size;
    node* column,*up,*down,*left,*right;
};

struct DLX{
    void cover(node *c){
        c->right->left = c->left;
        c->left->right = c->right;
        for(node* it = c->down; it != c; it = it->down) {
            for(node* jt = it->right; jt != it; jt = jt->right){
                jt->down->up = jt->up;
                jt->up->down = jt->down;
                jt->column->size--;
            }
        }
    }
    void uncover(node *c){
        for(node * it = c->up; it != c; it = it->up){
            for(node * jt = it->left; jt != it; jt = jt->left){
                jt->down->up = jt;
                jt->up->down = jt;
                jt->column->size++;
            }
        }
        c->right->left = c;
        c->left->right = c;
    }
    bool search(node* head, int k, vector<int>& solution){
        if(head->right == head) return 1;
        node*ptr = nullptr;
        int low = 1<<30;
        for(node* it = head->right; it != head; it = it->right){
            if(it->size < low){
                if(it->size == 0 ) return 0;
                low = it->size;
                ptr = it;
            }
        }
        cover(ptr);
        for(node* it = ptr->down; it != ptr; it = it->down){
            solution.push_back(it->row);
            for(node* jt = it->right; jt != it; jt = jt->right){
                cover(jt->column);
            }
            if(search(head,k+1,solution)) return 1;
            else{
                solution.pop_back();
                for(node * jt = it->left; jt != it; jt = jt->left){
                    uncover(jt->column);
                }
            }
        }
        uncover(ptr);
        return 0;
    }
    vector<int> solve(vector<vector<int>> &matrix){
        int n = matrix[0].size();
        vector<node> column(n);
        node head;
        head.right = &column[0];
        head.left = &column[n-1];
        for(int i=0; i < n; i++){
            column[i].size = 0;
            column[i].up = &column[i];
            column[i].down = &column[i];
            if( i == 0) column[i].left = &head;
            else column[i].left = &column[i - 1];
            if( i == n-1) column[i].right = &head;
            else column[i].right = &column[i + 1];
        }
        vector<node*> nodes;
        for( int i=0; i < matrix.size(); i++){
            node* last = nullptr;
            for(int j=0; j < n; j++){
                if(matrix[i][j]){
                    node* now = new node;
                    now->row = i;
                    now->column = &column[j];
                    now->up = column[j].up;
                    now->down = &column[j];
                    if(last){
                        now->left = last;
                        now->right = last->right;
                        last->right->left = now;
                        last->right = now;
                    }else{
                        now->left = now;
                        now->right = now;
                    }
                    column[j].up->down = now;
                    column[j].up = now;
                    column[j].size++;
                    last = now;
                    nodes.push_back(now);
                }
            }
        }
        vector<int> solution;
        search(&head, 0, solution);
        for(node* ptr : nodes) delete ptr;
        return solution;
    }

}dlx;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
    vector<vector<int>> mat;
    vector<tii> data;
    int board[10][10];   
    for(int i=0; i < 9; i++){
        for(int j=0; j < 9; j++){
            cin >> board[i][j];
            if(board[i][j]){
                int k = board[i][j]-1;
                vector<int> row(324,0);
                row[i*9+j] =1;
                row[81 + i * 9 + k] =1;
                row[81 * 2 + j * 9 + k] =1;
                row[81 * 3 + (i / 3 * 3 + j / 3) * 9 + k] = 1;
                mat.push_back(row);
                data.push_back({i,j,k});
            }else{
                for(int k=0; k < 9; k++){
                    vector<int> row(324,0);
                    row[i * 9 + j] = 1;
                    row[81 + i * 9 + k] =1;
                    row[81 * 2 + j * 9 + k] = 1;
                    row[81 * 3 + ( i / 3 * 3 + j / 3) * 9 + k] =1;
                    mat.push_back(row);
                    data.push_back({i,j,k});
                }
            }
        }
    }

    vector<int> ans = dlx.solve(mat);

    for(int u : ans) board[get<0>(data[u])][get<1>(data[u])] = get<2>(data[u]);

    for(int i=0; i < 9; i++){
        for(int j=0; j < 9; j++){
            cout << board[i][j] + 1 << ' ';
        }
        cout << '\n';
    }

}