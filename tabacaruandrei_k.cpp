#include<fstream>
#include<iostream>
using namespace  std;

typedef struct {
                        float greutate;
                        float profit;
                        float eficienta;
                        } obiect;
obiect M[100];
float profit_total;
float G;
int n;

int read_data()
{
    ifstream f("data.in");
    f>>n;
    for(int i = 1; i <= n; i++)
    {
        f>>M[i].greutate>>M[i].profit;
        M[i].eficienta = M[i].profit/M[i].greutate;
    }
    f>>G;
}

int sort_data()
{
    int isSorted;
    do
    {
        isSorted = 1;
        for(int i = 1; i < n; i++)
            if(M[i].eficienta < M[i + 1].eficienta)
        {
            swap(M[i].eficienta, M[i + 1].eficienta);
            swap(M[i].profit, M[i + 1].profit);
            swap(M[i].greutate, M[i + 1].greutate);
            isSorted = 0;
        }
     }while(isSorted == 0);
}

float sweet_greddy()
{
    int current;
    float G_current = 0;
    for(current = 1; current <= n; current++)
        while(G_current + M[current].greutate <= G)
    {
        profit_total += M[current].profit;
        G_current += M[current].greutate;
    }
    current--;
    profit_total += M[current].profit * (G - G_current) / M[current].greutate;
    return profit_total;
}

int main()
{
    read_data();
    sort_data();
    profit_total=sweet_greddy();
    cout<<profit_total;
}
