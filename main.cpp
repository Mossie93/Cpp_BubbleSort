#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;


void readData(vector<int> &data)
{
    ifstream inputFile;
    inputFile.open("data.txt");
    int numberRead;

    while(!inputFile.eof())
    {
        inputFile>>numberRead;
        data.push_back(numberRead);
    }

    inputFile.close();
    cout<<"Bubble sort: \tdata reading from file finished\n";
}


int writeData(vector<int> &data)
{
    ofstream outputFile;
    outputFile.open("sortedData.txt");

    for(int i=0; i<data.size(); i++)
    {
        outputFile<<data[i]<<endl;
    }

    outputFile.close();
    cout<<"Bubble sort: \twriting data to file finished\n";
}


void sortData(vector<int> &data)
{
    bool sorted;
    int swapTemp;
    int index1, index2;
    int dataSize = data.size();


    do
    {
        sorted = true;
        for(int i=0; i<dataSize-1; i++)
        {
            if(data[i]>data[i+1])
            {
                sorted = false;
                swapTemp = data[i];
                data[i] = data[i+1];
                data[i+1] = swapTemp;
            }
        }
    }
    while(!sorted);

    cout<<"Bubble sort: \tsorting finished.\n";
}


int main()
{
    vector<int> data;
    data.clear();

    readData(data);
    sortData(data);
    writeData(data);

    cout<<"Bubble sort: \tfinished.\n";
    system("PAUSE");
    return 0;
}

