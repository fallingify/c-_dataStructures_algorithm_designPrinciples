//
//  main.cpp
//  004
//  연습문제 4: 다양한 반복자에서 이동하기
//  Created by 이지훈 on 2/15/24.
//

#include <iostream>
#include <forward_list>
#include <vector>

using namespace std;

int main()
{
    //vector
    vector<string> vec = {
        "Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg",
        "Sebastian Vettel", "Lewis Hamilton", "Sebastian Vettel",
        "Sebastian Vettel", "Sebastian Vettel", "Fernando Alonso"
    };
    
    auto it = vec.begin(); //상수 시간
    cout << "가장 최근 우승자: " << *it << endl;
    
    it += 8; //상수 시간
    cout << "8년 전 우승자: " << *it << endl;
    
    advance(it, -3); //상수 시간
    cout << "그 후 3년 뒤 우승자" << *it << endl;
    
    //forward_list
    forward_list<string> fwd(vec.begin(), vec.end());
    
    auto it1 = fwd.begin();
    cout << "가장 최근 우승자: " << *it1 << endl;
    
    advance(it1, 5); //선형 시간
    cout << "5년 전 우승자 : " << *it1 << endl;
    
    //forward_list 는 순방향으로만 이동할 수 있으므로
    //아래코드는 에러발생
    //advance(it1, -2)
    
    
    
}
/*
array : C스타일의 배열의 래퍼
forward_list : 단일 연결 리스트 래퍼
 
vector에서는 특정 원소에 즉각적으로 접근가능 O(1)
forward_list에서는 연속적인 순회를 통해서만 특정원소에 접근 가능 O(n)


 */
