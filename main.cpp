#include <iostream>

using namespace std;
class Matrix
{
private:
    int row;
    int col;
    double **storage;
public:
    Matrix(int l=0,int h=0):row(l),col(h)
    {
        storage=new double *[row];
        for(int i=0; i<row; i++)
        {
            storage[i]=new double[col];
        }
    }
    void view(int a,int b)
    {
        cout<<storage[a][b]<<endl;
        cout<<endl;
    }
    Matrix &operator=(const Matrix&a)
    {
        if(this ==&a) return *this;
        delete [] storage;
        row=a.row;
        col=a.col;
        storage=new double *[row];
        for(int i=0; i<row; i++)
        {
            storage[i]=new double[col];
            for(int k=0; k<col; k++)
                storage[i][k]=a.storage[i][k];
        }
        return *this;

    }
    void start()
    {
        for(int i=0; i<row; i++)
        {
            for(int k=0; k<col; k++)
            {
                cin>>storage[i][k];
            }
        }
    }
    void display()
    {
        for(int i=0; i<row-1; i++)
        {
            for(int k=0; k<col-1; k++)
            {
                cout<<storage[i][k]<<' ';
            }
            cout<<storage[i][col-1];
            cout<<endl;
        }
        for(int k=0; k<col-1; k++)
        {
            cout<<storage[row-1][k]<<' ';

        }
        cout<<storage[row-1][col-1];
    }
    Matrix &operator+=(const Matrix&a)
    {
        if(col!=a.col||row!=a.row)
        {
            cout<<"ERROR!";

        }
        else
        {

            for(int i=0; i<row; i++)
            {
                for(int k=0; k<a.col; k++)
                {
                    storage[i][k]+=a.storage[i][k];

                }
            }


            display();


        }

        return *this;
    }


    Matrix &operator*=(const Matrix&a)
    {
        Matrix tmp(row,a.col);
        double  m=0;
        if(col!=a.row)
        {
            cout<<"ERROR!";

        }
        else
        {

            for(int i=0; i<row; i++)
            {
                for(int k=0; k<a.col; k++)
                {
                    m=0;
                    for(int n=0; n<col; n++)
                        m+=storage[i][n]*a.storage[n][k];
                    tmp.storage[i][k]=m;

                }
            }

            *this=tmp;
            display();

        }

        return *this;
    }
};

int main()
{
    int r1,c1,r2,c2;
    cin>>r1>>c1;
    Matrix table1(r1,c1);
    table1.start();
    cin>>r2>>c2;
    Matrix table2(r2,c2);
    table2.start();
    table1.view(int(r1/2),int(c1/2));
    table1 *= table2;

    cout<<endl;
    cout<<endl;
    table1 += table2;

    cout<<endl;
    cout<<endl;
    table1=table2;
    table1.display();


}
