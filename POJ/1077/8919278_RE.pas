program eightcode;

{YZT Bless Me!!!}

const
  ed = 123456780;    //1,2,3,4 => u,d,l,r

var
  st: longint;
  ch: char;
  i: integer;

  function move(n: longint; i: integer): longint;
  var
    s: string;
    j: integer;
    a: longint;
  begin
    str(n, s);
    if length(s) = 8 then
      s := '0' + s;
    j := pos('0', s);
    case i of
      1: if j <= 3 then
          exit(0)
        else
        begin
          s[j] := s[j - 3];
          s[j - 3] := '0';
          val(s, a);
        end;
      2: if j >= 7 then
          exit(0)
        else
        begin
          s[j] := s[j + 3];
          s[j + 3] := '0';
          val(s, a);
        end;
      3: if j mod 3 = 1 then
          exit(0)
        else
        begin
          s[j] := s[j - 1];
          s[j - 1] := '0';
          val(s, a);
        end;
      4: if j mod 3 = 0 then
          exit(0)
        else
        begin
          s[j] := s[j + 1];
          s[j + 1] := '0';
          val(s, a);
        end;
    end;
    exit(a);
  end;

  procedure bfs;
  var
    l: array[1..1000] of longint;
    vst: array[1..1000] of longint;
    path: array[1..1000] of string;
    i, p, q, n: integer;
    j: longint;
    f: boolean;
  begin
    p := 1;
    q := 1;
    l[1] := st;
    n := 0;
    path[1] := '';
    while l[p] <> ed do
    begin
      f := True;
      for i := 1 to n do
        if vst[i] = l[p] then
        begin
          f := False;
          break;
        end;
      if f then
      begin
        j := move(l[p], 1);
        if j <> 0 then
        begin
          Inc(q);
          l[q] := j;
          path[q] := path[p] + 'u';
        end;
        j := move(l[p], 2);
        if j <> 0 then
        begin
          Inc(q);
          l[q] := j;
          path[q] := path[p] + 'd';
        end;
        j := move(l[p], 3);
        if j <> 0 then
        begin
          Inc(q);
          l[q] := j;
          path[q] := path[p] + 'l';
        end;
        j := move(l[p], 4);
        if j <> 0 then
        begin
          Inc(q);
          l[q] := j;
          path[q] := path[p] + 'r';
        end;
        Inc(n);
        vst[n] := l[p];
      end;
      Inc(p);
    end;
    writeln(path[p]);
  end;

begin
  i := 0;
  st := 0;
  while not seekeoln do
  begin
    Read(ch);
    if ch <> ' ' then
    begin
      Inc(i);
      if ch <> 'x' then
        st := st * 10 + Ord(ch) - Ord('0')
      else
        st := st * 10;
    end;
  end;
  bfs;
end.
