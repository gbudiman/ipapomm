load('m1_1024');
load('m2_1024');
load('m3_1024');
load('m1_2048');
load('m2_2048');
load('m3_2048');
load('m1_4096');
load('m2_4096');
load('m3_4096');
tic;
m4_1024 = m1_1024 * m2_1024;
toc;
tic;
m4_2048 = m1_2048 * m2_2048;
toc;
tic;
m4_4096 = m1_4096 * m2_4096;
toc;
max(max(abs(m3_1024-m4_1024)))
max(max(abs(m3_2048-m4_2048)))
max(max(abs(m3_4096-m4_4096)))
