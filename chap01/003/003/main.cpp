//
//  main.cpp
//  003
//  연습문제 3: 연결 리스트에서 remove_if()함수를 이용한 조건부 원소 삭제
//  Created by 이지훈 on 2/15/24.
//

#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

struct citizen
{
    string name;
    int age;
};

ostream &operator<<(ostream &os, const citizen &c)
{
    return os << "[" << c.name << ", " << c.age << "]";
}

int main()
{
    forward_list<citizen> citizens = {
        {"kim", 22}, {"Lee", 25}, {"Park", 18}, {"Jin", 16}
    };
    
    auto citizens_copy = citizens;
    
    cout << "전체 시민들";
    for(const auto &c : citizens)
    {
        cout << c << " ";
    }
    cout << endl;
    
    //나이 정보를 이용하여 투표권이 없는 시민을 리스트에서 제거
    //remove_if() : 조건식에 참을 만족하는 원소는 모두 제거
    citizens.remove_if([](const citizen & c){
        //나이가 19세보다 작으면 리스트에서 제거
        return c.age < 19;
    });
    
    cout << "투표권이 있는 시민들";
    for(const auto &c : citizens)
        cout << c << " ";
    cout << endl;
    
    //이번에는 내년에 새로 투표권이 생기는 사람
    citizens_copy.remove_if([](const citizen &c) {
        return c.age != 18;
    });
    
    cout << "내년에 투표권이 생기는 시민들";
    for(const auto &c : citizens_copy)
    {
        cout << c << " ";
    }
    cout << endl;
    
}
/*
 remove(), remove_if() ->  O(n), 리스트전체를 순회하면서 조건에 맞는것을 삭제
 sort() : 원소데이터를 정렬
 */
