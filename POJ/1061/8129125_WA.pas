var x,y,m,n,l:int64;
    i        :longint;
begin
   read(x,y,m,n,l);
   for i:=1 to 10000000 do
      if (x+m*i-y-n*i)mod l=0 then begin
           writeln(i);
           break;
          end;
end.