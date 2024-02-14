#include <iostream>
using namespace std;

int main() {
    
    array<int, 5> arr = {1, 2, 3, 4, 5};
    for(auto it = arr.begin(); it != arr.end(); it++)
    {
        auto element = (*it);
        cout << element << ' ';
        
    }
    cout << arr.front() << endl;
    cout << arr.back() << endl;
    cout << *(arr.data() + 1) << endl;

    return 0;
}
