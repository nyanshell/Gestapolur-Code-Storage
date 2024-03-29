type
integer=longint;
const
maxn = 100;
inf  = 10000000;
var  
w:array[1..maxn,1..maxn] of integer;
lx,ly,mx,my,slack:array[1..maxn] of integer;
vx,vy:array[1..maxn] of boolean;
n:integer;
procedure init;
var
m,i,j,a,b,c:integer;
begin
readln(n);
m := n * n ;
fillchar(w,sizeof(w),12);
for i:=1 to n do begin 
	for j:= 1 to n do 
		begin
			read(w[ i , j ]);
		end;
		readln;
	end;
end;
function find(root:integer):boolean;
var
i,t:integer;
begin
vx[root]:=true;
for i:=1 to n do
if not(vy[i]) then
begin
   t:=w[root,i]-lx[root]-ly[i];
   if t=0 then
   begin
      vy[i]:=true;
      if (my[i]=0)or(find(my[i])) then
      begin
         mx[root]:=i;my[i]:=root;
         find:=true; exit;
      end;
   end else
   begin
      if ( t&lt;slack[i] ) then
      slack[i]:=t;
   end;
end;
   find:=false;
end; { find }

procedure KM;
var
   i,d,j : integer;
begin
   fillchar(lx,sizeof(lx),12);
   for i:=1 to n do
      for j:=1 to n do
         if w[i,j]&lt;lx[i] then
   lx[i]:=w[i,j];
   for i:=1 to n do
      repeat
         fillchar(vx,sizeof(vx),false);
         fillchar(vy,sizeof(vy),false);
         fillchar(slack,sizeof(slack),12);
         if find(i) then break;
         d:=inf;
         for j:=1 to n do
            if (not(vy[j]))and(slack[j]&lt;d) then
               d:=slack[j];
for j:=1 to n do
begin
   if vx[j] then inc(lx[j],d);
   if vy[j] then dec(ly[j],d);
end;
      until false;
end; { KM }

procedure print;
var
   k,c,i,j,s : integer;
   path      : array[1..maxn] of integer;
   first     : boolean;
begin
   k:=n;c:=0;
   for i:=1 to n do
   begin
      j:=mx[i];
      if w[i,j]&lt;inf then
   begin
      dec(k);
      inc(c,w[i,j]);
   end;
   end;
   writeln(c);
end; { print }

begin
   init;
   KM;
   print;
end.