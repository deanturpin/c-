- [ ] User defined literals for PI
- [ ] Lambda - std::for_each(nums.begin(), nums.end(), [](int &n){ n++; });
- [ ] Transform (?)
- [ ] OpenMP timings

```cpp
int main()
{
	std::string s("hello");
	std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::toupper(c); });
	std::cout << s;
}
```
