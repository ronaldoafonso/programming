-- A simple lua script
a = 5
if a then print('Value of a: '..a) end
for i = 1, a do print('Now i: '..i) end
function seta() a = 10 print('New value of a: '..a) end
seta()
