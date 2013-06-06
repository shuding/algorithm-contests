program pku_3125;
var i,j,n,k,t,l,tt,o:integer;
    p               :array [0..10000] of integer;
begin
   readln(tt);
   for o:=1 to tt do begin
   read(n,k);
   for i:=0 to n-1 do read(p[i]);
   l:=n-1; j:=0;
   while true do
     begin
        for i:=j to l do
          if p[i]>p[j] then
             begin
                if j=k then k:=l+1;
                inc(j); inc(l);
                p[l]:=p[j-1];
                break;
             end else
          if (i=l) and (p[i]<=p[j]) then
             begin
                inc(j);
                inc(t);
                if j-1=k then
                   begin
                      write(t);
                      halt;
                   end;
             end;
     end;
   end;
end.
