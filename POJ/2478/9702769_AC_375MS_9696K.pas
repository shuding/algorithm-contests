program pku2478;

var n:array[1..1000000] of boolean;
    f:array[1..1000000] of int64;
    i,j:longint;
    ans:int64;

begin
  for i:=1 to 1000000 do
    begin
      f[i]:=i;
      n[i]:=true;
    end;
  for i:=2 to 1000000 do
    if n[i] then
    begin
      for j:=2 to (1000000 div i) do
        begin
          f[j*i]:=f[j*i]*(i-1) div i;
          n[j*i]:=false;
        end;
      f[i]:=i-1;
    end;
  for i:=3 to 1000000 do
    f[i]:=f[i]+f[i-1];
  readln(i);
  while i<>0 do
    begin
      writeln(f[i]);
      readln(i);
    end;
end.