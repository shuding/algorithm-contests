program Equation;

var
  n, m, mid,i: longint;
  k, p: array[1..10] of longint;
  tot, ans: int64;
  hn: array[-10000..10000] of int64;

  function f(n: int64): longint;
  begin
    f := n mod 9973;
  end;

  function num(i, j: integer): int64;
  var
    q: integer;
    ans: int64;
  begin
    ans := k[i];
    for q := 1 to p[i] do
      ans := ans * j;
    num := ans;
  end;

  procedure seek1(deep, i: integer; ans: int64);
  var
    fs, j: longint;
  begin
    if i > deep then
    begin
      fs := f(ans);
      Inc(hn[fs]);
      exit;
    end;
    for j := 1 to m do
      seek1(deep, i + 1, ans + num(i,j));
  end;

  procedure seek2(deep, i: integer; ans: int64);
  var
    fs, j: longint;
  begin
    if i = deep then
    begin
      fs := f(ans);
      tot:=tot+hn[f(-fs)];
      exit;
    end;
    for j := 1 to m do
      seek2(deep, i - 1, ans + num(i,j));
  end;

begin
  Read(n, m);
  for i := 1 to n do
    Read(k[i], p[i]);
  mid := n div 2;
  fillchar(hn, sizeof(hn), 0);
  tot:=0;
  seek1(mid,1,0);
  seek2(mid,n,0);
  writeln(tot);
end.
