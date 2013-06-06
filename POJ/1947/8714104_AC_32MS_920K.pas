program poj_1947;

const maxint=150;

var n,m,i,j,x,y,min:integer;
    v:set of 1..150;
    s,b,sn:array [-1..150] of integer;
    f:array [-1..150,0..150] of integer;

function build(i:integer):integer;
var j:integer;
begin
   if sn[i]<>-1 then exit(sn[i]);
   j:=s[i];
   sn[i]:=1;
   while j<>-1 do
     begin
        inc(sn[i],build(j));
        j:=b[j];
     end;
   exit(sn[i]);
end;

function minn(a,b:integer):integer;
begin
     if a<b then exit(a) else exit(b);
end;

function dp(i,j:integer):integer;
var k,min:integer;
begin
   if (i=-1) and (j=0) then exit(0);
   if (i=-1) then exit(maxint);
   if f[i,j]<>-1 then exit(f[i,j]);
   min:=1+dp(b[i],j);
   for k:=0 to minn(j-1,sn[i]-1) do
     if dp(s[i],k)+dp(b[i],j-1-k)<min then
       min:=dp(s[i],k)+dp(b[i],j-1-k);
   f[i,j]:=min;
   exit(f[i,j]);
end;

begin
   read(n,m);
   for i:=1 to n do
     begin
        s[i]:=-1;
        sn[i]:=-1;
        b[i]:=-1;
     end;
   for i:=1 to n-1 do
     begin
        read(x,y);
        b[y]:=s[x];
        s[x]:=y;
     end;
   for i:=0 to n do
     for j:=0 to n do
       f[i,j]:=-1;
   build(1);
   min:=dp(s[1],m-1);
   for i:=2 to n do
     if dp(s[i],m-1)+1<min then
       min:=dp(s[i],m-1)+1;
   writeln(min);
end.