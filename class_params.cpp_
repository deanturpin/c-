struct A {
  int func(const int a);
};

// Implementation doesn't quite match the prototype
int A::func(int a) { return a; }

int main() { return A().func(1); }
