program cube;

var
  l: array[0..1000] of longint;
  step: array[1..1000] of integer;
  vst: array[1..65536] of boolean;
  i, j, k, p, q: longint;

  procedure updata(n, a: integer);
  var
    x, y, m: longint;
  begin
    m := l[p];
    x := 32768 shr (n-1);
    y := 32768 shr (n+a-1);
    if (m shr (16-n)) and 1 <> (m shr (16-n-a)) and 1 then
    begin
      if vst[m xor x xor y] then exit;
      if (step[p]=2) and (m xor x xor y<>255) then exit;
      Inc(q);
      l[q] := m xor x xor y;
      step[q]:=step[p]+1;
    end;
  end;

  procedure move(n: integer);
  var
    a, b, c, d: integer;
  begin
    if n and 1 = 1 then
      a := 1
    else
      a := -1;
    if (n and 3 <= 2) and (n and 3 >= 1) then
      b := 2
    else
      b := -2;
    if (n and 7 <= 4) and (n and 7 >= 1) then
      c := 4
    else
      c := -4;
    if (n and 15 <= 8) and (n and 15 >= 1) then
      d := 8
    else
      d := -8;
    updata(n, a);
    updata(n, b);
    updata(n, c);
    updata(n, d);
  end;

  procedure solve;
  var
    i, j: longint;
  begin
    while p <= q do
    begin
      if step[p] > 3 then
      begin
        writeln('more');
        exit;
      end;
      if l[p] = 255 then
      begin
        writeln(step[p]);
        exit;
      end;
      if not vst[l[p]] then
      begin
        for i := 1 to 8 do
          move(i);
        vst[l[p]] := True;
      end;
      Inc(p);
    end;
    writeln('more');
  end;

begin
  assign(input,'alice.in');
  assign(output,'alice.out');
  reset(input);
  rewrite(output);
  Read(k);
  for i := 1 to k do
  begin
    p := 0;
    for q := 1 to 16 do
    begin
      Read(j);
      p := p * 2 + j;
    end;
    l[1] := p;
    step[1] := 0;
    p := 1;
    q := 1;
    fillchar(vst, sizeof(vst), False);
    Write('Case #', i, ': ');
    solve;
  end;
end.

