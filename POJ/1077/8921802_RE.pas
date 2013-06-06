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

  function rate(n: longint): integer;
  var
    tot: integer;
    i: char;
    s, ss: string;
  begin
    if n = 0 then
      exit(10000);
    str(n, s);
    tot := 0;
    if length(s) = 8 then
      s := '0' + s;
    ss := '123456780';
    for i := '1' to '9' do
      tot := tot + abs(pos(i, s) div 3 - pos(i, ss) div 3) +
        abs(pos(i, s) - pos(i, ss)) mod 3;
    exit(tot);
  end;

  procedure bfs;
  var
    path: string;
    vst: array[1..362880] of longint;
    i, n, j, p: longint;
    a, b, c, d, e, g: integer;
    f: boolean;
  begin
    p := st;
    n := 0;
    path := '';
    while p <> ed do
    begin
      Inc(n);
      vst[n] := p;
      a := move(p, 1);
      b := move(p, 2);
      c := move(p, 3);
      d := move(p, 4);
      e := 1000;
      if rate(a) < e then
      begin
        f := True;
        for i := 1 to n do
          if vst[i] = a then
          begin
            f := False;
            break;
          end;
        if f then
        begin
          e := rate(a);
          g := 1;
        end;
      end;
      if rate(b) < e then
      begin
        f := True;
        for i := 1 to n do
          if vst[i] = b then
          begin
            f := False;
            break;
          end;
        if f then
        begin
          e := rate(b);
          g := 2;
        end;
      end;
      if rate(c) < e then
      begin
        f := True;
        for i := 1 to n do
          if vst[i] = c then
          begin
            f := False;
            break;
          end;
        if f then
        begin
          e := rate(c);
          g := 3;
        end;
      end;
      if rate(d) < e then
      begin
        f := True;
        for i := 1 to n do
          if vst[i] = d then
          begin
            f := False;
            break;
          end;
        if f then
        begin
          e := rate(d);
          g := 4;
        end;
      end;
      case g of
        1: p := a;
        2: p := b;
        3: p := c;
        4: p := d;
      end;
      case g of
        1: path := path + 'u';
        2: path := path + 'd';
        3: path := path + 'l';
        4: path := path + 'r';
      end;
    end;
    writeln(path);
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
