Requires ncurses

```bash
sudo apt-get install ncurses-dev
```

##TODO
- [ ] Add framerate
- [ ] Keyboard shortcuts (zoom, pan)
- [ ] add min/max on opposite corners

- [x] Add exception handling - no required
- [x] Add set marker routine - not sure what this means
- [x] Fit to page - handled by ncurses
- [x] Add resize method - handled by ncurses
- [x] calculate current shell size  - not required with ncurses
- [x] Investigate clear screen options - not required with ncurses
- [x] Rename to pixl8? Or pxl::pxl8?
- [x] Render should return a string or use operator<< - not required with ncurses
- [x] Reset display - return to top of shell
- [x] Add mega:: namespace?
- [x] Add border
- [x] Unicode border - too complicated
- [x] Add axes

```bash
$ make run
         *        *         *             *        
                                                   
                                                   
                        *                          
  *                                               *
                                                   
                          *                        
                                                   
  *                                               *
                                                   
                                                   
                                                   
     *                                        *    
                                                   
                                                   
                                                   
                                                   
                                                   
               *                     *             
                                                   
                                 *                 
                   *                               
                                                   
                                                   
                                                   
                       *    *                      
                        *  *                       
                         **
```
