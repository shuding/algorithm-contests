program project1;

type
  arr = array[1..10000] of real;

var
  n, m, i, j: longint;
  ax, ay, bx, by, cx, cy, dx, dy: longint;
  tot: real;
  t1, t2: arr;

  procedure qsort(var Data: arr; i, j: integer);
  var
    p, q: integer;
    key: real;
  begin
    p := i;
    q := j;
    key := Data[i];
    while p < q do
    begin
      while (p < q) and (key <= Data[q]) do
        Dec(q);
      if p <> q then
      begin
        Data[p] := Data[q];
        Inc(p);
      end;
      while (p < q) and (key >= Data[p]) do
        Inc(p);
      if p < q then
      begin
        Data[q] := Data[p];
        Dec(q);
      end;
    end;
    Data[p] := key;
    if p - i > 1 then
      qsort(data,i, p - 1);
    if j - q > 1 then
      qsort(data,q + 1, j);
  end;

  function getx(t: real; n: integer): real;
  begin
    if n = 1 then
      getx := ax * t + bx * (1 - t)
    else
      getx := cx * t + dx * (1 - t);
  end;

  function gety(t: real; n: integer): real;
  begin
    if n = 1 then
      gety := ay * t + by * (1 - t)
    else
      gety := cy * t + dy * (1 - t);
  end;

  function getper(t: real; s: integer): real;
  var
    m, n, a, b, c, p: real;
  begin
    m := getx(t, s);
    n := gety(t, s);
    if s = 2 then
    begin
      a := (bx - ay);
      b := (ax - bx);
      c := ay * bx - ax * by;
    end
    else
    begin
      a := (dx - cy);
      b := (cx - dx);
      c := cy * dx - cx * dy;
    end;
    p := (b * b * m - a * b * n - a * c) / (a * a + b * b);
    getper := p;
  end;

  function seek(t: real; n, i, j: integer): integer;
  var
    a, b: integer;
  begin
    if i = j then
      if n = 1 then
        exit(i)
      else
        exit(i);
    a := seek(t, n, i, (i + j) shr 1);
    b := aeek(t, n, (i + j) shr 1 + 1, j);
    if n = 1 then
      if abs(getx(t1[a], n) - t) < abs(getx(t1[b], n) - t) then
        exit(a)
      else
        exit(b)
    else
    if abs(getx(t2[a], n) - t) < abs(getx(t2[b], n) - t) then
      exit(a)
    else
      exit(b);
  end;

  function dis(a, b, n, m: integer): real;
  begin
    if n = 1 then
      if m = 1 then
        exit(sqrt(sqr(getx(t1[a]) - getx(t1[b])) + sqr(gety(t1[a]) - gety(t1[b]))))
      else
        exit(sqrt(sqr(getx(t1[a]) - getx(t2[b])) + sqr(gety(t1[a]) - gety(t2[b]))))
    else
    if m = 1 then
      exit(sqrt(sqr(getx(t2[a]) - getx(t1[b])) + sqr(gety(t2[a]) - gety(t1[b]))))
    else
      exit(sqrt(sqr(getx(t2[a]) - getx(t2[b])) + sqr(gety(t2[a]) - gety(t2[b]))));
  end;

  procedure sovle;
  var
    i, j: longint;
    a,b:real;
    vst:array[1..10000] of boolean;
  begin
    tot := 0;
    for i := 1 to n-1 do
      begin
        a:=dis(i,i+1,1,1);
        b:=dis(i,seek(getper(t1[i],1),1,2));
        if a>b then tot:=tot+b else tot:=tot+b;
      end;
    for i := 1 to m-1 do
      begin
        a:=dis(i,i+1,2,2);
        b:=dis(i,seek(getper(t2[i],2),2,1));
        if a>b then tot:=tot+b else tot:=tot+b;
      end;
    writeln(tot);
  end;

begin
  Read(n, m);
  Read(ax, ay, bx, by, cx, cy, dx, dy);
  for i := 1 to n do
    Read(t1[i]);
  for i := 1 to m do
    Read(t2[i]);
  qsort(t1, 1, n);
  qsort(t2, 1, m);
end.

