var n,i,j:integer;
    f:array[1..100,1..100] of longint;

function max(a,b:longint):longint;
begin
  if a>b then max:=a else max:=b;
end;

begin
  read(n);
  for i:=1 to n do
    for j:=1 to n do
      read(f[i,j]);
  for i:=n-1 downto 1 do
    for j:=1 to i do
      f[i,j]:=max(f[i+1,j],f[i+1,j+1])+f[i,j];
  writeln(f[1,1]);
end.