##TODO
- [ ] https://en.wikipedia.org/wiki/Homomorphic_encryption

```bash
$ ./create_secret 
Creating secrets
00000000: 8c0d 0409 0302 1bf2 eb8b 1fed 3ba0 60d2  ............;.`.
00000010: 3d01 666f 681f bb78 88e7 4cf7 cd23 ed40  =.foh..x..L..#.@
00000020: 5b2f 507e 3bfd 4cf3 d1cf 9909 6f64 8bb5  [/P~;.L.....od..
00000030: 0779 a2b7 9fb1 66f6 c477 6b87 c942 be91  .y....f..wk..B..
00000040: 60a7 86ca 3f2b 5668 f1f0 7fe7 cdd0       `...?+Vh......

$ pgpdump secret1.gpg 
Old: Symmetric-Key Encrypted Session Key Packet(tag 3)(13 bytes)
	New version(4)
	Sym alg - AES with 256-bit key(sym 9)
	Iterated and salted string-to-key(s2k 3):
		Hash alg - SHA1(hash 2)
		Salt - 1b f2 eb 8b 1f ed 3b a0 
		Count - 65536(coded count 96)
New: Symmetrically Encrypted and MDC Packet(tag 18)(61 bytes)
	Ver 1
	Encrypted data [sym alg is specified in sym-key encrypted session key]
		(plain text + MDC SHA1(20 bytes))

```
