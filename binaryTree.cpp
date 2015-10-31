#include <iostream>
using namespace std;

// 전체 노드(검색 키)의 개수
#define NODES 1001

// 노드가 존재하지 않는 경우에 대한 NIL 포인터(노드 번호)
#define NIL 0

int Key[NODES]; // 각 노드의 키값
int Left[NODES], Right[NODES]; // 각 노드의 왼쪽, 오른쪽 노드의 번호
int Root = NIL; // 루트 노드의 번호
int r =1;
// BST에 대한 검색을 수행하는 함수
// t번 노드를 루트로 하는 서브트리에서 키값이 x인 노드를 찾는다
// 검색에 성공하면 해당 노드의 번호를, 실패하면 NIL을 리턴한다
int treeSearch(int t, int x){
        // 검색에 실패하거나 성공하여 검색을 종료하는 경우
        if( t == NIL || Key[t] == x)
        {             
                // 종료하기 전에 검색하려 했던 키값을 출력한다
                // 검색에 성공한 경우에는 Key[t]를 출력하면 되지만,
                // 검색에 실패하였을 때는 t가 NIL이므로 Key[t]가 정의되지 않는다
                // x를 출력한다면 두 경우를 모두 처리할 수 있다
                cout << x << endl;

                return t;
        }


        // 검색 과정에서 지나게 되는 키값을 출력한다
        // 단, 마지막 키값은 위에서 출력한다
        cout << Key[t] << " ";

        if(x < Key[t]) return treeSearch(Left[t],x);
        else return treeSearch(Right[t],x);
        // 이 부분에 구현 내용이 들어간다
}

// BST에 새 노드를 삽입하는 함수
// t번 노드를 루트로 하는 서브트리에 키값이 x인 노드를 삽입한다
// 삽입을 수행한 후 해당 서브트리의 루트 노드의 번호를 리턴한다
int treeInsert(int t, int x)
{
        if(t == NIL){
                Key[r] = x; 
                Left[r]=NIL;
                Right[r]=NIL;
                r++;
                return r-1;
        }
        // 이 부분에 구현 내용이 들어간다
        if(x < Key[t]) {Left[t] =treeInsert(Left[t],x); return t;}
        else  {Right[t]=treeInsert(Right[t],x); return t; }
        
}

int main(void)
{
        while(1)
        {
                int x;

                // 검색, 또는 삽입을 위한 키값이 주어진다
                cin >> x; 

                // 0이 주어지는 경우에는 프로그램을 종료한다
                if(x == 0) break;

                // 우선 검색을 수행해 보고,
                if( treeSearch(Root, x) == NIL)
                {
                        // 검색에 실패한다면(NIL이 리턴됨) x를 삽입한다
                        Root = treeInsert(Root, x);
                }
               
        }
       
}