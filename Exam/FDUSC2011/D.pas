program D;
var
  n,m,k,i,j,ansp,ansq:longint;
  a:array[1..100] of string;
  f:array[1..100] of boolean;
  ans:string;
  t:longint;

procedure init;
var
  i,j:longint;
begin
  read(n);
  if n=0 then halt;
  readln(m,k);
  for i:=1 to n do
    begin
      readln(a[i]);
      j:=length(a[i]);
      if a[i][j]='s' then f[i]:=true else f[i]:=false;
      delete(a[i],pos(' ',a[i]),j-pos(' ',a[i])+1);
    end;
end;

function check(st:string;p,q:longint):boolean;
var
  i,j:longint;
begin
  if ans='' then begin check:=true; exit; end;
  if q*ansp<p*ansq then begin check:=true; exit; end else begin check:=false; exit; end;
  if p<m then begin check:=false; exit; end else begin check:=true; exit; end;
  if st<ans then begin check:=true; exit; end else begin check:=false; exit; end;
end;

procedure main;
var
  i,j,p,q,l:longint;
  st:string;
begin
  ans:='';
  for i:=1 to n do
    for j:=1 to length(a[i])-k+1 do
      begin
        st:=copy(a[i],j,k);
        p:=0; q:=0;
        for l:=1 to n do
          if pos(st,a[l])>0 then
            begin
              inc(p);
              if f[l] then inc(q);
            end;
        if p<m then continue;
        if check(st,p,q) then
          begin
            ansp:=p;
            ansq:=q;
            ans:=st;
          end;
      end;
  inc(t);
  if ans='' then ans:='No solution';
  writeln('Case ',t,': ',ans);
end;

begin
  assign(input,'d.in');
  reset(input);
  assign(output,'d.out');
  rewrite(output);
  t:=0;
  while true do
    begin
      init;
      main;
    end;
end.
