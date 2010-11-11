load('m1');
load('m2');
load('m3');
tic;
m4 = m1 * m2;
toc;
max(max(abs(m3-m4)))
