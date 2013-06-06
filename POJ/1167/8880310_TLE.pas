program poj1167;

var
  n, i, j, tot, min: integer;
  t: array[1..300] of integer;
  f: array[1..300] of boolean;

  procedure seek(k: integer);
  var
    i, j, p, d, s: integer;
    flag, te: boolean;
    fs: array[1..300] of boolean;
  begin
    if k >= min then
      exit;
    flag := False;
    for i := 1 to n do
      if f[i] then
        for j := i + 1 to n do
          if f[j] then
          begin
            flag := True;
            if t[i] <> t[j] then
            begin
              fs := f;
              te := True;
              f[i] := False;
              f[j] := False;
              d := t[j] - t[i];
              s := 0;
              for p := j + 1 to n do
                if t[p] <> t[p-1] then
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
                seek(k + 1);
              f := fs;
            end;
          end;
    if not flag then min := k;
  end;

begin
  Read(n);
  for i := 1 to n do
    Read(t[i]);
  min := 17;
  fillchar(f, sizeof(f), True);
  seek(0);
  Write(min);
end.