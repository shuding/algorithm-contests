const maxn=101;
      inf=1000000000;

var n,a,num,i,l,r,m:longint;
    b:double;
    F:array[0..maxn] of double;

function get(p:double):double;
begin
  get:=(p-F[i-1])/(1+exp(ln(p-a)*b));
end;

function max(a,b:double):double;
begin
  if a>b then max:=a else max:=b;
end;

begin
    num:=0;
    while true do
    begin
        inc(num);
        read(n);
        if n=0 then halt;
        read(a,b);
        F[0]:=a;
        for i:=1 to n-1 do
        begin
            l:=a+1;r:=inf;
            while (l+1<r) do
            begin
                m:=trunc((l+r)/2);
                if get(m+1)-get(m)>=0 then
                    l:=m
                else
                    r:=m;
            end;
            F[i]:=max(get(l),get(r))+F[i-1];
        end;
        writeln('Case ',num,': ',F[n-1]:0:2);
    end;
end.
