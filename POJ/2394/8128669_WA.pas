program poj2394;
  type code = record
                x,y,c,next : longint;
              end;
  var tot,i,x,y,c,n,m,cow,ti : longint;
      b : array[0..500] of boolean;
      dis,be,dui,po : array[0..500] of longint;  //dis存距离 ,,po存点x在堆中的位置
      e : array[0..2000] of code;
      
  procedure enter(x,y,c:longint);
    begin
      inc(tot);
      e[tot].x := x; e[tot].y := y; e[tot].c := c;
      e[tot].next := be[x];  be[x] := tot;
    end;
  
  procedure swap(x,y:longint); //swap 是换堆中第x个和第y个的元素..不是换点x和点y的位子
    var  t : longint;
    begin
      t := dui[x]; dui[x] := dui[y]; dui[y] := t;
      po[dui[x]] := x; po[dui[y]] := y; //元素换了之后,,记录点所在位子的数组也要换
    end; //这个过程是我写堆中错的次数最多的...望注意.!

  procedure upheap(x:longint);
    begin
      while x > 1 do
        begin
          if  dis[dui[x]] < dis[dui[x shr 1]] then //看看是比的什么数组.!! 大于号小于号注意!!
            begin
              swap(x,x shr 1);
              x := x shr 1;
            end else break //这个break不样忘了哦
        end;
    end;  //x shr p(0-31) 和 x shl p 用的很多的

  procedure downheap(x:longint);     //编程时候数组尽量不要开在procedure 或 function里面!!!
    var i : longint; //有需要变量
    begin
      while x + x <= tot do
        begin
          if  (x+x+1 > tot) or (dis[dui[x+x]] < dis[dui[x+x+1]])  //这个很好用哦
            then i := x + x
            else i := x + x + 1;
          if dis[dui[x]] > dis[dui[i]] then //注意大于号还是小于号
            begin
              swap(x,i);
              x := i;
            end else break; //还是不要忘了break
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
      //dis[st] := 0;
      //st:=1;
      //swap(st,1);    如果开始点不是1的话,就这么办
      dis[1] := 0;
      tot := n;
      while tot > 0 do   //相当于n2的dij的第一层循环
        begin
          x := dui[1]; p := be[x];     //点x已经确定了 ,,n2的dij的第二层循环找最小值的点x被数据结构堆给优化了
          
          swap(1,tot);
          dec(tot);
          downheap(1);
          //删除这个确定了的点
          
          while p <> -1 do    //开始用点x更新其他点
            begin
              y := e[p].y;
              if dis[x] + e[p].c < dis[y] then
                begin
                  dis[y] := dis[x] + e[p].c;
                  upheap(po[y]); //看点y所在位置需不需要更新
                end;
              p := e[p].next;
            end;
        end;
    end;
      
  begin
    assign(input,'poj.in'); reset(input);
    assign(output,'poj.out'); rewrite(output);
    
    readln(n,m,cow,ti);
    fillchar(be,sizeof(be),byte(-1));
    tot := -1;    //tot这里当做总边数,,只是起引导作用,,存完边之后就没用了..我程序中其他的地方的tot有其他的意义寻
    for i := 1 to m do
      begin
        readln(x,y,c);
        enter(x,y,c);
        enter(y,x,c);  //链表存边
      end;
    fillchar(dis,sizeof(dis),1);  //自己试下这样dis数组里面存下来的是什么值呀~
    dijkstra;
    
    fillchar(b,sizeof(b),0);         //接下来是和本题有关的处理了.
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
      
    close(output);
  end.
    
