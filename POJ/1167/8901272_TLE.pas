program buses;

var
  n, i, min: integer;
  t: array[1..300] of integer;
  f: array[0..59] of integer;

  procedure seek(j: integer);
  var
    k, p, d, i : integer;
    flag: boolean;
    fs:array[0..59] of integer;
  begin
    if j >= min then
      exit;
    flag := True;
    for k := 1 to n do
      if f[t[k]] <> 0 then
      begin
        flag := False;
        break;
      end;
    if flag then
    begin
      min := j;
      exit;
    end;
    if 2*t[k]>=59 then exit;
    for p := k + 1 to n do
    if 2*t[k]<t[p] then
     if f[t[p]]>0 then
      if t[p]<>t[k] then
      begin
        if j+1=min then exit;
        d := t[p] - t[k];
        fs:=f;
        flag:=true;
        for i := 0 to 59 do
          if abs(i - t[k]) mod d = 0 then break;
        while i<=59 do
          begin
            if f[i]<=0 then
              begin
                 flag:=false;
                 break;
              end;
            Dec(f[i]);
            i:=i+d;
          end;
        if flag then seek(j + 1);
        f:=fs;
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
  min := 17;
  seek(0);
  Writeln(min);
end.
