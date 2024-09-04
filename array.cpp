#include <iostream>
#include <vector>

class SparseMatrix {
private:
    std::vector<int> row, col, value;
    int numRows, numCols;

public:
    SparseMatrix(int r, int c) : numRows(r), numCols(c) {}

    void insert(int r, int c, int v) {
        if (v != 0) {
            row.push_back(r);
            col.push_back(c);
            value.push_back(v);
        }
    }

    void display() {
        int k = 0;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (k < row.size() && row[k] == i && col[k] == j) {
                    std::cout << value[k++] << " ";
                } else {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    SparseMatrix sm(4, 5);
    sm.insert(0, 2, 3);
    sm.insert(0, 4, 4);
    sm.insert(1, 2, 5);
    sm.insert(1, 3, 7);
    sm.insert(3, 1, 2);
    sm.insert(3, 2, 6);
    sm.display();
    return 0;
}
