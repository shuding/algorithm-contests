program buses;

var
  n, i, min: integer;
  t: array[1..300] of integer;
  f: array[0..59] of integer;

  function can(a, b: integer): boolean;
  var
    i, d: integer;
  begin
    d := t[b] - t[a];
    for i := 0 to 59 do
      if abs(i - t[a]) mod d = 0 then
        if f[i] <= 0 then
          exit(False);
    exit(True);
  end;

  procedure seek(j: integer);
  var
    k, p, d, i: integer;
    flag: boolean;
  begin
    if j >= min then
      exit;
    flag := True;
    for k := 1 to n do
      if f[t[k]] <> 0 then
      begin
        flag := False;
        break;
      end;
    if flag then
    begin
      min := j;
      exit;
    end;
    for p := k + 1 to n do
      if can(k, p) then
      begin
        d := t[p] - t[k];
        for i := 0 to 59 do
          if abs(i - t[k]) mod d = 0 then
            Dec(f[i]);
        seek(j + 1);
        for i := 0 to 59 do
          if abs(i - t[k]) mod d = 0 then
            Inc(f[i]);
      end;
  end;

begin
  Read(n);
  fillchar(f, sizeof(f), 0);
  for i := 1 to n do
  begin
    Read(t[i]);
    Inc(f[t[i]]);
  end;
  min := 17;
  seek(0);
  Writeln(min);
end.
