var
  x,y:double;i,n,ans:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(x,y);ans:=trunc(3.1415926535897932384626433832795*(x*x+y*y)/100)+1;
      writeln('Property ',i,': This property will begin eroding in year ',ans,'.');
    end;
  writeln('END OF OUTPUT.');
end.