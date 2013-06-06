program poj1167;

var
  n, i, j, tot, min: integer;
  t: array[1..300] of integer;
  f: array[1..300] of boolean;

  function search(a,i,j:integer):integer;
  begin
    if i>j then exit(0);
    if i=j then
      if a=t[i] then exit(i)
                else exit(0);
    if t[(i+j) shr 1]>a then exit(search(a,i,(i+j) shr 1)) else
    if t[(i+j) shr 1]=a then exit((i+j) shr 1) else
    if t[(i+j) shr 1]<a then exit(search(a,(i+j) shr 1+1,j));
  end;

  procedure seek(k: integer);
  var
    i, j, p, d, s,c: integer;
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
              if k >= min then
                exit;
              fs := f;
              te := True;
              f[i] := False;
              f[j] := False;
              d := t[j] - t[i];
            //  s := 0;
            {  for p := j + 1 to n do
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
                    end;  }
              for s:=1 to (t[n]-t[j]) div d do
                begin
                  c:=search(t[j]+d*s,j+1,n);
                  if c=0 then
                    begin
                      te:=false;
                      break;
                    end
                    else f[c]:=false;
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