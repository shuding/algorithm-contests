program POJ2409;

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

  procedure work;
  var
    g, i: longint;
    tot: extended;
  begin
    g := 2 * n;
    tot := power(m, n);
    for i := 1 to n div 2 do
      tot := tot + power(m, i);
    for i := 1 to n div 2 - 1 do
      tot := tot + power(m, i);
    if n and 1 = 1 then
      for i := 1 to n do
        tot := tot + power(m, 1 + (n - 1) div 2)
    else
      for i := 1 to n div 2 do
        tot := tot + power(m, 2 + (n - 2) div 2) + power(m, n div 2);
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
