#include "matrix.h"
#include <iostream>
#include <algorithm>
using namespace std;
int Matrix::create(char * filename, int row) 
{
  QFile outfile(filename);
  if (! outfile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
      cerr << "open " << filename << " failed" << endl;
      return -1;
    }
  QTextStream outstream(& outfile);
  for (int r = 0; r < row; r ++)
    {
      for (int c = 0; c < row; c ++)
	{
	  outstream << rand() % 100 << " ";
	}
      outstream << endl;
    }
  outfile.close();
  return 0;
}

int Matrix::allocateMemory(int n)
{
  numRow = n;
  elements = new int *[n];
  if (elements == NULL) 
    {
      cerr << "memory allocation fail"<< endl;
      return -1;
    }
  for (int r = 0; r <  n; r ++)
    {
      elements[r] = new int [n];
      int* eir = elements[r];
      for (int mr = 0; mr < n; mr++) {
	eir[mr] = 0;
      }
      if (elements[r] == NULL) 
	{
	  cerr << "memory allocation fail"<< endl;
	  return -1;
	}
    }
  return 0;
}

void Matrix::assignRow(int r, QString & oneLine)
{
  QStringList qsl = oneLine.split(" ");
  for (int c = 0; c < numRow; c ++)
    {
      elements[r][c] = qsl[c].toInt();
    }
}

Matrix::Matrix(int n)
{
  allocateMemory(n);
}

Matrix::Matrix(char * filename) 
{
  QFile infile(filename);
  if (! infile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
      cerr << "open " << filename << " failed" << endl;
      return;
    }
  QTextStream instream(&infile);
  QString oneLine = instream.readLine();
  int n = oneLine.count(" ");
  if (n <= 0)
    {
      cerr << "wrong matrix size" << endl;
      return;
    }
  else
    {
      // cout << "matrix size: " << n << endl;
    }
  if (allocateMemory(n) == 0)
    {
      int r = 0;
      assignRow(r, oneLine);
      for (int r = 1; r < n; r ++)
	{
	  oneLine = instream.readLine();
	  assignRow(r, oneLine);
	}
    }
  infile.close();
}

void Matrix::copyElement(const Matrix & orig) 
{
  if (allocateMemory(orig.numRow) != 0)
    {
      return;
    }
  for (int r = 0; r < numRow; r ++)
    {
      for (int c = 0; c < numRow; c ++)
	{
	  elements[r][c] = orig.elements[r][c];
	}
    }
}

Matrix::Matrix(const Matrix & orig) 
{
  copyElement(orig);
}

Matrix & Matrix::operator = (const Matrix & orig)
{
  if (this != & orig)
    {
      // cannot use "delete this" because it will also release the
      // space for numRow
      for (int r = 0; r < numRow; r ++)
	{
	  delete [] elements[r];
	}
      delete [] elements;
      copyElement(orig);
    }
  return * this;
}

Matrix * Matrix::append(Matrix * orig, int rowStart, int rowEnd) {
  for (int localrow = rowStart; localrow < rowEnd; localrow++) {
    int* lptr = elements[localrow];
    int* optr = orig->elements[localrow];
    for (int localcol = 0; localcol < numRow; localcol++) {
      //elements[localrow][localcol] = orig->elements[localrow][localcol];
      lptr[localcol] = optr[localcol];
    }
  }
  return this;
}

Matrix::~Matrix() {
  if (elements) 
    {
      for (int r = 0; r < numRow; r ++)
	{
	  delete [] elements[r];
	}
      delete [] elements;
    }
}

Matrix * Matrix::multiply(Matrix * B, int start, int end)
{
  if (numRow != B -> numRow)
    {
      cerr << "different dimensions"<< endl;
      return 0;
    }
  Matrix * C = new Matrix(numRow);

  int step = 64;
  for (int i0 = start; i0 < end; i0 += step) {
    for (int j0 = 0; j0 < numRow; j0 += step) {
      for (int k0 = 0; k0 < numRow; k0 += step) {
        for (int i = i0; i < min(i0 + step, end); i++) {
          int* cipointer = C->elements[i];
          int* aipointer = elements[i];
          for (int j = j0; j < min(j0 + step, numRow); j++) {
            for (int k = k0; k < min(k0 + step, numRow); ) {
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
              cipointer[j] = cipointer[j] + aipointer[k] * B->elements[k++][j];
            }
          }
        }
      }
    }
  }

  return C;
}

void Matrix::print(char * filename)
{
  QFile outfile(filename);
  if (! outfile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
      cerr << "open " << filename << " failed" << endl;
      return;
    }
  QTextStream outstream(& outfile);
  for (int r = 0; r < numRow; r ++)
    {
      for (int c = 0; c < numRow; c ++)
	{
	  outstream << elements[r][c] << " ";
	}
      outstream << endl;
    }
  outfile.close();
}
