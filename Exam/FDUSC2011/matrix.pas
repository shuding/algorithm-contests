program matrix;

uses crt;

type matrixs=array[1..2,1..2] of extended;

var a,b,k,n,tot:longint;
    base,t:matrixs;

    function mul(a,b:matrixs):matrixs;
    var c:matrixs;
        i,j,k:integer;
    begin
      c[1,1]:=a[1,1]*b[1,1]+a[1,2]*b[2,1];
      c[1,2]:=a[1,1]*b[1,2]+a[1,2]*b[2,2];
      c[2,1]:=a[2,1]*b[1,1]+a[2,2]*b[2,1];
      c[2,2]:=a[2,1]*b[1,2]+a[2,2]*b[2,2];
      mul:=c;
    end;

    function expe(n:longint):matrixs;
    var tt:matrixs;
    begin
      if n=1 then
        exit(base);
      tt:=expe(n div 2);
      tt:=mul(tt,tt);
      if n and 1=1 then
        tt:=mul(tt,base);
      exit(tt);
    end;

begin
  read(a,b,k,n);
  a:=a mod k;
  b:=b mod k;
  base[1,1]:=0;
  base[1,2]:=1;
  base[2,1]:=1;
  base[2,2]:=1;
  t:=expe(n+1);
  write(t[1,1]:0:0);
  readkey;
end.
