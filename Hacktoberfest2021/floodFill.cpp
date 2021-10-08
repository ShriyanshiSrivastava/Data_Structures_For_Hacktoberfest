#include<iostream>
#include<list>
using namespace std;

int R,C;

void print(char input[][50]){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<<input[i][j];
        }
        cout<<endl;
    }
}
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
// ch - character to be replaced
// color is the character to be added
void floodfill(char mat[][50],int i,int j,char ch,char color){
    // base case - matrix boundary
    if(i<0||j<0||i>=R||j>=C){
        return;
    }
    // figure boundary condition
    if(mat[i][j]!=ch){
        return;
    }
    // Recursive call
    mat[i][j] = color;
    for(int k=0;k<4;k++){
        floodfill(mat,i+dx[k],j+dy[k],ch,color);
    }
}
int main(){
    cin>>R>>C;
    char input[15][50];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>input[i][j];
        }
    }
    print(input);
    floodfill(input,8,13,'.','r');
    print(input);
}