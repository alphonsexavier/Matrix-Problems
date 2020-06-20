#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int dmatrixA[50][50];
int dmatrixB[50][50];
int dmatrixM[50][50];
int dmatrixF[50][50]={0};

void printmatrixM(int n, int d)
{
    cout<<"\nMultiplied Values \n";
    for(int i=1;i<=n*n;i++)
    {
        cout<<"\n";
        for(int j=1; j<=n*d; j++)
        {
            cout<<dmatrixM[i][j]<<"\t";
        }
    }
}

void printmatrixF(int n, int d)
{
    cout<<"\n\nFinal Values \n";
    for(int i=1;i<=n*n;i++)
    {
        cout<<"\n";
        for(int j=1; j<=d; j++)
        {
            cout<<dmatrixF[i][j]<<"\t";
        }
    }
}


void settingUpDMatrix(int num, int n, int d)
{
    int rn;
    srand(time(0));
    //Setting up the matrix 1
    if(num==1)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n*d; j++)
            {
                dmatrixA[i][j]=rand()%20 + 5;
            }
        }

        cout<<"\nA matrix \n\n";

        for(int i=1; i<=n;i++)
        {
            for(int j=1; j<=n*d; j++)
            {
                cout<<dmatrixA[i][j]<<"\t";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    //Setting up the matrix 2
    else
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n*d; j++)
            {
                dmatrixB[i][j]=rand()%20 + 7;
            }
        }


        cout<<"\nB matrix \n\n";

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n*d; j++)
            {
                cout<<dmatrixB[i][j]<<"\t";
            }
            cout<<"\n";
        }
    }
}

void matrixMultiplication(int n, int d)
{
    int arow=1, brow=1, bcol=1, start=1;

    for(int i=1;i<=n*n;i++)
    {
        for(int j=1;j<=n*d;j++)
        {
                dmatrixM[i][j]=dmatrixA[arow][j] * dmatrixB[brow][bcol];

                if(bcol%d==0 && j==n*d)
                {
                    if(bcol==n*d)
                    {
                        bcol=1;
                        start=1;
                    }
                    else
                    {
                        start=start+d;
                    }
                    break;
                }

                if(j%d==0)
                {
                     brow=brow+1;
                }
                if(bcol%d==0)
                {
                    bcol=start;
                }
                else
                {
                    ++bcol;
                }
        }

            brow=1;

        if(bcol!=1)
        {
            bcol=start;
        }

        if(i%n==0)
        {
            ++arow;
        }

    }

    printmatrixM(n,d);

    for(int i=1;i<=n*n;i++)
    {
        for(int j=1;j<=d;j++)
        {
            for(int k=j;k<=n*d;)
            {
                if(k<=n*d)
                {
                    dmatrixF[i][j]=dmatrixF[i][j]+dmatrixM[i][k];
                }
                else
                {
                    break;
                }
                k=k+d;
            }
        }
    }
}

int main()
{
    int n, d;

    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Enter the value of d: ";
    cin>>d;

    settingUpDMatrix(1,n,d);
    settingUpDMatrix(2,n,d);

   matrixMultiplication(n,d);
   printmatrixF(n,d);

    return 0;
}


