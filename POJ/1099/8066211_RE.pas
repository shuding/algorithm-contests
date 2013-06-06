program pku_1099;
var n             :array[1..11,1..11] of integer;
    s             :array[1..10,-1..55] of string;
    i,j,m,l,k,t   :integer;
begin
   m:=1; t:=0;
   while m<>0 do begin
   readln(m);
   if m<>0 then begin
   inc(t);
   for i:=1 to m do
   for j:=1 to m do
      read(n[i,j]);
   for i:=1 to 55 do s[t][i]:='';
   l:=1;
   for i:=1 to 4*m+3 do s[t][l]:=s[t][l]+'*';
   inc(l);
   for j:=1 to m-1 do begin
   s[t][l]:=s[t][l]+'*';
   for i:=1 to 2*m+1 do
      if i mod 2=0 then s[t][l]:=s[t][l]+'O '
                   else if i=2*m+1 then s[t][l]:=s[t][l]+'H'
                                   else s[t][l]:=s[t][l]+'H ';
   s[t][l]:=s[t][l]+'*';
   inc(l);
   s[t][l]:=s[t][l]+'*';
   for i:=1 to 4*m+1 do s[t][l]:=s[t][l]+' ';
   s[t][l]:=s[t][l]+'*';
   inc(l);
   s[t][l]:=s[t][l]+'*  H';
   for i:=2 to m do s[t][l]:=s[t][l]+'   H';
   s[t][l]:=s[t][l]+'  *';
   inc(l);
   s[t][l]:=s[t][l]+'*';
   for i:=1 to 4*m+1 do s[t][l]:=s[t][l]+' ';
   s[t][l]:=s[t][l]+'*';
   inc(l);
   end;
   s[t][l]:=s[t][l]+'*';
   for i:=1 to 2*m+1 do
      if i mod 2=0 then s[t][l]:=s[t][l]+'O '
                   else if i=2*m+1 then s[t][l]:=s[t][l]+'H'
                                   else s[t][l]:=s[t][l]+'H ';
   s[t][l]:=s[t][l]+'*';
   inc(l);
   for i:=1 to 4*m+3 do s[t][l]:=s[t][l]+'*';
   for k:=1 to 2 do
   for i:=1 to m do
     for j:=1 to m do
        case n[i,j] of
           1:if k=1 then
             begin
                s[t][4*i-2][4*j-1]:='-';
                s[t][4*i-2][4*j+1]:='-';
             end;
          -1:if k=1 then
             begin
                s[t][4*i-1][4*j]:='|';
                s[t][4*i-3][4*j]:='|';
             end;
           0:begin
                 if ((j<m) and (n[i,j+1]=1)) or ((j>1) and (n[i,j-1]=-1)) then
                   begin
                      s[t][4*i-2][4*j-1]:='-';
                   end;
                 if ((j>1) and (n[i,j-1]=1)) or ((j<m) and (n[i,j+1]=-1)) then
                   begin
                      s[t][4*i-2][4*j+1]:='-';
                   end;
                 if (i>1) and (n[i-1,j]=1) then
                   begin
                      s[t][4*i-3][4*j]:='|';
                   end;
                 if (m>i) and (n[i+1,j]=1) then
                   begin
                      s[t][4*i-1][4*j]:='|';
                   end;
                 if s[t][4*i-2][4*j-3]='-' then s[t][4*i-2][4*j+1]:='-';
                 if s[t][4*i-2][4*j+3]='-' then s[t][4*i-2][4*j-1]:='-';
                 if s[t][4*i-5][4*j]=' ' then s[t][4*i-3][4*j]:='|';
                 if s[t][4*i-5][4*j]='|' then s[t][4*i-1][4*j]:='|';
            end;
        end;
  // for i:=1 to 4*m-1 do writeln(s[t][i]);
   end; end;
   for i:=1 to t do
      begin
         writeln('Case ',i,':');
         j:=1;
         while s[i][j]<>'' do
           begin
              writeln(s[i][j]);
              inc(j);
           end;
      end;
end.