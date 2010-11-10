#ifndef MATRIX_H_
#define MATRIX_H_
#include <QtCore>
#include <stdlib.h>
#include <iostream>
#include <qthread.h>
using namespace std;
// Do not delete anything in this file.
// You may add new functions or attributes.
class Matrix 
{
 public:
  Matrix(char * filename);
  Matrix(int n);
  Matrix(const Matrix & morig); // copy constructor
  Matrix & operator = (const Matrix & morig);
  Matrix * append (Matrix * morig, int start, int end); 
  // create a matrix and save it to a file. This function is static
  // and does not need to create an object.
  static int create(char * filename, int row);
  // The last argument specifies the number of threads to be used.
  void multiply(Matrix * BM, Matrix * CM, int start, int end);
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
  QMutex mu;
};

class MyThread : public QThread {
 public:
  //int start;
  //int end;
  MyThread(Matrix* AIN, Matrix* BIN, Matrix* CIN, int s, int e) {
    ka = AIN;
    kb = BIN;
    kc = CIN;
    kstart = s;
    kend = e;
    start();
  }
  void run() {
    ka->multiply(kb, kc, kstart, kend); // unused second parameter;
  }
  Matrix* getBack() {
    return kc;
  }
 private:
  int kstart;
  int kend;
  Matrix* ka;
  Matrix* kb;
  Matrix* kc;
};

#endif /*MATRIX_H_*/
