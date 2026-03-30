#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int SIZE = 4;

class Matrix {
private:
    int data[SIZE][SIZE];

public:
    Matrix() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                data[i][j] = 0;
            }
        }
    }

    bool readFromFile(ifstream& file) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (!(file >> data[i][j])) {
                    return false;
                }
            }
        }
        return true;
    }

    void display() const {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << setw(4) << data[i][j];
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < SIZE; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    int sumOfDiagonals() const {
        int sum = 0;
        for (int i = 0; i < SIZE; i++) {
            sum += data[i][i];
            sum += data[i][SIZE - 1 - i];
        }

        if (SIZE % 2 == 1) {
            sum -= data[SIZE / 2][SIZE / 2];
        }

        return sum;
    }

    void swapRows(int row1, int row2) {
        if (row1 < 0 || row1 >= SIZE || row2 < 0 || row2 >= SIZE) {
            cout << "Invalid row indices." << endl;
            return;
        }

        for (int j = 0; j < SIZE; j++) {
            int temp = data[row1][j];
            data[row1][j] = data[row2][j];
            data[row2][j] = temp;
        }
    }
};

int main() {

    string fileName;
    cout<<"Enter the filename"<<endl;
    cin>>fileName;
    ifstream file(fileName);

    if (!file.is_open()) {
        cerr << "Failed to open file: " << fileName << endl;
        return 1;
    }

    Matrix mat1, mat2;

    if (!mat1.readFromFile(file) || !mat2.readFromFile(file)) {
        cerr << "Error reading matrix data from file." << endl;
        file.close();
        return 1;
    }

    file.close();

    cout << "Matrix 1:" << endl;
    mat1.display();

    cout << "\nMatrix 2:" << endl;
    mat2.display();

    Matrix sum = mat1 + mat2;
    cout << "\nSum of matrices:" << endl;
    sum.display();

    Matrix product = mat1 * mat2;
    cout << "\nProduct of matrices:" << endl;
    product.display();

    cout << "\nSum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

    mat1.swapRows(0, 2);
    cout << "\nMatrix 1 after swapping row 0 and row 2:" << endl;
    mat1.display();

    return 0;
}
