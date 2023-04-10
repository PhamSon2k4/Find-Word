#include <iostream>
#include <vector>
#include <string>
using namespace std;

int m, n, k;
vector<string> grid;

// Hàm kiểm tra xem từ có nằm trong ma trận không
bool isInGrid(string word, int r, int c, int dr, int dc) {
    for (int i = 0; i < word.size(); i++) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != word[i]) {
            return false;
        }
        r += dr;
        c += dc;
    }
    return true;
}

// Hàm tìm từ trong ma trận
string findWord(string word) {
    if (word.find_first_of("0123456789!@#$%^&*()_+ ") != string::npos) {
        return "input error";
    }
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (isInGrid(word, r, c, 1, 0)) { // Tìm theo chiều dọc
                return to_string(r + 1) + " " + to_string(c + 1) + " " + to_string(r + word.size()) + " " + to_string(c + 1);
            }
            if (isInGrid(word, r, c, 0, 1)) { // Tìm theo chiều ngang
                return to_string(r + 1) + " " + to_string(c + 1) + " " + to_string(r + 1) + " " + to_string(c + word.size());
            }
            if (isInGrid(word, r, c, 1, 1)) { // Tìm theo đường chéo
                return to_string(r + 1) + " " + to_string(c + 1) + " " + to_string(r + word.size()) + " " + to_string(c + word.size());
            }
            if (isInGrid(word, r, c, 1, -1)) { // Tìm theo đường chéo
                return to_string(r + 1) + " " + to_string(c + word.size()) + " " + to_string(r + word.size()) + " " + to_string(c + 1);
            }
        }
    }
    return "not found";
}

int main() {
    cin >> m >> n;
    grid.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> grid[i];
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        string word;
        cin >> word;
        cout << findWord(word) << endl;
    }
    return 0;
}
