program Atlantis;

type
  arr = array[1..200] of real;

var
  n, i, j, k, p, q, r, s, xtot, ytot, time: integer;
  area: real;
  xr, yr: arr;
  x1, y1, x2, y2: array[1..100] of real;
  f: array[1..202, 1..202] of boolean;

  function max(a, b: real): real;
  begin
    if a > b then
      max := a
    else
      max := b;
  end;

  procedure qsort(i, j: integer; var Data: arr);
  var
    p, q: integer;
    key: real;
  begin
    p := i;
    q := j;
    key := Data[p];
    while p < q do
    begin
      while (p < q) and (key <= Data[q]) do
        Dec(q);
      if p < q then
      begin
        Data[p] := Data[q];
        Inc(p);
      end;
      while (p < Q) and (Data[p] <= key) do
        Inc(p);
      if p < q then
      begin
        Data[q] := Data[p];
        Dec(q);
      end;
    end;
    Data[p] := key;
    if p - i > 1 then
      qsort(i, p - 1, Data);
    if j - q > 1 then
      qsort(q + 1, j, Data);
  end;

  function seek(t: arr; a: real; i, j: integer): integer;
  begin
    if t[(i + j) div 2] = a then
      exit((i + j) div 2);
    if t[(i + j) div 2] > a then
      exit(seek(t, a, i, (i + j) div 2 - 1))
    else
      exit(seek(t, a, (i + j) div 2 + 1, j));
  end;

  procedure swap(var a, b: real);
  var
    c: real;
  begin
    c := a;
    a := b;
    b := c;
  end;

begin
  Read(n);
  time := 0;
  while n <> 0 do
  begin
    for i := 1 to n do
    begin
      Read(x1[i], y1[i], x2[i], y2[i]);
      if x1[i] > x2[i] then
        swap(x1[i], x2[i]);
      if y1[i] > y2[i] then
        swap(y1[i], y2[i]);
      xr[2 * i - 1] := x1[i];
      xr[2 * i] := x2[i];
      yr[2 * i - 1] := y1[i];
      yr[2 * i] := y2[i];
    end;
    qsort(1, 2 * n, xr);
    qsort(1, 2 * n, yr);
    xtot := 1;
    ytot := 1;
    for i := 2 to 2 * n do
      if xr[i] <> xr[i - 1] then
      begin
        Inc(xtot);
        xr[xtot] := xr[i];
      end;
    for i := 2 to 2 * n do
      if yr[i] <> yr[i - 1] then
      begin
        Inc(ytot);
        yr[ytot] := yr[i];
      end;
    area := 0;
    fillchar(f, sizeof(f), False);
    for i := 1 to n do
    begin
      p := seek(xr, x1[i], 1, 2 * n);
      q := seek(xr, x2[i], 1, 2 * n);
      r := seek(yr, y1[i], 1, 2 * n);
      s := seek(yr, y2[i], 1, 2 * n);
      for j := p to q - 1 do
        for k := r to s - 1 do
          f[j, k] := True;
    end;
    for i := 1 to xtot do
      for j := 1 to ytot do
        if f[i, j] then
          area := area + (xr[i + 1] - xr[i]) * (yr[i + 1] - yr[i]);
    Inc(time);
    writeln('Test case #', time);
    Writeln('Total explored area: ', area: 0: 2);
    Read(n);
  end;
end.
