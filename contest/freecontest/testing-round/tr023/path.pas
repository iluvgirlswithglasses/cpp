(*
 this is my first time using pascal
 18:32 Nov-22-2021
 *)

{ defs }
var m, n: longint;
    a: array[0..1000007] of Int64;
    l: array[0..1000007] of Int64;
    r: array[0..1000007] of Int64;

var i, j: longint;

{ utils }
function index(i, j: longint): longint;
begin
    index := i*n + j;
end;

function max2(a, b: Int64): Int64;
var
    res: Int64;
begin
    if a > b then
        res := a
    else
        res := b;
    max2 := res;
end;

// VNOI's pascal compiler doesn't allow function overloading
function max3(a, b, c: Int64): Int64;
begin
    max3 := max2(a, max2(b, c));
end;

{ drivers }
function dp: Int64;
var
    res: Int64;
begin
    // row 0
    l[index(0, 0)] := a[index(0, 0)];
    for j := 1 to n-1 do
        l[index(0, j)] := max2(0, l[index(0, j-1)]) + a[index(0, j)];

    r[index(0, n-1)] := a[index(0, n-1)];
    for j := n-2 downto 0 do
        r[index(0, j)] := max2(0, r[index(0, j+1)]) + a[index(0, j)];

    // row [1:m)
    for i := 1 to m-1 do
    begin
        // first column in row
        l[index(i, 0)] := max2(
            l[index(i-1, 0)], 
            r[index(i-1, 0)]
        ) + a[index(i, 0)];
        // others
        for j := 1 to n-1 do
            l[index(i, j)] := max3(
                l[index(i, j-1)],
                l[index(i-1, j)],
                r[index(i-1, j)]
            ) + a[index(i, j)];
        // last column in row
        r[index(i, n-1)] := max2(
            l[index(i-1, n-1)],
            r[index(i-1, n-1)]
        ) + a[index(i, n-1)];
        // others
        for j := n-2 downto 0 do
            r[index(i, j)] := max3(
                r[index(i, j+1)],
                l[index(i-1, j)],
                r[index(i-1, j)]
            ) + a[index(i, j)];
    end;

    // returns
    res := max2(l[index(m-1, 0)], r[index(m-1, 0)]);
    for j := 1 to n-1 do
        res := max3(res, l[index(m-1, j)], r[index(m-1, j)]);
    dp := res;
end;

begin
    read(m, n);
    for i := 0 to m-1 do
    for j := 0 to n-1 do
        read(a[index(i, j)]);
    //
    Writeln(dp());
end.
