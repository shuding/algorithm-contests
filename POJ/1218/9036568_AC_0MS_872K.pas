var n,i,j:longint;

begin
  read(n);
  for i:=1 to n do
    begin
      read(j);
      writeln(trunc(sqrt(j)));
    end;
end.