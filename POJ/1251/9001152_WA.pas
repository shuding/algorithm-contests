program Kruskal;

var
  h: array[1..1] of char;
  g: array['A'..'Z', 'A'..'Z'] of longint;
  fa: array['A'..'Z'] of char;
  i, j, n, k, p, q, min, tot: longint;
  f: boolean;
  c1, c2: char;

  function father(i:char):char;
  var f:char;
  begin
    if fa[i]=i then exit(i);
    f:=father(fa[i]);
    fa[i]:=f;
    exit(f);
  end;

  procedure merge(a,b:char);
  var f1,f2:char;
  begin
    f1:=father(a);
    f2:=father(b);
    fa[f1]:=f2;
  end;

  procedure mst;
  begin
    for k := 1 to n - 1 do
    begin
      min:=1000000;
      for i:=1 to n do
        for j:=1 to n do
          if (g[h[i],h[j]]>0) and (g[h[i],h[j]]<min) then
           if father(h[i])<>father(h[j]) then
           begin
             min:=g[h[i],h[j]];
             p:=i;
             q:=j;
           end;
      tot:=tot+min;
      merge(h[p],h[q]);
    end;
  end;

begin
  Readln(n);
  while n <> 0 do
  begin
    p := 0;
    for i := 1 to n - 1 do
    begin
      Read(c1);
      f := True;
      for q := 1 to p do
        if h[q] = c1 then
          f := False;
      if f then
      begin
        Inc(p);
        h[p] := c1;
      end;
      Read(k);
      for j := 1 to k do
      begin
        Read(c2);
        while c2 = ' ' do
          Read(c2);
        f := True;
        for q := 1 to p do
          if h[q] = c2 then
            f := False;
        if f then
        begin
          Inc(p);
          h[p] := c2;
        end;
        Read(g[c1, c2]);
        g[c2, c1] := g[c1, c2];
      end;
      readln;
    end;
    for i := 1 to n do
      fa[h[i]] := h[i];
    tot:=0;
    mst;
    writeln(tot);
    Readln(n);
  end;
end.
