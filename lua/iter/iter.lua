
list = {{1, 10, 100},
        {2, 20, 200},
        {3, 30, 300},
        {4, 40, 400},
        {5, 50, 500}}

function iter(seq)
    local i = 0
    return function()
        i = i + 1
        if seq[i] then
            return seq[i][1], seq[i][2], seq[i][3]
        else
            return nil
        end
    end
end

for i1, i2, i3 in iter(list) do
    print(i1, i2, i3)
end
