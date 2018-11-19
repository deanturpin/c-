Includes compilers gcc 8, clang 7 and the usual git/make/vim.

---

Pull and run interactively.
```bash
docker run -it deanturpin/cpp
```

```bash
root@8f9fc9c03d23:/# g++-8 --version
g++-8 (Debian 8.2.0-9) 8.2.0
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

root@8f9fc9c03d23:/# clang++-7 --version
clang version 7.0.0-6 (tags/RELEASE_700/final)
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
```

Accessing the host file system
```bash
docker run -it -v /tmp/cpp:/cpp deanturpin/cpp
```
