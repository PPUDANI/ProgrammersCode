#include <string>
#include <vector>
using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int size = array.size();
    int mid = (size/2);
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    
    answer = array[mid];
    
    
    return answer;
}