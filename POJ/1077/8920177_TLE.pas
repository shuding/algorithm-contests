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

 { function rate(n: longint): integer;
  var
    tot: integer;
    i: char;
    s, ss: string;
  begin
    if n = 0 then
      exit(1000);
    str(n, s);
    tot := 0;
    if length(s) = 8 then
      s := '0' + s;
    ss := '123456780';
    for i := '0' to '9' do
      tot := tot + abs(pos(i, s) div 3 - pos(i, ss) div 3) +
        abs(pos(i, s) - pos(i, ss)) mod 3;
    exit(tot);
  end;     }

  procedure bfs;
  var
    l: array[1..3000] of longint;
    path: array[1..3000] of string;
    vst:array[1..362880] of longint;
    i, p, q, n, j: longint;
    a, b, c, d, e, g: integer;
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
       { a := move(l[p], 1);
        b := move(l[p], 2);
        c := move(l[p], 3);
        d := move(l[p], 4);
        e := 1000;
        if rate(a) < e then
        begin
          e := rate(a);
          g := 1;
          Inc(q);
          case g of
            1: l[q] := a;
            2: l[q] := b;
            3: l[q] := c;
            4: l[q] := d;
          end;
          case g of
            1: path[q] := path[p] + 'u';
            2: path[q] := path[p] + 'd';
            3: path[q] := path[p] + 'l';
            4: path[q] := path[p] + 'r';
          end;
        end;
        if rate(b) < e then
        begin
          e := rate(b);
          g := 2;
          Inc(q);
          case g of
            1: l[q] := a;
            2: l[q] := b;
            3: l[q] := c;
            4: l[q] := d;
          end;
          case g of
            1: path[q] := path[p] + 'u';
            2: path[q] := path[p] + 'd';
            3: path[q] := path[p] + 'l';
            4: path[q] := path[p] + 'r';
          end;
        end;
        if rate(c) < e then
        begin
          e := rate(c);
          g := 3;
          Inc(q);
          case g of
            1: l[q] := a;
            2: l[q] := b;
            3: l[q] := c;
            4: l[q] := d;
          end;
          case g of
            1: path[q] := path[p] + 'u';
            2: path[q] := path[p] + 'd';
            3: path[q] := path[p] + 'l';
            4: path[q] := path[p] + 'r';
          end;
        end;
        if rate(d) < e then
        begin
          e := rate(d);
          g := 4;
          Inc(q);
          case g of
            1: l[q] := a;
            2: l[q] := b;
            3: l[q] := c;
            4: l[q] := d;
          end;
          case g of
            1: path[q] := path[p] + 'u';
            2: path[q] := path[p] + 'd';
            3: path[q] := path[p] + 'l';
            4: path[q] := path[p] + 'r';
          end;
        end;
       {Inc(q);
        case g of
          1: l[q] := a;
          2: l[q] := b;
          3: l[q] := c;
          4: l[q] := d;
        end;
        case g of
          1: path[q] := path[p] + 'u';
          2: path[q] := path[p] + 'd';
          3: path[q] := path[p] + 'l';
          4: path[q] := path[p] + 'r';
        end;}  }
       j := move(l[p], 1);
        if j <> 0 then
        begin
          Inc(q);
          if q>3000 then q:=1;
          l[q] := j;
          path[q] := path[p] + 'u';
        end;
        j := move(l[p], 2);
        if j <> 0 then
        begin
          Inc(q);
          if q>3000 then q:=1;
          l[q] := j;
          path[q] := path[p] + 'd';
        end;
        j := move(l[p], 3);
        if j <> 0 then
        begin
          Inc(q);
          if q>3000 then q:=1;
          l[q] := j;
          path[q] := path[p] + 'l';
        end;
        j := move(l[p], 4);
        if j <> 0 then
        begin
          Inc(q);
          if q>3000 then q:=1;
          l[q] := j;
          path[q] := path[p] + 'r';
        end;
      end;
      inc(n);
      vst[n]:=l[p];
      Inc(p);
      if p>3000 then p:=1;
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
