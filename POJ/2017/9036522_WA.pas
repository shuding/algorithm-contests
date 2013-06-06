program poj2017;

var n,i,j,k,v,tot:longint;

begin
  while not seekeof do
    begin
      read(n);
      tot:=0; k:=0;
      for i:=1 to n do
        begin
          read(v,j);
          tot:=tot+v*(j-k);
          k:=j;
        end;
      writeln(tot,' miles');
    end;
end.