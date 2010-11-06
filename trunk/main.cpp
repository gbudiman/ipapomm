/*
 * Do not modify this file.
 */
#include "matrix.h"
#include <sys/time.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <QtCore>
#include <qthread.h>
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
  MyThread* th1;
  MyThread* th2;
  MyThread* th3;
  MyThread* th4;
  MyThread* th5;
  MyThread* th6;
  MyThread* th7;
  MyThread* th8;
  MyThread* th9;
  MyThread* th10;
  MyThread* th11;
  MyThread* th12;
  MyThread* th13;
  MyThread* th14;
  MyThread* th15;
  MyThread* th16;
  MyThread* th17;
  MyThread* th18;
  MyThread* th19;
  MyThread* th20;
  MyThread* th21;
  MyThread* th22;
  MyThread* th23;
  MyThread* th24;
  MyThread* th25;
  MyThread* th26;
  MyThread* th27;
  MyThread* th28;
  MyThread* th29;
  MyThread* th30;
  MyThread* th31;
  MyThread* th32;

  switch (cmd)
    {
    case 'c':
      Matrix::create(argv[3], numRow);
      return 0;
    case 'm':
      m1 = new Matrix(argv[3]);
      m2 = new Matrix(argv[4]);
      gettimeofday(&t1, 0);
      //m3 = new Matrix(numRow);
      if (numThread == 1) {
        th1 = new MyThread(m1, m2, m3, 0, m1->size());
        th1->start();
        th1->wait();
        m3 = th1->getBack();
      }
      else if (numThread == 2) {
        th1 = new MyThread(m1, m2, m3, 0, m1->size()/2);
        th2 = new MyThread(m1, m2, m3, m1->size()/2, m1->size());
        th1->start();
        th2->start();
        th1->wait();
        th2->wait();
        m3 = th1->getBack();
        //Matrix* mx = th2->getback();
        m3->append(th2->getBack(), m1->size()/2, m1->size());
      }
      //}
      //m3 = m1 -> multiply(m2, numThread);
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
