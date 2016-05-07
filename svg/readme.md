## Extract plots from SVG and generate CSV
```bash
curl http://www.fileformat.info/info/unicode/char/0950/devanagari_om.svg | ./bitmap  > om.csv && libreoffice om.csv
```

![alt text](https://github.com/deanturpin/alpha/blob/master/unicode/images/om_plot.png "Excel plot of om symbol")

##TODO
- [ ] Use cin.read not streaming (breaks ncurses)
- [ ] Better way to extract coordinates?
- [ ] Render should return a string or use operator<<
- [ ] Allow white space after command
- [ ] Try to_wstring
- [ ] Try wregex
- [ ] Explore regex - how simple can we make it?
- [ ] Add framerate

##SVG format
M - Start a new sub-path at the given (x,y) coordinate. M (uppercase) indicates that absolute coordinates will follow; m (lowercase) indicates that relative coordinates will follow. 

Q - Draws a quadratic Bézier curve from the current point to (x,y) using (x1,y1) as the control point. Q (uppercase) indicates that absolute coordinates will follow; q (lowercase) indicates that relative coordinates will follow. Multiple sets of coordinates may be specified to draw a polybézier. At the end of the command, the new current point becomes the final (x,y) coordinate pair used in the polybézier.

Z - Close the current subpath by drawing a straight line from the current point to current subpath's initial point. Since the Z and z commands take no parameters, they have an identical effect.

