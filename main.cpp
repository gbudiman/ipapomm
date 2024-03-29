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
  int matsize;
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
      matsize = m1->size();
      m3 = new Matrix(matsize);
      if (matsize <= 64 && numThread > 2) {
        numThread = 2;
      }
      switch (numThread) {
      case 1:
        th1 = new MyThread(m1, m2, m3, 0, matsize);
        th1->wait();
        break;
      case 2:
        th1 = new MyThread(m1, m2, m3, 0, matsize/2);
        th2 = new MyThread(m1, m2, m3, matsize/2, matsize);
        th1->wait();
        th2->wait();
        break;
      //case 3:
      case 4:
        th1 = new MyThread(m1, m2, m3, 0, matsize*1/4);
        th2 = new MyThread(m1, m2, m3, matsize*1/4, matsize*2/4);
        th3 = new MyThread(m1, m2, m3, matsize*2/4, matsize*3/4);
        th4 = new MyThread(m1, m2, m3, matsize*3/4, matsize);
        th1->wait(); th2->wait(); th3->wait(); th4->wait();
        break;
      //case 5:
      //case 6:
      //case 7:
      case 8:
        th1 = new MyThread(m1, m2, m3, 0, matsize*1/8);
        th2 = new MyThread(m1, m2, m3, matsize*1/8, matsize*2/8);
        th3 = new MyThread(m1, m2, m3, matsize*2/8, matsize*3/8);
        th4 = new MyThread(m1, m2, m3, matsize*3/8, matsize*4/8);
        th5 = new MyThread(m1, m2, m3, matsize*4/8, matsize*5/8);
        th6 = new MyThread(m1, m2, m3, matsize*5/8, matsize*6/8);
        th7 = new MyThread(m1, m2, m3, matsize*6/8, matsize*7/8);
        th8 = new MyThread(m1, m2, m3, matsize*7/8, matsize);
        th1->wait(); th2->wait(); th3->wait(); th4->wait();
        th5->wait(); th6->wait(); th7->wait(); th8->wait();
        break;
      /*case 9:
      case 10:
      case 11:
      case 12:
      case 13:
      case 14:
      case 15:*/
      case 16:
        th1 = new MyThread(m1, m2, m3, 0, matsize*1/16);
        th2 = new MyThread(m1, m2, m3, matsize*1/16, matsize*2/16);
        th3 = new MyThread(m1, m2, m3, matsize*2/16, matsize*3/16);
        th4 = new MyThread(m1, m2, m3, matsize*3/16, matsize*4/16);
        th5 = new MyThread(m1, m2, m3, matsize*4/16, matsize*5/16);
        th6 = new MyThread(m1, m2, m3, matsize*5/16, matsize*6/16);
        th7 = new MyThread(m1, m2, m3, matsize*6/16, matsize*7/16);
        th8 = new MyThread(m1, m2, m3, matsize*7/16, matsize*8/16);
        th9 = new MyThread(m1, m2, m3, matsize*8/16, matsize*9/16);
        th10 = new MyThread(m1, m2, m3, matsize*9/16, matsize*10/16);
        th11 = new MyThread(m1, m2, m3, matsize*10/16, matsize*11/16);
        th12 = new MyThread(m1, m2, m3, matsize*11/16, matsize*12/16);
        th13 = new MyThread(m1, m2, m3, matsize*12/16, matsize*13/16);
        th14 = new MyThread(m1, m2, m3, matsize*13/16, matsize*14/16);
        th15 = new MyThread(m1, m2, m3, matsize*14/16, matsize*15/16);
        th16 = new MyThread(m1, m2, m3, matsize*15/16, matsize);
        th1->wait(); th2->wait(); th3->wait(); th4->wait();
        th5->wait(); th6->wait(); th7->wait(); th8->wait();
        th9->wait(); th10->wait(); th11->wait(); th12->wait();
        th13->wait(); th14->wait(); th15->wait(); th16->wait();
      break;
      /*case 17:
      case 18:
      case 19:
      case 20:
      case 21:
      case 22:
      case 23:
      case 24:
      case 25:
      case 26:
      case 27:
      case 28:
      case 29:
      case 30:
      case 31:*/
      case 32:
        th1 = new MyThread(m1, m2, m3, 0, matsize*1/32);
        th2 = new MyThread(m1, m2, m3, matsize*1/32, matsize*2/32);
        th3 = new MyThread(m1, m2, m3, matsize*2/32, matsize*3/32);
        th4 = new MyThread(m1, m2, m3, matsize*3/32, matsize*4/32);
        th5 = new MyThread(m1, m2, m3, matsize*4/32, matsize*5/32);
        th6 = new MyThread(m1, m2, m3, matsize*5/32, matsize*6/32);
        th7 = new MyThread(m1, m2, m3, matsize*6/32, matsize*7/32);
        th8 = new MyThread(m1, m2, m3, matsize*7/32, matsize*8/32);
        th9 = new MyThread(m1, m2, m3, matsize*8/32, matsize*9/32);
        th10 = new MyThread(m1, m2, m3, matsize*9/32, matsize*10/32);
        th11 = new MyThread(m1, m2, m3, matsize*10/32, matsize*11/32);
        th12 = new MyThread(m1, m2, m3, matsize*11/32, matsize*12/32);
        th13 = new MyThread(m1, m2, m3, matsize*12/32, matsize*13/32);
        th14 = new MyThread(m1, m2, m3, matsize*13/32, matsize*14/32);
        th15 = new MyThread(m1, m2, m3, matsize*14/32, matsize*15/32);
        th16 = new MyThread(m1, m2, m3, matsize*15/32, matsize*16/32);
        th17 = new MyThread(m1, m2, m3, matsize*16/32, matsize*17/32);
        th18 = new MyThread(m1, m2, m3, matsize*17/32, matsize*18/32);
        th19 = new MyThread(m1, m2, m3, matsize*18/32, matsize*19/32);
        th20 = new MyThread(m1, m2, m3, matsize*19/32, matsize*20/32);
        th21 = new MyThread(m1, m2, m3, matsize*20/32, matsize*21/32);
        th22 = new MyThread(m1, m2, m3, matsize*21/32, matsize*22/32);
        th23 = new MyThread(m1, m2, m3, matsize*22/32, matsize*23/32);
        th24 = new MyThread(m1, m2, m3, matsize*23/32, matsize*24/32);
        th25 = new MyThread(m1, m2, m3, matsize*24/32, matsize*25/32);
        th26 = new MyThread(m1, m2, m3, matsize*25/32, matsize*26/32);
        th27 = new MyThread(m1, m2, m3, matsize*26/32, matsize*27/32);
        th28 = new MyThread(m1, m2, m3, matsize*27/32, matsize*28/32);
        th29 = new MyThread(m1, m2, m3, matsize*28/32, matsize*29/32);
        th30 = new MyThread(m1, m2, m3, matsize*29/32, matsize*30/32);
        th31 = new MyThread(m1, m2, m3, matsize*30/32, matsize*31/32);
        th32 = new MyThread(m1, m2, m3, matsize*31/32, matsize);
        th1->wait(); th2->wait(); th3->wait(); th4->wait();
        th5->wait(); th6->wait(); th7->wait(); th8->wait();
        th9->wait(); th10->wait(); th11->wait(); th12->wait();
        th13->wait(); th14->wait(); th15->wait(); th16->wait();
        th17->wait(); th18->wait(); th19->wait(); th20->wait();
        th21->wait(); th22->wait(); th23->wait(); th24->wait();
        th25->wait(); th26->wait(); th27->wait(); th28->wait();
        th29->wait(); th30->wait(); th31->wait(); th32->wait();
      break;
      default: cout << "Non-standard threads amount" << endl;
      }
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
