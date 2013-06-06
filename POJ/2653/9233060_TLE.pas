program sticks;

var
  n, i, j: longint;
  x1, y1, x2, y2: array[1..100000] of real;
  top: array[1..100000] of boolean;
  l: array[1..100000] of longint;

  function tax(i, j: longint): boolean;
  var
    s1, s2: extended;
  begin
    s1 := x1[i] * y1[j] + x1[j] * y2[i] + y1[i] * x2[i] - y1[j] *
      x2[i] - y1[i] * x1[j] - y2[i] * x1[i];
    s2 := x2[i] * y2[j] + x2[j] * y1[i] + y2[i] * x1[i] - y2[j] *
      x1[i] - y2[i] * x2[j] - x2[i] * y1[i];
    if s1 * s2 >= 0 then
    begin
      s1 := x1[j] * y1[i] + x1[i] * y2[j] + y1[j] * x2[j] - y1[i] *
        x2[j] - y1[j] * x1[i] - y2[j] * x1[j];
      s2 := x2[j] * y2[i] + x2[i] * y1[j] + y2[j] * x1[j] - y2[i] *
        x1[j] - y2[j] * x2[i] - x2[j] * y1[j];
      if s1 * s2 >= 0 then
        exit(True)
      else
        exit(False);
    end
    else
      exit(False);
  end;

begin
  Read(n);
  while n<>0 do
  begin
  for i := 1 to n do
  begin
    top[i] := True;
    Read(x1[i], y1[i], x2[i], y2[i]);
    l[i] := i - 1;
    j := i - 1;
    while j > 0 do
    begin
      if tax(i, j) then
      begin
        top[j] := False;
        if j = l[i] then
          Dec(l[i]);
      end;
      j := l[j];
    end;
  end;
  Write('Top sticks:');
  for i := 1 to n do
    if top[i] then
      Write(' ', i, ',');
  writeln(chr(8),'.');
  read(n);
  end;
end.
