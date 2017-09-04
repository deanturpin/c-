An lvalue refers to an object that persists beyond a single expression. You can
think of an lvalue as an object that has a name. All variables, including
nonmodifiable (const) variables, are lvalues. An rvalue is a temporary value
that does not persist beyond the expression that uses it. 

 A function call can be an lvalue if and only if the return value is a reference 
