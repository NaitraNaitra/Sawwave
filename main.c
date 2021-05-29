#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "portaudio.h"
#define ANSI_COLOUR_RED     "\x1b[31m"
#define ANSI_COLOUR_GREEN     "\x1b[32m"
#define ANSI_COLOUR_RESET     "\x1b[0m"
#define ANSI_CLEAR_CONSOLE "\e[1;1H\e[2J"
#define NUM_SECONDS   (1)
#define SAMPLE_RATE   (44100)
float pitchModifier;
typedef struct
{
    float left_phase;
    float right_phase;
}
paTestData;


static int patestCallback( const void *inputBuffer, void *outputBuffer,
                          unsigned long framesPerBuffer,
                          const PaStreamCallbackTimeInfo* timeInfo,
                          PaStreamCallbackFlags statusFlags,
                          void *userData )
{
    /* Cast data passed through stream to our structure. */
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) inputBuffer; /* Prevent unused variable warning. */
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++ = data->left_phase;  /* left */
        *out++ = data->right_phase;  /* right */
        /* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
        data->left_phase += 0.01f;
        /* When signal reaches top, drop back down. */
        if( data->left_phase >= 1.0f ) data->left_phase -= pitchModifier;
        /* higher pitch so we can distinguish left and right. */
        data->right_phase += 0.03f;
        if( data->right_phase >= 1.0f ) data->right_phase -= pitchModifier;
    }
    return 0;
}


int main(){
    
    static paTestData data;
    char usernote[5];
    int i=0,j=0,rNote,m,k,l,NQuestions=0,Correct=0;
    float percentageCorrect,nextPitch;
    float C = 3.3708f;
    float ratio = 0.94387970035f;
    char sNotes[][12] ={"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
    char SEnhNotes[][12] ={"B#","DB","D","EB","FB","E#","GB","G","AB","A","BB","CB"};
    time_t t;
    srand((unsigned) time(&t));
    PaStream *stream;
    PaError err;

    typedef struct{
            char note[5];
            char enharmonic[5];
            float pitch;
    }note;

    note notes[37];

    for(i =0; i < 37; i++)
    {
    nextPitch= C * (pow(ratio,i));

    strcpy(notes[i].note,sNotes[j]);
    strcpy(notes[i].enharmonic,SEnhNotes[j]);
    notes[i].pitch = nextPitch;
        j++;
        if (j==12)
            j=0;
    }
    
    note randomNote;
    
    for(j=0; j < 100; j++){
        //random function
        rNote= rand() % 37;
        randomNote = notes[rNote];
        pitchModifier = randomNote.pitch;
        
        REPEAT:
        /* Initialize our data for use by callback. */
        data.left_phase = data.right_phase = 0.0;
        /* Initialize library before making any other calls. */
        err = Pa_Initialize();
        if( err != paNoError ) goto error;
        
        /* Open an audio I/O stream. */
        err = Pa_OpenDefaultStream( &stream,
                                   0,          /* no input channels */
                                   2,          /* stereo output */
                                   paFloat32,  /* 32 bit floating point output */
                                   SAMPLE_RATE,
                                   256,        /* frames per buffer */
                                   patestCallback,
                                   &data );
        if( err != paNoError ) goto error;
        
        err = Pa_StartStream( stream );
        if( err != paNoError ) goto error;
        
        /* Sleep for several seconds. */
        Pa_Sleep(NUM_SECONDS*1000);
        
        err = Pa_StopStream( stream );
        if( err != paNoError ) goto error;
        err = Pa_CloseStream( stream );
        if( err != paNoError ) goto error;
        Pa_Terminate();
    
        printf(ANSI_CLEAR_CONSOLE);
        //logic for comparing
        //printf("%s\n", randomNote.note);
        printf("Please enter a note. R to repeat Q and to quit\n");
        fgets(usernote,5,stdin);
        
        for (k = 0; usernote[k]!='\0'; k++) {
            if(usernote[k] >= 'a' && usernote[k] <= 'z') {
                usernote[k] = usernote[k] -32;
            }
        }
        
        for (l = 0; usernote[l]!='\0'; l++) {
            if(usernote[l] == '\n') {
                usernote[l] = '\0';
            }
            switch(usernote[l]){
            case 'R':
                goto REPEAT;
                break;
            case 'Q':
                goto EXIT;
                break;
                
            }
        }

        for (k = 0; randomNote.note[k]!='\0'; k++){}
        for (l = 0; randomNote.enharmonic[l]!='\0'; l++){}
        
        strncmp(usernote,randomNote.note,(k))==0 || strncmp(usernote,randomNote.enharmonic,(l))==0 ? 
        (printf(ANSI_COLOUR_GREEN"Great!\n"ANSI_COLOUR_RESET) && Correct++ )  : printf(ANSI_COLOUR_RED"wrong!\n"ANSI_COLOUR_RESET);
        NQuestions++;
    
    percentageCorrect = ((float)Correct/(float)NQuestions) *100;
    printf("%.1f%%\n",percentageCorrect);
        
        
    } EXIT:
    if(i!=100)
        printf("%.1f%%\n",percentageCorrect); 
    
    Pa_Sleep(1000);
    printf(ANSI_CLEAR_CONSOLE);
    
    return err;
error:
    Pa_Terminate();
    fprintf( stderr, "An error occurred while using the portaudio stream\n" );
    fprintf( stderr, "Error number: %d\n", err );
    fprintf( stderr, "Error message: %s\n", Pa_GetErrorText( err ) );
    return err;
    

return 0;
}
