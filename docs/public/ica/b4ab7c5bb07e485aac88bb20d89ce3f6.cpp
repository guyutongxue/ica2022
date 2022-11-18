#include <cstring>
#include <iostream>
using namespace std;

struct Result {
    int if_;
    int switch_;
    int while_;
    int for_;
};

bool equal(Result a, Result b) {
    return a.if_ + a.switch_ == b.if_ + b.switch_ && a.while_ + a.for_ == b.while_ + b.for_;
}

int count(const char* src, const char* target) {
    int tLen = strlen(target);
    const char* pos = src;
    int cnt = 0;
    while (true) {
        pos = strstr(pos, target);
        if (!pos) break;
        pos += tLen;
        cnt++;
    }
    return cnt;
}

Result get() {
    int n;
    cin >> n;
    cin.ignore();
    Result r{};
    while (n--) {
        static char line[10000]{};
        cin.getline(line, 10000);
        r.if_ += count(line, "if ");
        r.switch_ += count(line, "switch ");
        r.while_ += count(line, "while ");
        r.for_ += count(line, "for ");
    }
    return r;
}

int main() {
    cout << (equal(get(), get()) ? "Yes" : "No") << endl;
}