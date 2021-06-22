#include <iostream>
#include <stdlib.h>


using namespace std;


int main()
{
    int pn;    
    int money;    
    cin >> pn >> money;
    int** arr_p;      
    int** arr_p_r;  
    arr_p = (int**)malloc(sizeof(int*) * pn);
    arr_p_r = (int**)malloc(sizeof(int*) * pn);
    for (int i = 0; i <pn; i++) {
        arr_p[i] = (int*)malloc(sizeof(int) * (money+1));
        arr_p_r[i] = (int*)malloc(sizeof(int) * (money + 1));
    }
    for (int i = 0; i < pn; i++) {
        for (int j = 0; j <=money ; j++) {
            arr_p_r[i][j] = 0;
        }
    }

    for (int i = 0; i <pn; i++) {
        for (int j = 0; j <=money; j++) {
            cin >> arr_p[i][j];
        }
    }
    int j, i;
    for (i = 0; i < pn; i++) {
        for ( j = 0; j <= money; j++) {
            if (i == 0) {
                arr_p_r[i][j] = arr_p[i][j];
              
            }
            else {
                for (int k = 0; k <= j; k++) {
                    if (arr_p[i][k] + arr_p_r[i - 1][j - k] > arr_p_r[i][j]) 
                    {
                        arr_p_r[i][j] = arr_p[i][k] + arr_p_r[i - 1][j - k];
                    }
                }
            }
        }
    }
    cout << arr_p_r[pn - 1][money];


}

