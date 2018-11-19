Pull and run interactively.
```bash
$ docker run -it deanturpin/cpp

root@d7f49cd960bd:/# clang++-6.0 --version
clang version 6.0.1-9.2 (tags/RELEASE_601/final)
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin

root@d7f49cd960bd:/# g++-8 --version
g++-8 (Debian 8.2.0-9) 8.2.0
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

# Accessing the host file system
```bash
docker run -it -v /tmp/cpp:/cpp deanturpin/cpp
```
