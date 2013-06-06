var x,y,m,n,l:int64;
    i        :int64;
begin
   read(x,y,m,n,l);i:=1;
   while true do begin
      if (x+m*i-y-n*i)mod l=0 then begin
           writeln(i);
           break;
          end; inc(i);
     end;
end.