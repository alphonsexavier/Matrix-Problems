#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int n, d, pos=1;
float dmatrixA[50][50]={0};

void settingUpDMatrix()
{
    int cnt=1;
    srand(time(0));

        for(int i=1; i<=n*d; i++)
        {
            cnt=i%d;
            if(cnt==0)
            {
                cnt=d;
            }
            for(int j=1; j<=n*d; j++)
            {
                if(cnt==j)
                {
                    dmatrixA[i][j]=rand()%20 + 1;
                }
                if(cnt+d==j)
                {
                    dmatrixA[i][j]=rand()%20 + 1;
                    cnt=cnt+d;
                }

            }
        }

        cnt=n*d;

        for(int i=1; i<=n*d;i++)
        {
                ++cnt;
                dmatrixA[i][cnt]=1;
        }

        for(int i=1; i<=n*d;i++)
        {
            for(int j=1; j<=2*n*d; j++)
            {
                cout<<dmatrixA[i][j]<<"\t";
            }
            cout<<"\n";
        }
        cout<<"\n";
}

void printMatrix()
{
    cout<<"\n";
    for(int i=1; i<=n*d;i++)
        {
            for(int j=1; j<=2*n*d; j++)
            {
                cout<<dmatrixA[i][j]<<"\t";
            }
            cout<<"\n";
        }
}

void divideRow(int row, float val)
{
    for(int j=1; j<=2*n*d; j++)
    {
        if(val!=0)
            dmatrixA[row][j]=dmatrixA[row][j]/val;
    }
}

void subRow(int row, int j, float val)
{
    for(; j<=2*n*d;j++)
    {
        dmatrixA[row][j]=dmatrixA[row][j] - (val*dmatrixA[pos][j]);
    }
}

void diagonalOne(int i)
{
    float val;

    if(dmatrixA[i][i]!=1)
    {
        val=dmatrixA[i][i];
        divideRow(i,val);
    }
}

void matrixInverse()
{
    float val;

    for(int j=1; j<=n*d; j++)
    {
        diagonalOne(j);
        for(int i=1;i<=n*d;i++)
        {
            if(i!=j && dmatrixA[i][j]!=0)
            {
                val=dmatrixA[i][j];
                subRow(i,j,val);
            }
        }
        ++pos;
    }
}

int main()
{
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Enter the value of d: ";
    cin>>d;

    settingUpDMatrix();
    matrixInverse();
    printMatrix();

    return 0;
}
