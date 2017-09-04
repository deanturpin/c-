# Casts
static_cast reinterpret_cast dynamic_cast const_cast

Arrays can be implicity converted to pointers without casting -- 4.2.  There is
no implicit conversion from pointers to arrays.

 int* can be implicity converted to int const* -- 4.4.  There is no implicit
 conversion from int const* to int*.
