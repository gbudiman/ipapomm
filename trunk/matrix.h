#ifndef MATRIX_H_
#define MATRIX_H_
#include <QtCore>
// Do not delete anything in this file.
// You may add new functions or attributes.
class Matrix 
{
 public:
  Matrix(char * filename);
  Matrix(int n);
  Matrix(const Matrix & morig); // copy constructor
  Matrix & operator = (const Matrix & morig); 
  // create a matrix and save it to a file. This function is static
  // and does not need to create an object.
  static int create(char * filename, int row);
  // The last argument specifies the number of threads to be used.
  virtual Matrix * multiply(Matrix * BM, int thread);
  virtual ~Matrix();
  virtual void print(char * filename);
  virtual int size() { return numRow; }
 private:
  int numRow; // consider only square matrixes
  int * * elements;
  int allocateMemory(int row);
  void readElement(QTextStream & ins);
  void copyElement(const Matrix & morig); 
  void assignRow(int r, QString & oneLine);
};

#endif /*MATRIX_H_*/
