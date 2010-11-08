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
  MyThread* th33;
  MyThread* th34;
  MyThread* th35;
  MyThread* th36;
  MyThread* th37;
  MyThread* th38;
  MyThread* th39;
  MyThread* th40;
  MyThread* th41;
  MyThread* th42;
  MyThread* th43;
  MyThread* th44;
  MyThread* th45;
  MyThread* th46;
  MyThread* th47;
  MyThread* th48;
  MyThread* th49;
  MyThread* th50;
  MyThread* th51;
  MyThread* th52;
  MyThread* th53;
  MyThread* th54;
  MyThread* th55;
  MyThread* th56;
  MyThread* th57;
  MyThread* th58;
  MyThread* th59;
  MyThread* th60;
  MyThread* th61;
  MyThread* th62;
  MyThread* th63;
  MyThread* th64;

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
      if (numThread == 1) {
        th1 = new MyThread(m1, m2, m3, 0, m1->size());
        th1->start();
        th1->wait();
      }
      else if (numThread == 2) {
        th1 = new MyThread(m1, m2, m3, 0, matsize/2);
        th2 = new MyThread(m1, m2, m3, matsize/2, matsize);
        th1->start();
        th2->start();
        th1->wait();
        th2->wait();
        //m3 = th1->getBack();
        //Matrix* mx = th2->getback();
        //m3->append(th2->getBack(), matsize/2, matsize);
      }
      else if (numThread == 4) {
        th1 = new MyThread(m1, m2, m3, 0, matsize*1/4);
        th2 = new MyThread(m1, m2, m3, matsize*1/4, matsize*2/4);
        th3 = new MyThread(m1, m2, m3, matsize*2/4, matsize*3/4);
        th4 = new MyThread(m1, m2, m3, matsize*3/4, matsize*4/4);
        th1->start(); th2->start(); th3->start(); th4->start();
        th1->wait(); th2->wait(); th3->wait(); th4->wait();
      }
      else if (numThread == 8) {
        th1 = new MyThread(m1, m2, m3, matsize*0/8, matsize*1/8);
        th2 = new MyThread(m1, m2, m3, matsize*1/8, matsize*2/8);
        th3 = new MyThread(m1, m2, m3, matsize*2/8, matsize*3/8);
        th4 = new MyThread(m1, m2, m3, matsize*3/8, matsize*4/8);
        th5 = new MyThread(m1, m2, m3, matsize*4/8, matsize*5/8);
        th6 = new MyThread(m1, m2, m3, matsize*5/8, matsize*6/8);
        th7 = new MyThread(m1, m2, m3, matsize*6/8, matsize*7/8);
        th8 = new MyThread(m1, m2, m3, matsize*7/8, matsize*8/8);
        th1->start(); th2->start(); th3->start(); th4->start();
        th5->start(); th6->start(); th7->start(); th8->start();
        th1->wait(); th2->wait(); th3->wait(); th4->wait();
        th5->wait(); th6->wait(); th7->wait(); th8->wait();
      }
      else if (numThread == 16) {
        th1 = new MyThread(m1, m2, m3, matsize*0/16, matsize*1/16);
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
        th16 = new MyThread(m1, m2, m3, matsize*15/16, matsize*16/16);
        th1->start(); th2->start(); th3->start(); th4->start();
        th5->start(); th6->start(); th7->start(); th8->start();
        th9->start(); th10->start(); th11->start(); th12->start();
        th13->start(); th14->start(); th15->start(); th16->start();
        th1->wait(); th2->wait(); th3->wait(); th4->wait();
        th5->wait(); th6->wait(); th7->wait(); th8->wait();
        th9->wait(); th10->wait(); th11->wait(); th12->wait();
        th13->wait(); th14->wait(); th15->wait(); th16->wait();
      }
      else if (numThread == 32) {
        th1 = new MyThread(m1, m2, m3, matsize*0/32, matsize*1/32);
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
        th32 = new MyThread(m1, m2, m3, matsize*31/32, matsize*32/32);
        th1->start(); th2->start(); th3->start(); th4->start();
        th5->start(); th6->start(); th7->start(); th8->start();
        th9->start(); th10->start(); th11->start(); th12->start();
        th13->start(); th14->start(); th15->start(); th16->start();
        th17->start(); th18->start(); th19->start(); th20->start();
        th21->start(); th22->start(); th23->start(); th24->start();
        th25->start(); th26->start(); th27->start(); th28->start();
        th29->start(); th30->start(); th31->start(); th32->start();
        th1->wait(); th2->wait(); th3->wait(); th4->wait();
        th5->wait(); th6->wait(); th7->wait(); th8->wait();
        th9->wait(); th10->wait(); th11->wait(); th12->wait();
        th13->wait(); th14->wait(); th15->wait(); th16->wait();
        th17->wait(); th18->wait(); th19->wait(); th20->wait();
        th21->wait(); th22->wait(); th23->wait(); th24->wait();
        th25->wait(); th26->wait(); th27->wait(); th28->wait();
        th29->wait(); th30->wait(); th31->wait(); th32->wait();
      }
      /*else if (numThread == 64) {
        th1 = new MyThread(m1, m2, m3, matsize*0/64, matsize*1/64);
        th2 = new MyThread(m1, m2, m3, matsize*1/64, matsize*2/64);
        th3 = new MyThread(m1, m2, m3, matsize*2/64, matsize*3/64);
        th4 = new MyThread(m1, m2, m3, matsize*3/64, matsize*4/64);
        th5 = new MyThread(m1, m2, m3, matsize*4/64, matsize*5/64);
        th6 = new MyThread(m1, m2, m3, matsize*5/64, matsize*6/64);
        th7 = new MyThread(m1, m2, m3, matsize*6/64, matsize*7/64);
        th8 = new MyThread(m1, m2, m3, matsize*7/64, matsize*8/64);
        th9 = new MyThread(m1, m2, m3, matsize*8/64, matsize*9/64);
        th10 = new MyThread(m1, m2, m3, matsize*9/64, matsize*10/64);
        th11 = new MyThread(m1, m2, m3, matsize*10/64, matsize*11/64);
        th12 = new MyThread(m1, m2, m3, matsize*11/64, matsize*12/64);
        th13 = new MyThread(m1, m2, m3, matsize*12/64, matsize*13/64);
        th14 = new MyThread(m1, m2, m3, matsize*13/64, matsize*14/64);
        th15 = new MyThread(m1, m2, m3, matsize*14/64, matsize*15/64);
        th16 = new MyThread(m1, m2, m3, matsize*15/64, matsize*16/64);
        th17 = new MyThread(m1, m2, m3, matsize*16/64, matsize*17/64);
        th18 = new MyThread(m1, m2, m3, matsize*17/64, matsize*18/64);
        th19 = new MyThread(m1, m2, m3, matsize*18/64, matsize*19/64);
        th20 = new MyThread(m1, m2, m3, matsize*19/64, matsize*20/64);
        th21 = new MyThread(m1, m2, m3, matsize*20/64, matsize*21/64);
        th22 = new MyThread(m1, m2, m3, matsize*21/64, matsize*22/64);
        th23 = new MyThread(m1, m2, m3, matsize*22/64, matsize*23/64);
        th24 = new MyThread(m1, m2, m3, matsize*23/64, matsize*24/64);
        th25 = new MyThread(m1, m2, m3, matsize*24/64, matsize*25/64);
        th26 = new MyThread(m1, m2, m3, matsize*25/64, matsize*26/64);
        th27 = new MyThread(m1, m2, m3, matsize*26/64, matsize*27/64);
        th28 = new MyThread(m1, m2, m3, matsize*27/64, matsize*28/64);
        th29 = new MyThread(m1, m2, m3, matsize*28/64, matsize*29/64);
        th30 = new MyThread(m1, m2, m3, matsize*29/64, matsize*30/64);
        th31 = new MyThread(m1, m2, m3, matsize*30/64, matsize*31/64);
        th32 = new MyThread(m1, m2, m3, matsize*31/64, matsize*32/64);
        th33 = new MyThread(m1, m2, m3, matsize*32/64, matsize*33/64);
        th34 = new MyThread(m1, m2, m3, matsize*33/64, matsize*34/64);
        th35 = new MyThread(m1, m2, m3, matsize*34/64, matsize*35/64);
        th36 = new MyThread(m1, m2, m3, matsize*35/64, matsize*36/64);
        th37 = new MyThread(m1, m2, m3, matsize*36/64, matsize*37/64);
        th38 = new MyThread(m1, m2, m3, matsize*37/64, matsize*38/64);
        th39 = new MyThread(m1, m2, m3, matsize*38/64, matsize*39/64);
        th40 = new MyThread(m1, m2, m3, matsize*39/64, matsize*40/64);
        th41 = new MyThread(m1, m2, m3, matsize*40/64, matsize*41/64);
        th42 = new MyThread(m1, m2, m3, matsize*41/64, matsize*42/64);
        th43 = new MyThread(m1, m2, m3, matsize*42/64, matsize*43/64);
        th44 = new MyThread(m1, m2, m3, matsize*43/64, matsize*44/64);
        th45 = new MyThread(m1, m2, m3, matsize*44/64, matsize*45/64);
        th46 = new MyThread(m1, m2, m3, matsize*45/64, matsize*46/64);
        th47 = new MyThread(m1, m2, m3, matsize*46/64, matsize*47/64);
        th48 = new MyThread(m1, m2, m3, matsize*47/64, matsize*48/64);
        th49 = new MyThread(m1, m2, m3, matsize*48/64, matsize*49/64);
        th50 = new MyThread(m1, m2, m3, matsize*49/64, matsize*50/64);
        th51 = new MyThread(m1, m2, m3, matsize*50/64, matsize*51/64);
        th52 = new MyThread(m1, m2, m3, matsize*51/64, matsize*52/64);
        th53 = new MyThread(m1, m2, m3, matsize*52/64, matsize*53/64);
        th54 = new MyThread(m1, m2, m3, matsize*53/64, matsize*54/64);
        th55 = new MyThread(m1, m2, m3, matsize*54/64, matsize*55/64);
        th56 = new MyThread(m1, m2, m3, matsize*55/64, matsize*56/64);
        th57 = new MyThread(m1, m2, m3, matsize*56/64, matsize*57/64);
        th58 = new MyThread(m1, m2, m3, matsize*57/64, matsize*58/64);
        th59 = new MyThread(m1, m2, m3, matsize*58/64, matsize*59/64);
        th60 = new MyThread(m1, m2, m3, matsize*59/64, matsize*60/64);
        th61 = new MyThread(m1, m2, m3, matsize*60/64, matsize*61/64);
        th62 = new MyThread(m1, m2, m3, matsize*61/64, matsize*62/64);
        th63 = new MyThread(m1, m2, m3, matsize*62/64, matsize*63/64);
        th64 = new MyThread(m1, m2, m3, matsize*63/64, matsize*64/64);
        th1->start(); th2->start(); th3->start(); th4->start();
        th5->start(); th6->start(); th7->start(); th8->start();
        th9->start(); th10->start(); th11->start(); th12->start();
        th13->start(); th14->start(); th15->start(); th16->start();
        th17->start(); th18->start(); th19->start(); th20->start();
        th21->start(); th22->start(); th23->start(); th24->start();
        th25->start(); th26->start(); th27->start(); th28->start();
        th29->start(); th30->start(); th31->start(); th32->start();
        th33->start(); th34->start(); th35->start(); th36->start();
        th37->start(); th38->start(); th39->start(); th40->start();
        th41->start(); th42->start(); th43->start(); th44->start();
        th45->start(); th46->start(); th47->start(); th48->start();
        th49->start(); th50->start(); th51->start(); th52->start();
        th53->start(); th54->start(); th55->start(); th56->start();
        th57->start(); th58->start(); th59->start(); th60->start();
        th61->start(); th62->start(); th63->start(); th64->start();
        th1->wait(); th2->wait(); th3->wait(); th4->wait();
        th5->wait(); th6->wait(); th7->wait(); th8->wait();
        th9->wait(); th10->wait(); th11->wait(); th12->wait();
        th13->wait(); th14->wait(); th15->wait(); th16->wait();
        th17->wait(); th18->wait(); th19->wait(); th20->wait();
        th21->wait(); th22->wait(); th23->wait(); th24->wait();
        th25->wait(); th26->wait(); th27->wait(); th28->wait();
        th29->wait(); th30->wait(); th31->wait(); th32->wait();
      }*/
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
