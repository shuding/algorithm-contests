program POJ2388;

var n,i:longint;
    num:array[1..10000] of longint;

    function seek(i,j,k:longint):longint;
    var p,q,key:longint;
    begin
      key:=num[i];
      p:=i;q:=j;
      while p<>q do
      begin
        while (p<q) and (key<=num[q]) do dec(q);
        if p<>q then
        begin
          num[p]:=num[q];
          inc(p);
        end;
        while (p<q) and (key>=num[p]) do inc(p);
        if p<>q then
        begin
          num[q]:=num[p];
          dec(q);
        end;
      end;
      if p=k then exit(key);
      if k<p then exit(seek(i,p-1,k)) else exit(seek(p+1,j,k));
    end;

begin
  read(n);
  for i:=1 to n do read(num[i]);
  writeln(seek(1,n,(n+1) div 2));
end.
