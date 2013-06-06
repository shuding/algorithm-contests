program flower;

var
  n, v, i, j: integer;
  a: array [1..100, 1..100] of integer;
  r: array [0..100, 0..100] of boolean;
  f: array [0..100, 0..100] of integer;

  procedure print(i, j: integer);
  begin
    if j > i then
      exit;
    if r[i, j] then
    begin
      print(i - 1, j - 1);
      Write(i, ' ');
    end
    else
      print(i - 1, j);
  end;

begin
  Read(n, v);
  for i := 1 to n do
    for j := 1 to v do
      Read(a[i, j]);
  for j := 1 to n do
    for i := 1 to v do
      if j <= i then
        if (f[i - 1, j] >= f[i - 1, j - 1] + a[j, i]) and (i - 1 >= j) then
        begin
          f[i, j] := f[i - 1, j];
          r[i, j] := False;
        end
        else
        begin
          f[i, j] := f[i - 1, j - 1] + a[j, i];
          r[i, j] := True;
        end;
  writeln(f[v, n]);
  print(v, n);
end.
