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

  function search(i,j,a:integer):integer;
    begin
      if i=j then
        if t[i]=a then exit(i) else exit(0);
      if a<t[(i+j) shr 1] then exit(search(i,(i+j) shr 1,a)) else
      if a=t[(i+j) shr 1] then exit((i+j) shr 1) else
      exit(search((i+j) shr 1+1,j,a))
    end;


  procedure seek(k, st: integer);
  var
    i, j, p, d, s, c, st2, l: integer;
    flag, te: boolean;
    fs: array[1..300] of boolean;
  begin
    if k >= min then
      exit;
    flag := False;
    i := st;
    l := 0;
    for j := i + 1 to n do
      if f[j] then
        if t[j] <> t[l] then
        begin
          flag := True;
          if t[i] <> t[j] then
          begin
            if k >= min then
              exit;
            l := j;
            fs := f;
            te := True;
            f[i] := False;
            f[j] := False;
            d := t[j] - t[i];
            s := 0;
            {for p := j + 1 to n do
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
                  end;}
            for s:=1 to (60-t[j]) div d do
              begin
                c:=search(1,n,t[j]+s*d);
                if c=0 then begin
                te:=false;
                break;end;
                f[c]:=false;
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
