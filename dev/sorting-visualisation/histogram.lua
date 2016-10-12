-- Sleep
function sleep(n)
	os.execute("sleep " .. tonumber(n))
end

-- Print a bar
-- --------|
function bar(n)

	-- Exit case: the cap atop the bar
	if n == 1 then return "|"

	-- Otherwise return the stem and recurse
	else return "-" .. bar(n - 1) end
end
