#include <iostream>
#include <fstream>
using namespace std;

void MultiplyAndSquareAndSave(ofstream& file) {
    // 1. int 1234 저장
    int num1 = 1234;
    file.write(reinterpret_cast<const char*>(&num1), sizeof(int));

    // 2. int 1000부터 5000까지 숫자에 5를 곱하여 저장
    int multiplyArr[5];
    for (int i = 0; i < 5; i++) {
        multiplyArr[i] = 1000 * (i + 1) * 5;
    }
    file.write(reinterpret_cast<const char*>(multiplyArr), sizeof(int) * 5);

    // 3. float -0.5에서 0.5씩 증가하면서 자승을 하고 저장
    float squareArr[3];
    float num = -0.5;
    for (int i = 0; i < 3; i++) {
        squareArr[i] = num * num;
        num += 0.5;
    }
    file.write(reinterpret_cast<const char*>(squareArr), sizeof(float) * 3);
}

int main() {
    ofstream file("mybin.dat", ios::binary | ios::out);
    if (!file) {
        cout << "파일을 열 수 없습니다.";
        return 1;
    }

    MultiplyAndSquareAndSave(file);

    file.close();
    return 0;
}