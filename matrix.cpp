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

void Matrix::multiply(Matrix * B, Matrix * C, int start, int end)
{
  if (numRow != B -> numRow)
    {
      cerr << "different dimensions"<< endl;
      //return 0;
    }
  //Matrix * C = new Matrix(numRow);

  int step = 64;
  int* cipointer = 0;
  int* aipointer = 0;
  int i0;
  int j0;
  int k0;
  int i;
  int j;
  int k;
  int** celements = C->elements;
  int** belements = B->elements;
  int sum;
  int lmi, lmj, lmk;
  /*for (int ii = start; ii < end; ii += step) {
    for (int kk = 0; kk < numRow; kk += step) {
      for (int jj = 0; jj < numRow; jj += step) {
        for (int i = ii; i < min(ii + step, end); i++) {
          for (int j = jj; j < min(jj + step, numRow); j+=2) {
            int R = C->elements[j][i];
            for (int k = kk; k < min(kk + step, numRow); k++) {
              R = R + B->elements[k][i] * elements[j][k];
            }
            C->elements[j][i] = R;
          }
        }
      }
    }
  }*/
  for (i0 = start; i0 < end; i0 += step) {
    lmi = min(i0 + step, end);
    for (j0 = 0; j0 < numRow; j0 += step) {
      lmj = min(j0 + step, numRow);
      for (k0 = 0; k0 < numRow; k0 += step) {
        lmk = min(k0 + step, numRow);
        for (i = i0; i < lmi; i++) {
          cipointer = celements[i];
          aipointer = elements[i];
          for (j = j0; j < lmj; j++) {
            sum = cipointer[j];
            for (k = k0; k < lmk; k+=32) {
              sum += aipointer[k]*belements[k][j];
              sum += aipointer[k+1]*belements[k+1][j];
              sum += aipointer[k+2]*belements[k+2][j];
              sum += aipointer[k+3]*belements[k+3][j];
              sum += aipointer[k+4]*belements[k+4][j];
              sum += aipointer[k+5]*belements[k+5][j];
              sum += aipointer[k+6]*belements[k+6][j];
              sum += aipointer[k+7]*belements[k+7][j];
              sum += aipointer[k+8]*belements[k+8][j];
              sum += aipointer[k+9]*belements[k+9][j];
              sum += aipointer[k+10]*belements[k+10][j];
              sum += aipointer[k+11]*belements[k+11][j];
              sum += aipointer[k+12]*belements[k+12][j];
              sum += aipointer[k+13]*belements[k+13][j];
              sum += aipointer[k+14]*belements[k+14][j];
              sum += aipointer[k+15]*belements[k+15][j];
              sum += aipointer[k+16]*belements[k+16][j];
              sum += aipointer[k+17]*belements[k+17][j];
              sum += aipointer[k+18]*belements[k+18][j];
              sum += aipointer[k+19]*belements[k+19][j];
              sum += aipointer[k+20]*belements[k+20][j];
              sum += aipointer[k+21]*belements[k+21][j];
              sum += aipointer[k+22]*belements[k+22][j];
              sum += aipointer[k+23]*belements[k+23][j];
              sum += aipointer[k+24]*belements[k+24][j];
              sum += aipointer[k+25]*belements[k+25][j];
              sum += aipointer[k+26]*belements[k+26][j];
              sum += aipointer[k+27]*belements[k+27][j];
              sum += aipointer[k+28]*belements[k+28][j];
              sum += aipointer[k+29]*belements[k+29][j];
              sum += aipointer[k+30]*belements[k+30][j];
              sum += aipointer[k+31]*belements[k+31][j];
            }
            cipointer[j] = sum;
          }
        }
      }
    }
  }

  //return C;
}

void Matrix::multiplyGeneric(Matrix * B, Matrix * C, int start, int end)
{
  /*if (numRow != B -> numRow)
    {
      cerr << "different dimensions"<< endl;
      //return 0;
    }
  //Matrix * C = new Matrix(numRow);
  */

  int step = 64;
  int** celements = C->elements;
  int** belements = B->elements;
  
  for (int i0 = start; i0 < end; i0 += step) {
    int imin = min(i0 + step, end);
    for (int j0 = 0; j0 < numRow; j0 += step) {
      int jmin = min(j0 + step, numRow);
      for (int k0 = 0; k0 < numRow; k0 += step) {
        int kmin = min(k0 + step, numRow);
        for (int i = i0; i < imin; i++) {
          int* cipointer = celements[i];
          int* aipointer = elements[i];
          for (int j = j0; j < jmin; j++) {
            int sum = cipointer[j];
            for (int k = k0; k < kmin; k+=32) {
              sum += aipointer[k]*belements[k][j];
              sum += aipointer[k+1]*belements[k+1][j];
              sum += aipointer[k+2]*belements[k+2][j];
              sum += aipointer[k+3]*belements[k+3][j];
              sum += aipointer[k+4]*belements[k+4][j];
              sum += aipointer[k+5]*belements[k+5][j];
              sum += aipointer[k+6]*belements[k+6][j];
              sum += aipointer[k+7]*belements[k+7][j];
              sum += aipointer[k+8]*belements[k+8][j];
              sum += aipointer[k+9]*belements[k+9][j];
              sum += aipointer[k+10]*belements[k+10][j];
              sum += aipointer[k+11]*belements[k+11][j];
              sum += aipointer[k+12]*belements[k+12][j];
              sum += aipointer[k+13]*belements[k+13][j];
              sum += aipointer[k+14]*belements[k+14][j];
              sum += aipointer[k+15]*belements[k+15][j];
              sum += aipointer[k+16]*belements[k+16][j];
              sum += aipointer[k+17]*belements[k+17][j];
              sum += aipointer[k+18]*belements[k+18][j];
              sum += aipointer[k+19]*belements[k+19][j];
              sum += aipointer[k+20]*belements[k+20][j];
              sum += aipointer[k+21]*belements[k+21][j];
              sum += aipointer[k+22]*belements[k+22][j];
              sum += aipointer[k+23]*belements[k+23][j];
              sum += aipointer[k+24]*belements[k+24][j];
              sum += aipointer[k+25]*belements[k+25][j];
              sum += aipointer[k+26]*belements[k+26][j];
              sum += aipointer[k+27]*belements[k+27][j];
              sum += aipointer[k+28]*belements[k+28][j];
              sum += aipointer[k+29]*belements[k+29][j];
              sum += aipointer[k+30]*belements[k+30][j];
              sum += aipointer[k+31]*belements[k+31][j];
            }
            cipointer[j] = sum;
          }
        }
      }
    }
  }

  //return C;
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
