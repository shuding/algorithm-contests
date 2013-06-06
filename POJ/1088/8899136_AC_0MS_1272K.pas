program snow;

type integer=longint;

var c,r,i,j,tot:integer;
    g:array[1..500,1..500] of integer;
    f:array[1..500,1..500] of integer;

function getf(i,j:integer):integer;
begin
   if f[i,j]<>1 then exit(f[i,j]);
   if (i>1) and (g[i,j]>g[i-1,j]) then
     if (getf(i-1,j)+1>f[i,j]) then f[i,j]:=getf(i-1,j)+1;
   if (i<r) and (g[i,j]>g[i+1,j]) then
     if (getf(i+1,j)+1>f[i,j]) then f[i,j]:=getf(i+1,j)+1;
   if (j>1) and (g[i,j]>g[i,j-1]) then
     if (getf(i,j-1)+1>f[i,j]) then f[i,j]:=getf(i,j-1)+1;
   if (j<c) and (g[i,j]>g[i,j+1]) then
     if (getf(i,j+1)+1>f[i,j]) then f[i,j]:=getf(i,j+1)+1;
   exit(f[i,j]);
end;

begin
   read(r,c);
   for i:=1 to r do
     for j:=1 to c do
       begin
          read(g[i,j]);
          f[i,j]:=1;
       end;
   tot:=0;
   for i:=1 to r do
     for j:=1 to c do
       if getf(i,j)>tot then
         tot:=getf(i,j);
   write(tot);
end.