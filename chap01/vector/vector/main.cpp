//
//  main.cpp
//  vector
//
//  Created by 이지훈 on 2/15/24.
//

#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<int> vec; //크기가 0인 벡터 선언
    vector<int> vec1 = {1, 2, 3, 4, 5}; // 지정한 초기값으로 이루어진 크기 5인 백터선언
    vector<int> vec2(10); //크기가 10인 백터 선언
    vector<int> vec3(10, 5); //크기가 10이고, 모든 원소가 5인 초기화된 벡터선언
    
    vec1.insert(vec1.begin(), 0); // 새로운 원소 추가  insert()
    vec.push_back(1); //맨 뒤에 1 추가
    vec.push_back(2); //맨 뒤에 2 추가
    vec.insert(vec.begin(), 0); // 맨 뒤에 0 추가
    
    vec.insert(find(vec.begin(), vec.end(), 1), 4); //1앞에 4추가
    
    vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vec2.pop_back(); //마지막 원소 하나 제거
    vec2.erase(vec2.begin()); //맨 처음 원소를 제거
    vec2.erase(vec2.begin() + 1, vec2.begin() + 4); //1번째 원소부터 4번째 앞 원소까지 제거
    
//    clear() : 모든 원소를 제거
//    reserve(capacity) : 벡터에서 사용할 용량을 지정
//    shrink_to_fit() : 여분의 메모리 공간을 해제하는 용도로 사용, 백터의 용량과 백터의 크기가 같아짐
    
    
    // forward_list
    // push_fron(), insert_after()
    forward_list<int> fwd_list = {1, 2, 3};
    fwd_list.push_front(0); // 맨 앞에 0 추가
    auto it = fwd_list.begin();
    fwd_list.insert_after(it, 5); // 맨 처음 원소 뒤에 5추가
    fwd_list.insert_after(it, 6); // 같은 위치에 6추가
    
    // pop_front(), erase_after()
    fwd_list.pop_front(); // 맨 앞에 있는 원소를 삭제
    
    auto it2 = fwd_list.begin();
    fwd_list.erase_after(it2); // 맨 앞의 다음 원소를 삭제
    
    fwd_list.erase_after(it2, fwd_list.end()); //맨 앞에 원소 다음부터 맨 마지막 원소까지 삭제
    
    
    
    //remove()
    //remove_if()
    
    
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
