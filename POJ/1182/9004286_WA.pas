program chain;

var
  n, k, i, j, sum, d, x, y: longint;
  eat, ate, fa: array[0..200000] of longint;

  function father(i: longint): longint;
  var
    f: longint;
  begin
    if fa[i] = i then
      exit(i);
    f := father(fa[i]);
    fa[i] := f;
    exit(f);
  end;

  procedure merge(x, y: longint);
  var
    f1, f2: longint;
  begin
    f1 := father(x);
    f2 := father(y);
    fa[f2] := f1;
  end;

begin
  assign(input,'e:in.in');
  reset(input);
  Read(n, k);
  sum := 0;
  for i := 0 to n do
  begin
    fa[i] := i;
    eat[i] := n+i;
    ate[i] := 2*n+i;
  end;
  for i:=n+1 to 3*n do fa[i]:=i;
  for i := 1 to k do
  begin
    Read(d, x, y);
    if (x > n) or (y > n) or ((d = 2) and (x = y)) then
    begin
      Inc(sum);
      continue;
    end;
    case d of
      1:
      begin
        if (father(x) = father(eat[y])) or (father(x) = father(ate[y])) or (father(y) = father(eat[x])) or (father(y) = father(ate[x])) then
        begin
          Inc(sum);
          continue;
        end;
        merge(x, y);
        merge(eat[x], eat[y]);
        merge(ate[x], ate[y]);
      end;
      2:
      begin
        if (father(x) = father(y)) or (father(y) = father(ate[x])) or (father(x) = father(eat[y])) then
        begin
          Inc(sum);
          continue;
        end;
        merge(eat[x], y);
        merge(ate[y], x);
        merge(ate[x], eat[y])
      end;
    end;
  end;
  Write(sum);
end.
