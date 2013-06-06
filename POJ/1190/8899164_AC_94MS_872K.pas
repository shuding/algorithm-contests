program cake;

var
  n, i, j, m, min: longint;

  procedure seek(r, h, a, b, k: longint);
  var
    i, j, tot: longint;
  begin
    if (r <= 0) or (h <= 0) then
      exit;
    if (k > m + 1) or (b >= min) then
      exit;
    tot := 0;
    for i := 1 to m - k + 1 do
      tot := tot + (r - i) * (r - i) * (h - i);
    if a + tot < n then
      exit;
    if (a >= n) then
    begin
      if (k = m + 1) and (a = n) then
        min := b;
      exit;
    end;
    for i := r - 1 downto m - k + 1 do
      for j := h - 1 downto m - k + 1 do
        seek(i, j, a + j * i * i, b + 2 * i * j, k + 1);
  end;

begin
  Read(n, m);
  min := 1000000000;
  for i := trunc(sqrt(n)) downto m do
    for j := n div (i * i) downto m do
      seek(i, j, j * i * i, 2 * i * j + i * i, 2);
  if min <> 1000000000 then
    Write(min)
  else
    Write(0);
end.
