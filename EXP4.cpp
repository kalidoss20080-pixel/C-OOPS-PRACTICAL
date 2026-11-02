#include <iostream>
#include <stack>
#include <queue>
#include <chrono>

using namespace std;
using namespace chrono;

// Generic Stack using a template
template <typename T>
class MyStack
{
private:
    T items[100000];
    int topIndex;

public:
    MyStack()
    {
        topIndex = -1;
    }

    void push(const T& element)
    {
        if (topIndex < 99999)
        {
            items[++topIndex] = element;
        }
    }

    void pop()
    {
        if (topIndex >= 0)
        {
            topIndex--;
        }
    }
};

// Generic Queue using a template
template <typename T>
class MyQueue
{
private:
    T items[100000];
    int first;
    int last;

public:
    MyQueue()
    {
        first = 0;
        last = 0;
    }

    void enqueue(const T& element)
    {
        if (last < 100000)
        {
            items[last++] = element;
        }
    }

    void dequeue()
    {
        if (first < last)
        {
            first++;
        }
    }
};

int main()
{
    // Test case: 100000 operations
    const int SIZE = 100000;

    // Custom Stack Benchmark
    MyStack<int> customStack;
    auto stackStart = high_resolution_clock::now();

    for (int value = 0; value < SIZE; value++)
        customStack.push(value + 100);

    for (int value = 0; value < SIZE; value++)
        customStack.pop();

    auto stackEnd = high_resolution_clock::now();
    auto customStackTime =
        duration_cast<microseconds>(stackEnd - stackStart);

    // STL Stack Benchmark
    stack<int> standardStack;
    stackStart = high_resolution_clock::now();

    for (int value = 0; value < SIZE; value++)
        standardStack.push(value + 100);

    for (int value = 0; value < SIZE; value++)
        standardStack.pop();

    stackEnd = high_resolution_clock::now();
    auto stlStackTime =
        duration_cast<microseconds>(stackEnd - stackStart);

    // Custom Queue Benchmark
    MyQueue<int> customQueue;
    auto queueStart = high_resolution_clock::now();

    for (int value = 0; value < SIZE; value++)
        customQueue.enqueue(value + 100);

    for (int value = 0; value < SIZE; value++)
        customQueue.dequeue();

    auto queueEnd = high_resolution_clock::now();
    auto customQueueTime =
        duration_cast<microseconds>(queueEnd - queueStart);

    // STL Queue Benchmark
    queue<int> standardQueue;
    queueStart = high_resolution_clock::now();

    for (int value = 0; value < SIZE; value++)
        standardQueue.push(value + 100);

    for (int value = 0; value < SIZE; value++)
        standardQueue.pop();

    queueEnd = high_resolution_clock::now();
    auto stlQueueTime =
        duration_cast<microseconds>(queueEnd - queueStart);

    // Display performance results
    cout << "Custom Stack Time: "
         << customStackTime.count() << " microseconds" << endl;

    cout << "STL Stack Time: "
         << stlStackTime.count() << " microseconds" << endl;

    cout << "Custom Queue Time: "
         << customQueueTime.count() << " microseconds" << endl;

    cout << "STL Queue Time: "
         << stlQueueTime.count() << " microseconds" << endl;

    return 0;
}