
var n: longint;
	l: array[0..200007] of Int64;
	r: array[0..200007] of Int64;

var i: longint;
	res: Int64;

function min(a, b: Int64): Int64;
var
	res: Int64;
begin
	if (a < b) then
		res := a
	else
		res := b;
	min := res;
end;

function abs(a: Int64): Int64;
var
	res: Int64;
begin
	if (a < 0) then
		res := -a
	else
		res := a;
	abs := res;
end;

begin
	res := 1000000000000000007;
	read(n);
	for i := 1 to n do
		read(l[i]);
	for i := n downto 1 do
		r[i] := r[i+1] + l[i];
	for i := 1 to n-1 do
	begin
		l[i] := l[i-1] + l[i];
		res := min(res, abs(l[i] - r[i+1]));
	end;
	Writeln(res);
end.
