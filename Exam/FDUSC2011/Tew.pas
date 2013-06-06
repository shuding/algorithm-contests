program Tew;

var
  c, i, n: longint;
  a, b, last ,p, q, m: real;
  s: ansistring;

  function max(a, b: real): real;
  begin
    if a > b then
      max := a
    else
      max := b;
  end;

  function f(p: real): real;
  begin
    f := (p-last) / (1 + exp(b * ln(p - a)));
  end;

begin
  c := 0;
  Read(n);
  while (n <> 0) do
  begin
    Inc(c);
    Read(a, b);
    Write('Case ', c, ': ');
    last := a;
    for i := 1 to n - 1 do
    begin
      p := trunc(a) + 1;
      q := 1000000000;
      while q - p > 1 do
      begin
        m := round((p + q)/2);
        if f(m) > f(m + 1) then
          q := m
        else
          p := m;
      end;
      last := last + max(f(p), f(q));
    end;
    str(trunc(last * 100), s);
    insert('.', s, length(s) - 1);
    writeln(s);
    Read(n);
  end;
end.

