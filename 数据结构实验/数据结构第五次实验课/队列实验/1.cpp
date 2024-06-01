#include <iostream>
#include"myQueue1.h"
using namespace std;

int main(){
    int e, n;
    LinkQueue Q;

    InitQueue(Q);
        cin >> n;
        for(int i = 0;i < n;i++)
        {
            int x;
            cin >> x;
            EnQueue(Q, x);
        }

        cin >> n;
        for(int i = 0;i < n;i++)    DeQueue(Q, e);

        if(!isEmptyQueue(Q))
        {
            cout << "N" << endl;
            TopQueue(Q, e);
            cout << e << endl;
            PrintQueue(Q);
            cout << endl;
        }
        else cout<< "Y";
}
