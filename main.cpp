/*
 * Do not modify this file.
 */
#include "matrix.h"
#include <sys/time.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <QtCore>
using namespace std;
static void commandOptions()
{
  cerr << "usage:" << endl;
  cerr << "  c r f: create a r x r matrix and save it in file f" << endl;
  cerr << "  m n f1 f2 f3: multiply two matrixes using n threads;" << endl;
  cerr << "                from files f1 and f2 to f3" << endl;
}
int main(int argc, char * argv[]) 
{
  // set the random number seed so that it is sufficiently random
  srand(time(NULL)); 
  if (argc < 4)
    {
      commandOptions();
      return -1;
    }
  char cmd = 0;
  int numThread = 1;
  int numRow = 1;
  if ((strcmp(argv[1], "c") == 0) && (argc >= 4)) 
    { 
      cmd = 'c'; 
      numRow = (int)strtol(argv[2], (char **)NULL, 10);
    }
  if ((strcmp(argv[1], "m") == 0) && (argc >= 5)) 
    { 
      cmd = 'm'; 
      numThread = (int)strtol(argv[2], (char **)NULL, 10);
    }
  if (cmd == 0)
    {
      cerr << "unknown command" << endl;
      commandOptions();
      return -1;
    }
  if (numRow <= 0)
    {
      cerr << "number of rows must be positive" << endl;
      return -1;
    }
  if (numThread <= 0)
    {
      cerr << "number of threads must be positive" << endl;
      return -1;
    }
  Matrix * m1 = 0;
  Matrix * m2 = 0;
  Matrix * m3 = 0;
  struct timeval t1;
  struct timeval t2;
  switch (cmd)
    {
    case 'c':
      Matrix::create(argv[3], numRow);
      return 0;
    case 'm':
      m1 = new Matrix(argv[3]);
      m2 = new Matrix(argv[4]);
      gettimeofday(&t1, 0);
      m3 = m1 -> multiply(m2, numThread);
      gettimeofday(&t2, 0);
      m3 -> print(argv[5]);
      break;
    default:
      // not necessary since it was checked already
      break;
    }
  if ((m1 != 0) || (m2 != 0) || (m3 != 0))
    {
      /* some problem occurred */
      if (m1 != 0) { delete m1; }
      if (m2 != 0) { delete m2; }
      if (m3 != 0) { delete m3; }
    }
  double msec = 1.0e+3 * (t2.tv_sec - t1.tv_sec) +
    1.0e-3 * (t2.tv_usec - t1.tv_usec);
  cout << "time : " << msec << " ms" << endl;
  return 0;
}
