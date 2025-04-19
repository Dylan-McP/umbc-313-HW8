#include <iostream>

using namespace std;

class Matrix {
public:
  // Default constructors
  Matrix() {
    m_rows = 0;
    m_columns = 0;
    m_matrix = nullptr;
  }
  // Constructor w/ parameters
  Matrix(int rows, int columns) {
    m_rows = rows;
    m_columns = columns;
    m_matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
      m_matrix[i] = new int[columns];
      for (int j = 0; j < columns; j++) {
	m_matrix[i][j] = 0;
      }
    }
  }
  // Destructor
  ~Matrix() {
    for (int i = 0; i < m_rows; i++) {
      delete[] m_matrix[i];
    }
    delete [] m_matrix;
  }
  // Getters
  int getRows() {return m_rows;}
  int getColumns() {return m_columns;}
  // Lets the user input the initial values of the matrix
  void initializeMatrix() {
    cout << "Input number of rows: ";
    cin >> m_rows;
    cout << "Input number of columns: ";
    cin >> m_columns;
    m_matrix = new int*[m_rows];
    for (int i = 0; i < m_rows; i++) {
      m_matrix[i] = new int[m_columns];
      for (int j = 0; j < m_columns; j++) {
	cout << "Input value at [" << i << "][" << j << "] : ";
	cin >> m_matrix[i][j];
      }
    }
  }
  // Adds the values of the passed matrix to the original matrix
  void addMatrices(Matrix & matrixToAdd) {
    // Matrix addition is only defined for same-sized matrices
    for (int i = 0; i < getRows(); i++) {
      for (int j = 0; j < getColumns(); j++) {
	m_matrix[i][j] += matrixToAdd.m_matrix[i][j];
      }
    }
  }
  // Multiplies every value in the matrix by the passed constant
  void multiplyConstant(int constant = 3) {
    for (int i = 0; i < getRows(); i++) {
      for (int j = 0; j < getColumns(); j++) {
	m_matrix[i][j] *= constant;
      }
    }
  }
  // Multiplies the values of the two passed matrices into the original matrix
  void multiplyMatrices(Matrix & matrix1, Matrix & matrix2) {
    // The [i][j] value of the result is matrix1's row i * matrix2's column j
    //Matrix newMatrix(matrix1.getRows(), matrix2.getColumns());
    for (int i = 0; i < matrix1.getRows(); i++) {
      for (int j = 0; j < matrix2.getColumns(); j++) {
	for (int k = 0; k < matrix1.getColumns(); k++) {
	  m_matrix[i][j] += (matrix1.m_matrix[i][k] * matrix2.m_matrix[k][j]);
	}
      }
    }
  }
  void transpose() {
    int ** newMatrix = new int*[m_columns];
    // Nested for loop to copy all the data members
    for (int i = 0; i < getColumns(); i++) {
      newMatrix[i] = new int[getRows()];
      for (int j = 0; j < getRows(); j++) {
	newMatrix[i][j] = m_matrix[j][i];
      }
    }
    for (int i = 0; i < m_rows; i++) {
      delete[] m_matrix[i];
    }
    delete [] m_matrix;
    m_matrix = newMatrix;
    int temp = m_rows;
    m_rows = m_columns;
    m_columns = temp;
  }
  void dump() {
    // Print the matrix with a nested for loop
    for (int i = 0; i < getRows(); i++) {
      for (int j = 0; j < getColumns(); j++) {
	cout << m_matrix[i][j] << " ";
      }
      cout << endl;
    }
  }
private:
  int m_rows;
  int m_columns;
  int** m_matrix;
};

int main() {
  Matrix A;
  cout << "Input values for Matrix A:" << endl;
  A.initializeMatrix();
  
  Matrix B;  
  cout << "Input values for Matrix B:" << endl;
  B.initializeMatrix();
  
  Matrix C;
  cout << "Input values for Matrix C:" << endl;
  C.initializeMatrix();
  
  // D's dimensions are B's row number and C's row number
  // C's rows and not columns because it's pre-transposition
  Matrix D(B.getRows(),C.getRows());  
  
  // Step-by-step matrix calculation
  int scalar;
  cout << "Input scalar: ";
  cin >> scalar;
  B.multiplyConstant(scalar);
  C.transpose();
  D.multiplyMatrices(B, C);
  D.addMatrices(A);

  cout << "The solution to the matrix equation of the test program" << endl;
  D.dump();
  return 0;
}
