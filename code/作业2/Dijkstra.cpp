#include <iostream>
#include <stdlib.h>
using namespace std;
int** Creat(int s,int e) {
    int** num = (int**)malloc(sizeof(int*) * s);
    for (int i=0; i < s; i++) {
        num[i] = (int*)malloc(sizeof(int) * s);
    }
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (i == j) {
                num[i][j] = 0;
            }
            else {
                num[i][j] = 9999;
            }
        }
    }
    for (int i = 0; i < e; i++) {
        int start, vertex, weight;
        cin >> start >> vertex >> weight;
        num[start][vertex] = weight;
    }
    return num;
}

int* Dijkstra(int** num,int s,int e,int b, int f) {
    int flag = 1;
    int* visited = (int*)malloc(sizeof(int) * s);
    int* lenth = (int*)malloc(sizeof(int) * s);
    for (int i = 0; i < s; i++) {
        visited[i] = 0;
        lenth[i] = num[b][i];
    }
    visited[b] = 1;
    while(flag!=s){
        for (int i = 0; i < s; i++) {
            if (visited[i] == 1) {
                int minlenth = 9999;
                int v = i;
                for (int j = 0; j < s; j++) {
                    if (minlenth > num[i][j]&& visited[j]==0 ) {
                        minlenth = num[i][j];
                        v = j;
                        visited[v] = 1;
                        flag = flag + 1;
                        if (lenth[v] > lenth[i] + minlenth) {
                            lenth[v] = lenth[i] + minlenth;
                        }
                    }
                }
            }
        }
    }
    return lenth;
}



int main()
{
    int s, e;
    cin >> s >> e;
    int** num = Creat(s, e);
    int start, finals;
    cin >> start >> finals;
    int* min = Dijkstra(num, s, e, start, finals);
    for (int i = 0; i < s; i++) {
        printf("%d\t", min[i]);
    }
}
