var x,y,m,n,l:int64;
    i,j,k    :int64;
begin
   read(x,y,m,n,l);
   i:=1; j:=10000; k:=10000000;
   while true do begin
     if (x+m*j-y-n*j) mod l=0 then begin
        writeln(j);
        break;
     end; inc(j);
     if (x+m*k-y-n*k) mod l=0 then begin
        writeln(k);
        break;
     end; inc(k);
     if (x+m*i-y-n*i) mod l=0 then begin
        writeln(i);
        break;
     end; inc(i); end;
end.
