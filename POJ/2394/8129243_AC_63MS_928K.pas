  type code = record
                x,y,c,next : longint;
              end;
  var tot,i,x,y,c,n,m,cow,ti : longint;
      b : array[0..500] of boolean;
      dis,be,dui,po : array[0..500] of longint;
      e : array[0..2000] of code;
  procedure enter(x,y,c:longint);
    begin
      inc(tot);
      e[tot].x := x; e[tot].y := y; e[tot].c := c;
      e[tot].next := be[x];  be[x] := tot;
    end;
  procedure swap(x,y:longint); 
    var  t : longint;
    begin
      t := dui[x]; dui[x] := dui[y]; dui[y] := t;
      po[dui[x]] := x; po[dui[y]] := y; 
    end; 
  procedure upheap(x:longint);
    begin
      while x > 1 do
        begin
          if  dis[dui[x]] < dis[dui[x shr 1]] then 
            begin
              swap(x,x shr 1);
              x := x shr 1;
            end else break 
        end;
    end; 
  procedure downheap(x:longint);     
    var i : longint; 
    begin
      while x + x <= tot do
        begin
          if  (x+x+1 > tot) or (dis[dui[x+x]] < dis[dui[x+x+1]]) 
            then i := x + x
            else i := x + x + 1;
          if dis[dui[x]] > dis[dui[i]] then 
            begin
              swap(x,i);
              x := i;
            end else break; 
        end;
    end;
  procedure dijkstra;
    var  i,p,x,y : longint;
    begin
      for i := 1 to n do
        begin
          dui[i] := i;
          po[i] := i;
        end;
      dis[1] := 0;
      tot := n;
      while tot > 0 do  
        begin
          x := dui[1]; p := be[x]; 
          swap(1,tot);
          dec(tot);
          downheap(1);
          while p <> -1 do   
            begin
              y := e[p].y;
              if dis[x] + e[p].c < dis[y] then
                begin
                  dis[y] := dis[x] + e[p].c;
                  upheap(po[y]);
                end;
              p := e[p].next;
            end;
        end;
    end;
  begin
    readln(n,m,cow,ti);
    fillchar(be,sizeof(be),byte(-1));
    tot := -1;    
    for i := 1 to m do
      begin
        readln(x,y,c);
        enter(x,y,c);
        enter(y,x,c); 
      end;
    fillchar(dis,sizeof(dis),1); 
    dijkstra;
    fillchar(b,sizeof(b),0);       
    tot := 0;
    for i := 1 to cow do
      begin
        read(x);
        if dis[x] <= ti then
          begin
            inc(tot);
            b[i] := true;
          end;
      end;
    writeln(tot);
    for i := 1 to cow do
      if b[i] then writeln(i);
  end.
    