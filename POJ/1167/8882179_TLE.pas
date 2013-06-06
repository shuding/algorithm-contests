program poj1167;

{
God Bless Me!!!
Bro.Xian Bless Me!!!
}

type
  integer = longint;

var
  n, i, j, tot, min: integer;
  t: array[0..300] of integer;
  f: array[1..300] of boolean;
  ans: array[1..300] of integer;
  pl: array[1..300] of integer;

  procedure seek(k, st: integer);
  var
    i, j, p, d, s, c, st2, num: integer;
    flag, te: boolean;
    fs: array[1..300] of boolean;
  begin
    if k >= min then
      exit;
    i := st;
    flag := False;
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
          pl[i] := k;
          pl[j] := k;
          d := t[j] - t[i];
          s := 0;
       {   for p :=1 to n do
            if abs(t[p] - t[j]) mod d = 0 then
              if ((t[p] - t[j]) div d = s + 1) and f[p] then
               begin
                 Inc(s);
                 f[p] := False;
               end
               else
               if not ((t[p] - t[j]) div d = s + 1) then
               begin
                 te := False;
                 break;
               end; }
          num := t[j];
          for p := j + 1 to n do
            if (abs(t[p] - t[j]) mod d = 0) and (t[p] <> num) then
              if f[p] then
              begin
                Inc(s);
                f[p] := False;
                pl[p] := k;
                num := t[p];
              end;
           {    else
               begin
                 te := False;
                 break;
               end; }
          if (60 - t[j]) div d > s then
            te := False;
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
      for i := 1 to n do
        ans[i] := pl[i];
    end;
  end;

begin
  Read(n);
  for i := 1 to n do
    Read(t[i]);
  min := 17;
  fillchar(f, sizeof(f), True);
  seek(0, 1);
  Writeln(min);
end.
