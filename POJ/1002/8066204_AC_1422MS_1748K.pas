var
  st:array[1..100001] of string[8];flag:boolean;
  s:string;x,y:string[8];n,m,i,k,last:longint;
procedure qsort(l,r:longint);
var
  i,j:longint;
begin
  i:=l;j:=r;x:=st[(l+r) shr 1];
  while i<=j do
    begin
      while st[i]<x do inc(i);
      while st[j]>x do dec(j);
      if i<=j then
        begin
          y:=st[i];st[i]:=st[j];st[j]:=y;
          inc(i);dec(j);
        end;
    end;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
end;
begin
  readln(n);m:=0;
  for k:=1 to n do
    begin
      readln(s);while pos('-',s)<>0 do delete(s,pos('-',s),1);
      for i:=1 to 7 do
        case s[i] of
          'A','B','C':s[i]:='2';
          'D','E','F':s[i]:='3';
          'G','H','I':s[i]:='4';
          'J','K','L':s[i]:='5';
          'M','N','O':s[i]:='6';
          'P','R','S':s[i]:='7';
          'T','U','V':s[i]:='8';
          'W','X','Y':s[i]:='9';
        end;
      insert('-',s,4);st[k]:=s;
    end;
  qsort(1,n);st[n+1]:='';last:=0;flag:=true;
  for i:=1 to n do
    if st[i+1]<>st[i] then
      begin
        if i-last>1 then begin flag:=false;writeln(st[i],' ',i-last); end; last:=i;
      end;
  if flag then writeln('No duplicates.');
end.