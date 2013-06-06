program poj3468;

type
  node = record
    x, y: longint;
    sum,adk: int64;
  end;

var
  n, q, i, j, a, b, c, max: longint;
  t: array[1..260000] of node;
  ch: char;

  procedure build(n, i, j: longint);
  begin
    t[n].x := i;
    t[n].y := j;
    t[n].sum := 0;
    t[n].adk:=0;
    if i = j then
    begin
      Read(t[n].sum);
      if n > max then
        max := n;
      exit;
    end;
    build(2 * n, i, (i + j) shr 1);
    build(2 * n + 1, (i + j) shr 1 + 1, j);
    t[n].sum := t[2 * n].sum + t[2 * n + 1].sum;
  end;

  function que(n, i, j: longint): longint;
  begin
    if (t[n].x = i) and (t[n].y = j) then
      exit(t[n].sum);
    if i > (t[n].x + t[n].y) shr 1 then
      exit(que(2 * n + 1, i, j)+t[n].adk*(j-i+1))
    else
    if j <= (t[n].x + t[n].y) shr 1 then
      exit(que(2 * n, i, j)+t[n].adk*(j-i+1))
    else
      exit(que(2 * n, i, (t[n].x + t[n].y) shr 1) +
        que(2 * n + 1, (t[n].x + t[n].y) shr 1 + 1, j)+t[n].adk*(j-i+1));
  end;

  procedure add(n, i, j, k: longint);
  begin
    if (t[n].x = i) and (t[n].y = j) then
    begin
      t[n].sum := t[n].sum + k * (j - i + 1);
      t[n].adk:=k;
      exit;
    end;
    if i > (t[n].x + t[n].y) shr 1 then
      add(2 * n + 1, i, j, k)
    else
    if j <= (t[n].x + t[n].y) shr 1 then
      add(2 * n, i, j, k)
    else
    begin
      add(2 * n, i, (t[n].x + t[n].y) shr 1, k);
      add(2 * n + 1, (t[n].x + t[n].y) shr 1 + 1, j, k);
    end;
    t[n].sum := t[2 * n].sum + t[2 * n + 1].sum;
  end;

begin
  Read(n, q);
  readln;
  build(1, 1, n);
  readln;
  for i := 1 to q do
  begin
    Read(ch);
    case ch of
      'Q':
      begin
        Read(a, b);
        writeln(que(1, a, b));
      end;
      'C':
      begin
        Read(a, b, c);
        add(1, a, b, c);
      end;
    end;
    readln;
  end;
end.
