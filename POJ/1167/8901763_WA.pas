program buses;

var
  n, i, min,num: integer;
  t: array[1..300] of integer;
  f: array[0..59] of integer;
  times:longint;

  procedure seek(j: integer);
  var
    k, p, d, i,bc: integer;
    flag: boolean;
    fs: array[0..59] of integer;
  begin
    if times>100000 then
      begin
        writeln(min);
        halt;
      end;
    if j >= min then
      exit;
    if num=n then
    begin
      min := j;
      exit;
    end;
    for k := 1 to n do
      if f[t[k]] <> 0 then break;
    if 2 * t[k] >= 59 then exit;
    for p := k + 1 to n do
      if 2 * t[k] < t[p] then
        if f[t[p]] > 0 then
          if t[p] <> t[k] then
          begin
            if j+1 >= min then
              exit;
            d := t[p] - t[k];
            fs := f; bc:=num;
            flag := True;
            i:=t[k];
            inc(times);
            while i <= 59 do
            begin
              if f[i] <= 0 then
              begin
                flag := False;
                break;
              end;
              Dec(f[i]);
              inc(num);
              i := i + d;
            end;
            if flag then
              seek(j + 1);
            f := fs;
            num:=bc;
          end;
  end;

begin
  Read(n);
  fillchar(f, sizeof(f), 0);
  for i := 1 to n do
  begin
    Read(t[i]);
    Inc(f[t[i]]);
  end;
  min := 17; num:=0; times:=0;
  seek(0);
  Writeln(min);
end.
