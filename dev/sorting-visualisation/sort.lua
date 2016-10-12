#!/usr/bin/lua5.3

require "histogram"

-- A random sequence
sequence = {
	13, 6, 30, 17, 6, 28, 25, 22, 13, 24, 29, 9, 6, 21, 12, 16, 11, 16, 11, 12,
	1, 31, 3, 15, 12, 10, 18, 11, 13, 28, 10, 28, 21, 5, 27, 22, 12, 26, 24, 8
}

-- For each value in the sequence print a bar to construct histogram
for key, value in pairs(sequence) do

	io.write(bar(value), "\n")
end

-- Insertion sort
function insertionSort(s)

	for key, value in pairs(sequence) do
	end
end

io.write("C'est fini")
