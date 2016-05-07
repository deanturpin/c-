#Text-based GPX processing and What 3 Words integration

##TODO
- [ ] ascii route
- [ ] Add hotspot generator

#Extract
##Usage
```bash
 w3wkey=xxxxxxxx ./extract ride.gpx | head
 Revision $Id$
 Reading file ride.gpx
 {"words":["formed","tidy","swung"],"position":[50.845744,-0.155192],"language":"en"}
 {"words":["winks","singer","pump"],"position":[50.845664,-0.155449],"language":"en"}
 {"words":["lease","gladiators","pouch"],"position":[50.845637,-0.155406],"language":"en"}

 {"words":["bleak","error","given"],"position":[50.84534,-0.155278],"language":"en"}
 {"words":["ladder","letter","lows"],"position":[50.845313,-0.155235],"language":"en"}
 {"words":["spared","milk","topped"],"position":[50.845232,-0.155235],"language":"en"}
 {"words":["homes","boring","long"],"position":[50.845125,-0.155192],"language":"en"}
 {"words":["shave","agreed","spices"],"position":[50.844963,-0.155235],"language":"en"}
```
##W3W API
Convert 3 words to position:

https://api.what3words.com/w3w?key=YOURAPIKEY&string=word1.word2.word3

Convert position to 3 words:

https://api.what3words.com/position?key=YOURAPIKEY&position=lat,long

##Resources
* https://en.wikipedia.org/wiki/GPS_Exchange_Format
