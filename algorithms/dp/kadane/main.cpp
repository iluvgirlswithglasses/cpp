#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

//
int n; int * arr;

//
/* 
    Nói thêm về khoảng này
    Thật ra ban đầu nó khá khó hình dung
    Nhưng về sau thì dễ không ngờ

    Trường hợp kết quả là một số âm:
        Thì thuật toán sẽ lấy kết quả là dãy có độ dài = 1, đồng thời là dãy có giá trị lớn nhất bé hơn 0
        Vì: một số âm cộng một số âm luôn ra một số bé hơn
        Và: thuật toán chỉ ghi nhận một phần tử bé hơn 0 trước khi reset crBest

    Trường hợp kết quả là một số dương:
        Nếu các số dương trước i cộng lại vẫn cho ra kết quả âm khi duyệt đến i,...
        ...các số từ i trở đi không lí gì phải thêm các số từ i trở về trước vào dãy cả
        Thế nên mỗi khi cho ra tổng < 0, crBest lập tức reset về không
        Giá trị crBest lớn nhất đồng thời là giá trị của result.
*/
int calc() {
    int res = INT_MIN, crBest = 0;
    //
    for (int i = 0; i < n; i++) {
        crBest += arr[i];
        if (crBest > res) res = crBest;
        if (crBest < 0) crBest = 0;
    }
    //
    return res;
}

//
void getinp() {
    ifstream inp("inp.txt");
    inp >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++) inp >> arr[i];
}

int main() {
    getinp();
    cout << calc();
    system("pause");
    return 0;
}