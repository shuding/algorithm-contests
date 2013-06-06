program pku2394;

var f,p,c,m:longint;
    g      :array [1..500,1..500] of integer;
    r      :array [1..500] of integer;
    cow    :array [1..100] of integer;
    can    :array [1..100] of integer;
    i,j,k  :integer;

procedure dij(a,b:longint);
var i,j:integer;
    s  :string;
begin
   for i:=1 to f do
     if g[a,i]>0 then
       if b+g[a,i]<r[i] then
          begin
             r[i]:=b+g[a,i];
             dij(i,r[i]);
          end;
end;

begin
   fillchar(g,sizeof(g),0);
   read(f,p,c,m);
   for i:=1 to p do
     begin
        read(j,k);
        read(g[j,k]);
        g[k,j]:=g[j,k];
     end;
   for i:=1 to f do r[i]:=32767;
   for i:=1 to c do read(cow[i]);
   dij(1,0); j:=0;
   for i:=1 to c do
     if r[cow[i]]<=m then
       begin
          inc(j);
          can[j]:=i;
       end;
   writeln;
   writeln(j);
   for i:=1 to j do writeln(can[i]);
end.