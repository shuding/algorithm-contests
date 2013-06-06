var
  stack:array[1..101] of string[100];
  top:longint;st:string[120];i:longint;
procedure up;
begin
  if stack[top+1]='' then writeln('Ignored')
  else begin inc(top);writeln(stack[top]); end;
end;
procedure down;
begin
  if top=1 then writeln('Ignored')
  else begin dec(top);writeln(stack[top]); end;
end;
procedure push;
begin
  delete(st,1,6);writeln(st);inc(top);stack[top]:=st;i:=top+1;
  while stack[i]<>'' do begin stack[i]:='';inc(i); end;
end;
begin
  readln(st);for i:=1 to 101 do stack[i]:='';
  top:=1;stack[1]:='http://www.acm.org/';
  while st<>'QUIT' do
    begin
      if st='BACK' then down
      else
        if st='FORWARD' then up
        else push;
      readln(st);
    end;
end.