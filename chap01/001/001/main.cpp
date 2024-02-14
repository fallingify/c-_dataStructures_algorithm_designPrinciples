//
//  main.cpp
//  001
//  연습문제 1: 동적 크기 배열 구현하기
//  Created by 이지훈 on 2/15/24.
//

#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

template <typename T>
class dynamic_array
{
    T* data;
    size_t n;
    
public:
    dynamic_array(int n)
    {
        this->n = n;
        data = new T[n];
    }
    
    dynamic_array(const dynamic_array<T>& other)
    {
        n = other.n;
        data = new T[n];
        
        for(int i=0; i<n; i++)
            data[i] = other[i];
    }
    
    //멤버 데이터에 접근 연산자 재정의, 함수
    T& operator[](int index)
    {
        return data[index];
    }
    
    const T& operator[](int index) const
    {
        return data[index];
    }
    
    T& at(int index)
    {
        if(index < n)
            return data[index];
        throw "Index out of range";
    }
    
    //크기반환
    size_t size() const
    {
        return n;
    }
    
    //소멸자
    ~dynamic_array()
    {
        delete[] data; //메모리 릭 방지
    }
    
    //반복자 관련 함수
    T* begin() { return data; }
    const T* begin() const { return data; }
    T* end() {  return data + n; }
    const T* end() const {  return data + n; }
    
    //두 배열을 하나로 합치는 연산자 함수 정의
    friend dynamic_array<T> operator+(const dynamic_array<T>& arr1,
                                      dynamic_array<T>& arr2)
    {
        dynamic_array<T> result(arr1.size() + arr2.size());
        copy(arr1.begin(), arr1.end(), result.begin());
        copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());
        
        return result;
    }
    
    //to_string()멤버 함수 : 모든 데이터를 문자열로 반환
    string to_string(const string& sep = ", ")
    {
        if(n == 0)
            return "";
        
        ostringstream os;
        os << data[0];
        
        for(int i=1; i<n; i++)
            os << sep << data[i];
        
        return os.str();
    }
};
    
//학생정보 구조체
struct student
{
    string name;
    int standard;
};

ostream& operator<<(ostream& os, const student& s)
{
    return os << "[" << s.name << ", " << s.standard << "]";
}
    
int main()
{
    int nStudents;
    cout << "1반 학생 수를 입력하세요: ";
    cin >> nStudents;
    
    dynamic_array<student> class1(nStudents);
    for(int i=0; i<nStudents; i++)
    {
        string name;
        int standard;
        cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
        cin >> name >> standard;
    }
    
    //배열크기보다 큰 인덱스의 학생에 접근
    try {
        class1.at(nStudents) = student{"John", 8}; //예외발생
    } 
    catch (...) {
        cout << "에외발생!" << endl;
    }
    
    //깊은 복사
    auto class2 = class1;
    cout << "1번을 복사하여 2번 생성 : " << class2.to_string() << endl;
    
    auto class3 = class1 + class2;
    cout << "1반과 2반을 합쳐 3반 생성" << class3.to_string() << endl;
    
    return 0;
    
}
