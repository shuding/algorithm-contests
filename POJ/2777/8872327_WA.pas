program poj2777;

type node=record
            x,y,c,lc,rc:longint;
          end;

var l,o,a,b,c,i,ct:longint;
    t:array[1..10000] of node;
    ch:char;

  procedure build(n,i,j:longint);
  begin
    t[n].x:=i;
    t[n].y:=j;
    t[n].c:=1;
    t[n].lc:=1;
    t[n].rc:=1;
    if i=j then exit;
    build(2*n,i,(i+j)shr 1);
    build(2*n+1,(i+j)shr 1+1,j);
  end;

  procedure color(n,i,j,k:longint);
  begin
    if (t[n].x=i) and (t[n].y=j) then
      begin
        t[n].c:=1;
        t[n].lc:=k;
        t[n].rc:=k;
        exit;
      end;
    if (t[n].x+t[n].y)shr 1>=j then
      color(2*n,i,j,k) else
    if (t[n].x+t[n].y)shr 1<i then
      color(2*n+1,i,j,k) else
    begin
      color(2*n,i,(t[n].x+t[n].y)shr 1,k);
      color(2*n+1,(t[n].x+t[n].y)shr 1+1,j,k);
    end;
    t[n].c:=t[2*n].c+t[2*n+1].c;
    if t[2*n].rc=t[2*n+1].lc then dec(t[n].c);
    t[n].lc:=t[2*n].lc;
    t[n].rc:=t[2*n].rc;
  end;

  function que(n,i,j:longint):longint;
  var tot:longint;
  begin
    if (t[n].x=i) and (t[n].y=j) then exit(t[n].c);
    if t[n].c=1 then exit(1);
    if (t[n].x+t[n].y)shr 1>=j then
      exit(que(2*n,i,j)) else
    if (t[n].x+t[n].y)shr 1<i then
      exit(que(2*n+1,i,j)) else
    begin
      tot:=que(2*n,i,(t[n].x+t[n].y)shr 1)+que(2*n+1,(t[n].x+t[n].y)shr 1+1,j);
      if t[2*n].rc=t[2*n+1].lc then dec(tot);
      exit(tot);
    end;
  end;

begin
  readln(l,ct,o);
  build(1,1,l);
  for i:=1 to o do
    begin
      read(ch);
      if ch='C' then
        begin
          read(a,b,c);
          color(1,a,b,c);
          readln;
        end
        else
        begin
          read(a,b);
          writeln(que(1,a,b));
          readln;
        end;
    end;
end.