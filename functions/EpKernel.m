function K=EpKernel(X,h)


X(abs(X)>1)=1;

K=0.75*(1-(X).^2)/h;

