program chain;

var n,k,i,j,sum,d,x,y:longint;
    eat,ate,fa:array[1..500000] of longint;

    function father(i:longint):longint;
    var f:longint;
    begin
      if fa[i]=i then exit(i);
      f:=father(fa[i]);
      fa[i]:=f;
      exit(f);
    end;

    procedure merge(x,y:longint);
    var f1,f2:longint;
    begin
      f1:=father(x);
      f2:=father(y);
      if (f1=0) or (f2=0) then exit;
      fa[f1]:=f2;
    end;

begin
  read(n,k);
  sum:=0;
  for i:=1 to n do
    begin
      fa[i]:=i;
      eat[i]:=0;
      ate[i]:=0;
    end;
  for i:=1 to k do
    begin
      read(d,x,y);
      if (x>n) or (y>n) or ((d=2) and (x=y)) then
        begin
          inc(sum);
          continue;
        end;
      case d of
        1:begin
            if (father(x)=father(eat[y])) or (father(x)=father(ate[y])) then
              begin
                inc(sum);
                continue;
              end;
            merge(x,y);
        end;
        2:begin
            if (father(x)=father(y)) or (father(y)=father(ate[x])) then
              begin
                inc(sum);
                continue;
              end;
            merge(eat[x],y);
            merge(ate[y],x);
        end;
      end;
    end;
  write(sum);
end.