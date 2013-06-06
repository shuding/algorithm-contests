program shuangguang8; {Made By  P.D.B (AYLA)}
{此程序可全部AC,用时0 ms}
const ji:array[1..8]of longint=(40320,5040,720,120,24,6,2,1);
      {康托展开时用到的常数，分别为为9-1的阶乘}
 var d1,d2:array[0..10000]of string[10];{两个队，分别存放双向广搜的一支}
     k1,k2:array[0..370000]of boolean;{Hash表，康托展开的数组，判重用}
     kb1,kb2:array[0..370000]of integer;{Hash表，康托展开的数组，存放每种情况的步数}
     fu1,fu2:array[0..10000]of integer;{两个队，存放当前步数}
     w1,w2,h1,t1,h2,t2,i,j,tol,lei,b:longint;m,n,z:string[10];l,c:char;{辅助变量}
procedure print;{输出}
begin
 writeln(kb1[lei]+kb2[lei]);{从起始到当前情况与从目标到当前情况的步数和}
 halt;
end;
function PDhash1(x:string):boolean;{判断当前情况在队列1中是否重复}
begin
 lei:=0;
 for i:=8 downto 1 do  {康托展开，i表示当前位数}
  begin
   tol:=0;
   for j:=i to 9 do {将当前位数前比当前位数大的数的个数与当前位数的阶乘相乘，并累加到l变量lei中}
    if x[i]>x[j] then inc(tol);
   lei:=lei+ji[i]*tol;
  end;
 PDhash1:=k1[lei];
end;
function PDhash2(x:string):boolean;{判断当前情况在队列2中是否重复}
begin
 lei:=0;
 for i:=8 downto 1 do
  begin
   tol:=0;
   for j:=i to 9 do
    if x[i]>x[j] then inc(tol);
   lei:=lei+ji[i]*tol;
  end;
 PDhash2:=k2[lei];
end;
procedure hash1(x:string[10]);
{将当前情况加入到队列1的Hash表中，可与PDhash1过程合并，为便于理解将其分开}
begin
 lei:=0;
 for i:=8 downto 1 do
  begin
   tol:=0;
   for j:=i to 9 do
    if x[i]>x[j] then inc(tol);
   lei:=lei+ji[i]*tol;
  end;
 k1[lei]:=true;
 kb1[lei]:=fu1[t1]; {将当前步数存入康托展开后的数组中}
 if k2[lei] then print; {如果反向搜索状态中由此情况，则输出，并结束程序}
end;
procedure hash2(x:string[10]);
{将当前情况加入到队列2的Hash表中，可与PDhash2过程合并，为便于理解将其分开}
begin
 lei:=0;
 for i:=8 downto 1 do
  begin
   tol:=0;
   for j:=i to 9 do
    if x[i]>x[j] then inc(tol);
   lei:=lei+ji[i]*tol;
  end;
 k2[lei]:=true;
 kb2[lei]:=fu2[t2]; {将当前步数存入康托展开后的数组中}
 if k1[lei] then print; {如果正向搜索状态中由此情况，则输出，并结束程序}
end;
procedure init;{读入}
begin
 fillchar(k1,sizeof(k1),false);
 fillchar(k2,sizeof(k2),false);
 {for i:=1 to 3 do
  begin
   for j:=1 to 3 do
    begin
     read(c); m:=m+c; read(c);
    end;
   readln;
  end;}
 m:='123456780';
 for i:=1 to 3 do
  begin
   for j:=1 to 3 do
    begin
     read(c); n:=n+c; read(c);
    end;
   readln;
  end;
end;
procedure WFS;{双向广搜}
begin
 t1:=1;t2:=1;h1:=0;h2:=0;
 repeat
  inc(h1);  {正向搜索}
  w1:=pos('0',d1[h1]);
  if w1-3>0 then {查找'0'的位置，判断'0'可移动的方向}
   begin
    z:=d1[h1];l:=z[w1];z[w1]:=z[w1-3];z[w1-3]:=l;{移动'0'}
    if not PDhash1(z) then {判断是否重复}
    begin
     inc(t1); d1[t1]:=z;
     fu1[t1]:=fu1[h1]+1; {当前情况步数等于其父节点的步数加1}
     hash1(z); {加入Hash表}
    end;
   end;
  if w1+3<10 then
   begin
    z:=d1[h1];l:=z[w1];z[w1]:=z[w1+3];z[w1+3]:=l;
    if not PDhash1(z) then
    begin
     inc(t1); d1[t1]:=z;
     fu1[t1]:=fu1[h1]+1;
     hash1(z);
    end;
   end;
  case w1 mod 3 of {判断'0'可移动的方向}
   0: begin
       z:=d1[h1];l:=z[w1];z[w1]:=z[w1-1];z[w1-1]:=l;
       if not PDhash1(z) then
       begin
        inc(t1); d1[t1]:=z;
        fu1[t1]:=fu1[h1]+1;
        hash1(z);
       end;
      end;
   1: begin
       z:=d1[h1];l:=z[w1];z[w1]:=z[w1+1];z[w1+1]:=l;
       if not PDhash1(z) then
       begin
        inc(t1); d1[t1]:=z;
        fu1[t1]:=fu1[h1]+1;
        hash1(z);
       end;
      end;
   2:begin
       z:=d1[h1];l:=z[w1];z[w1]:=z[w1-1];z[w1-1]:=l;
       if not PDhash1(z) then
       begin
       inc(t1); d1[t1]:=z;
       fu1[t1]:=fu1[h1]+1;
       hash1(z);
       end;
       z:=d1[h1];l:=z[w1];z[w1]:=z[w1+1];z[w1+1]:=l;
       if not PDhash1(z) then
       begin
       inc(t1);d1[t1]:=z;
       fu1[t1]:=fu1[h1]+1;
       hash1(z);
       end;
      end;
    end;

  inc(h2);{反向搜索，过程与正向搜索基本相同}
  w1:=pos('0',d2[h2]);
  if w1-3>0 then
   begin
    z:=d2[h2];l:=z[w1];z[w1]:=z[w1-3];z[w1-3]:=l;
    if not PDhash2(z) then
    begin
    inc(t2);d2[t2]:=z;
    fu2[t2]:=fu2[h2]+1;
    hash2(z);
   end;
   end;
  if w1+3<10 then
   begin
    z:=d2[h2];l:=z[w1];z[w1]:=z[w1+3];z[w1+3]:=l;
    if not PDhash2(z) then
    begin
    inc(t2);d2[t2]:=z;
    fu2[t2]:=fu2[h2]+1;
    hash2(z);
    end;
   end;
  case w1 mod 3 of
   0: begin
       z:=d2[h2];l:=z[w1];z[w1]:=z[w1-1];z[w1-1]:=l;
       if not PDhash2(z) then
       begin
       inc(t2);d2[t2]:=z;
       fu2[t2]:=fu2[h2]+1;
       hash2(z);
       end;
      end;
   1: begin
       z:=d2[h2];l:=z[w1];z[w1]:=z[w1+1];z[w1+1]:=l;
       if not PDhash2(z) then
       begin
       inc(t2); d2[t2]:=z;
       fu2[t2]:=fu2[h2]+1;
       hash2(z);
       end;
      end;
   2:begin
       z:=d2[h2];l:=z[w1];z[w1]:=z[w1-1];z[w1-1]:=l;
       if not PDhash2(z) then
       begin
       inc(t2); d2[t2]:=z;
       fu2[t2]:=fu2[h2]+1;
       hash2(z);
       end;
       z:=d2[h2];l:=z[w1];z[w1]:=z[w1+1];z[w1+1]:=l;
       if not PDhash2(z) then
       begin
       inc(t2); d2[t2]:=z;
       fu2[t2]:=fu2[h2]+1;
       hash2(z);
       end;
      end;
    end;
  until (h2>=t2)or(h1>=t1);
end;
begin {主程序，十分简洁}
 init;
 d1[1]:=m; {初始化，队中存入起始状态}
 d2[1]:=n; {初始化，队中存入目标状态}
 hash1(m);
 hash2(n);
 WFS;
end.