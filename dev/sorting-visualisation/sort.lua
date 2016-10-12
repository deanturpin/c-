#!/usr/bin/lua5.3

sequence = {
	13, 6, 30, 17, 6, 28, 25, 22, 13, 24, 29, 9, 6, 21, 12, 16, 11, 16, 11, 12,
	1, 31, 3, 15, 12, 10, 18, 11, 13, 28, 10, 28, 21, 5, 27, 22, 12, 26, 24, 8
}

print("Length", #sequence)

function bar(n)

	-- Exit case: the cap atop the bar
	if n == 1 then return "|"

	-- Otherwise return the stem and recurse
	else return "-" .. bar(n - 1) end

end

for key, value in pairs(sequence) do

	io.write(bar(value), "\n")
end
