WAV parsing and tinkering

Write a song with a very limited palette of instruments and effects. (In fact, I must write them first.)

##Usage
./foo < ../../csound/android/CSDPlayer/assets/Csound6AndroidExamples/Hunkins/ChimePad/14.wav

##TODO
- [ ] Make random source of data musical - network activity?
- [ ] Tone generator
- [ ] Sequencer
- [ ] Reverb (convolution/algorithmic)
- [ ] Time stretch
- [ ] Look at scale command
- [x] Spectrum - started
- [x] Monitor mic - using asound
- [x] Good source of WAVs
- [x] Read whole file and resize

```
X 0, 164
Y -17, 20
|                                                                                                                                                                     
|                                                                                                                                                                     
|                                                                                                                                                                     
|       ***  * *                                                                                                                                                      
|         *****                                                                                                                                                       
|        *******                                                                                                                                                      
|       *******                                                                                                                                                       
|       *********                                                                                                                                                     
|       *********  **                                                                                                                                                 
|        *******  ****                                                                                                                                                
|       ********* ****    *                                                                                                                                           
|       ********* ****   ***                                                                                                                                          
|       ***************  ****                                                                                                                                         
|       ***************  ****   **                                                                                                                                    
|       *********************   ***                                                                                                                                   
|       *********************  ****   ***                                                                                                                             
|       ********************** ****** ****    *                                                                                                                       
|       *********************************** *****   **                                                                                                                
|       ****************************************** ***** ****   ****  ****                                                                                            
|       **************************************************************************************  **                                                                    
|*********************************************************************************************************************************************************************
|       ************************************************************************************** ****                                                                   
|       *********************************** ****** ***** *****  ****  ****                                                                                            
|       ***************************** *****  ****   **                                                                                                                
|       ********************** *****  ****    *                                                                                                                       
|       *********************  *****   **                                                                                                                             
|       *********************   ***                                                                                                                                   
|       ***************  ****   * *                                                                                                                                   
|       ********* *****  ***     *                                                                                                                                    
|       ********* ****   ***                                                                                                                                          
|       ********* ****    *                                                                                                                                           
|       ********   **                                                                                                                                                 
|       *********  **                                                                                                                                                 
|        *******                                                                                                                                                      
|         ******                                                                                                                                                      
|        ******                                                                                                                                                       
|        ******                                                                                                                                                       
|        *  ***                                                                                                                                                       
|           **                                                                                                                                                        
|           **                                                                                                                                                        
|            *                                                                                                                                                        
20
```

##Linux audio
* https://en.wikipedia.org/wiki/List_of_Linux_audio_software#Distributions_and_add-ons
* https://en.wikipedia.org/wiki/Mixxx
