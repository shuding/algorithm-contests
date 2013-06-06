program pku_1099;
var n          :array[1..11,1..11] of integer;
    s          :array[-1..55] of string;
    i,j,m,l,k,t:integer;
begin
   m:=1; t:=0;
   while m<>0 do begin
   readln(m);
   if m=0 then
     halt;
   inc(t);
   writeln('Case ',t,':');
   for i:=1 to m do
   for j:=1 to m do
      read(n[i,j]);
   for i:=1 to 55 do s[i]:='';
   l:=1;
   for i:=1 to 4*m+3 do s[l]:=s[l]+'*';
   inc(l);
   for j:=1 to m-1 do begin
   s[l]:=s[l]+'*';
   for i:=1 to 2*m+1 do
      if i mod 2=0 then s[l]:=s[l]+'O '
                   else if i=2*m+1 then s[l]:=s[l]+'H'
                                   else s[l]:=s[l]+'H ';
   s[l]:=s[l]+'*';
   inc(l);
   s[l]:=s[l]+'*';
   for i:=1 to 4*m+1 do s[l]:=s[l]+' ';
   s[l]:=s[l]+'*';
   inc(l);
   s[l]:=s[l]+'*  H';
   for i:=2 to m do s[l]:=s[l]+'   H';
   s[l]:=s[l]+'  *';
   inc(l);
   s[l]:=s[l]+'*';
   for i:=1 to 4*m+1 do s[l]:=s[l]+' ';
   s[l]:=s[l]+'*';
   inc(l);
   end;
   s[l]:=s[l]+'*';
   for i:=1 to 2*m+1 do
      if i mod 2=0 then s[l]:=s[l]+'O '
                   else if i=2*m+1 then s[l]:=s[l]+'H'
                                   else s[l]:=s[l]+'H ';
   s[l]:=s[l]+'*';
   inc(l);
   for i:=1 to 4*m+3 do s[l]:=s[l]+'*';
   for k:=1 to 2 do
   for i:=1 to m do
     for j:=1 to m do
        case n[i,j] of
           1:begin
                s[4*i-2][4*j-1]:='-';
                s[4*i-2][4*j+1]:='-';
             end;
          -1:begin
                s[4*i-1][4*j]:='|';
                s[4*i-3][4*j]:='|';
             end;
           0:begin
                 if ((j<m) and (n[i,j+1]=1)) or ((j>1) and (n[i,j-1]=-1)) then
                   begin
                      s[4*i-2][4*j-1]:='-';
                   end;
                 if ((j>1) and (n[i,j-1]=1)) or ((j<m) and (n[i,j+1]=-1)) then
                   begin
                      s[4*i-2][4*j+1]:='-';
                   end;
                 if (i>1) and (n[i-1,j]=1) then
                   begin
                      s[4*i-3][4*j]:='|';
                   end;
                 if (m>i) and (n[i+1,j]=1) then
                   begin
                      s[4*i-1][4*j]:='|';
                   end;
                 if s[4*i-2][4*j-3]='-' then s[4*i-2][4*j+1]:='-';
                 if s[4*i-2][4*j+3]='-' then s[4*i-2][4*j-1]:='-';
                 if s[4*i-5][4*j]=' ' then s[4*i-3][4*j]:='|';
                 if s[4*i-5][4*j]='|' then s[4*i-1][4*j]:='|';
            end;
        end;
   for i:=1 to 4*m-1 do writeln(s[i]);
   end;
end.