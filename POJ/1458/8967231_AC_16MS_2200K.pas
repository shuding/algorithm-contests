var   s,a,b:ansistring;
      i,j,n,m:longint;
      f:array[0..500,0..500] of longint;

      procedure predo;
      var   o:longint;
      begin
            for o:=1 to length(s) do
            begin
                  if s[o]=#9 then s[o]:=' ';
                  if s[o]=#10 then s[o]:=' ';
                  if s[o]=#13 then s[o]:=' ';
            end;
            a:=copy(s,1,pos(' ',s)-1);
            n:=length(a);
            delete(s,1,pos(' ',s));
            while s[1]=' ' do delete(s,1,1);
            b:=s;
            m:=length(b);
            fillchar(f,sizeof(f),0);
      end;

      function max(a,b:longint):longint;
      begin
            if a>b then exit(a); exit(b);
      end;

begin
      while not eof do
      begin
            readln(s);
            predo;
            for i:=1 to n do
               for j:=1 to m do
               if a[i]=b[j] then f[i,j]:=f[i-1,j-1]+1
               else f[i,j]:=max(f[i,j-1],f[i-1,j]);
            writeln(f[n,m]);
      end;
end.
