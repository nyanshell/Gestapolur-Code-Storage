program poj1276;
var 
   f   : array [0..100000 , 0..10 ] of boolean;
   a,c : array [1..10] of integer;
   n,m   : integer;
   i , j , k  : longint;

begin
   read( m , n );
   for i := 1 to n do
      read( a[ i ] , c[ i ] );

   for i := 0 to n do
      
      f[ 0 , i ] := true;

   for i := 1 to m do
      for j := 1 to n do
	 for k := 1 to a[ j ] do
	    if i - c[ j ] * k >= 0 then
	       f[ i , j ] := f[ i , j ] or f[ i - c[ j ] * k ];
   i := n;
   while f[ m , i ] <> true do
   begin
      i := i - 1 ;
   end;
   writeln( i );
   
end.