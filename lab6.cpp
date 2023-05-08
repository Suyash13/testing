// By: Suyash Pandey
// 2020KUEC2045
#include <iostream>
using namespace std;
int main()
{
    int i, j, m, n, z, r, p;

    cout << "Enter the no of processes:\t";
    cin >> p;
    cout << "Enter the no of resource instances:\t";
    cin >> r;
    int maximum[p][r];
    int allotment[p][r];
    int available[r];

    // P0, P1, P2 and P3

    cout << "Enter the max matrix:\n";
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            cin >> maximum[i][j];
        }
    }
    cout << "Enter the allocation matrix:\n";
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            cin >> allotment[i][j];
        }
    }
    cout << "Enter the available resources:\n";
    for (j = 0; j < r; j++)
    {
        cin >> available[j];
    }

    int f[p], res[p], ind = 0;
    for (z = 0; z < p; z++)
    {
        f[z] = 0;
    }

    int requirement[p][r];
    for (m = 0; m < p; m++)
    {
        for (n = 0; n < r; n++)
            requirement[m][n] = maximum[m][n] - allotment[m][n];
    }

    int a = 0;
    for (z = 0; z < 4; z++)
    {
        for (m = 0; m < p; m++)
        {
            if (f[m] == 0)
            {
                int flag = 0;
                for (n = 0; n < r; n++)
                {
                    if (requirement[m][n] > available[n])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    res[ind++] = m;
                    for (a = 0; a < r; a++)
                        available[a] += allotment[m][a];
                    f[m] = 1;
                }
            }
        }
    }

    int flag = 1;
    for (int x = 0; x < p; x++)
    {
        if (f[x] == 0)
        {
            flag = 0;
            cout << "The given sequence is not safe" << endl;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "The given sequence is safe" << endl;
        for (m = 0; m < p - 1; m++)
            cout << " P" << res[m] << " ->";
        cout << " P" << res[p - 1] << endl;
    }
    return (0);
}
