#include <bits/stdc++.h>
using namespace std;
 
double gini_of_class(vector<double>& classarr)
{
    double sum=0.0;
    for(auto x:classarr)
    sum+=x;
    double powsum=0.0;
    for(int i=0;i<classarr.size();++i)
    {
        powsum+=pow(classarr[i]/sum, 2.0);
    }
    return (1.0 - powsum);
}
 
int main()
{
 
    ifstream file("./gini_index.csv");
 
    string line, word;
    string outlook, temp, humidity, windy, mainclass;
 
    map<string, int> parent;
    map<string, map<string, int>> attribute;
 
    if (!file.is_open())
    {
        perror("Error in opening input file : ");
        return -1;
    }
 
    int i = 0;
    string attributeName;
    while (getline(file, line))
    {
        stringstream str(line);
 
        getline(str, outlook, ',');
        getline(str, temp, ',');
        getline(str, humidity, ',');
        getline(str, windy, ',');
        getline(str, mainclass, ',');
 
        int choice;
 
        if (i == 0)
        {
            i++;
            cout << "Enter Attribute Column Name :\n1. Outlook\n2. Temperature\n3. Humidity\n4. Windy\n";
            cin >> choice;
            cout << endl;
            continue;
        }
 
        switch (choice)
        {
 
        case 1:
            attributeName = outlook;
            break;
 
        case 2:
            attributeName = temp;
            break;
 
        case 3:
            attributeName = humidity;
            break;
 
        case 4:
            attributeName = windy;
            break;
 
        default:
            attributeName = outlook;
            break;
        }
 
        parent[mainclass]++;
        attribute[attributeName][mainclass]++;
    }
    vector<double> classArray(0);
    for(auto x: parent)
    {
        cout<<x.second<<" ";
        classArray.push_back(x.second);
    }
    double gini_parent = gini_of_class(classArray);
    cout << gini_parent <<endl;
    for(auto x:attribute)
    {
        string temp=x.first;
        cout<<temp<<endl;
        map<string,int> mp=x.second;
        for(auto y:mp)
        {
            cout<<y.first<<" "<<y.second<<endl;
        }
    }
    return 0;
}
 


