program POJ2653;

var
  n, i, j: longint;
  x1, y1, x2, y2: array[1..100000] of real;
  top: array[1..100000] of boolean;
  tot: integer;

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
  fillchar(top,sizoef(top),true);
  for i := 1 to n do
    Read(x1[i], y1[i], x2[i], y2[i]);
  for i:=1 to n do
  begin
    for j:=i+1 to n do
      if tax(i, j) then
      begin
        top[i] := False;
        break;
      end;
  end;
  Write('Top sticks:');
  tot:=0;
  for i := 1 to n do
    begin
      if (tot>0) and top[i] then
        write(', ', i);
      if (tot=0) and top[i] then
      begin
        inc(tot);
        Write(' ', i);
      end;
    end;
  writeln('.');
  read(n);
  end;
end.
