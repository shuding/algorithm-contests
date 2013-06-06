program poj_2253;

type point=record
             x,y:integer;
           end;

var g        :array[1..200,1..200] of real;
    p        :array[1..200] of point;
    re       :array[1..200] of real;
    i,j,k,n,o:integer;

begin
   read(n); o:=1;
   while n<>0 do begin
   for i:=1 to n do read(p[i].x,p[i].y);
   fillchar(g,sizeof(g),0);
   for k:=1 to n do
     for i:=1 to n do
       for j:=1 to n do
         if i<>j then
           if g[i,j]<0.00000001 then
              begin
                 g[i,j]:=sqrt(sqr(p[i].x-p[j].x)+sqr(p[i].y-p[j].y));
                 g[j,i]:=g[i,j];
              end
           else if g[i,k]>0.00000001 then
                 if g[k,j]>0.00000001 then
                  if (g[i,j]>g[i,k]) and (g[i,j]>g[j,k]) then
                   begin
                      g[i,j]:=g[i,k];
                      if g[i,j]>g[k,j] then g[i,j]:=g[k,j];
                   end;
   {writeln('Scenario #',o);
   writeln('Frog Distance = ',g[1,2]:0:3);}
   re[o]:=g[1,2];
   //writeln;
   inc(o);
   read(n); end;
   for i:=1 to o-1 do
     begin
        writeln('Scenario #',i);
        writeln('Frog Distance = ',re[i]:0:3);
        writeln;
     end;
end.