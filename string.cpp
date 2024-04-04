#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int solve(string a[], int n) {
    int cnt = 0;
    bool appeared[10000] = {false}; // Mảng đánh dấu các từ đã xuất hiện, ban đầu chưa xuất hiện
    for (int i = 0; i < n; ++i) {
        if (!appeared[i]) {
            appeared[i] = true; // Đánh dấu từ đã xuất hiện
            ++cnt; // Tăng biến đếm lên 1
            // Duyệt qua các từ sau và đánh dấu các từ trùng lặp
            for (int j = i + 1; j < n; ++j) {
                if (a[i] == a[j]) {
                    appeared[j] = true;
                }
            }
        }
    }
    return cnt;
}

int main() {
    string s;
    getline(cin, s);

    // Chuyển tất cả các ký tự thành chữ thường
    for (char& c : s) {
        c = tolower(c);
    }

    stringstream ss(s);
    const int wordMax = 10000;
    string words[wordMax];
    int wc = 0;
    string w;

    while (ss >> w && wc < wordMax) {
        words[wc++] = w;
    }

    cout << solve(words, wc);
    return 0;
}
