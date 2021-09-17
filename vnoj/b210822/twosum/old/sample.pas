var     n,i,j,l,len,k : longint;
        f             : array[0..10000] of longint;
 
function find(q,l,r : longint) : boolean;
 var    x : longint;
 begin
        while l <= r do begin
                x := (l+r) div 2;
                if q = f[x] then exit(true);
                if q < f[x] then r := x-1
                else l := x+1;
        end;
        exit(false);
 end;
 
begin
        readln(n);
        for i := 1 to n do begin
                readln(f[i]);
                f[i] := f[i-1] + f[i];
        end;
        for len := n downto 2 do
                for l := 1 to n - len + 1 do begin
                        if (f[l-1]+f[l+len-1]) mod 2 = 0 then
                                if find((f[l-1]+f[l+len-1]) div 2
                                         l,l+len-1) then begin
                                        writeln(len);
                                        halt;
                                end;
                end;
        writeln(0);
end.