program substr;
const
  fin='substr.in';
  fout='substr.out';
var
  tr:array[0..524287,#0..#127]of longint;
  s:array[0..1024]of char;
  tt,t,n,i,j,p:longint;
procedure insert(x,ad:longint);
var
  r,i:longint;
  c:char;
begin
   // writeln( x );
  for i:=x to n do
  begin
     // writeln( s[ i ] ,' ' , tr[ ad , c ] ,' ', p , ' ' , ad ,' f ');
 
    c:=s[i];r:=tr[ad,c];
    if r<=t shl 19 then
    begin
      inc(p);tr[ad,c]:=p or t shl 19;
      ad:=p;
    end
    else
       begin
	  ad:=r and 524287;
	  writeln('!!!');
       end;
     // writeln( s[ i ] ,' ' , tr[ ad , c ] ,' ', p , ' ' , ad , ' s ');
  end;
end;
begin
    assign(input,fin);reset(input);
   // assign(output,fout);rewrite(output);
  readln(tt);
  fillchar(tr,sizeof(tr),0);
  for t:=1 to tt do
  begin
    writeln('Case #',t);
    n:=0;
    while not eoln do
    begin
      inc(n);read(s[n]);
    end;
    p:=1;
    for i:=1 to n do
    insert(i,1);
    writeln(p-1);
    {if t<tt then writeln;}
    readln;
  end;
  // close(input);close(output);
end.
