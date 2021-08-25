#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct median
{
    // 기준보다 작은 것을 넣는 경우
    priority_queue<int> maxHeap;
    // 기준보다 큰 것을 넣는 경우
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void insert(int data) 
    {   
        // Heap에 아무것도 없을 경우
        if(maxHeap.size() == 0) {
            maxHeap.push(data);
            // 이 때 중간 값은 maxHeap의 top값이다.
            return;
        }

        // Heap 전체의 갯수가 짝수 일 경우
        if(maxHeap.size() == minHeap.size())
        {
            if(data <= get())
                maxHeap.push(data);
            else 
                minHeap.push(data);

            return;
        }

        // Heap 전체의 갯수가 홀수이며, maxHeap의 크기가 minHeap보다 작을 경우
        if (maxHeap.size() < minHeap.size()) 
        {
            // data의 값이 중간값보다 클 경우, minHeap에 삽입해야 하는데, 균형을 위해 minHeap의 top값을 maxHeap에 넣고, data를 삽입
            if(data > get()) 
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(data);
            }
            // data의 값이 중간값보다 작을 경우, maxHeap에 들어가므로 균형이 맞음.
            else
            {
                maxHeap.push(data);
            }

            return;
        }

        // Heap 전체의 갯수가 홀수이며, minHeap의 크기가 maxHeap보다 작을 경우
        // data의 값이 중간값보다 작을 경우, maxHeap에 삽입해야 하는데, 균형을 위해 maxHeap의 top값을 minHeap에 넣고, data를 삽입
        if(data < get()) 
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(data);
        }
        // data의 값이 중간값보다 작을 경우, maxHeap에 들어가므로 균형이 맞음.
        else
        {
            minHeap.push(data);
        }
        
        return;
    }

    double get()
    {
        if(maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        if(maxHeap.size() < minHeap.size())
            return minHeap.top();
        return maxHeap.top();
    }
};

int main()
{
    median med;

    med.insert(1);
    cout << "1 삽입 후 중앙값 : " << med.get() << endl;

    med.insert(5);
    cout << "5 삽입 후 중앙값 : " << med.get() << endl;

    med.insert(2);
    cout << "2 삽입 후 중앙값 : " << med.get() << endl;

    med.insert(10);
    cout << "10 삽입 후 중앙값 : " << med.get() << endl;

    med.insert(40);
    cout << "40 삽입 후 중앙값 : " << med.get() << endl;
}