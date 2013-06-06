program Poj2409;

var
  n: integer;

  function power(n: integer): longint;
  var
    k: longint;
  begin
    if n = 1 then
      exit(3);
    k := power(n shr 1);
    if n and 1 = 1 then
      exit(k * k * 3)
    else
      exit(k * k);
  end;

  function swap(s: integer): integer;
  var
    f: array[1..24] of integer;
    t: array[1..24] of boolean;
    i, j, k, tot: integer;
  begin
    for i := 1 to n do
      f[i] := (i + s - 1) mod n + 1;
    fillchar(t, sizeof(t), False);
    tot := 0;
    for i := 1 to n do
      if not t[i] then
      begin
        Inc(tot);
        j := i;
        t[i] := True;
        k := f[i];
        while k <> j do
        begin
          t[k] := True;
          k := f[k];
        end;
      end;
    exit(tot);
  end;

  procedure work;
  var
    g, i: integer;
    tot: longint;
  begin
    g := 2 * n;
    tot := power(n);
    for i := 1 to n - 1 do
      tot := tot + power(swap(i));
    if n and 1 = 1 then
      for i := 1 to n do
        tot := tot + power(1 + n div 2)
    else
      for i := 1 to n div 2 do
        tot := tot + power(1 + n div 2) + power(n div 2);
    writeln(trunc(tot) div g);
  end;

begin
  Read(n);
  while n <> -1 do
  begin
    work;
    Read(n);
  end;
end.
