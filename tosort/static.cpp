/*
# Uses of static
TBD

variables with static storage duration are zero initialized.  Note that x has
static storage duration even though the static keyword is not used.  According
to the standard: "All objects which do not have dynamic storage duration, do
not have thread storage duration, and are not local have static storage
duration"

Only static_cast (or c-style casts) can be used to cast an int to an enum

Only reinterpret_cast (or c-style casts) can be used to cast an int to a pointer or a pointer to an int
*/
