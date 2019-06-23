
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "portaudio.h"
#include "conio.h"
#include "functions.h"
#define NUM_SECONDS   (10)
#define SAMPLE_RATE   (44100)
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


///////////////////////////////////////////////////////////////////*******************************************************************/
static paTestData data;

int main(void)
{
       
       
       int i, notenum;
       char usernote[3], compnote;
       PaStream *stream;
       PaError err;
       usernote[0] = 'a';
       for (i=0; i<200; i++) {
          notenum = rand() %16;
          //so we can test/tune the individual notes.
           /*notenum = 14; 
        
         1  DB2
         2  EB2
         3  GB2
         4  AB2
         5  BB2
         6  DB3
         7  EB3
         8  GB3
         9  AB3
         10 BB3
         11 DB4
         12 EB4
         13 GB4
         14 AB4
         15 BB4
         */
             switch (notenum) {
                           case 1:
                             printf("Guess the note.\n # or b for accidentals X to exit");
                               
                               /* Initialize our data for use by callback. */
                               data.left_phase = data.right_phase = 0.0;
                               /* Initialize library before making any other calls. */
                               err = Pa_Initialize();
                               if( err != paNoError ) goto error;
                               
                               /* Open an audio I/O stream. */
                               err = Pa_OpenDefaultStream( &stream,
                                                                                                    0,          /* no input channels */
                                                                                                    2,          /* stereo output */
                                                                                                    paFloat32,  /* 32 bit floating point output */
                                                                                                    SAMPLE_RATE,
                                                                                                    256,        /* frames per buffer */
                                                                                                    patestCallbackDB2,
                                                                                                    &data );
                               if( err != paNoError ) goto error;
                               
                               err = Pa_StartStream( stream );
                               if( err != paNoError ) goto error;
                               
                               /* Sleep for several seconds. */
                               Pa_Sleep(NUM_SECONDS*100);
                               
                               err = Pa_StopStream( stream );
                               if( err != paNoError ) goto error;
                               err = Pa_CloseStream( stream );
                               if( err != paNoError ) goto error;
                               usernote[0] = getche() ;
                               usernote[1] = getche() ;
                               printf("\n");
                               Pa_Terminate();
                               
                               switch (usernote[0]) {
                    case 'C': case'c':
                        switch (usernote[1]) {
                            case '#':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'D': case'd':
                        switch (usernote[1]) {
                            case 'b': case 'B':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'x': case 'X':
                        goto end;
                    default:
                        printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                        
                        break;
                }
                break;
                /////////////////////////////            
                break;
                
                           case 2:
                                printf("Guess the note.\n # or b for accidentals X to exit");
                               
                               /* Initialize our data for use by callback. */
                               data.left_phase = data.right_phase = 0.0;
                               /* Initialize library before making any other calls. */
                               err = Pa_Initialize();
                               if( err != paNoError ) goto error;
                               
                               /* Open an audio I/O stream. */
                               err = Pa_OpenDefaultStream( &stream,
                                                                                                    0,          /* no input channels */
                                                                                                    2,          /* stereo output */
                                                                                                    paFloat32,  /* 32 bit floating point output */
                                                                                                    SAMPLE_RATE,
                                                                                                    256,        /* frames per buffer */
                                                                                                    patestCallbackEB2,
                                                                                                    &data );
                               if( err != paNoError ) goto error;
                               
                               err = Pa_StartStream( stream );
                               if( err != paNoError ) goto error;
                               
                               /* Sleep for several seconds. */
                               Pa_Sleep(NUM_SECONDS*100);
                               
                               err = Pa_StopStream( stream );
                               if( err != paNoError ) goto error;
                               err = Pa_CloseStream( stream );
                               if( err != paNoError ) goto error;
                               usernote[0] = getche() ;
                               usernote[1] = getche() ;
                               printf("\n");
                               Pa_Terminate();
                               
                               switch (usernote[0]) {
                    case 'D': case'd':
                        switch (usernote[1]) {
                            case '#':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'E': case'e':
                        switch (usernote[1]) {
                            case 'b': case 'B':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'x': case 'X':
                        goto end;
                    default:
                        printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                        
                        break;
                }
                break;
                /////////////////////////////            
                break;
                
                             
                           case 3:
                               printf("Guess the note.\n # or b for accidentals X to exit");
                               
                               /* Initialize our data for use by callback. */
                               data.left_phase = data.right_phase = 0.0;
                               /* Initialize library before making any other calls. */
                               err = Pa_Initialize();
                               if( err != paNoError ) goto error;
                               
                               /* Open an audio I/O stream. */
                               err = Pa_OpenDefaultStream( &stream,
                                                                                                    0,          /* no input channels */
                                                                                                    2,          /* stereo output */
                                                                                                    paFloat32,  /* 32 bit floating point output */
                                                                                                    SAMPLE_RATE,
                                                                                                    256,        /* frames per buffer */
                                                                                                    patestCallbackGB2,
                                                                                                    &data );
                               if( err != paNoError ) goto error;
                               
                               err = Pa_StartStream( stream );
                               if( err != paNoError ) goto error;
                               
                               /* Sleep for several seconds. */
                               Pa_Sleep(NUM_SECONDS*100);
                               
                               err = Pa_StopStream( stream );
                               if( err != paNoError ) goto error;
                               err = Pa_CloseStream( stream );
                               if( err != paNoError ) goto error;
                               usernote[0] = getche() ;
                               usernote[1] = getche() ;
                               printf("\n");
                               Pa_Terminate();
                               
                               switch (usernote[0]) {
                    case 'F': case'f':
                        switch (usernote[1]) {
                            case '#':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'G': case'g':
                        switch (usernote[1]) {
                            case 'b': case 'B':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'x': case 'X':
                        goto end;
                    default:
                        printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                        
                        break;
                }
                break;
                /////////////////////////////           
                break;
                
                
                           case 4:
                                 printf("Guess the note.\n # or b for accidentals X to exit");
                               
                               /* Initialize our data for use by callback. */
                               data.left_phase = data.right_phase = 0.0;
                               /* Initialize library before making any other calls. */
                               err = Pa_Initialize();
                               if( err != paNoError ) goto error;
                               
                               /* Open an audio I/O stream. */
                               err = Pa_OpenDefaultStream( &stream,
                                                                                                    0,          /* no input channels */
                                                                                                    2,          /* stereo output */
                                                                                                    paFloat32,  /* 32 bit floating point output */
                                                                                                    SAMPLE_RATE,
                                                                                                    256,        /* frames per buffer */
                                                                                                    patestCallbackAB2,
                                                                                                    &data );
                               if( err != paNoError ) goto error;
                               
                               err = Pa_StartStream( stream );
                               if( err != paNoError ) goto error;
                               
                               /* Sleep for several seconds. */
                               Pa_Sleep(NUM_SECONDS*100);
                               
                               err = Pa_StopStream( stream );
                               if( err != paNoError ) goto error;
                               err = Pa_CloseStream( stream );
                               if( err != paNoError ) goto error;
                               usernote[0] = getche() ;
                               usernote[1] = getche() ;
                               printf("\n");
                               Pa_Terminate();
                               
                               switch (usernote[0]) {
                    case 'G': case'g':
                        switch (usernote[1]) {
                            case '#':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'A': case'a':
                        switch (usernote[1]) {
                            case 'b': case 'B':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'x': case 'X':
                        goto end;
                    default:
                        printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                        
                        break;
                }
                break;
                /////////////////////////////            
                break;
                           case 5:
                printf("Guess the note.\n # or b for accidentals X to exit");
                               
                               /* Initialize our data for use by callback. */
                               data.left_phase = data.right_phase = 0.0;
                               /* Initialize library before making any other calls. */
                               err = Pa_Initialize();
                               if( err != paNoError ) goto error;
                               
                               /* Open an audio I/O stream. */
                               err = Pa_OpenDefaultStream( &stream,
                                                                                                    0,          /* no input channels */
                                                                                                    2,          /* stereo output */
                                                                                                    paFloat32,  /* 32 bit floating point output */
                                                                                                    SAMPLE_RATE,
                                                                                                    256,        /* frames per buffer */
                                                                                                    patestCallbackBB2,
                                                                                                    &data );
                               if( err != paNoError ) goto error;
                               
                               err = Pa_StartStream( stream );
                               if( err != paNoError ) goto error;
                               
                               /* Sleep for several seconds. */
                               Pa_Sleep(NUM_SECONDS*100);
                               
                               err = Pa_StopStream( stream );
                               if( err != paNoError ) goto error;
                               err = Pa_CloseStream( stream );
                               if( err != paNoError ) goto error;
                               usernote[0] = getche() ;
                               usernote[1] = getche() ;
                               printf("\n");
                               Pa_Terminate();
                               
                               switch (usernote[0]) {
                    case 'A': case'a':
                        switch (usernote[1]) {
                            case '#':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'B': case'b':
                        switch (usernote[1]) {
                            case 'b': case 'B':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'x': case 'X':
                        goto end;
                    default:
                        printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                        
                        break;
                }
                break;
                /////////////////////////////            
                break;
                           case 6:
                printf("Guess the note.\n # or b for accidentals X to exit");
                               
                               /* Initialize our data for use by callback. */
                               data.left_phase = data.right_phase = 0.0;
                               /* Initialize library before making any other calls. */
                               err = Pa_Initialize();
                               if( err != paNoError ) goto error;
                               
                               /* Open an audio I/O stream. */
                               err = Pa_OpenDefaultStream( &stream,
                                                                                                    0,          /* no input channels */
                                                                                                    2,          /* stereo output */
                                                                                                    paFloat32,  /* 32 bit floating point output */
                                                                                                    SAMPLE_RATE,
                                                                                                    256,        /* frames per buffer */
                                                                                                    patestCallbackDB3,
                                                                                                    &data );
                               if( err != paNoError ) goto error;
                               
                               err = Pa_StartStream( stream );
                               if( err != paNoError ) goto error;
                               
                               /* Sleep for several seconds. */
                               Pa_Sleep(NUM_SECONDS*100);
                               
                               err = Pa_StopStream( stream );
                               if( err != paNoError ) goto error;
                               err = Pa_CloseStream( stream );
                               if( err != paNoError ) goto error;
                               usernote[0] = getche() ;
                               usernote[1] = getche() ;
                               printf("\n");
                               Pa_Terminate();
                               
                               switch (usernote[0]) {
                    case 'C': case'c':
                        switch (usernote[1]) {
                            case '#':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'D': case'd':
                        switch (usernote[1]) {
                            case 'b': case 'B':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'x': case 'X':
                        goto end;
                    default:
                        printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                        
                        break;
                }
                break;
                /////////////////////////////            
                break;
                               
                           case 7:
                              printf("Guess the note.\n # or b for accidentals X to exit");
                               
                               /* Initialize our data for use by callback. */
                               data.left_phase = data.right_phase = 0.0;
                               /* Initialize library before making any other calls. */
                               err = Pa_Initialize();
                               if( err != paNoError ) goto error;
                               
                               /* Open an audio I/O stream. */
                               err = Pa_OpenDefaultStream( &stream,
                                                                                                    0,          /* no input channels */
                                                                                                    2,          /* stereo output */
                                                                                                    paFloat32,  /* 32 bit floating point output */
                                                                                                    SAMPLE_RATE,
                                                                                                    256,        /* frames per buffer */
                                                                                                    patestCallbackEB3,
                                                                                                    &data );
                               if( err != paNoError ) goto error;
                               
                               err = Pa_StartStream( stream );
                               if( err != paNoError ) goto error;
                               
                               /* Sleep for several seconds. */
                               Pa_Sleep(NUM_SECONDS*100);
                               
                               err = Pa_StopStream( stream );
                               if( err != paNoError ) goto error;
                               err = Pa_CloseStream( stream );
                               if( err != paNoError ) goto error;
                               usernote[0] = getche() ;
                               usernote[1] = getche() ;
                               printf("\n");
                               Pa_Terminate();
                               
                               switch (usernote[0]) {
                    case 'D': case'd':
                        switch (usernote[1]) {
                            case '#':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'E': case'e':
                        switch (usernote[1]) {
                            case 'b': case 'B':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'x': case 'X':
                        goto end;
                    default:
                        printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                        
                        break;
                }
                break;
                /////////////////////////////            
                break;
                
                           case 8:
                printf("Guess the note.\n # or b for accidentals X to exit");
                               
                               /* Initialize our data for use by callback. */
                               data.left_phase = data.right_phase = 0.0;
                               /* Initialize library before making any other calls. */
                               err = Pa_Initialize();
                               if( err != paNoError ) goto error;
                               
                               /* Open an audio I/O stream. */
                               err = Pa_OpenDefaultStream( &stream,
                                                                                                    0,          /* no input channels */
                                                                                                    2,          /* stereo output */
                                                                                                    paFloat32,  /* 32 bit floating point output */
                                                                                                    SAMPLE_RATE,
                                                                                                    256,        /* frames per buffer */
                                                                                                    patestCallbackGB3,
                                                                                                    &data );
                               if( err != paNoError ) goto error;
                               
                               err = Pa_StartStream( stream );
                               if( err != paNoError ) goto error;
                               
                               /* Sleep for several seconds. */
                               Pa_Sleep(NUM_SECONDS*100);
                               
                               err = Pa_StopStream( stream );
                               if( err != paNoError ) goto error;
                               err = Pa_CloseStream( stream );
                               if( err != paNoError ) goto error;
                               usernote[0] = getche() ;
                               usernote[1] = getche() ;
                               printf("\n");
                               Pa_Terminate();
                               
                              switch (usernote[0]) {
                    case 'F': case'f':
                        switch (usernote[1]) {
                            case '#':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'G': case'g':
                        switch (usernote[1]) {
                            case 'b': case 'B':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'x': case 'X':
                        goto end;
                    default:
                        printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                        
                        break;
                }
                break;
                /////////////////////////////            
                break;
                           case 9:
                printf("Guess the note.\n # or b for accidentals X to exit");
                               
                               /* Initialize our data for use by callback. */
                               data.left_phase = data.right_phase = 0.0;
                               /* Initialize library before making any other calls. */
                               err = Pa_Initialize();
                               if( err != paNoError ) goto error;
                               
                               /* Open an audio I/O stream. */
                               err = Pa_OpenDefaultStream( &stream,
                                                                                                    0,          /* no input channels */
                                                                                                    2,          /* stereo output */
                                                                                                    paFloat32,  /* 32 bit floating point output */
                                                                                                    SAMPLE_RATE,
                                                                                                    256,        /* frames per buffer */
                                                                                                    patestCallbackAB3,
                                                                                                    &data );
                               if( err != paNoError ) goto error;
                               
                               err = Pa_StartStream( stream );
                               if( err != paNoError ) goto error;
                               
                               /* Sleep for several seconds. */
                               Pa_Sleep(NUM_SECONDS*100);
                               
                               err = Pa_StopStream( stream );
                               if( err != paNoError ) goto error;
                               err = Pa_CloseStream( stream );
                               if( err != paNoError ) goto error;
                               usernote[0] = getche() ;
                               usernote[1] = getche() ;
                               printf("\n");
                               Pa_Terminate();
                               
                               switch (usernote[0]) {
                    case 'G': case'g':
                        switch (usernote[1]) {
                            case '#':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'A': case'a':
                        switch (usernote[1]) {
                            case 'b': case 'B':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'x': case 'X':
                        goto end;
                    default:
                        printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                        
                        break;
                }
                break;
                /////////////////////////////            
                break;
                           case 10:
                printf("Guess the note.\n # or b for accidentals X to exit");
                               
                               /* Initialize our data for use by callback. */
                               data.left_phase = data.right_phase = 0.0;
                               /* Initialize library before making any other calls. */
                               err = Pa_Initialize();
                               if( err != paNoError ) goto error;
                               
                               /* Open an audio I/O stream. */
                               err = Pa_OpenDefaultStream( &stream,
                                                                                                    0,          /* no input channels */
                                                                                                    2,          /* stereo output */
                                                                                                    paFloat32,  /* 32 bit floating point output */
                                                                                                    SAMPLE_RATE,
                                                                                                    256,        /* frames per buffer */
                                                                                                    patestCallbackBB3,
                                                                                                    &data );
                               if( err != paNoError ) goto error;
                               
                               err = Pa_StartStream( stream );
                               if( err != paNoError ) goto error;
                               
                               /* Sleep for several seconds. */
                               Pa_Sleep(NUM_SECONDS*100);
                               
                               err = Pa_StopStream( stream );
                               if( err != paNoError ) goto error;
                               err = Pa_CloseStream( stream );
                               if( err != paNoError ) goto error;
                               usernote[0] = getche() ;
                               usernote[1] = getche() ;
                               printf("\n");
                               Pa_Terminate();
                               
                               switch (usernote[0]) {
                    case 'A': case'a':
                        switch (usernote[1]) {
                            case '#':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'B': case'b':
                        switch (usernote[1]) {
                            case 'b': case 'B':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'x': case 'X':
                        goto end;
                    default:
                        printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                        
                        break;
                }
                break;
                /////////////////////////////           
                break;
                             
                           case 11:
                             printf("Guess the note.\n # or b for accidentals X to exit");
                               
                               /* Initialize our data for use by callback. */
                               data.left_phase = data.right_phase = 0.0;
                               /* Initialize library before making any other calls. */
                               err = Pa_Initialize();
                               if( err != paNoError ) goto error;
                               
                               /* Open an audio I/O stream. */
                               err = Pa_OpenDefaultStream( &stream,
                                                                                                    0,          /* no input channels */
                                                                                                    2,          /* stereo output */
                                                                                                    paFloat32,  /* 32 bit floating point output */
                                                                                                    SAMPLE_RATE,
                                                                                                    256,        /* frames per buffer */
                                                                                                    patestCallbackDB4,
                                                                                                    &data );
                               if( err != paNoError ) goto error;
                               
                               err = Pa_StartStream( stream );
                               if( err != paNoError ) goto error;
                               
                               /* Sleep for several seconds. */
                               Pa_Sleep(NUM_SECONDS*100);
                               
                               err = Pa_StopStream( stream );
                               if( err != paNoError ) goto error;
                               err = Pa_CloseStream( stream );
                               if( err != paNoError ) goto error;
                               usernote[0] = getche() ;
                               usernote[1] = getche() ;
                               printf("\n");
                               Pa_Terminate();
                               
                              switch (usernote[0]) {
                    case 'C': case'c':
                        switch (usernote[1]) {
                            case '#':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'D': case'd':
                        switch (usernote[1]) {
                            case 'b': case 'B':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'x': case 'X':
                        goto end;
                    default:
                        printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                        
                        break;
                }
                break;
                /////////////////////////////            
                break;
                
                           case 12:
                                printf("Guess the note.\n # or b for accidentals X to exit");
                               
                               /* Initialize our data for use by callback. */
                               data.left_phase = data.right_phase = 0.0;
                               /* Initialize library before making any other calls. */
                               err = Pa_Initialize();
                               if( err != paNoError ) goto error;
                               
                               /* Open an audio I/O stream. */
                               err = Pa_OpenDefaultStream( &stream,
                                                                                                    0,          /* no input channels */
                                                                                                    2,          /* stereo output */
                                                                                                    paFloat32,  /* 32 bit floating point output */
                                                                                                    SAMPLE_RATE,
                                                                                                    256,        /* frames per buffer */
                                                                                                    patestCallbackEB4,
                                                                                                    &data );
                               if( err != paNoError ) goto error;
                               
                               err = Pa_StartStream( stream );
                               if( err != paNoError ) goto error;
                               
                               /* Sleep for several seconds. */
                               Pa_Sleep(NUM_SECONDS*100);
                               
                               err = Pa_StopStream( stream );
                               if( err != paNoError ) goto error;
                               err = Pa_CloseStream( stream );
                               if( err != paNoError ) goto error;
                               usernote[0] = getche() ;
                               usernote[1] = getche() ;
                               printf("\n");
                               Pa_Terminate();
                               
                              switch (usernote[0]) {
                    case 'D': case'd':
                        switch (usernote[1]) {
                            case '#':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'E': case'e':
                        switch (usernote[1]) {
                            case 'b': case 'B':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'x': case 'X':
                        goto end;
                    default:
                        printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                        
                        break;
                }
                break;
                /////////////////////////////            
                break;
                
                             
                           case 13:
                               printf("Guess the note.\n # or b for accidentals X to exit");
                               
                               /* Initialize our data for use by callback. */
                               data.left_phase = data.right_phase = 0.0;
                               /* Initialize library before making any other calls. */
                               err = Pa_Initialize();
                               if( err != paNoError ) goto error;
                               
                               /* Open an audio I/O stream. */
                               err = Pa_OpenDefaultStream( &stream,
                                                                                                    0,          /* no input channels */
                                                                                                    2,          /* stereo output */
                                                                                                    paFloat32,  /* 32 bit floating point output */
                                                                                                    SAMPLE_RATE,
                                                                                                    256,        /* frames per buffer */
                                                                                                    patestCallbackGB4,
                                                                                                    &data );
                               if( err != paNoError ) goto error;
                               
                               err = Pa_StartStream( stream );
                               if( err != paNoError ) goto error;
                               
                               /* Sleep for several seconds. */
                               Pa_Sleep(NUM_SECONDS*100);
                               
                               err = Pa_StopStream( stream );
                               if( err != paNoError ) goto error;
                               err = Pa_CloseStream( stream );
                               if( err != paNoError ) goto error;
                               usernote[0] = getche() ;
                               usernote[1] = getche() ;
                               printf("\n");
                               Pa_Terminate();
                               
                               switch (usernote[0]) {
                    case 'F': case'f':
                        switch (usernote[1]) {
                            case '#':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'G': case'g':
                        switch (usernote[1]) {
                            case 'b': case 'B':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'x': case 'X':
                        goto end;
                    default:
                        printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                        
                        break;
                }
                break;
                /////////////////////////////            
                break;
                
                
                           case 14:
                                 printf("Guess the note.\n # or b for accidentals X to exit");
                               
                               /* Initialize our data for use by callback. */
                               data.left_phase = data.right_phase = 0.0;
                               /* Initialize library before making any other calls. */
                               err = Pa_Initialize();
                               if( err != paNoError ) goto error;
                               
                               /* Open an audio I/O stream. */
                               err = Pa_OpenDefaultStream( &stream,
                                                                                                    0,          /* no input channels */
                                                                                                    2,          /* stereo output */
                                                                                                    paFloat32,  /* 32 bit floating point output */
                                                                                                    SAMPLE_RATE,
                                                                                                    256,        /* frames per buffer */
                                                                                                    patestCallbackAB4,
                                                                                                    &data );
                               if( err != paNoError ) goto error;
                               
                               err = Pa_StartStream( stream );
                               if( err != paNoError ) goto error;
                               
                               /* Sleep for several seconds. */
                               Pa_Sleep(NUM_SECONDS*100);
                               
                               err = Pa_StopStream( stream );
                               if( err != paNoError ) goto error;
                               err = Pa_CloseStream( stream );
                               if( err != paNoError ) goto error;
                               usernote[0] = getche() ;
                               usernote[1] = getche() ;
                               printf("\n");
                               Pa_Terminate();
                               
                              switch (usernote[0]) {
                    case 'G': case'g':
                        switch (usernote[1]) {
                            case '#':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'A': case'a':
                        switch (usernote[1]) {
                            case 'b': case 'B':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'x': case 'X':
                        goto end;
                    default:
                        printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                        
                        break;
                }
                break;
                /////////////////////////////           
                break;
                           case 15:
                printf("Guess the note.\n # or b for accidentals X to exit");
                               
                               /* Initialize our data for use by callback. */
                               data.left_phase = data.right_phase = 0.0;
                               /* Initialize library before making any other calls. */
                               err = Pa_Initialize();
                               if( err != paNoError ) goto error;
                               
                               /* Open an audio I/O stream. */
                               err = Pa_OpenDefaultStream( &stream,
                                                                                                    0,          /* no input channels */
                                                                                                    2,          /* stereo output */
                                                                                                    paFloat32,  /* 32 bit floating point output */
                                                                                                    SAMPLE_RATE,
                                                                                                    256,        /* frames per buffer */
                                                                                                    patestCallbackBB4,
                                                                                                    &data );
                               if( err != paNoError ) goto error;
                               
                               err = Pa_StartStream( stream );
                               if( err != paNoError ) goto error;
                               
                               /* Sleep for several seconds. */
                               Pa_Sleep(NUM_SECONDS*100);
                               
                               err = Pa_StopStream( stream );
                               if( err != paNoError ) goto error;
                               err = Pa_CloseStream( stream );
                               if( err != paNoError ) goto error;
                               usernote[0] = getche() ;
                               usernote[1] = getche() ;
                               printf("\n");
                               Pa_Terminate();
                               
                              switch (usernote[0]) {
                    case 'A': case'a':
                        switch (usernote[1]) {
                            case '#':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'B': case'b':
                        switch (usernote[1]) {
                            case 'b': case 'B':
                                printf(ANSI_COLOR_GREEN   "Great!\n"  ANSI_COLOR_RESET "\n");
                                break;
                                
                            default:
                                printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                                
                                break;
                        }
                        break;
                    case 'x': case 'X':
                        goto end;
                    default:
                        printf(ANSI_COLOR_RED     "Wrong note\a\n"     ANSI_COLOR_RESET "\n");
                        
                        break;
                }
                break;
                /////////////////////////////            
                break;
                      
                           
                /////////////////////////////
                 }
           }
       
       
       
       
       
       
       return err;
error:
       Pa_Terminate();
       fprintf( stderr, "An error occured while using the portaudio stream\n" );
       fprintf( stderr, "Error number: %d\n", err );
       fprintf( stderr, "Error message: %s\n", Pa_GetErrorText( err ) );
       return err;
end:
       Pa_Terminate();
       printf("Thanks for playing Muthahubbard!\n");
       
}

