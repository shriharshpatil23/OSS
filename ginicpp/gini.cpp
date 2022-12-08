#include<bits/stdc++.h>
using namespace std;

void gini(vector<string> a,vector<string> c)
{
    int flag=0;
    vector<pair<string,int>> b;

    for ( int i =0;i<a.size();i++)
    {
        flag=0;
        for (int j=0;j<b.size();j++)
        {
            
            if (a[i]==b[j].first)
            {
                b[j].second++;
                flag=1;
            }
                
        }
        if(flag!=1)
        {
            
            b.push_back(make_pair(a[i],1));
        }
        
    } 
    double total=0;
    for(int i =0;i<b.size();i++)
    {
        total = total + b[i].second;
    } 

    double arr[b.size()]={0};
    for (int i =0;i<a.size();i++)
    {
        for (int j=0;j<b.size();j++)
        {
            if ( a[i]==b[j].first&&c[i]=="Y")
            {
                arr[j]++;
            }
        }
    }

    double gini =0;
    double sum =0;

    for (int i =0;i<b.size();i++)
    {
        double temp =(b[i].second/total)*(1 - ((arr[i]*arr[i])/(b[i].second*b[i].second)+((b[i].second-arr[i])*(b[i].second-arr[i]))/(b[i].second*b[i].second)));
        sum = sum + temp;
    }

    cout<<sum;
}


int main()
{

    fstream fin;
    fin.open("input.csv");


    vector<string> row,row2;
    string line, word, temp;
   
    int i =0;
    while (fin.peek() != EOF)
    {
        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
         row.push_back("eol");

    }

    for (int i =0;i<row.size();i++)
    {
        cout<<row[i]<<" ";
        if (row[i]=="eol")
        cout<<endl;

    }

    int cols=0;
    for (int j =0;j<row.size();j++)
    {
        if (row[j]=="eol")
        break;

        cols++;
    }

    cout<<cols<<endl;

vector<vector<string>> input;

for (int i =0;i<cols;i++)
{
    vector<string> temp={};
    input.push_back(temp);
}

for (int i =cols;i<row.size();i=i+cols)
{
    for (int j =0;j<cols;j++)
    {
        cout<<i<<" "<<j<<endl;
        input[j].push_back(row[i+j]);
    }
}



for (int i =0;i<input.size();i++)
{
    for (int j =0;j<input[i].size();j++)
    {
        cout<<input[i][j]<<" ";
    }

    cout<<endl;
}

    return 0;
}