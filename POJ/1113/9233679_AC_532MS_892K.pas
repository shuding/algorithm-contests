program POJ1113;

const
  oo = 10000001;

type
  point = record
    x, y: int64;
  end;

var
  n, i, j, l, r, Next, re: longint;
  p: array[1..5000] of point;
  left, right: point;
  s, max: real;

  function dis(i, j: longint): real;
  begin
    dis:=sqrt(sqr(p[i].x - p[j].x) + sqr(p[i].y - p[j].y));
  end;

begin
  Read(n, re);
  left.x := oo;
  right.x := -oo;
  for i := 1 to n do
  begin
    Read(p[i].x, p[i].y);
    if p[i].x > right.x then
    begin
      right := p[i];
      r := i;
    end;
    if p[i].x < left.x then
    begin
      left := p[i];
      l := i;
    end;
  end;
  s := 0;
  i := l;
  while i <> r do
  begin
    max := -oo;
    for j := 1 to n do
      if (p[j].x >= p[i].x) and (i <> j) and (dis(i, j)<>0) then
        if (p[j].y - p[i].y) / dis(i, j) > max then
        begin
          max := (p[j].y - p[i].y) / dis(i, j);
          Next := j;
        end;
    s := s + dis(i, Next);
    i := Next;
  end;
  while (i <> l) do
  begin
    max := -oo;
    for j := 1 to n do
      if (p[j].x <= p[i].x) and (i <> j) and (dis(i, j)<>0) then
        if (p[i].y - p[j].y) / dis(i, j) > max then
        begin
          max := (p[i].y - p[j].y) / dis(i, j);
          Next := j;
        end;
    s := s + dis(i, Next);
    i := Next;
  end;
  Write((s+2*re*3.1415926): 0: 0);
end.
