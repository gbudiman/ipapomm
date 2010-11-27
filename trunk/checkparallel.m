load('m1');
load('m2');
load('m31');
load('m32');
load('m34');
load('m38');
load('m316');
load('m332');
tic;
m4 = m1 * m2;
toc;
max(max(abs(m31-m4)))
max(max(abs(m32-m4)))
max(max(abs(m34-m4)))
max(max(abs(m38-m4)))
max(max(abs(m316-m4)))
max(max(abs(m332-m4)))
