program poj1167;

type integer=longint;

var
  n, i, j, tot, min: integer;
  t: array[1..300] of integer;
  f: array[1..300] of boolean;

  procedure seek(k, st: integer);
  var
    i, j, p, d, s, c, st2: integer;
    flag, te: boolean;
    fs: array[1..300] of boolean;
  begin
    if k >= min then
      exit;
    flag := False;
    i := st;
    if f[i] then
      for j := i + 1 to n do
        if f[j] then
        begin
          flag := True;
          if t[i] <> t[j] then
          begin
            if k >= min then
              exit;
            fs := f;
            te := True;
            f[i] := False;
            f[j] := False;
            d := t[j] - t[i];
            s := 0;
            for p := j + 1 to n do
              if t[p] <> t[p - 1] then
                if (t[p] - t[j]) mod d = 0 then
                  if (t[p] - t[j]) div d = s + 1 then
                  begin
                    Inc(s);
                    f[p] := False;
                  end
                  else
                  begin
                    te := False;
                    break;
                  end;
            if te then
            begin
              st2 := st;
              while f[st2] = False do
                Inc(st2);
              seek(k + 1, st2);
            end;
            f := fs;
          end;
        end;
    if not flag then
    begin
      min := k;
    end;
  end;

begin
  Read(n);
  for i := 1 to n do
    Read(t[i]);
  min := 17;
  fillchar(f, sizeof(f), True);
  seek(0, 1);
  Write(min);
end.
