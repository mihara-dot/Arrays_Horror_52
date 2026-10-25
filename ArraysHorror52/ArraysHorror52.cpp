/********************************
 * Автор:    Рычков Михаил      *
 * Название: Обработка массивов *
 * Вариант:  24                 *
 ********************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  const int maxRows = 20;
  const int maxColumns = 20;
  const int maxMagnitude = 1000;
  const int maxDiagonalCount = maxRows + maxColumns - 1;
  int H[maxRows][maxColumns];
  int diagonalSums[maxDiagonalCount];
  int rowCount, columnCount;
  int diagonalCount, minimumSum;

  cout << "Enter the number of rows (1-20): ";
  if (!(cin >> rowCount) || rowCount < 1 || rowCount > maxRows) {
    cout << "INVALID" << endl;
    return 1;
  }

  cout << "Enter the number of columns (1-20): ";
  if (!(cin >> columnCount) || columnCount < 1 || columnCount > maxColumns) {
    cout << "INVALID" << endl;
    return 1;
  }

  cout << "Enter matrix elements (absolute value <= 1000):" << endl;
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      if (!(cin >> H[rowIndex][columnIndex]) || H[rowIndex][columnIndex] < -maxMagnitude || H[rowIndex][columnIndex] > maxMagnitude) {
        cout << "INVALID" << endl;
        return 1;
      }
    }
  }

  diagonalCount = rowCount + columnCount - 1;

  for (int diagonalIndex = 0; diagonalIndex < diagonalCount; ++diagonalIndex) {
    diagonalSums[diagonalIndex] = 0;
  }

  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      diagonalSums[rowIndex + columnIndex] += abs(H[rowIndex][columnIndex]);
    }
  }

  minimumSum = diagonalSums[0];
  for (int diagonalIndex = 1; diagonalIndex < diagonalCount; ++diagonalIndex) {
    if (diagonalSums[diagonalIndex] < minimumSum) {
      minimumSum = diagonalSums[diagonalIndex];
    }
  }

  cout << "Original matrix:" << endl;
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      cout << H[rowIndex][columnIndex] << " ";
    }
    cout << endl;
  }

  cout << "Sums of diagonals parallel to the secondary diagonal:" << endl;
  for (int diagonalIndex = 0; diagonalIndex < diagonalCount; ++diagonalIndex) {
    cout << "Diagonal " << diagonalIndex + 1
         << ": " << diagonalSums[diagonalIndex] << endl;
  }

  cout << "Minimum sum = " << minimumSum << endl;

  return 0;
}