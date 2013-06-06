var a,b:ansistring;
    f:array[0..10000,0..10000] of integer;
    i,j:integer;
begin
  while not seekeoln do
    begin
      readln(b);
      a:=copy(b,1,pos(' ',b)-1);
      delete(b,1,pos(' ',b));
      f[0,0]:=0;
      for i:=1 to length(a) do
        for j:=1 to length(b) do
          if a[i]=b[j] then
             f[i,j]:=f[i-1,j-1]+1
          else if f[i-1,j]>f[i,j-1] then f[i,j]:=f[i-1,j] else f[i,j]:=f[i,j-1];
      writeln(f[length(a),length(b)]);
    end;
end.