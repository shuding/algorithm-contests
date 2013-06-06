var i,j,k,l,m,n:longint;
    ans,sum,sb,wen:real;
begin
 readln(sb);
 while sb<>0.00 do begin
  if sb<0.5 then writeln(1,' card(s)') else begin
  n:=1;  ans:=0;
  while ans<sb do begin inc(n);ans:=ans+1/n;end;
  writeln(n-1,' card(s)'); end;
  readln(sb);
  end;
end.
