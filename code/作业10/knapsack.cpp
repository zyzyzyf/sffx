#include <iostream>
#include <cmath>
#include <cstring>
#define num 100
using namespace std;
float p1 = 0.0, w1 = 0.0;
int all = 0;
void bagloading(int x[], float p[], float w[], float c, int n)
{
    float t, k, pw[num];
    int i, j, m, kk;
    for (i = 0; i < n; i++)
        pw[i] = p[i] / w[i];
    m = n - 1;
    while (m > 0)
    {
        kk = 0;
        for (j = 0; j < m; j++)
            if (pw[j] < pw[j + 1])
            {
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
                k = w[j];
                w[j] = w[j + 1];
                w[j + 1] = k;
                kk = j;
            }
        m = kk;
    }

}

int main()
{
    int n;
    float c;
    float p[num];
    float w[num];
    int x[num];
    int i;
    cout << "��������Ʒ�ļ�����";
    cin >> n;
    cout << "�������������Ʒ�ļ�ֵ������ \nÿ����Ʒ�ļ�ֵ������֮���ÿո�������س���������һ����Ʒ��" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> p[i] >> w[i];
    }
    cout << "�����뱳�������������";
    cin >> c;
    bagloading(x, p, w, c, n);
    for (i = 0; i < n; i++)
    {
        if (c >= w[i]) {
            cout << w[i] << "���뱳��" << endl;
            c -= w[i];
            p1 = p1 + p[i];
            w1 = w1 + w[i];
            x[i] = 1;
            all++;
        }

    }
    if (all > 0)
    {
        cout << "�ñ�����װ�����" << all << "����Ʒ" << endl;
        for (i = 0; i < n; i++)
            if (x[i] == 1)
                cout << p[i] << " " << w[i] << endl;
    }
    cout << "��װ��Ʒ�ܵļ�ֵΪ��" << p1 << endl;
    cout << "��װ��Ʒ�ܵ�����Ϊ��" << w1 << endl;
    cout << endl;
    system("pause");
    return 0;
}
