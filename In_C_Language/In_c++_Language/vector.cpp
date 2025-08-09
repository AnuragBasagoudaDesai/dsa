#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVectors(vector<int> vec);
void PrintvectorsWIthIndex(vector<int> vec);


int main() 
{
    vector<int>  vec = {1, 2, 3, 4, 5};
    PrintVectors(vec);

   
    PrintVectors(vec);

    vec.pop_back();
    PrintVectors(vec);

    vec.insert(vec.begin() + 2,8);
    PrintVectors(vec);
    vec.push_back(6);


    vec.erase(vec.begin() + 3);
    PrintVectors(vec);

    vec.push_back(7);

    sort(vec.begin() , vec.end());
    PrintvectorsWIthIndex(vec);

    return 0;




}

void PrintVectors(vector<int> vec)
{
    for(int element : vec)
    {
        cout << element << " ";
    }
    cout << endl;
}

void PrintvectorsWIthIndex(vector<int> vec)
{
    for( vector<int>::size_type index = 0 ; index < vec.size() ; index++)
    {
        cout << vec[index] << " ";
    }
}
