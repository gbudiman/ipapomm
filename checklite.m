load('m11');
load('m21');
load('m31');
load('m12');
load('m22');
load('m32');
load('m13');
load('m23');
load('m33');
load('m14');
load('m24');
load('m34');
tic;
m41 = m11 * m21;
m42 = m12 * m22;
m43 = m13 * m23;
m44 = m14 * m24;
toc;
fprintf('64');
max(max(abs(m31-m41)))
fprintf('256');
max(max(abs(m32-m42)))
fprintf('1024');
max(max(abs(m33-m43)))
fprintf('4096');
max(max(abs(m34-m44)))
