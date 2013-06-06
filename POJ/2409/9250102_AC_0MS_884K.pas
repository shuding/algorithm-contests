program Poj2409;

var
  m, n: longint;

  function power(m, n: integer): extended;
  var
    k: extended;
  begin
    if n = 1 then
      exit(m);
    k := power(m, n shr 1);
    if n and 1 = 1 then
      exit(k * k * m)
    else
      exit(k * k);
  end;

  function swap(s:integer):integer;
  var f:array[1..32] of integer;
      t:array[1..32] of boolean;
      i,j,k,tot:integer;
  begin
    for i:=1 to n do
      f[i]:=(i+s-1) mod n+1;
    fillchar(t,sizeof(t),false);
    tot:=0;
    for i:=1 to n do
      if not t[i] then
        begin
          inc(tot);
          j:=i;
          t[i]:=true;
          k:=f[i];
          while k<>j do
            begin
              t[k]:=true;
              k:=f[k];
            end;
        end;
    exit(tot);
  end;

  procedure work;
  var
    g, i: longint;
    tot: extended;
  begin
    g := 2 * n;
    tot := power(m, n);
    for i := 1 to n-1 do
      tot := tot + power(m, swap(i));
    if n and 1 = 1 then
      for i := 1 to n do
        tot := tot + power(m, 1 + n div 2)
    else
      for i := 1 to n div 2 do
        tot := tot + power(m, 1 + n div 2) + power(m, n div 2);
    writeln(trunc(tot) div g);
  end;

begin
  Read(m, n);
  while m + n <> 0 do
  begin
    work;
    Read(m, n);
  end;
end.
